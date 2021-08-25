/* ADT Bahan */

#ifndef BAHAN_H
#define BAHAN_H

typedef int BahanNo;
/* BahanNo 1: Kayu
   BahanNo 2: Batu
   BahanNo 3: Besi */
   
typedef struct {
	char Name[3][8];
	int Cost[3];
} TabBahan;

extern int totalBahan[3]; // Total bahan yang dibutuhkan
extern int CurrentBahan[3]; // Total bahan yang dimiliki player

extern TabBahan ArrBahan;
/* SELEKTOR TabBahan */
#define TabBahanName(TB, i) (TB).Name[(i)]
#define TabBahanCost(TB, i) (TB).Cost[(i)]

void SetBahan();


#endif
