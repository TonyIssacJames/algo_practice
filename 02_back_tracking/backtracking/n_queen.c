
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* A utility function to print solution */
static void printBoard(int *pBoard, int N)
{

    printf("\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(pBoard[(i * N) + j] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("Q ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
    This is a utility function which checks if a Queen can be
    placed on a particular row or column.

    Basically our Bounding Function
*/
static bool isSafe(int *pBoard, int row, int col, int N)
{
    int i, j;

    /*check rows*/
    for(j = 0; j < col; j++)
    {
        if(pBoard[(row * N) + j] != 0)
            return false;
    }

    /*check upper diagonal or left side*/
    for(i = row, j = col; i >= 0 && j >=0; i--, j--)
    {
        if(pBoard[(i * N) + j] != 0)
            return false;
    }

    /*check lower diagonal or left side*/
    for(i = row, j = col; i < N && j >=0; i++, j--)
    {
        if(pBoard[(i * N) + j] != 0)
            return false;
    }

    return true;
}

/*
    A recursive utility function which does the BT
*/
bool solveNQUtil(int pState, int *pBoard, int col, int N, int *noSolutions)
{
    int row;

    /* Base condition*/
    if (col >= N)
    {
        printBoard(pBoard, N);
        *noSolutions +=1;
        return false;
    }


    /*for every row in the column*/
    for(row = 0; row < N; row++)
    {
        if(isSafe(pBoard, row, col, N))
        {
            pBoard[(row * N) + col] = 1;//if Safe place the Queen

            /* then recur to place the rest of the queens*/
            if(solveNQUtil(pState, pBoard, col + 1, N, noSolutions))
            {
                return true;
            }

            /* placing the Queen on i, col did not lead to a solution
               so backtrack*/
            pBoard[(row * N) + col] = 0;//BACK TRACK
        }
    }

    /* Base condition*/
    return false;
}

bool solveNQ(int N)
{
    bool isSolved = true;
    int noSolutions = 0;

    int *pBoard = (int*)malloc(N*N*sizeof(int)); //creating the memory for board
    int *pState = (int*)malloc(N*sizeof(int)); //creating the memory for state

    /*initialize the board*/
    memset((unsigned char*) pBoard, 0, N*N*sizeof(int));

    /*initialize the state*/
    memset((unsigned char*) pState, 0, N*sizeof(int));

    solveNQUtil(pState, pBoard, 0, N, &noSolutions);

    if(noSolutions == 0)
    {
        printf("Could not find a solution for N = %d\n", N);
        isSolved = false;
    }
    else
    {
        printf("%d Solutions found for N = %d\n", noSolutions, N);
        isSolved = true;
    }

    printBoard(pBoard, N);

    free(pBoard);
    free(pState);

    return isSolved;
}


