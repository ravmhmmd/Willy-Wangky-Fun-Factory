#include <stdio.h>
#include "string.h"
#include "ride.h"

/* Harga bahan dari tiap wahana */


Ride R1, R2, R3, R4, R5;

int BahanCost[5][3];

void MakeRide(Ride *R, RideNo x)
/* I.S. R tidak terdefinisi
   F.S. R terdefinisi dengan nomor wahana ke-x */
{
	/* Kamus */
	int i;
	int No;  // Nomor wahana
	POINT XY;
	/* Algoritma */
	FILE * file = fopen("wahana.txt", "r");
	fscanf(file, "\n%d,", &No);
	while (x != No){
		fscanf(file, "%*[^;];");
		fscanf(file, "\n%d,", &No);
	}
	fscanf(file, "%[^:]:%d,[%d,%d,%d],%d,%d,%[^;];", RideName(*R), &RidePrice(*R), &BahanCost[x-1][0], &BahanCost[x-1][1],\
	&BahanCost[x-1][2], &RideCapacity(*R), &RideDuration(*R), RideDesk(*R));
	fclose(file);
	
	RideLocation(*R).X = ValUndef; RideLocation(*R).Y = ValUndef;
	RideSymbol(*R) = '~';
	CountReport(*R) = 0;
	CountReportD(*R) = 0;
	IncomeReport(*R) = 0;
	IncomeReportD(*R) = 0;
	RideNumber(*R) = x;
	RideSafe(*R) = true;
	RideBroken(*R) = 0;
	RideUp(*R) = x;
}

void SetRideLokasi(Ride *R, POINT XY)
/* I.S. R dan XY terdefinisi 
   F.S. Lokasi R di Peta adalah XY */
{
	RideLocation(*R) = XY;
}

void SetRide()
/* I.S. Setiap wahana tidak terdefinisi
   F.S. Setiap wahana terdefinisi atau teralokasi dalam memori */
{
	/* Kamus */
	MakeRide(&R1, 1); MakeEmptySeat(&(RideSeat(R1)), 12);
	MakeRide(&R2, 2); MakeEmptySeat(&(RideSeat(R2)), 5);
	MakeRide(&R3, 3); MakeEmptySeat(&(RideSeat(R3)), 15);
	MakeRide(&R4, 4); MakeEmptySeat(&(RideSeat(R4)), 20);
	MakeRide(&R5, 5); MakeEmptySeat(&(RideSeat(R5)), 30);
}
