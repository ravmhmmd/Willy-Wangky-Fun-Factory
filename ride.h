/* ADT Ride */

#ifndef RIDE_H
#define RIDE_H

#include "prioqueue.h"
#include "point.h"


#define ValUndef -1

typedef int RideNo; //Nomor wahana

typedef struct {
	char Name[30];
	char symbol;
	int Price;
	Queue Seat;
	int Duration;
	int Capacity;
	RideNo Number;
	boolean Safe;
	POINT Location;
	int Upgrade;
	int Broken;
	char Desk[50];
	int Count;
	int Income;
	int Countdaily;
	int Incomedaily;
} Ride;

extern Ride R1, R2, R3, R4, R5;

/* Harga bahan dari Wahana */
extern int BahanCost[5][3];

/* SELEKTOR */
#define RideName(R) (R).Name
#define RideSymbol(R) (R).symbol
#define RideAge(R) (R).Age
#define RidePrice(R) (R).Price
#define RideSeat(R) (R).Seat
#define RideDuration(R) (R).Duration
#define RideCapacity(R) (R).Capacity
#define RideNumber(R) (R).Number
#define RideSafe(R) (R).Safe
#define RideLocation(R) (R).Location
#define RideUp(R) (R).Upgrade
#define RideBroken(R) (R).Broken
#define RideDesk(R) (R).Desk
#define CountReport(R) (R).Count
#define CountReportD(R) (R).Countdaily
#define IncomeReport(R) (R).Income
#define IncomeReportD(R) (R).Incomedaily

/* Konstruktor */

void MakeRide(Ride *R, RideNo x);
/* I.S. R tidak terdefinisi
   F.S. R terdefinisi dengan nomor wahana ke-x */
   
void SetRideLokasi(Ride *R, POINT XY);
/* I.S. R dan XY terdefinisi 
   F.S. Lokasi R di Peta adalah XY */

void SetRide();
/* I.S. Setiap wahana tidak terdefinisi
   F.S. Setiap wahana terdefinisi atau teralokasi dalam memori */

#endif
