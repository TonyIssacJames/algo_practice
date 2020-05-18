#ifndef BACK_TRACKING_H_INCLUDED
#define BACK_TRACKING_H_INCLUDED

#include <stdbool.h>

//#define DEBUG

/* Solve an N*N board*/
bool solveNQ(int N);

/* solve the Knights Travel Path*/
bool knightsTravel(int N);
bool knightsTravel_sol2(int N); //solution based on GeekforGeeks
bool knightsTravel_sol3(int N); //solution based on GeekforGeeks

bool solveSudoku(int *pGrid, int N);
bool solveSudoku_sol2(int *pGrid, int N);
#ifdef DEBUG
#define ENTER() printf("\n###### In %s ######\n", __func__); //print function name
#else // DEBUG
#define ENTER()
#endif // DEBUG
#endif // BACK_TRACKING_H_INCLUDED
