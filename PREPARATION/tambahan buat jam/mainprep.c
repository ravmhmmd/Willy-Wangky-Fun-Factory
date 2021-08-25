#include <stdio.h>
#include "functions.h"
#include "prep.h"
#include "jam.h"

int main() {
	SetPeta();
	Kata PlayerName;

    long hourRemaining;
    long minuteRemaining;
    long secondRemaining;

    long hourDuration;
    long minuteDuration;
    long secondDuration;

	JAM buka;
	MakeJamBuka(&buka);

	JAM tutup;
	MakeJamTutup(&tutup);

	MakeEmptyStack(&StackAksi);
	printf("Welcome to Willy Wangky's fun factory!!\n"); printf("Masukkan nama: ");
	STARTKATA();
	SaveKata(&PlayerName);
	while (!quitprep) {
		printf("\nPreparation Phase day 1\n");
	
	//	printf("\n\nINI PETA, LEGEND, DLL\n\n\n");
	    TulisPeta(P);
		
		//PRINT LEGEND
		//PRINT STATE
		
		printf("Nama: "); PrintKata(PlayerName);
		printf("Money: %d\n", CurrentMoney);
		printf("Current Time: ");
		TulisJAM(tutup);
		printf("\nClosing Time: ");
		TulisJAM(buka);
        long durasi = Durasi(tutup, buka);
        hourRemaining = (durasi - totalDuration)/3600;
        minuteRemaining = ((durasi - totalDuration)%3600)/60;
        secondRemaining = ((durasi-totalDuration)%3600)%60;

        hourDuration = (totalDuration)/3600;
        minuteDuration = ((totalDuration)%3600)/60;
        secondDuration = (totalDuration%3600)%60;
		if ( durasi - totalDuration > 0 ) {
			printf("\nTime Remaining : %ld hour(s) %ld minute(s)", hourRemaining, minuteRemaining);
			printf("\nTotal Aksi: %d", totalAksi);
		} else {
			printf("\nerror, durasi melebihi batas waktu");
		}
        printf("\nTotal Durasi: %ld hour(s) %ld minute(s)", hourDuration, minuteDuration);
        printf("\nTotal Biaya: %d\n\n", totalCost);
		printf("Banyaknya bahan: -Kayu: %d -Batu: %d -Besi: %d\n", CurrentBahan[0], CurrentBahan[1], CurrentBahan[2]);
		Prep();
	}
	return 0;
}

// NB: ADT Mesinkar, Mesinkata dan Mesintoken ada sedikit diubah dari file aslinya, jadi jangan pake header/body dari olympia.
// COMPILE: gcc functions.c matriks.c point.c peta.c mesinkar.c mesinkata.c mesintoken.c prep.c ride.c aksi.c jam.c mainprep.c -o [NAMAFILE]
// Kalo undefined sin, cos, dll, tambahin -lm di akhir: ... -o [NAMAFILE] -lm
// RUN: ./[NAMAFILE]