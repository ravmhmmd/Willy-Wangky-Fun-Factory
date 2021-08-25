/* ADT Ride */

#ifndef RIDE_H
#define RIDE_H

extern char *ArrRideName[5];
extern char *ArrRideAge[5];
extern int ArrRidePrice[5];
extern int ArrRideBCost[5][3];

typedef int RideNo; //Nomor wahana

typedef struct {
	char Name[50];
	char Age[3];
	int Price;
	int BahanCost[3];
} Ride;

/* SELEKTOR */
#define RideName(R) (R).Name
#define RideAge(R) (R).Age
#define RidePrice(R) (R).Price
#define RideBCost(R) (R).BahanCost

/* Konstruktor */

void MakeRide(Ride *R, RideNo x);
/* I.S. R tidak terdefinisi
   F.S. R terdefinisi dengan nomor wahana ke-x */

#endif
