#ifndef __KOMPONEN_H__
#define __KOMPONEN_H__

typedef struct {
    int KodeKomponen;
    int Harga;
    int Kategori;
} Komponen;

/* 
KATEGORI
Motherboard = 1
CPU = 2
Memory = 3
CPU Cooler = 4
Case = 5
GPU = 6
Storage = 7
PSU = 8
*/

void namaKomponen (int ID, char* Nama[30]);

#endif