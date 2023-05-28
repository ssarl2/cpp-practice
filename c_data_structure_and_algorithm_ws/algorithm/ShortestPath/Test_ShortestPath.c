#include "../Graph/Graph.h"
#include "ShortestPath.h"

int main(void)
{
    Graph *graph = CreateGraph();
    Graph *PrimMST = CreateGraph();

    Vertex *A = CreateVertex('A');
    Vertex *B = CreateVertex('B');
    Vertex *C = CreateVertex('C');
    Vertex *D = CreateVertex('D');
    Vertex *E = CreateVertex('E');
    Vertex *F = CreateVertex('F');
    Vertex *G = CreateVertex('G');
    Vertex *H = CreateVertex('H');
    Vertex *I = CreateVertex('I');

    AddVertex(graph, A);
    AddVertex(graph, B);
    AddVertex(graph, C);
    AddVertex(graph, D);
    AddVertex(graph, E);
    AddVertex(graph, F);
    AddVertex(graph, G);
    AddVertex(graph, H);
    AddVertex(graph, I);

    AddEdge(A, CreateEdge(A, E, 247));

    AddEdge(B, CreateEdge(B, A, 35));
    AddEdge(B, CreateEdge(B, C, 126));
    AddEdge(B, CreateEdge(B, F, 150));

    AddEdge(C, CreateEdge(C, D, 117));
    AddEdge(C, CreateEdge(C, F, 162));
    AddEdge(C, CreateEdge(C, G, 220));

    AddEdge(E, CreateEdge(E, H, 98));

    AddEdge(F, CreateEdge(F, E, 82));
    AddEdge(F, CreateEdge(F, G, 154));
    AddEdge(F, CreateEdge(F, H, 120));

    AddEdge(G, CreateEdge(G, I, 106));

    AddEdge(I, CreateEdge(I, G, 106));

    Dijkstra(graph, B, PrimMST);
    PrintGraph(PrimMST);

    DestroyGraph(PrimMST);
    DestroyGraph(graph);

    return 0;
}