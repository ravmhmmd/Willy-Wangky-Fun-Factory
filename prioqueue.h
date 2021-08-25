/* ADT Priority Queue */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include <stdio.h>
#include "boolean.h"
#include "customer.h"

#define Nil NULL
#define MaxQ 10

typedef struct tNode *address;
typedef struct tNode {
	Customer Info;
	int Prio;		// Untuk antrean utama, diurutkan berdasarkan prioritas
	int Duration;	// Untuk 'antrean' wahana, diurutkan berdasarkan durasi
	address Next;
} Node;

typedef struct {
	address HEAD;
	int Capacity;
} Queue;

/* Selektor */
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define PrioQ(P) (P)->Prio
#define DurationQ(P) (P)->Duration
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define CapacityQ(Q) (Q).Capacity

void AlokasiQueue(address *P,  Customer C);
/* I.S. P tidak terdefinisi
   F.S. P terdefinisi dengan Info(P) berisikan C */

void MakeEmptyQueue(Queue *Q);
/* I.S. Q tidak terdefinisi
   F.S. Head(Q) menunjuk ke nil */
   
void MakeEmptySeat(Queue *Q, int X);

void Dealokasi(address P);
/* I.S. P teralokasi
   F.S. P telah di-dealokasi */

boolean IsEmptyQ(Queue Q);
/* Mengecek apakah Q kosong. true jika kosong, false jika tidak kosong */

int NbElmtQ(Queue Q);
/* Mengembalikan banyaknya elemen pada Q */

boolean IsNotFullQ(Queue Q);
/* Mengecek apakah Q belum penuh */

void Enqueue(Queue *Q, Customer C);
/* I.S. Q mungkin kosong, C terdefinisi
   F.S. Node dengan info C ditambahkan ke antrean Q, sesuai dengan nilai prioritasnya */
   
void EnqueueSeat(Queue *Q, Customer C);
/* Enqueue untuk seat, yaitu urutannya berdasarkan durasi
   I.S. Q Mungkin kosong, C terdefinisi
   F.S. Node dengan info C ditambahkan ke antrean Q, sesuai dengan nilai durasinya */
   
void Dequeue(Queue *Q, address *P);
/* I.S. Q tidak kosong, P terdefinisi/teralokasi
   F.S. Elemen Q dengan prioritas paling tinggi akan dikeluarkan dari antrean, kemudian P akan menunjuk elemen tersebut */

void PrintAntrean(Queue Q);
/* I.S. Q terdefinisi
   F.S. Jika kosong, program hanya menampilkan "Antrean: ".
        Jika tidak kosong, program akan menuliskan setiap nama, daftar wahana, prioritas, dan kesabaran customer. */

#endif
