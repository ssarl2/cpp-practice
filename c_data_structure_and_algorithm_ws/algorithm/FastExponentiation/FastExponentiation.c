#include <stdio.h>

typedef unsigned long ULONG; // 64bit

ULONG Power(int Base, int Exponenet)
{
    if (Exponenet == 1)
        return Base;
    else if (Base == 0)
        return 1;

    if (Exponenet % 2 == 0)
    {
        ULONG NewBase = Power(Base, Exponenet / 2);
        return NewBase * NewBase;
    }
    else
    {
        ULONG NewBase = Power(Base, (Exponenet - 1) / 2);
        return (NewBase * NewBase) * Base;
    }
}

int main(void)
{
    int Base = 2;
    int Exponenet = 30;
    printf("%d^%d=%lu\n", Base, Exponenet, Power(Base, Exponenet));

    return 0;
}