#ifndef __BOYERMOORE_H__
#define __BOYERMOORE_H__

#include <stdio.h>

int BoyerMoore(char *Text, int TextSize, int Start, char *Pattern, int PatternSize);

void BuildGST(char *Pattern, int PatternSize, int *PosOfBorder, int *GoodSuffTable);
void BuildBCT(char *Pattern, int PatternSize, int *BadCharTable);

int Max(int A, int B);

#endif // __BOYERMOORE_H__