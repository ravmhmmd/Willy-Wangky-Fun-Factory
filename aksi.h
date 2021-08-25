/* ADT Aksi */

#ifndef AKSI_H
#define AKSI_H

#include "ride.h"
#include "boolean.h"
#include "mesinkata.h"
#include "jam.h"
#include "mesintoken.h"
#include "array.h"
#include "listlinier.h"
#include "peta.h"
#include "tree.h"
#include <stdio.h>

#define Nil NULL

/* Total aksi serta durasi dan biaya yang dibutuhkan untuk melakukan seluruh aksi yang ada di dalam stack */
extern int totalAksi;
extern long totalDuration;
extern int totalCost;

/* Uang dan bahan yang dimiliki */
extern int CurrentMoney;

typedef struct {
   Lokasi lokasiAksi;
   Peta petaAksi;
} letakAksi;

typedef struct {
	AksiNo Nomor; // Nomor aksi
	RideNo NomorTargetRide;
	UpgradeNo NomorUpgradeRide;
	BahanNo NomorTargetBahan; // Target aksi (Bahan), jika aksinya adalah Buy
	letakAksi LokasiTarget;
	int BuildCost[3];
	int QuantityTargetBahan;
	int Cost; // Biaya yang dibutuhkan untuk melakukan aksi
} Aksi;

/* SELEKTOR Aksi */
#define AksiNomor(A) (A).Nomor
#define AksiCost(A) (A).Cost
#define AksiRBCost(A) (A).BuildCost
#define AksiRNomor(A) (A).NomorTargetRide
#define AksiUNomor(A) (A).NomorUpgradeRide
#define AksiBNomor(A) (A).NomorTargetBahan
#define AksiLokasi(A) (A).LokasiTarget
#define AksiBQty(A) (A).QuantityTargetBahan

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
   		
void PilihUpgrade(Aksi *A, BinTree U, Ride R);

void Buy(Aksi *A);
/* I.S. A terdefinisi
   F.S. A merupakan aksi buy
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan Bahan */
        
void Execute(Aksi A);
/* I.S. A terdefinisi dalam Stack of Aksi
   F.S. A di-execute lalu di-pop dari stack */
   
void ExeUpgrade(infoUpgrade U, Ride *R);

   
boolean IsMoneyCukup(Aksi A);
/* Mengembalikan true jika uang masih tersisa setelah melakukan aksi A */

boolean IsBahanCukup(Aksi A);
/* Mengembalikan true jika bahan masih tersisa setelah melakukan aksi A */

boolean IsDurationCukup(Aksi A);
/* Mengembalikan true jika durasi masih tersisa setelah melakukan aksi A */

#endif
