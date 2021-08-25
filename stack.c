#include "stack.h"
#include <stdio.h>

Stack StackAksi;

void MakeEmptyStack(Stack *S)
/* I.S. S sembarang
   F.S. S terdefinisi kosong */
{
	/* Kamus */
	/* Algoritma */
	Top(*S) = IdxNil;
	Len(*S) = 0;
}

boolean IsStackEmpty(Stack S)
/* Mengembalikan true apabila S kosong */
{
	/* Kamus */
	/* Algoritma */
	return (Top(S) == IdxNil);
}

void PushAksi(Stack *S, Aksi A)
/* Menambahkan A sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh. A terdefinisi */
/* F.S. A menjadi TOP yang baru,TOP bertambah 1
        totalAksi di-inkremen, totalDuration, dan totalCost ditambahkan sesuai dengan durasi dan biaya aksi A */
{
	/* Kamus */
	int i;
	/* Algoritma */
	Top(*S) += 1;
	InfoTop(*S) = A;
	totalAksi += 1;
	totalDuration += TabAksiDuration(ArrAksi, AksiNomor(A) - 1);
	totalCost += AksiCost(A);
	if (AksiNomor(A) != 3){
		for (i = 0; i < 3; i++){
			totalBahan[i] += BahanCost[AksiRNomor(A) - 1][i];
		}
	}
	Len(*S)++;
}

void PopAksi(Stack *S, Aksi *A)
/* Mengeluarkan A dari elemen Stack S. */
/* I.S. S TIDAK mungkin kosong. A sembarang/teralokasi */
/* F.S. A dikeluarkan dari TOP, TOP berkurang 1
        totalAksi di-dekremen, totalDuration, dan totalCost dikurangi sesuai dengan durasi dan biaya aksi InfoTop(S) */
{
	/* Kamus */
	int i;
	/* Algoritma */
	*A = InfoTop(*S);
	Top(*S) -= 1;
	totalAksi -= 1;
	totalCost -= AksiCost(*A);
	totalDuration -= TabAksiDuration(ArrAksi, AksiNomor(*A) - 1);
	if (AksiNomor(*A) != 3){
		for (i = 0; i < 3; i++){
			totalBahan[i] -= BahanCost[AksiRNomor(*A) - 1][i];
		}
	}
	Len(*S)--;
}

