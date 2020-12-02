#ifndef __GRAPH__
#define __GRAPH__

#include "boolean.h"
#include "matriks.h"

typedef struct tGraphNode *adrNode;
typedef struct tGraphSuccNode *adrSuccNode;
typedef struct tGraphNode {
    int NoPelanggan;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} GraphNode;
typedef struct tGraphSuccNode {
    adrNode Succ;
    adrSuccNode Next;
} GraphSuccNode;
typedef struct {
    adrNode First;
} Graph;

adrNode AlokasiNode (int NP);
void DealokasiNode (adrNode P);

adrSuccNode AlokasiSuccNode (adrNode Pn);
void DealokasiSuccNode (adrSuccNode Pn);

void insertNode(Graph *G, int X, adrNode *P);
void insertEdge(Graph *G, int prec, int succ);

void MatrixToGraph (Matriks M, Graph *G);

#endif