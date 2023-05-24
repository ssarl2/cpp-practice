#ifndef __MST_H__
#define __MST_H__

#include "../Graph/Graph.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../../data_structure/DisjointSet/DisjointSet.h"

#define MAX_WEIGHT 36267

void Prim(Graph *G, Vertex *StartVertex, Graph *MST);
void Kruskal(Graph *G, Graph *MST);

#endif // __MST_H__