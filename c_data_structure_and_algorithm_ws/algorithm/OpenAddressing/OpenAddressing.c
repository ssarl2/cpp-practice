#include "OpenAddressing.h"

HashTable *OAHT_CreateHashTable(int TableSize)
{
    HashTable *HT = (HashTable *)malloc(sizeof(HashTable));
    HT->Table = (ElementType *)malloc(sizeof(ElementType) * TableSize);

    memset(HT->Table, 0, sizeof(ElementType) * TableSize);

    HT->TableSize = TableSize;
    HT->OccupiedCount = 0;

    return HT;
}

void OAHT_DestroyHashTable(HashTable *HT)
{
    int i = 0;
    for (i = 0; i < HT->TableSize; i++)
        OAHT_ClearElement(&(HT->Table[i]));

    free(HT->Table);
    free(HT);
}

void OAHT_ClearElement(ElementType *Element)
{
    if (Element->Status == EMPTY)
        return;

    free(Element->Key);
    free(Element->Value);
}

void OAHT_Set(HashTable **HT, KeyType Key, ValueType Value)
{
    int KeyLen, Address, StepSize;
    double Usage;

    Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;

    if (Usage > 0.5)
        OAHT_Rehash(HT);

    KeyLen = strlen(Key);
    Address = OAHT_Hash(Key, KeyLen, (*HT)->TableSize);
    StepSize = OAHT_Hash2(Key, KeyLen, (*HT)->TableSize);

    while ((*HT)->Table[Address].Status != EMPTY && strcmp((*HT)->Table[Address].Key, Key) != 0)
    {
        printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n", Key, Address, StepSize);

        Address = (Address + StepSize) % (*HT)->TableSize;
    }

    (*HT)->Table[Address].Key = (char *)malloc(sizeof(char) * (KeyLen + 1));
    strcpy((*HT)->Table[Address].Key, Key);

    (*HT)->Table[Address].Value = (char *)malloc(sizeof(char) * (strlen(Value) + 1));
    strcpy((*HT)->Table[Address].Value, Value);

    (*HT)->Table[Address].Status = OCCUPIED;

    (*HT)->OccupiedCount++;

    printf("Key(%s) entered at address(%d)\n", Key, Address);
}

ValueType OAHT_Get(HashTable *HT, KeyType Key)
{
    int KeyLen = strlen(Key);

    int Address = OAHT_Hash(Key, KeyLen, HT->TableSize);
    int StepSize = OAHT_Hash2(Key, KeyLen, HT->TableSize);

    while (HT->Table[Address].Status != EMPTY && strcmp(HT->Table[Address].Key, Key) != 0)
    {
        Address = (Address + StepSize) % HT->TableSize;
    }

    return HT->Table[Address].Value;
}

int OAHT_Hash(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < KeyLength; i++)
        HashValue = (HashValue << 3) + Key[i];

    return HashValue % TableSize;
}

int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < KeyLength; i++)
        HashValue = (HashValue << 2) + Key[i];

    return (HashValue % (TableSize - 3)) + 1;
}

void OAHT_Rehash(HashTable **HT)
{
    int i = 0;
    ElementType *OldTable = (*HT)->Table;

    HashTable *NewHT = OAHT_CreateHashTable((*HT)->TableSize * 2);

    printf("\nRehashed. New table size is : %d\n\n", NewHT->TableSize);

    for (i = 0; i < (*HT)->TableSize; i++)
    {
        if (OldTable[i].Status == OCCUPIED)
            OAHT_Set(&NewHT, OldTable[i].Key, OldTable[i].Value);
    }

    OAHT_DestroyHashTable((*HT));

    (*HT) = NewHT;
}
