#ifndef __CHAINING_H__
#define __CHAINING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *KeyType;
typedef char *ValueType;

typedef struct tagNode
{
    KeyType Key;
    ValueType Value;

    struct tagNode *Next;
} Node;

typedef Node *List;

typedef struct tagHashTable
{
    int TableSize;
    List *Table;
} HashTable;

HashTable *CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable *HT);
Node *CHT_createNode(KeyType Key, ValueType Value);
void CHT_DestroyNode(Node *TheNode);
void CHT_Set(HashTable *HT, KeyType Key, ValueType Value);
ValueType CHT_Get(HashTable *HT, KeyType Key);
int CHT_Hash(KeyType Key, int KeyLength, int TableSize);

#endif // __CHAINING_H__