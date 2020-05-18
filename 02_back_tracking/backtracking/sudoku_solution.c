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

static bool isChangable(int *pGrid, int *pGridBkup, int row, int col, int N)
{

    if(pGridBkup[(row * N) + col] == 0)//already filled
    {
        return true;
    }
    else
    {
        return false;
    }


}


static bool isLegal(int *pGrid, int *pGridBkup, int num, int row, int col, int N)
{
    ENTER()

    int i, j, elem;
    int orig_elem;

    orig_elem = pGridBkup[(row * N) + col];

    if(orig_elem != 0)//already filled
    {
        if(num == orig_elem)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

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
static bool solveSudokuUtil(int *pGrid, int *pGridBkup, int row, int col, int N)
{
    ENTER()
    /* Base condition*/
    if (row >= N)
    {
        return true;
    }




    /*from the current position try out every next possible move*/
    for(int num = 1; num <= 9; num++)
    {
        if(isLegal(pGrid, pGridBkup, num, row, col, N))
        {
            int nextCol;
            int nextRow;

            /* It is legal to place the num here  so a Move is made*/
            if(isChangable(pGrid, pGridBkup, row, col, N))
            {
                //printf("isChangable\n");
                pGrid[(row * N) + col] = num;//if
            }

            /* move to the next col*/
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
            if(solveSudokuUtil(pGrid, pGridBkup, nextRow, nextCol, N))
            {
                return true;
            }

            if(isChangable(pGrid, pGridBkup, row, col, N))
            {
                 pGrid[(row * N) + col] = 0;//BACK TRACK
            }
        }
    }

    /* If all numbers are tried and failed*/
    return false;
}

bool solveSudoku(int *pGrid, int N)
{
    bool isSolved = true;
    int noSolutions = 0;

    int *pGridBkup = (int*)malloc(N*N*sizeof(int)); //creating the memory for board

    /* a back up is required to keep track of what is original and what is getting updated*/
    for(int i = 0; i < (N*N); i++)
    {
        pGridBkup[i] = pGrid[i];
    }

    printGrid(pGrid, N);
    printGrid(pGridBkup, N);
    /*solve the Sudoku Puzzle starting from the first row, first col*/
    if(!solveSudokuUtil(pGrid, pGridBkup, 0, 0, N))
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

    free(pGridBkup);

    return isSolved;
}
