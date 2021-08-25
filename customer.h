/* ADT Customer */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "boolean.h"

#define ValUndef -1
#define RideMax 5  // Misal tiap customer maksimal memilih 5 wahana

extern char CustomerName; // Nama tiap customer: A, B, C, dst.
extern int seed; // Seed untuk random, sehingga setiap customer punya seed yang berbeda-beda

typedef struct {
	int RideNo[RideMax]; // Pilihan wahana
	char Name;
	int Priority;
	int Patience;
	int Neff;
	int Duration;
} Customer;

/* SELEKTOR */
#define CustRideNo(C) (C).RideNo
#define CustName(C) (C).Name
#define Prio(C) (C).Priority
#define Patience(C) (C).Patience
#define NeffCust(C) (C).Neff
#define CustDuration(C) (C).Duration

boolean IsArrUnique(int arr[], int x, int N);

void MakeRandomCust(Customer *C);
/* I.S. C Sembarang */
/* F.S. C Terdefinisi dengan Age, Neff, dan RideNo bernilai random. */
/* Proses: Menamai customer sesuai urutan: A, B, C, dst. Kemudian menetapkan nilai dari C.Age dan C.Neff secara acak.
		   Lalu, menetapkan wahana yang dipilih secara acak. */

void PrintRideCust(Customer C);
/* I.S. C Terdefinisi */
/* F.S. Daftar wahana yang dipesan C dituliskan di layar */

#endif
