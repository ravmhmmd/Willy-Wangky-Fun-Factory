#include <stdio.h>
#include "functions.h"
#include "prep.h"

int main() {
	
	// Peta dibuat
	SetPeta();
	
	// Nama player
	Kata PlayerName;
	
	// Waktu buka dan tutup didefinisikan
	MakeJamBuka(&buka);
	MakeJamTutup(&tutup);
	
	// Durasi preparation phase didefinisikan
	long durasi = Durasi(tutup, buka);
	
	// Inisialisasi stack yang menyimpan aksi
	MakeEmptyStack(&StackAksi);
	
	printf("Welcome to Willy Wangky's fun factory!!\n"); printf("Masukkan nama: ");
	STARTKATA();
	SaveKata(&PlayerName);
	
	// Mulai preparation phase
	while (!quitprep) {
		printf("\nPreparation Phase day 1\n");
	
	    TulisPeta(P);
		
		printf("Nama: "); PrintKata(PlayerName);
		printf("Money: %d\n", CurrentMoney);
		
		printf("Current Time: "); TulisJAM(tutup);
		printf("\nClosing Time: "); TulisJAM(buka);
		
        hourRemaining = (durasi - totalDuration)/3600;
        minuteRemaining = ((durasi - totalDuration)%3600)/60;
        secondRemaining = ((durasi-totalDuration)%3600)%60;

        hourDuration = (totalDuration)/3600;
        minuteDuration = ((totalDuration)%3600)/60;
        secondDuration = (totalDuration%3600)%60;
 
		printf("\nTime Remaining : %ld hour(s) %ld minute(s)", hourRemaining, minuteRemaining);
		printf("\nTotal Aksi: %d", totalAksi);
        printf("\nTotal Durasi: %ld hour(s) %ld minute(s)", hourDuration, minuteDuration);
        printf("\nTotal Biaya: %d\n\n", totalCost);
		printf("Banyaknya bahan: -Kayu: %d -Batu: %d -Besi: %d\n", CurrentBahan[0], CurrentBahan[1], CurrentBahan[2]);
		Prep();
	}
	return 0;
}

// NB: ADT Mesinkar, Mesinkata dan Mesintoken ada sedikit diubah dari file aslinya, jadi jangan pake header/body dari olympia.
// Kalo undefined sin, cos, dll, tambahin -lm di akhir: ... -o [NAMAFILE] -lm
