#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode *Left;
    struct tagSBTNode *Right;

    ElementType Data;
} SBTNode;

SBTNode *SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode *Node);
void SBT_PreorderPrintTree(SBTNode *Node);

void SBT_InorderPrintTree(SBTNode *Node);
void SBT_PostorderPrintTree(SBTNode *Node);
void SBT_DestroyTree(SBTNode *Node);

#endif // __BINARYTREE_H__