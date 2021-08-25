/* ADT Stack */

#ifndef STACK_H
#define STACK_H

#include "aksi.h"
#include "prep.h"

#define IdxNil -1

typedef struct {
	Aksi T[15]; // Array of aksi
	int Top;
	int length;
} Stack; // Stack of aksi

/* Stack tempat menyimpan aksi */
extern Stack StackAksi;

/* SELEKTOR Stack */
#define Top(S) (S).Top
#define InfoTop(S) (S).T[(S).Top]
#define Len(S) (S).length

void MakeEmptyStack(Stack *S);
/* I.S. S sembarang
   F.S. S terdefinisi kosong */
   
boolean IsStackEmpty(Stack S);
/* Mengembalikan true apabila S kosong */

void PushAksi(Stack *S, Aksi A);
/* Menambahkan A sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh. A terdefinisi */
/* F.S. A menjadi TOP yang baru,TOP bertambah 1
        totalAksi di-inkremen, totalDuration, dan totalCost ditambahkan sesuai dengan durasi dan biaya aksi A */

void PopAksi(Stack *S, Aksi *A);
/* Mengeluarkan A dari elemen Stack S. */
/* I.S. S TIDAK mungkin kosong. A sembarang/teralokasi */
/* F.S. A dikeluarkan dari TOP, TOP berkurang 1
        totalAksi di-dekremen, totalDuration, dan totalCost dikurangi sesuai dengan durasi dan biaya aksi InfoTop(S) */


#endif
