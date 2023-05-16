#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <stdlib.h>
#include "../LinkedListStack/LinkedListStack.h"

typedef enum
{
    LEFT_PARENTHESIS = '(',
    RIGHT_PARENTHESIS = ')',
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
    SPACE = ' ',
    OPERAND
} SYMBOL;

int IsNumber(char Cipher);
unsigned int GetNextToken(char *Expression, char *Token, int *TYPE);
int GetPriority(char Operator, int InStack);
int IsPrior(char OperatorInStack, char OperatorInToken);
void GetPostfix(char *InfixExpression, char *PostfixExpression);
double Calculate(char *PostfixExpression);

#endif // __CALCULATOR_H__