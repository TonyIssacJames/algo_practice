/*I modified my solution based what is given in Geeks for Geeks
    They have better stack usage
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "back_tracking.h"

#define WITHIN_BOUND(x, N)  ((x) < N? ((x)>=0? true: false): false)

/* A utility function to print solution */
static void printBoard(int *pBoard, int N)
{
    ENTER()
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int elem = pBoard[(i * N) + j];

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

static bool  isLegal(int *pBoard, int row, int col, int N)
{
    ENTER()
    if(WITHIN_BOUND(row, N) && WITHIN_BOUND(col , N))
    {
        if(pBoard[(row * N) + col] ==  0)//occupied
        {
            return true;
        }
    }

    return false;
}



/*
    A recursive utility that finds the path of the night
*/
static bool moveKnight(int *pBoard, int row, int col, int movesMade, int N, int *xMoves, int *yMoves)
{
    ENTER()
    /* Base condition*/
    if (movesMade >= N*N)
    {
        return true;
    }

    /*from the current position try out every next possible move*/
    for(int move = 0; move < 8; move++)
    {
        int nextRow =  row + xMoves[move];
        int nextCol =  col + yMoves[move];

        if(isLegal(pBoard, nextRow, nextCol, N))
        {
            /* Move is Legal so a Move is made*/
            movesMade += 1;
            pBoard[(nextRow * N) + nextCol] = movesMade;//if

            /* then recur to place the rest of the queens*/
            if(moveKnight(pBoard, nextRow, nextCol, movesMade, N, xMoves, yMoves))
            {
                return true;
            }

            /* if none of the next moves are success,  then backtrack*/
            pBoard[(nextRow * N) + nextCol] =  0;//BACK TRACK
            movesMade -= 1;
        }
    }

    /* Base condition*/
    return false;
}

static bool findKnightsPath(int *pBoard, int N)
{
    int row, col;
    int xMoves[8]= {-2, -2, -1, -1,  1,  1,  2,  2};
    int yMoves[8]= {-1,  1, -2,  2, -2,  2, -1,  1};


    ENTER()
    /* try out every starting position*/
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            pBoard[(row * N) + col] = 1;//if

            if(moveKnight(pBoard, row, col, 1, N, xMoves, yMoves))
            {
                return true;//success
            }

            pBoard[(row * N) + col] = 0;//if
        }
    }

    return false;
}

bool knightsTravel_sol3(int N)
{
    bool isSolved = true;
    int noSolutions = 0;

    int *pBoard = (int*)malloc(N*N*sizeof(int)); //creating the memory for board

    /*initialize the board*/
    memset((unsigned char*) pBoard, 0, N*N*sizeof(int));

    if(!findKnightsPath(pBoard, N))
    {
        printf("Could not find a solution for N = %d\n", N);
        isSolved = false;
    }
    else
    {
        printf("Found the solution\n");
        isSolved = true;
    }

    printBoard(pBoard, N);

    free(pBoard);

    return isSolved;
}
