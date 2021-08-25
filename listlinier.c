/* Nama: Rafi Naufal Aziz
   NIM: 10119057 */
/* Impe ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

List LU1, LU2, LU3, LU4, LU5;

void SetList()
{
	CreateEmpty(&LU1);
	CreateEmpty(&LU2);
	CreateEmpty(&LU3);
	CreateEmpty(&LU4);
	CreateEmpty(&LU5);
}

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	/* Kamus */
	/* Algoritma */
	return (FirstLL(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	/* Kamus */
	/* Algoritma */
	FirstLL(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressLL AlokasiLL (infotypeL X)
/* Mengirimkan addressLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLL tidak nil, dan misalnya */
/* menghasilkan P, maka InfoLL(P)=X, NextLL(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus */
	addressLL P;
	/* Algoritma */
	P = (ElmtListL*) malloc(sizeof(ElmtListL));
	if (P == Nil){ // Alokasi gagal
		return Nil;
	}
	else {
		InfoLL(P) = X; NextLL(P) = Nil;
		return P;
	}
}

void DealokasiLL (addressLL *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLL P */
{
	/* Kamus */
	/* Algoritma */
	NextLL(*P) = Nil;
	free(*P);
	
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	/* Kamus */
	addressLL P, ptr;
	/* Algoritma */
	P = AlokasiLL(X);
	if (FirstLL(*L) != Nil){
		ptr = FirstLL(*L);
		while (NextLL(ptr) != Nil){
			ptr = NextLL(ptr);
		}
		NextLL(ptr) = P;
		NextLL(P) = Nil;
		
	}
	else {
		NextLL(P) = FirstLL(*L);
		FirstLL(*L) = P;
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoUpgrade(List L, BinTree T)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	/* Kamus */
	addressLL ptr;
	/* Algoritma */
	if (FirstLL(L) == Nil){
		printf("[]\n");
	}
	
	else {
		ptr = FirstLL(L);
		if (NextLL(ptr) != Nil){
			printf("[%s,", upName(Akar(GetTree(T, InfoLL(ptr)))));
			while (NextLL(NextLL(ptr)) != Nil){
				ptr = NextLL(ptr);
				printf("%s,", upName(Akar(GetTree(T, InfoLL(ptr)))));
			}
			ptr = NextLL(ptr);
			printf("%s]\n", upName(Akar(GetTree(T, InfoLL(ptr)))));
		}
		else{
			printf("[%s]\n", upName(Akar(GetTree(T, InfoLL(ptr)))));
		}
	}
}

void PrintHistoryUpgrade (List L, BinTree T)
{
	/* Kamus */
	addressLL ptr;
	/* Algoritma */
	if (FirstLL(L) == Nil){
		printf("%s\n", upName(Akar(T)));
	}
	else{
		printf("%s -> ", upName(Akar(T)));
		ptr = FirstLL(L);
		if (NextLL(ptr) != Nil){
			printf("%s -> ", upName(Akar(GetTree(T, InfoLL(ptr)))));
			while (NextLL(NextLL(ptr)) != Nil){
				ptr = NextLL(ptr);
				printf("%s -> ", upName(Akar(GetTree(T, InfoLL(ptr)))));
			}
			ptr = NextLL(ptr);
			printf("%s\n", upName(Akar(GetTree(T, InfoLL(ptr)))));
		}
		else{
			printf("%s\n", upName(Akar(GetTree(T, InfoLL(ptr)))));
		}
	}
}

