/*I modified my solution based what is given in Geeks for Geeks
    They have better stack usage
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "back_tracking.h"

/* A utility function to print Grid */
static void printGrid(int *pGrid, int N)
{
    ENTER()
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int elem = pGrid[(i * N) + j];

            if(elem < 10)
            {
                printf(" %d ", elem);
            }
            else
            {
                printf("%d ",elem);
            }
        }
        printf("\n");
    }
    printf("\n");
}

static bool isLegal(int *pGrid, int num, int row, int col, int N)
{
    ENTER()

    int i, j, elem;

    /*check if same element is there row wise*/
    for(j = 0; j < N; j++)
    {
        elem = pGrid[(row * N) + j];

        if(elem == num)
        {
             return false;
        }

    }

    /*check if same element is there col wise*/
    for(i = 0; i < N; i++)
    {
        elem = pGrid[(i * N) + col];

        if(elem == num)
        {
             return false;
        }

    }

    /*check if same element is there col wise*/
    int blk_row_start = (row/3)*3;
    int blk_col_start = (col/3)*3;

    for(i = blk_row_start; i < (blk_row_start+3); i++)
    {
        for(j = blk_col_start; j < (blk_col_start+3); j++)
        {
            elem = pGrid[(i * N) + j];

            if(elem == num)
            {
                return false;
            }
        }
    }
    return true;
}



/*
    A recursive utility that finds the path of the night
*/
static bool solveSudokuUtil(int *pGrid, int row, int col, int N)
{
    ENTER()
    /* Base condition*/
    if (row >= N)
    {
        return true;
    }

    int nextCol;
    int nextRow;

    /*get the next rows and cols*/
    if(col != (N -1))
    {
        nextCol = col + 1;
        nextRow = row;
    }
    else
    {
        nextRow = row + 1;
        nextCol = 0;
    }

        /* then recur to place the rest of the queens*/
    if(pGrid[(row * N) + col] != 0)
    {
        return solveSudokuUtil(pGrid, nextRow, nextCol, N);
    }


    /*from the current position try out every next possible move*/
    for(int num = 1; num <= 9; num++)
    {
        if(isLegal(pGrid, num, row, col, N))
        {
            //printf("isChangable\n");
            pGrid[(row * N) + col] = num;//if

            /* then recur to place the rest of the queens*/
            if(solveSudokuUtil(pGrid, nextRow, nextCol, N))
            {
                return true;
            }

            pGrid[(row * N) + col] = 0;//BACK TRACK
        }
    }


    /* If all numbers are tried and failed*/
    return false;
}

bool solveSudoku_sol2(int *pGrid, int N)
{
    bool isSolved = true;
    int noSolutions = 0;

    printGrid(pGrid, N);

    /*solve the Sudoku Puzzle starting from the first row, first col*/
    if(!solveSudokuUtil(pGrid, 0, 0, N))
    {
        printf("Could not find a solution for N = %d\n", N);
        isSolved = false;
    }
    else
    {
        printf("Found the solution\n");
        isSolved = true;
    }

    printGrid(pGrid, N);

    return isSolved;
}
