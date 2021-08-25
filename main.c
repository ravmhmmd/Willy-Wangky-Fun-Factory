#include <stdio.h>
#include "peta.h"
#include "array.h"
#include "prep.h"
#include "stack.h"
#include "listlinier.h"
#include "mainphase.h"

boolean quit = false;

void Save(Kata PlayerName, int day);
void SaveQueue(Queue Q, FILE *f, int seat);
void SaveRide(Ride R, FILE *f);
void SavePrep(FILE *f);
void SavePeta(Peta P, FILE *f);
void Load(Kata *PlayerName, int *day);

int main() {
	int day = 1;
	// Peta dan bahan dibuat
	SetPeta(); SetBahan(); SetAksi(); SetRide(); SetUpgrade(); SetList();
	MakeEmptyQueue(&Antrean);
	
	// Nama player
	Kata PlayerName;
	
	// Waktu buka dan tutup didefinisikan
	MakeJamBuka(&buka);
	MakeJamTutup(&tutup);
	
	printf("\n");
	printf("  $$\\      $$\\ $$$$$$\\ $$\\       $$\\   $$\\     $$\\       $$\\      $$\\  $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\   $$\\ $$\\     $$\\       $$\\ $$\\ \n");
	printf("  $$ | $\\  $$ |\\_$$  _|$$ |      $$ |  \\$$\\   $$  |      $$ | $\\  $$ |$$  __$$\\ $$$\\  $$ |$$  __$$\\ $$ | $$  |\\$$\\   $$  |      $$ |$$ |\n");
	printf("  $$ |$$$\\ $$ |  $$ |  $$ |      $$ |   \\$$\\ $$  /       $$ |$$$\\ $$ |$$ /  $$ |$$$$\\ $$ |$$ /  \\__|$$ |$$  /  \\$$\\ $$  /       $$ |$$ |\n");
	printf("  $$ $$ $$\\$$ |  $$ |  $$ |      $$ |    \\$$$$  /        $$ $$ $$\\$$ |$$$$$$$$ |$$ $$\\$$ |$$ |$$$$\\ $$$$$  /    \\$$$$  /        $$ |$$ |\n");
	printf("  $$$$  _$$$$ |  $$ |  $$ |      $$ |     \\$$  /         $$$$  _$$$$ |$$  __$$ |$$ \\$$$$ |$$ |\\_$$ |$$  $$<      \\$$  /         \\__|\\__|\n");
	printf("  $$$  / \\$$$ |  $$ |  $$ |      $$ |      $$ |          $$$  / \\$$$ |$$ |  $$ |$$ |\\$$$ |$$ |  $$ |$$ |\\$$\\      $$ |                  \n");
	printf("  $$  /   \\$$ |$$$$$$\\ $$$$$$$$\\ $$$$$$$$\\ $$ |          $$  /   \\$$ |$$ |  $$ |$$ | \\$$ |\\$$$$$$  |$$ | \\$$\\     $$ |          $$\\ $$\\ \n");
	printf("  \\__/     \\__|\\______|\\________|\\________|\\__|          \\__/     \\__|\\__|  \\__|\\__|  \\__| \\______/ \\__|  \\__|    \\__|          \\__|\\__|\n");
	printf("\n");
	
	MakeEmptyStack(&StackAksi);
	printf("Welcome to Willy Wangky's fun factory!!\n");
	printf("New Game / Load  Game / Exit\n");
	STARTKATA();
	if (IsKataEQStr(CKata, "Load Game") || IsKataEQStr(CKata, "load game")){
		Load(&PlayerName, &day);
	}
	else if (IsKataEQStr(CKata, "New Game") || IsKataEQStr(CKata, "new game")){
		printf("Masukkan nama: ");
		STARTKATA();
		SaveKata(&PlayerName);
	}
	
	while (!quit){
		// Durasi wahana didefinisikan
		durasi = Durasi(tutup, buka);
	
		// Mulai preparation phase
		while (!quitprep && !quit) {
			printf("\nPreparation Phase day %d\n", day);
		
		    TulisPeta(PetaM);
			
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
			if (IsKataEQStr(CKata, "save")){
				Save(PlayerName, day);
			}
		}
		
		hourRemaining = durasi/3600;
		minuteRemaining = (durasi%3600)/60;

		while (!quitmain && !quit) {	
			printf("\nMain Phase day %d\n", day);
			
			TulisPeta(PetaM);
			
			hourRemaining = (durasi)/3600;
	        minuteRemaining = ((durasi)%3600)/60;
	        SetBroke(&R1, 10);
			printf("Nama: "); PrintKata(PlayerName);
			printf("Money: %d\n", CurrentMoney);
			printf("\nTime Remaining : %ld hour(s) %ld minute(s)\n", hourRemaining, minuteRemaining);
			PrintAntrean(Antrean); printf("\n");
			mainphase();
			if (durasi <= 0){
				quitmain = true;
			}
			if (IsKataEQStr(CKata, "save")){
				Save(PlayerName, day);
			}
		}
		MakeEmptyQueue(&Antrean);
		CountReportD(R1) = 0; CountReportD(R2) = 0; CountReportD(R3) = 0; CountReportD(R4) = 0; CountReportD(R5) = 0;
		IncomeReportD(R1) = 0; IncomeReportD(R2) = 0; IncomeReportD(R3) = 0; IncomeReportD(R4) = 0; IncomeReportD(R5) = 0;
		MakeEmptyQueue(&RideSeat(R1)); MakeEmptyQueue(&RideSeat(R2)); MakeEmptyQueue(&RideSeat(R3)); MakeEmptyQueue(&RideSeat(R4)); MakeEmptyQueue(&RideSeat(R5));
		quitprep  = false; quitmain = false;
		day++;
	}
}

void Save(Kata PlayerName, int day){
	int i;
	FILE *fptr = fopen("state.txt", "w");
	if (fptr == NULL) 
    { 
        printf("File tidak bisa dibuka"); 
    }
    else{
    	
    	fprintf(fptr, "\nNama:");
    	for (i = 0; i < PlayerName.Length; i++){
    		fprintf(fptr, "%c", PlayerName.TabKata[i]);
    	}
    	fprintf(fptr, ";\n");
    	fprintf(fptr, "day:%d;\n", day);
    	fprintf(fptr, "InitialMoney,InitialBahan:%d,[%d,%d,%d];\n", CurrentMoney, CurrentBahan[0], CurrentBahan[1], CurrentBahan[2]);
    	fprintf(fptr, "quitprep,quitmain:%d,%d;\n", quitprep, quitmain);
    	
    	SavePrep(fptr);
    	
		
		
		fprintf(fptr, "12:CustomerName:%c;\n", CustomerName);
		
		SaveQueue(Antrean, fptr, -1);
		SaveQueue(RideSeat(R1), fptr, 1); SaveQueue(RideSeat(R2), fptr, 2); SaveQueue(RideSeat(R3), fptr, 3);
		SaveQueue(RideSeat(R4), fptr, 4); SaveQueue(RideSeat(R5), fptr, 5);
		
    	SaveRide(R1, fptr); SaveRide(R2, fptr); SaveRide(R3, fptr); SaveRide(R4, fptr); SaveRide(R5, fptr);
		
	}
	fclose(fptr);
}

void Load(Kata *PlayerName, int *day){
	int j;
	char Name[30];
	FILE * file = fopen("state.txt", "r");
	fscanf(file, "\n%*[^:]:%[^;];", Name);
	for (j = 0; Name[j] != '\0'; ++j){
		(*PlayerName).TabKata[j] = Name[j];
		(*PlayerName).Length++;
	}
	fscanf(file, "%*[^:]:%d;", day);
	fscanf(file, "%*[^:]:%d,[%d,%d,%d];", &CurrentMoney, &CurrentBahan[0], &CurrentBahan[1], &CurrentBahan[2]);
	int pp, mp;
	fscanf(file, "%*[^:]:%d,%d;", &pp, &mp);
	if (pp == 1){
		quitprep = true;
	}
	if (mp == 1){
		quitmain = true;
	}
	
	int no;
		if (!quitprep){
		Stack temp;
		MakeEmptyStack(&temp);
		fscanf(file, "\n%d,", &no);
		while (no == 11){
			Aksi A;
			MakeEmptyPeta(&AksiLokasi(A).petaAksi);
			fscanf(file, "%d,%d,%d,%d,%d,[%d,%d,%d],(%f,%f),%d,%c,%c;", &AksiNomor(A), &AksiRNomor(A), &AksiUNomor(A), &AksiBNomor(A), &AksiCost(A),\
			 &AksiRBCost(A)[0], &AksiRBCost(A)[1], &AksiRBCost(A)[2], &AksiLokasi(A).lokasiAksi.X, &AksiLokasi(A).lokasiAksi.Y, &AksiBQty(A),\
			 &Gerbang1(AksiLokasi(A).petaAksi).nilai, &Gerbang2(AksiLokasi(A).petaAksi).nilai);
			PushAksi(&temp, A);
			fscanf(file, "\n%d,", &no);
		}
		while (!IsStackEmpty(temp)){
			Aksi A;
			MakeEmptyAksi(&A);
			PopAksi(&temp, &A);
			PushAksi(&StackAksi, A);
		}
	}
	
	fclose(file);
}

void SaveQueue(Queue Q, FILE *f, int seat){
	int i;
	address ptr;
	ptr = Head(Q);
	while (ptr != Nil){
		fprintf(f, "13:%d,[",seat);
		for (i = 0; i < NeffCust(Info(ptr)); i++){
			fprintf(f, "%d,", CustRideNo(Info(ptr))[i]);
		}
		fprintf(f, "]%c,%d,%d,%d,%d;\n", CustName(Info(ptr)), Prio(Info(ptr)), Patience(Info(ptr)),\
		NeffCust(Info(ptr)),CustDuration(Info(ptr)));
		ptr = Next(ptr);
	}
}

void SaveRide(Ride R, FILE *f){
	fprintf(f, "%d,%s:%c,%d,%d,%d,%d,%d,%d(%.1f,%.1f),%s;\n", RideNumber(R), RideName(R), RideSymbol(R), RidePrice(R),\
	RideUp(R), CountReport(R), IncomeReport(R), CountReportD(R), IncomeReportD(R), RideLocation(R).X, RideLocation(R).Y, RideDesk(R));
}

void SavePrep(FILE *f){
	int i;
	for (i = 0; i < Len(StackAksi); i++){
		fprintf(f, "11,%d,%d,%d,%d,%d,[%d,%d,%d],(%.1f,%.1f),%d,%c,%c;\n", AksiNomor(StackAksi.T[i]), AksiRNomor(StackAksi.T[i]), \
		 AksiUNomor(StackAksi.T[i]), AksiBNomor(StackAksi.T[i]), AksiCost(StackAksi.T[i]), AksiRBCost(StackAksi.T[i])[0], AksiRBCost(StackAksi.T[i])[1], \
		 AksiRBCost(StackAksi.T[i])[2], AksiLokasi(StackAksi.T[i]).lokasiAksi.X, AksiLokasi(StackAksi.T[i]).lokasiAksi.Y, AksiBQty(StackAksi.T[i]), \
		 Gerbang1(AksiLokasi(StackAksi.T[i]).petaAksi).nilai, Gerbang2(AksiLokasi(StackAksi.T[i]).petaAksi).nilai);
	}
	fprintf(f, "12,totalAksi,totalDuration,totalCost:%d,%ld,%d;\n", totalAksi, totalDuration, totalCost);
	fprintf(f, "12,durasi:%ld;\n", durasi);
	fprintf(f, "12,RideBCost:");
	for (i = 0; i < 5; i++){
		fprintf(f,"[%d,%d,%d]", BahanCost[i][0], BahanCost[i][1], BahanCost[i][2]);
	}
	fprintf(f, ";\n");
}

void SavePeta(Peta P, FILE *f){
	
}
