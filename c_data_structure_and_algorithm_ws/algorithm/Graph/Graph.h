#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>

enum VisitMode
{
    Visited,
    NotVisited
};

typedef int VElementType;

typedef struct tagVertex
{
    VElementType Data;
    int Visited;
    int Index;

    struct tagVertex *Next;
    struct tagEdge *AdjacencyList;
} Vertex;

typedef struct tagEdge
{
    int Weight;
    struct tagEdge *Next;
    Vertex *From;
    Vertex *Target;
} Edge;

typedef struct tagGraph
{
    Vertex *Vertices;
    int VertexCount;
} Graph;

Graph *CreateGraph();
void DestroyGraph(Graph *G);

Vertex *CreateVertex(VElementType Data);
void DestroyVertex(Vertex *V);

Edge *CreateEdge(Vertex *From, Vertex *Target, int Weight);
void DestroyEdge(Edge *E);

void Addvertex(Graph *G, Vertex *V);
void AddEdge(Vertex *V, Edge *E);
void PrintGraph(Graph *G);

#endif // __GRAPH_H__