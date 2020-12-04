#include "build-component.h"

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

void startbuild(){
	printf("Kamu telah memulai pesanan %d untuk pelanggan %d", Head(Order), Order.Pemesan->NoPelanggan);
	CreateEmptyStack(&CurrentBuild);
}

void finishbuild(){
	/* if { *masi blm tau syaratnya*
		printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!", Head(Order), Order.Pemesan->NoPelanggan);
	}
	else {
		printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.");
	} */
}

void addcomponent(){
	int Nomor;
    printf("Komponen yang telah terpasang: \n");
	if (IsStackEmpty(CurrentBuild)) {
		printf("Tidak ada komponen yang terpasang. \n");
	}
	else {
		for (int x = 1; x < Top(CurrentBuild) ; x++) {
			printf("%d. %s \n", x, InfoTop(CurrentBuild));
		}
	}
	
	printf("Komponen yang tersedia: \n");
	if (IsEmpty(Inventory)) {
		printf("Inventory anda kosong.");
	}
	else {
		for (int y = 1; y < (Inventory).Neff; y++) {
			//printf("%d. %s \n", y, Inventory.NamaKomponen[(y)]);
		}
		
		printf("Komponen yang ingin dipasang: ");
		scanf("%d", Nomor);
		if (IsIdxEff(Inventory, Nomor)) {
			//Push(&CurrentBuild, Inventory.NamaKomponen[(Nomor)]);
			printf("Komponen berhasil dipasang!");
		}
		else {
			printf("Tidak ada komponen tersebut dalam inventory anda.");
		}
	}
}

void removecomponent(){
	char *Komp;
	if (IsStackEmpty(CurrentBuild)) {
		printf("Tidak ada komponen yang terpasang.");
	}
	else {
		//Komp = InfoTop(CurrentBuild);
		//Pop(&S, &Komp);
		//printf("Komponen %s berhasil dicopot!", Komp);
		/* for (int i = 1; i < Inventory.Neff; i++) {
			if (Inventory.NamaKomponen[(i)] == Komp) {
				
			}
			else {
				
			}
		} */
	}
}