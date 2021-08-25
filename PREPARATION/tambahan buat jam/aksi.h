/* ADT Aksi */

#ifndef AKSI_H
#define AKSI_h

#include "ride.h"
#include "boolean.h"
#include "string.h"
#include "mesinkata.h"
#include "jam.h"
#include "mesintoken.h"
#include <stdio.h>

#define Nil NULL
#define IdxNil -1

/* Total aksi serta durasi dan biaya yang dibutuhkan untuk melakukan seluruh aksi yang ada di dalam stack */
extern int totalAksi;
extern int totalDuration;
extern int totalCost;

/* Nama aksi, nama bahan, serta biaya bahan */
extern char *ArrAksiName[30];
extern char *ArrBahanName[5];
extern int ArrBahanCost[10];

/* Uang dan bahan yang dimiliki */
extern int CurrentMoney;
extern int CurrentBahan[3];

typedef int AksiNo;
/* AksiNo 1: BUILD
   AksiNo 2: UPGRADE
   AksiNo 3: BUY */
   
typedef int BahanNo;
/* BahanNo 1: Kayu
   BahanNo 2: Batu
   BahanNo 3: Besi */
   

typedef struct {
	char Name[15]; // Nama bahan
	BahanNo Nomor;
	int Quantity;
	int Cost; // Biaya bahan
} Bahan;

typedef struct {
	char Name[30]; // Nama dari aksi, dalam string / array of char
	AksiNo Nomor; // Nomor aksi
	Ride Target; // Target aksi (Ride), jika aksinya adalah Build atau Upgrade
	Bahan TargetB; // Target aksi (Bahan), jika aksinya adalah Buy
	int Duration; // Durasi yang dibutuhkan untuk melakukan aksi
	int Cost; // Biaya yang dibutuhkan untuk melakukan aksi
} Aksi;

typedef struct {
	Aksi T[30]; // Array of aksi
	int Top;
} Stack; // Stack of aksi


extern Stack StackAksi;

/* SELEKTOR Aksi */
#define AksiName(A) (A).Name
#define AksiNomor(A) (A).Nomor
#define AksiDuration(A) (A).Duration
#define AksiCost(A) (A).Cost
#define AksiTarget(A) (A).Target
#define AksiTargetB(A) (A).TargetB

/* SELEKTOR Stack */
#define Top(S) (S).Top
#define InfoTop(S) (S).T[(S).Top]

/* SELEKTOR Bahan */
#define BahanName(B) (B).Name
#define BahanNomor(B) (B).Nomor
#define BahanQty(B) (B).Quantity
#define BahanCost(B) (B).Cost

void MakeEmptyAksi(Aksi *A);
/* I.S. A sembarang
   F.S. A terdefinisi kosong */

void Build(Aksi *A);
/* I.S. A dan R terdefinisi
   F.S. A merupakan aksi Build, dan R merupakan target A, yaitu wahana yang akan dibangun 
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */

void Upgrade(Aksi *A);
/* I.S. A dan R terdefinisi, R telah dibangun 
   F.S. A merupakan aksi Upgrade, dan R merupakan target A, yaitu wahana yang akan diupgrade 
   		Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */

void Buy(Aksi *A);
/* I.S. A terdefinisi
   F.S. A merupakan aksi buy
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan Bahan */
        
void Execute(Aksi A);
/* I.S. A terdefinisi dalam Stack of Aksi
   F.S. A di-execute lalu di-pop dari stack */

void MakeEmptyStack(Stack *S);
/* I.S. S sembarang
   F.S. S terdefinisi kosong */
   
boolean IsStackEmpty(Stack S);

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
        
void MakeEmptyBahan(Bahan *B, BahanNo x);
/* I.S. B tidak terdefinisi
   F.S. B terdefinisi dengan nomor bahan ke-x */

#endif
