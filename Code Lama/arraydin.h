#ifndef __ARRAYDIN__
#define __ARRAYDIN__

#include "boolean.h"

typedef struct {
    int KodeKomponen; // BIKIN ARRAY KODE - NAMA KOMPONEN
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

typedef struct {
    Komponen *TabKomponen; 
    int *Kuantitas;
    int Neff;
    int MaxEl;
} ArrayDinInventory;

/*
#define Neff(T) (T).Neff
#define NamaKomponen(T) (T).NamaKomponen
#define NamaKomponen(T, i) (T).NamaKomponen[(i)]
#define Kuantitas(T) (T).Kuantitas
#define Kuantitas(T, i) (T).Kuantitas[(i)]
#define MaxEl(T) (T).MaxEl
*/


// KONSTRUKTOR
void MakeEmpty(ArrayDinInventory *T, int maxel);
void Dealokasi(ArrayDinInventory *T);

// SELEKTOR
int NbElmt(ArrayDinInventory T);
int MaxElement(ArrayDinInventory T);
int GetFirstIdx(ArrayDinInventory T);
int GetLastIdx(ArrayDinInventory T);

// CHECK INDEX
boolean IsIdxValid(ArrayDinInventory T, int i);
boolean IsIdxEff(ArrayDinInventory T, int i);

// CHECK ARRAY
boolean IsEmpty(ArrayDinInventory T);
boolean IsFull(ArrayDinInventory T);

// UBAH UKURAN ARRAY
void GrowTab(ArrayDinInventory *T, int num);
void ShrinkTab(ArrayDinInventory *T, int num);
void CompactTab(ArrayDinInventory *T);

// TAMBAH KURANG ELEMEN
void addKomponen (ArrayDinInventory *T, char *namakomponen, int kuantitas);
void removeSatuKomponen (ArrayDinInventory *T, char *namakomponen);


#endif