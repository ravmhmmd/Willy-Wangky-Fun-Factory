#include <stdio.h>
#include "string.h"
#include "ride.h"

char *ArrRideName[5] = {"Rollercoaster", "Bungee Jump", "Hurricane", "Bumping Car", "Haunted House"};
char *ArrRideAge[5] = {"Semua umur", "5+", "13+", "15+", "18+"};
int ArrRidePrice[5] = {20, 30, 50, 70, 100};
int ArrRideBCost[5][3] = {
	{10, 10, 10}, {20, 20, 20}, {30, 30, 30}, {40, 40, 40}, {50, 50, 50}
};

void MakeRide(Ride *R, RideNo x)
/* I.S. R tidak terdefinisi
   F.S. R terdefinisi dengan nomor wahana ke-x */
{
	/* Kamus */
	int i;
	/* Algoritma */
	strcpy(RideName(*R), ArrRideName[x-1]);
	strcpy(RideAge(*R), ArrRideAge[x-1]);
	RidePrice(*R) = ArrRidePrice[x-1];
	for (i = 0; i < 3; i++){
		RideBCost(*R)[i] = ArrRideBCost[x-1][i];
	}
}
