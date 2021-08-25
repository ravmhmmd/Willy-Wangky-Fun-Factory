#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "time.h"
#include "string.h"
#include "ride.h"


char CustomerName = 'A';
int seed = 0;

boolean IsArrUnique(int arr[], int x, int N){
	int i;
	for (i = 0; i < N; i++){
		if (arr[i] == x){
			return false;
		}
	}
	return true;
}

void MakeRandomCust(Customer *C)
/* I.S. C Sembarang */
/* F.S. C Terdefinisi dengan Neff dan RideNo bernilai random. */
/* Proses: Menamai customer sesuai urutan: A, B, C, dst. Kemudian menetapkan nilai C.Neff secara acak.
		   Lalu, menetapkan wahana yang dipilih secara acak. */
{
	/* Kamus */
	int i, j, k, l, m, max, tempRandom, rideNo;
	int availRide[5];
	// max merupakan banyaknya wahana yang bisa dipilih oleh customer.
	/* Algoritma */
	l = 0;
	max = 0;
	if (RideLocation(R1).X != ValUndef){
		max++; availRide[l] = 1; l++;
	}
	if (RideLocation(R2).X != ValUndef){
		max++; availRide[l] = 2; l++;
	}
	if (RideLocation(R3).X != ValUndef){
		max++; availRide[l] = 3; l++;
	}
	if (RideLocation(R4).X != ValUndef){
		max++; availRide[l] = 4; l++;
	}
	if (RideLocation(R5).X != ValUndef){
		max++; availRide[l] = 5; l++;
	}
	if (l != 5){
		for (m = 0; m < 5 - l; m++){
			availRide[l+m] = ValUndef;
		}
	}

	if (max != 0){
		srand(time(0) + seed); seed += 1; // Seed untuk random number. Seed di-increment untuk tiap customer, agar pseudorandom-nya tidak sama.
		CustName(*C) = CustomerName;
		CustDuration(*C) = 600; // Waktu kesabaran dari pelanggan.
		CustomerName += 1; // CustomerName di-increment, artinya hurufnya naik satu. Misal 'A' menjadi 'B'.
		Patience(*C) = 5;
		Prio(*C) = 1;
		NeffCust(*C) = ((rand() % max) + 1); // Banyaknya wahana adalah random
		
		int array[NeffCust(*C)]; // array berukuran NeffCust(*C) berisikan nomor wahana, yang nantinya akan dipilih oleh customer.
		
		
		for (i = 0; i < NeffCust(*C); i++){ // Inisialisasi array
			tempRandom = rand() % 5 + 1;
				while (!IsArrUnique(array, tempRandom, NeffCust(*C)) || \
				!((tempRandom == availRide[0]) || (tempRandom == availRide[1]) || (tempRandom == availRide[2]) \
				|| (tempRandom == availRide[3]) || (tempRandom == availRide[4]))){
					tempRandom = rand() % 5 + 1;
				}
			array[i] = tempRandom;
		}
	
		for (j = 0; j < NeffCust(*C); j++){
			rideNo = array[j];
			CustRideNo(*C)[j] = rideNo;
		}
	}
	else{
		NeffCust(*C) = ValUndef;
	}
}

void PrintRideCust(Customer C)
/* I.S. C Terdefinisi */
/* F.S. Daftar wahana yang dipesan C dituliskan di layar */
{
	/* Kamus */
	int i;
	char RideName[5][20] = {"Rollercoaster", "Bungee Jump", "Hurricane", "Bumping Car", "Haunted House"};
	/* Algoritma */
	printf("Customer %c: (", CustName(C));
	for (i = 0; i < NeffCust(C); i++){
		if (i != NeffCust(C) - 1){
			printf("%s, ", RideName[CustRideNo(C)[i] - 1]);
		}
		else{
			printf("%s", RideName[CustRideNo(C)[i] - 1]);
		}
	}
	printf(") Patience: %d\n", Patience(C));
}
