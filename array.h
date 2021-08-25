/* ADT Array */

#ifndef ARRAY_H
#define ARRAY_H

typedef int AksiNo;
/* AksiNo 1: BUILD
   AksiNo 2: UPGRADE
   AksiNo 3: BUY */

typedef int BahanNo;
/* BahanNo 1: Kayu
   BahanNo 2: Batu
   BahanNo 3: Besi */

typedef struct { 
    char *Name[3]; // String berisi nama aksi (Build, Upgrade, Buy)
    long Duration[3]; // Arr of long berisi durasi aksi (dalam detik)
} TabAksi;

typedef struct {
	char Name[3][8];
	int Cost[3];
} TabBahan;

extern int totalBahan[3]; // Total bahan yang dibutuhkan
extern int CurrentBahan[3]; // Total bahan yang dimiliki player

/* Nama dan durasi aksi*/
extern TabAksi ArrAksi;

/* Nama dan durasi Bahan */
extern TabBahan ArrBahan;;

/* SELEKTOR TabAksi */
#define TabAksiName(TA, i) (TA).Name[(i)]
#define TabAksiDuration(TA, i) (TA).Duration[(i)]

/* SELEKTOR TabBahan */
#define TabBahanName(TB, i) (TB).Name[(i)]
#define TabBahanCost(TB, i) (TB).Cost[(i)]

void SetAksi();
void SetBahan();

#endif
