#ifndef __DISJOINTSET_H__
#define __DISJOINTSET_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjointSet
{
    struct tagDisjoint *Parent;
    void *Data;
} DisjointSet;

void DS_UnionSet(DisjointSet *Set1, DisjointSet *Set2);
DisjointSet *DS_FindSet(DisjointSet *Set);
DisjointSet* DS_MakeSet(void* NewData);
void DS_DestroySet(DisjointSet* Set);

#endif // __DISJOINTSET_H__