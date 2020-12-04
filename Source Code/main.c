#include <stdio.h>
#include <stdlib.h>

// Library ADT
#include "ADT/arraydin.h"
#include "ADT/boolean.h"
#include "ADT/point.h"
#include "ADT/queue.h"
#include "ADT/stack.h"
/*
#include "ADT/graph.h"
#include "ADT/matriks.h"
*/

// Variable Global
int Uang;
ArrayDinInventory Inventory;
Point CurrentLocation;
Point BaseLocation;
Point ShopLocation;
Queue Order;
Stack CurrentBuild;


int main(){

    // LOAD FILE KONFIGURASI
    // mesin kata, disimpen ke konfig

    // LOAD FILE KOMPONEN
    
    // MINTA COMMAND

       
       
}

void load(){
    
}

void move(){

}

void status(){
    printf("Uang tersisa: $%d\n", Uang);
    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", Head(Order), Order.Pemesan->NoPelanggan );
    printf("Lokasi: pemain sedang berada pada %d\n", CurrentLocation);
    printf("Inventory anda: %d", Inventory.TabKomponen);
}

void checkorder(){
	
}

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
			printf("%d. %s \n", y, Inventory.NamaKomponen[(y)]);
		}
		
		printf("Komponen yang ingin dipasang: ");
		scanf("%d", Nomor);
		if (IsIdxEff(Inventory, Nomor)) {
			Push(&CurrentBuild, Inventory.NamaKomponen[(Nomor)]);
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
		Komp = InfoTop(CurrentBuild);
		Pop(&S, &Komp);
		printf("Komponen %s berhasil dicopot!", Komp);
		/* for (int i = 1; i < Inventory.Neff; i++) {
			if (Inventory.NamaKomponen[(i)] == Komp) {
				
			}
			else {
				
			}
		} */
	}
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

void deliver(){
    Point P = Order.Pemesan[Head(Order)].Lokasi;
    if(CurrentLocation == P){
        Head(Order) = Head(Order)+1;
        Uang = Uang + Order.Pemesan->Invoice;
    }
}

void end_day(){
    
}

void save(){
    
}

void map(){

}

void exit (){
    
}
