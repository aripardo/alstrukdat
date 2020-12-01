/*ADT Queue – Alternatif I 
*** Deklarasi Queue yang diimplementasi dengan tabel kontigu *** 
*** HEAD dan TAIL adalah alamat elemen pertama dan terakhir ***
*** Queue mampu menampung MaxEl buah elemen ***/

#ifndef queue_H
#define queue_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydin.h"
#include "point.h"
#define Nil 0 /* Nil adalah queue dengan elemen kosong */

/*selektor*/
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/*** Definisi elemen dan address ***/
typedef struct {
	int NoPelanggan;
	POINT Lokasi;
} infoPemesan;
typedef int address; /* indeks tabel */

/* *** Definisi Type Queue *** */
typedef struct {
	infoPemesan *T; /* tabel penyimpan elemen */
	Komponen *TabKomponen;
	address HEAD; /*alamat penghapusan*/
	address TAIL; /*alamat penambahan*/
	int MaxEl; /*maksimum banyaknya elemen queue*/
	boolean Status; /*mengecek apakah orderan sudah selesai diantar apa belum*/
	int Payment; /*pembayaran setelah orderan selesai diantar*/
} Queue;

/* Definisi Queue kosong Head = Nil; TAIL = Nil. */
/* Catatan : implementasi T[0] tidak pernah dipakai */
/* Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */
/* *** Predikat Pemeriksaan Kondisi Queue *** */

boolean IsEmpty (Queue Q);  
/* Mengirim true jika Q kosong */

boolean IsFull (Queue Q); 
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl
elemen */

int NBElmt (Queue Q); 
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
/* *** Konstruktor *** */

void CreateEmpty (Queue *Q,int Max);
/* I.S. Max terdefinisi */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb 
/*
Jika alokasi berhasil, tabel memori dialokasi berukuran Max
/*
atau  jika alokasi gagal, Q kosong dg Maksimum elemen=0
/* Proses  Melakukan alokasi memori dan membuat sebuah Q kosong
*/

/* *** Destruktor *** */
void DeAlokasi (Queue *Q);
/* Proses  Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q); diset 0 */

void Add (Queue *Q ,infoPemesan X);
/* Proses  Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju". */
/*
Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1. */

void Del (Queue *Q,infoPemesan *X);
/* Proses  Menghapus elemen pertama pada Q dengan aturan FIFO */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD pada I.S.,
Jika Queue masih isi  HEAD "maju".
Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
Jika Queue menjadi kosong, HEAD = TAIL = Nil. */

void PrintQueue (Queue Q);
/* I.S. : Q terdefinisi, mungkin kosong */
/* F.S. : Semua elemen Q tertulis di layar, dengan format:
[ el-head ... el-tail ], misalnya [4 8 12 9 10].
Jika kosong, tampilan di layar adalah []. */
#endif