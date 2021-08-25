/* ********** Definisi TYPE PETA dengan menggunakan ADT BOOLEAN, POINT, dan MATRIKS ********** */

#ifndef PETA_H
#define PETA_H

#include "boolean.h"
#include "point.h"
#include "matriks.h"
#include "ride.h"
#include <string.h>

// Jumlah bangunan maksimum dalam peta adalah 20, charundef untuk inisialisasi simbol.
#define IdxMax 19
#define IdxMin 0
#define valundef -1
#define charundef '~'
#define Nil NULL

typedef POINT Lokasi; // Lokasi sebagai representasi letak objek dalam matriks. Absis(P) = Baris, Ordinat(P) = Kolom
typedef struct {
    Lokasi lokasi;
    char nilai;
} Bangunan; // Bangunan merupakan objek selain pemain yang ada di dalam peta. Bangunan memiliki letak dan simbol.
typedef struct tElmtlist *addressPeta;
typedef struct tElmtlist {
    Lokasi Pemain; 
    Bangunan Gerbang1; 
    Bangunan Gerbang2; // Setiap peta memiliki 2 gerbang.
    Bangunan Office;
    Bangunan Antrean;
    Ride TabRide[IdxMax+1]; // Setiap objek selain pemain disimpan dalam TabBangunan yang merupakan array of Bangunan.
                                    // Alokasi memori array statik ujung kiri.
    addressPeta Tetangga[2]; // Tetangga merupakan kumpulan pointer yang mengacu ke peta lain.
} ElPeta;
typedef addressPeta Peta;


// Selektor
#define Pemain(P) (P)->Pemain
#define ElRide(P, i) (P)->TabRide[(i)]
#define Gerbang1(P) (P)->Gerbang1
#define Gerbang2(P) (P)->Gerbang2
#define Office(P) (P)->Office
#define Antrean(P) (P)->Antrean
#define Tetangga(P) (P)->Tetangga

extern Peta Peta1,Peta2,Peta3,Peta4,PetaM;
extern Bangunan B5, B6, C5, C6, D5, D6, E5, E6;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void MakeEmptyPeta(Peta *P);
/* ***Memberikan nilai "empty" pada Peta P, simbol di-assign charundef, int di-assign valundef*** */
void CopyPeta(Peta Pin, Peta *Pout);
/* Menghasilkan Pout Peta yang sama persis dengan Pin */
/* I.S. Pout, Pin bebas telah melalui MakeEmptyPeta*/
/* F.S. Peta Pout sama dengan Pin*/
void TukarPeta(Peta *P1, Peta *P2);
/* I.S. P1 dan P2 bebas, telah melalui MakeEmpty*/
/* F.S. P1 dan P2 tertukar nilai-nilainya denga metode swap*/
void TulisPeta(Peta M);
/* Menuliskan tampilan peta yang telah*/
void MovePemain(Peta *P, char input);
/* Menggerakkan pemain sesuai ketentuan*/
/* I.S. Peta P tidak kosong*/
/* F.S. Posisi Pemain pada P berubah jika tidak bersebelahan tembok*/
void TambahRide(Peta *P, Ride R);
/* I.S. Peta P terdefinisi */
/* F.S. Ride R tertambah pada Peta P */
boolean IsGoingUp(Peta P, char in);
/* Menghasilkan true jika pemain di depan gerbang dan hendak ke atas*/
boolean IsGoingLeft(Peta P, char in);
/* Menghasilkan true jika pemain di samping gerbang dan hendak ke kiri*/
boolean IsGoingDown(Peta P, char in);
/* Menghasilkan true jika pemain di depan gerbang dan hendak ke bawah*/
boolean IsGoingRight(Peta P, char in);
/* Menghasilkan true jika pemain di samping gerbang dan hendak ke kanan*/
boolean IsPetaSama(Peta P1, Peta P2);
/* Menghasilkan true jika peta P1 dan peta P2 adalah peta yang sama */
boolean IsDekatAntrean(Peta P);
/* Menghasilkan true jika lokasi pemain dengan antrean bersebelahan*/
boolean IsDiOffice(Peta P);
/* Mengasilkan true jika pemain berada di dalam office*/
Ride WahanaTerdekat(Peta P);
/* Memberi output berupa 1 wahana disekitar pemain jika ada, 
   jika ada beberapa wahana di sekitar pemain maka ada pengurutan. */

/* Fungsi-fungsi yang digunakan di main.c */
boolean IsInputValid(char in);
boolean IsCurPeta1(Peta P);
boolean IsCurPeta2(Peta P);
boolean IsCurPeta3(Peta P);
boolean IsCurPeta4(Peta P);
void PindahPeta(Peta *P, char in);
void DisplayPeta();
void SetPeta();
#endif
