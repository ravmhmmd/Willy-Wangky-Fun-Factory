/* ********** Definisi TYPE PETA dengan menggunakan ADT BOOLEAN, POINT, dan MATRIKS ********** */

#ifndef PETA_H
#define PETA_H

#include "boolean.h"
#include "point.h"
#include "matriks.h"
#include <string.h>

// Jumlah bangunan maksimum dalam peta adalah 20, charundef untuk inisialisasi simbol.
#define IdxMax 19
#define IdxMin 0
#define valundef -1
#define charundef '~'

typedef POINT Lokasi; // Lokasi sebagai representasi letak objek dalam matriks. Absis(P) = Baris, Ordinat(P) = Kolom
typedef struct {
    Lokasi adress;
    char value;
} Bangunan; // Bangunan merupakan objek selain pemain yang ada di dalam peta. Bangunan memiliki letak dan simbol.
typedef struct {
    Lokasi Pemain; 
    Bangunan Gerbang1; 
    Bangunan Gerbang2; // Setiap gerbang memiliki 2 peta.
    Bangunan TabBangunan[IdxMax+1]; // Setiap objek selain pemain disimpan dalam TabBangunan yang merupakan array of Bangunan.
                                    // Alokasi memori array statik ujung kiri.
} Peta; 

// Selektor
#define Pemain(P) (P).Pemain
#define ElBangunan(P, i) (P).TabBangunan[(i)]
#define Gerbang1(P) (P).Gerbang1
#define Gerbang2(P) (P).Gerbang2


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
boolean IsGoingUp(Peta P, char in);
/* Menghasilkan true jika pemain di depan gerbang dan hendak ke atas*/
boolean IsGoingLeft(Peta P, char in);
/* Menghasilkan true jika pemain di samping gerbang dan hendak ke kiri*/
boolean IsGoingDown(Peta P, char in);
/* Menghasilkan true jika pemain di depan gerbang dan hendak ke bawah*/
boolean IsGoingRight(Peta P, char in);
/* Menghasilkan true jika pemain di samping gerbang dan hendak ke kanan*/
#endif
