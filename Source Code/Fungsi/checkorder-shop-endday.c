#include "checkorder-shop-endday.h"

// Library ADT
#include "ADT/arraydin.h"
#include "ADT/boolean.h"
#include "ADT/point.h"
#include "ADT/queue.h"
#include "ADT/stack.h"
#include "ADT/graph.h"
#include "ADT/matriks.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"

// Variable Global
#ifndef GLOBALVAR
#define GLOBALVAR
int Uang;
ArrayDinInventory Inventory;
int CurrentLocation;
int NbBangungan;
int mapX, mapY;
Point LokasiBangunan[30];
Matriks Map;
Graph Jalur;
Queue Order;
Stack CurrentBuild;
#endif

void checkorder(){
	
}

void shop(){
    int belikomp,kuantitas,total;
    //Komponen ListKomp;
    //char IDKomponen;
    printf("Komponen yang tersedia:\n");
    for (int i=0;i<24;i++){
        printf("%d. %s - ""$""%d\n",(i+1),IDKomponen[i],ListKomp[i]->Harga);
    }
    printf("Komponen yang ingin dibeli: ");
    scanf("%d",(&belikomp));
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d",(&kuantitas));
    for (int i=0;i<24;i++){
        if (i==belikomp){
            total = ((ListKomp[i-1]->Harga)*(kuantitas));
            if (total>Uang){
                printf("Uang tidak cukup!");
            } else{
                Uang=Uang-total;
                 //addKomponen(*T,*[i-1],kuantitas);
                printf("Komponen berhasil dibeli!");
            }
        }else{
            printf("Tidak ada komponen");
            break;
        }
    }
}

void end_day(){
    
}