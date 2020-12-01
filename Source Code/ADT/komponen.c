#include <stdio.h>
#include <stdlib.h>

#include "komponen.h"

// array of string untuk menyimpan nama komponen
// indeks pada array menunjukkan ID komponen
char IDKomponen[80][30] = {
    // MOTHERBOARD IDX 0-9
    "Asrock B450M PRO",
    "Asus ROG STRIX B450F",
    "MSI B550A PRO",
    "Asrock Z490 PRO",
    "Asus ROG STRIX Z490E",
    "Asus TUF X570",
    "Asrock X570 PRO",
    "MSI X570 PRO GAMING",
    "",
    "",
    // CPU IDX 10-19
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // MEMORY IDX 20-29
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // CPU COOLER IDX 30-39
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // CASE IDX 40-49
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // GPU IDX 50-59
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // STORAGE IDX 60-69
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    // PSU IDX 70-79
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

Komponen ListKomponen[80] = {
    // {KODE, HARGA, KATEGORI}
    {1,250,1}
};

void namaKomponen (int ID, char* Nama[]){
    (*Nama) = IDKomponen[ID];
}