#include "Huffman.h"

void PrintToBinary(int target)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (target >> i) & 1);
}

void PrintQueue(PriorityQueue *DebugPQ, int priority, unsigned char symbol)
{
    PQNode DebugNode;
    DebugNode.Priority = priority;
    DebugNode.Data = symbol;
    PQ_Enqueue(DebugPQ, DebugNode);

    printf("Huffman_BuildPrefixTree, Priority Queue symbol '%c' and priority %d added \n", symbol, priority);
    printf("Huffman_BuildPrefixTree, Priority Queue: ");

    for (int i = 0; i < DebugPQ->UsedSize; i++)
    {
        printf("(%c, %d) ", DebugPQ->Nodes[i].Data, DebugPQ->Nodes[i].Priority);
    }

    printf("\n\n");
}

HuffmanNode *Huffman_CreateNode(SymbolInfo NewData)
{
    HuffmanNode *NewNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void Huffman_DestroyNode(HuffmanNode *Node)
{
    free(Node);
}

void Huffman_DestroyTree(HuffmanNode *Node)
{
    if (Node == NULL)
        return;

    Huffman_DestroyTree(Node->Left);
    Huffman_DestroyTree(Node->Right);
    Huffman_DestroyNode(Node);
}

void Huffman_AddBit(BitBuffer *Buffer, char Bit)
{
    printf("Huffman_AddBit, Buffer->Size : %d, Bit : '%d'\n", Buffer->Size, Bit);
    /**
     * @brief If you are not familar to the expresion of 0x80
     * or bit operation
     * https://chat.openai.com/share/abbf8595-08c2-4774-bb41-f8f78d8f72a6
     */
    UCHAR Mask = 0x80; // Binary: 1000 0000

    if (Buffer->Size % 8 == 0)
    {
        Buffer->Buffer = realloc(Buffer->Buffer, sizeof(UCHAR) * ((Buffer->Size / 8) + 1));
        Buffer->Buffer[Buffer->Size / 8] = 0x00;
    }

    Mask >>= Buffer->Size % 8;

    printf("Huffman_AddBit, Before: Buffer->Buffer[Buffer->Size / 8] : ");
    PrintToBinary(Buffer->Buffer[Buffer->Size / 8]);
    printf(", decimal notation : %d\n", Buffer->Buffer[Buffer->Size / 8]);
    if (Bit == 1)
    {
        printf("Huffman_AddBit,         Buffer->Buffer[Buffer->Size / 8] |= Mask\n");
        printf("Huffman_AddBit,         ");
        PrintToBinary(Buffer->Buffer[Buffer->Size / 8]);
        printf(" |= ");
        PrintToBinary(Mask);
        Buffer->Buffer[Buffer->Size / 8] |= Mask;
    }
    else
    {
        printf("Huffman_AddBit,         Buffer->Buffer[Buffer->Size / 8] &= ~Mask\n");
        printf("Huffman_AddBit,         ");
        PrintToBinary(Buffer->Buffer[Buffer->Size / 8]);
        printf(" &= ");
        PrintToBinary(~Mask);
        Buffer->Buffer[Buffer->Size / 8] &= ~Mask;
    }

    printf("\nHuffman_AddBit, After : Buffer->Buffer[Buffer->Size / 8] : ");
    PrintToBinary(Buffer->Buffer[Buffer->Size / 8]);
    printf(", decimal notation : %d\n\n", Buffer->Buffer[Buffer->Size / 8]);
    Buffer->Size++; // Breakpoint
}

void Huffman_Encode(HuffmanNode **Tree, UCHAR *Source, BitBuffer *Encoded, HuffmanCode CodeTable[MAX_CHAR])
{
    int i = 0,
        j = 0;

    SymbolInfo SymbolInfoTable[MAX_CHAR];
    UCHAR Temporary[MAX_BIT];

    for (i = 0; i < MAX_CHAR; i++)
    {
        SymbolInfoTable[i].Symbol = i;
        SymbolInfoTable[i].Frequency = 0;
    }

    i = 0;
    while (Source[i] != '\0')
        SymbolInfoTable[Source[i++]].Frequency++;

    Huffman_BuildPrefixTree(Tree, SymbolInfoTable);

    Huffman_BuildCodeTable(*Tree, CodeTable, Temporary, 0);

    i = 0;
    while (Source[i] != '\0')
    {
        int BitCount = CodeTable[Source[i]].Size;

        for (j = 0; j < BitCount; j++)
        {
            printf("Huffman_Encode, AddBit of Source : '%c'\n", Source[i]);
            Huffman_AddBit(Encoded, CodeTable[Source[i]].Code[j]);
        }

        printf("Huffman_Encode, ");
        Huffman_PrintBinary(Encoded);
        printf("               <<----------- %d bits were added\n\n", BitCount);

        i++; // Breakpoint
    }
}

void Huffman_Decode(HuffmanNode *Tree, BitBuffer *Encoded, UCHAR *Decoded)
{
    int i;
    int Index = 0;
    HuffmanNode *Current = Tree;

    for (i = 0; i <= Encoded->Size; i++)
    {
        UCHAR Mask = 0x80; // 1000 0000

        if (Current->Left == NULL && Current->Right == NULL)
        {
            printf("Huffman_Decode, Decoded char : %c\n\n", Current->Data.Symbol);
            Decoded[Index++] = Current->Data.Symbol; // Breakpoint
            Current = Tree;
        }

        Mask >>= i % 8;

        printf("Huffman_Decode, ");
        PrintToBinary(Encoded->Buffer[i / 8]);
        printf(" & ");
        PrintToBinary(Mask);
        printf(" = ");
        PrintToBinary(Encoded->Buffer[i / 8] & Mask);
        if ((Encoded->Buffer[i / 8] & Mask) != Mask)
        {
            Current = Current->Left;
            printf(" Left");
        }
        else
        {
            Current = Current->Right;
            printf(" Right");
        }

        printf("\n"); // Break point
    }

    Decoded[Index] = '\0';
}

void Huffman_BuildPrefixTree(HuffmanNode **Tree, SymbolInfo SymbolInfoTable[MAX_CHAR])
{
    int i = 0;
    PQNode Result;
    PriorityQueue *PQ = PQ_Create(0);
    PriorityQueue *DebugPQ = PQ_Create(0);

    for (i = 0; i < MAX_CHAR; i++)
    {
        if (SymbolInfoTable[i].Frequency > 0)
        {
            HuffmanNode *BitNode = Huffman_CreateNode(SymbolInfoTable[i]);
            PQNode NewNode;
            NewNode.Priority = SymbolInfoTable[i].Frequency;
            NewNode.Data = BitNode;
            PQ_Enqueue(PQ, NewNode);
            PrintQueue(DebugPQ, SymbolInfoTable[i].Frequency, BitNode->Data.Symbol);
        }
    }

    while (PQ->UsedSize > 1)
    {
        SymbolInfo NewData = {0, 0};
        HuffmanNode *BitNode = Huffman_CreateNode(NewData);
        HuffmanNode *Left;
        HuffmanNode *Right;

        PQNode QLeft;
        PQNode QRight;
        PQNode NewNode;
        PQNode DebugNode;

        PQ_Dequeue(PQ, &QLeft);
        PQ_Dequeue(PQ, &QRight);

        Left = (HuffmanNode *)QLeft.Data;
        Right = (HuffmanNode *)QRight.Data;

        BitNode->Data.Symbol = 0;
        BitNode->Data.Frequency = Left->Data.Frequency + Right->Data.Frequency;

        BitNode->Left = Left;
        BitNode->Right = Right;

        NewNode.Priority = BitNode->Data.Frequency;
        NewNode.Data = BitNode;

        PQ_Enqueue(PQ, NewNode);
        PQ_Dequeue(DebugPQ, &DebugNode);
        printf("Huffman_BuildPrefixTree, popped left data and priority: '%c', %d\n", DebugNode.Data, DebugNode.Priority);
        PQ_Dequeue(DebugPQ, &DebugNode);
        printf("Huffman_BuildPrefixTree, popped right data and priority: '%c', %d\n", DebugNode.Data, DebugNode.Priority);
        PrintQueue(DebugPQ, BitNode->Data.Frequency, BitNode->Data.Symbol); // Breakpoint
    }

    PQ_Dequeue(PQ, &Result);
    *Tree = (HuffmanNode *)Result.Data;
}

void Huffman_BuildCodeTable(HuffmanNode *Tree, HuffmanCode CodeTable[MAX_CHAR], UCHAR Code[MAX_BIT], int Size)
{
    if (Tree == NULL)
        return;

    if (Tree->Left != NULL)
    {
        Code[Size] = 0;
        Huffman_BuildCodeTable(Tree->Left, CodeTable, Code, Size + 1);
    }

    if (Tree->Right != NULL)
    {
        Code[Size] = 1;
        Huffman_BuildCodeTable(Tree->Right, CodeTable, Code, Size + 1);
    }

    if (Tree->Left == NULL && Tree->Right == NULL)
    {
        int i;

        printf("Huffman_BuildCodeTable, Making a bit of Tree->Data.Symbol : '%c'\n", Tree->Data.Symbol);
        for (i = 0; i < Size; i++)
        {
            CodeTable[Tree->Data.Symbol].Code[i] = Code[i];
            printf("Huffman_BuildCodeTable, CodeTable[Tree->Data.Symbol].Code[%d]:%d = Code[%d]:%d\n", i, CodeTable[Tree->Data.Symbol].Code[i], i, Code[i]);
        }

        CodeTable[Tree->Data.Symbol].Size = Size;
        printf("Huffman_BuildCodeTable, Size : %d\n\n", Size); // Breakpoint
    }
}

void Huffman_PrintBinary(BitBuffer *Buffer)
{
    int i;

    for (i = 0; i < Buffer->Size; i++)
    {
        UCHAR Mask = 0x80; // 1000 0000
        Mask >>= i % 8;

        printf("%d", (Buffer->Buffer[i / 8] & Mask) == Mask);
    }
}
