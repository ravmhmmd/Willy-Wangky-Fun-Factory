/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "tree.h"

#define Nil NULL
typedef int infotypeL;
typedef struct tElmtlistL *addressLL;
typedef struct tElmtlistL {
	infotypeL info;
	addressLL next;
} ElmtListL;
typedef struct {
	addressLL First;
} List;

extern List LU1, LU2, LU3, LU4, LU5;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressLL P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressLLnya Last, maka Next(Last)=Nil */

#define InfoLL(P) (P)->info
#define NextLL(P) (P)->next
#define FirstLL(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L);
/* Mengirim true jika list kosong */

void SetList();

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLL AlokasiLL (infotypeL X);
/* Mengirimkan addressLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiLL (addressLL *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLL P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeL X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoUpgrade (List L, BinTree T);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void PrintHistoryUpgrade (List L, BinTree T);


#endif
