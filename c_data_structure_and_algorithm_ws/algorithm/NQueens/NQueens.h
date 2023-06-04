#ifndef __NQUEENS_H__
#define __NQUEENS_H__

void PrintSolution(int Columns[], int NumberOfQueens);
int IsThreatened(int Columns[], int NewRow);
void FindSolutionForQueen(int Columns[], int Row, int NumberOfQueens, int *SolutionCount);

#endif // __NQUEENS_H__