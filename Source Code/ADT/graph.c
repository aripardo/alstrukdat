#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

adrNode AlokasiNode (int NP){
    adrNode P = (adrNode) malloc (sizeof(GraphNode));
    if (P!=NULL){
        P->NoPelanggan = NP;
        P->NPred = 0;
        P->Trail = NULL;
        P->Next = NULL;
    }
    else return NULL;
}
void DealokasiNode (adrNode P){
    free(P);
}

adrSuccNode AlokasiSuccNode (adrNode Pn){
    adrSuccNode P = (adrSuccNode) malloc (sizeof(GraphSuccNode));
    if (P!=NULL){
        P->Succ = Pn;
        P->Next = NULL;
    }
    else return NULL;
}
void DealokasiSuccNode (adrSuccNode Pn){
    free(Pn);
}

void insertNode(Graph *G, int X, adrNode *Pn){
    (*Pn) = AlokasiNode(X);
    if (*Pn!=NULL){
        adrNode P = G->First, Prev = NULL;
        while (P!=NULL){
            Prev = P;
            P = P->Next;
        }
        if (Prev==NULL){
            G->First = (*Pn);
        }
        else {
            Prev->Next = (*Pn);
        }
    }
}
void insertEdge(Graph *G, int prec, int succ){
    adrNode P, firstNode = NULL, secondNode = NULL;
    adrSuccNode firstSuccNode, secondSuccNode;

    P = G->First;
    while (P!=NULL){
        if (P->NoPelanggan == prec){
            firstNode = P;
        }
        if (P->NoPelanggan == succ){
            secondNode = P;
        }
        P = P->Next;
    }

    boolean firstFound = false, secondFound = false;
    firstSuccNode = firstNode->Trail;
    while (firstSuccNode!=NULL && firstFound == false){
        if (firstSuccNode->Succ == succ) firstFound = true;
        firstSuccNode = firstSuccNode->Next;
    }
    while (secondSuccNode!=NULL && secondFound == false){
        if (secondSuccNode->Succ == prec) secondFound = true;
        secondSuccNode = secondSuccNode->Next;
    }

    adrSuccNode first = AlokasiSuccNode(firstNode), second = AlokasiSuccNode(secondNode);
    if (firstFound == false && secondFound == false && first != NULL && second != NULL){
        firstSuccNode = second;
        firstSuccNode->Next = NULL;
        secondSuccNode = first;
        secondSuccNode->Next = NULL;
    }
}

void MatrixToGraph (Matriks M, Graph *G){
    for (int i = 1; i <= M.Baris; i++){
        for (int j = 1; j <= M.Kolom; j++){
            if (Elmt(M, i, j) == 1) {
                insertEdge(*G,i,j);
            }
        }
    }
}