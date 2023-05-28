#ifndef __SHORTESTPATH_H__
#define __SHORTESTPATH_H__

#include "../Graph/Graph.h"
#include "../PriorityQueue/PriorityQueue.h"

#define MAX_WEIGHT 36267

void Dijkstra(Graph *G, Vertex *StartVertex, Graph *ShortestPath);

#endif // __SHORTESTPATH_H__