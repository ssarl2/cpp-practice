#ifndef __LCRSTREE_H__
#define __LCRSTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode *LeftChild;
    struct tagLCRSNode *RightSibling;

    ElementType Data;
} LCRSNode;

LCRSNode *LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode *Node);
void LCRS_DestroyTree(LCRSNode *Root);

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child);
void LCRS_PrintTree(LCRSNode *Node, int Depth);

#endif // __LCRSTREE_H__