#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode
{
    struct tagBSTNode *Left;
    struct tagBSTNode *Right;

    ElementType Data;
} BSTNode;

BSTNode *BST_CreateNode(ElementType NewData);
void BST_DestroyNode(BSTNode *Node);
void BST_DestroyTree(BSTNode *Tree);

BSTNode *BST_SearchNode(BSTNode *Tree, ElementType Target);
BSTNode *BST_SearchMinNode(BSTNode *Tree);
void BST_InsertNode(BSTNode *Tree, BSTNode *Child);
BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, ElementType Target);
void BST_InorderPrintTree(BSTNode *Node);

#endif // __BINARYSEARCHTREE_H__