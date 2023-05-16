#include "PriorityQueue.h"

void PrintNode(PQNode *Node)
{
    printf("Task : %s (Priority:%d)\n", Node->Data, Node->Priority);
}

int main(void)
{
    PriorityQueue *PQ = PQ_Create(3);
    PQNode Popped;

    PQNode Nodes[7] =
        {
            {34, (void *)"coding"},
            {12, (void *)"meeting clients"},
            {87, (void *)"making a coffee"},
            {45, (void *)"writing a document"},
            {35, (void *)"debugging"},
            {66, (void *)"brushing teeth"}};

    PQ_Enqueue(PQ, Nodes[0]);
    PQ_Enqueue(PQ, Nodes[1]);
    PQ_Enqueue(PQ, Nodes[2]);
    PQ_Enqueue(PQ, Nodes[3]);
    PQ_Enqueue(PQ, Nodes[4]);
    PQ_Enqueue(PQ, Nodes[5]);

    printf("The number of left over tasks : %d\n", PQ->UsedSize);

    while (!PQ_IsEmpty(PQ))
    {
        PQ_Dequeue(PQ, &Popped);
        PrintNode(&Popped);
    }

    return 0;
}