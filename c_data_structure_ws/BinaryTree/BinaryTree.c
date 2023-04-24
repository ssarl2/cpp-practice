#include "BinaryTree.h"

SBTNode *SBT_CreateNode(ElementType NewData)
{
    SBTNode *NewNode = (SBTNode *)malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void SBT_DestroyNode(SBTNode *Node)
{
    free(Node);
}

void SBT_PreorderPrintTree(SBTNode *Node)
{
    if (Node == NULL)
    {
        return;
    }

    printf(" %c", Node->Data);

    SBT_PreorderPrintTree(Node->Left);
    SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode *Node)
{
    if (Node == NULL)
    {
        return;
    }

    SBT_InorderPrintTree(Node->Left);

    printf(" %c", Node->Data);

    SBT_InorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode *Node)
{
    if (Node == NULL)
    {
        return;
    }

    SBT_PostorderPrintTree(Node->Left);
    SBT_PostorderPrintTree(Node->Right);

    printf(" %c", Node->Data);
}

void SBT_DestroyTree(SBTNode *Node)
{
    if (Node == NULL)
    {
        return;
    }

    SBT_DestroyTree(Node->Left);
    SBT_DestroyTree(Node->Right);
    SBT_DestroyNode(Node);
}