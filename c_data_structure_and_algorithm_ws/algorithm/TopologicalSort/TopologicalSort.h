#ifndef __TOPOLOGICALSORT_H__
#define __TOPOLOGICALSORT_H__

#include "../Graph/Graph.h"
#include "LinkedList.h"

void TopologicalSort(Vertex *Ve, Node **List);
void TS_DFS(Vertex *V, Node **List);

#endif // __TOPOLOGICALSORT_H__