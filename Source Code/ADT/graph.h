/*
Implementasi Graph dengan Adjacency Matrix
File : graph.h
*/

// BELUM SELESAI

#ifndef __GRAPH__
#define __GRAPH__

#include "matriks.h"
#include "arraydin.h"

typedef struct {
    Matriks adjList;
    int vertices;
} Graph;

boolean isAdjacent(Graph G, int vertex1, int vertex2);

int countNeighbors(Graph G, int vertex);

TabInt neighborLists(Graph G, int vertex);

void delEdge(Graph *G, int vertex1, int vertex2);

void addEdge(Graph *G, int vertex1, int vertex2);

#endif