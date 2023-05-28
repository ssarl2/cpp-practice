#ifndef __KNUTHMORRISPRATT_H__
#define __KNUTHMORRISPRATT_H__

#include <stdio.h>

int KnuthMorrisPratt(char *Text, int TextSize, int Start, char *Pattern, int PatternSize);

void Preprocess(char *Pattern, int PatternSize, int *Border);

#endif // __KNUTHMORRISPRATT_H__