#include <stdio.h>
#include <stdlib.h>
#include "back_tracking.h"


#define SOLVE_BT_NQUEEN  false
#define SOLVE_BT_KT      false
#define SOLVE_BT_SUDOKU  true


int main()
{
    printf("Hello world!\n");

    if(SOLVE_BT_NQUEEN)
    {
        printf("Problem 1: Solve the N queen problem!\n");
        for(int i = 8; i < 9 ; i++)
        {
            solveNQ(i);
        }
    }

    if(SOLVE_BT_KT)
    {
        printf("Problem 2: Solve the Knights Travel Problem - mine!\n");
        knightsTravel(8);

        printf("Problem 2: Solve the Knights Travel Problem - GeekforGeek Version!\n");
        knightsTravel_sol2(8);

        printf("Problem 2: Solve the Knights Travel Problem - GeekforGeek Version+ last approach!\n");
        knightsTravel_sol3(8);
    }

    if(SOLVE_BT_SUDOKU)
    {
        printf("Problem 3: Solve the Sudoku!\n");
            // 0 means unassigned cells
        int grid[9][9] = {{ 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                            { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                            { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                            { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                            { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                            { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                            { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                            { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                            { 7, 4, 5, 0, 8, 6, 3, 1, 0 }};

        solveSudoku_sol2((int *)grid, 9);


        printf("Problem 3: Solve World's hardest Sudoku!\n");
            // 0 means unassigned cells
        int grid_hardest[9][9] =    {
                                    { 8, 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 3, 6, 0, 0, 0, 0, 0 },
                                    { 0, 7, 0, 0, 9, 0, 2, 0, 0 },
                                    //----------------------------
                                    { 0, 5, 0, 0, 0, 7, 0, 0, 0 },
                                    { 0, 0, 0, 0, 4, 5, 7, 0, 0 },
                                    { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
                                    //----------------------------
                                    { 0, 0, 1, 0, 0, 0, 0, 6, 8 },
                                    { 0, 0, 8, 5, 0, 0, 0, 1, 0 },
                                    { 0, 9, 0, 0, 0, 0, 4, 0, 0 }};

        solveSudoku_sol2((int *)grid_hardest, 9);
    }

    return 0;
}
