#include <stdio.h>
#include "functions.h"
#include "prep.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean quitprep = false;
long hourRemaining;
long minuteRemaining;
long secondRemaining;

long hourDuration;
long minuteDuration;
long secondDuration;


void Prep() {
	/* Kamus */
	Stack Sexecute;
	Aksi A, Atemp;
	/* Algoritma */
	MakeEmptyAksi(&A);
	
	printf("Masukkan perintah:\n");
	STARTKATA();
	printf("\n");
	if (IsKataEQStr(CKata, "Q") || IsKataEQStr(CKata, "q")){
		quitprep = true;
	}
	else if (IsKataEQStr(CKata, "A") || IsKataEQStr(CKata, "a") || IsKataEQStr(CKata, "S") || IsKataEQStr(CKata, "s") \
	|| IsKataEQStr(CKata, "D") || IsKataEQStr(CKata, "d") || IsKataEQStr(CKata, "W") || IsKataEQStr(CKata, "w")){
		DisplayPeta();
	}
	else if (IsKataEQStr(CKata, "BUY") || IsKataEQStr(CKata, "buy")){
		// BUY
		Buy(&A);
		if (!IsMoneyCukup(A)){
			printf("Uang tidak cukup!\n");
		}
		else if (!IsDurationCukup(A)){
			printf("Durasi melebihi batas waktu!\n");
		}
		else {
			PushAksi(&StackAksi, A);
		}
	}
	else if (IsKataEQStr(CKata, "BUILD") || IsKataEQStr(CKata, "build")){
		// BUILD
		Build(&A);
		if (!IsMoneyCukup(A)){
			printf("Uang tidak cukup!\n");
		}
		else if (!IsBahanCukup(A)){
			printf("Bahan tidak cukup!\n");
		}
		else if (!IsDurationCukup(A)){
			printf("Durasi melebihi batas waktu!\n");
		}
		else {
			PushAksi(&StackAksi, A);
		}
	}
	else if (IsKataEQStr(CKata, "UPGRADE") || IsKataEQStr(CKata, "upgrade")){
		// UPGRADE
		Upgrade(&A);
		PushAksi(&StackAksi, A);
	}
	else if (IsKataEQStr(CKata, "EXECUTE") || IsKataEQStr(CKata, "execute")){
		// EXECUTE
		MakeEmptyStack(&Sexecute);
		MakeEmptyAksi(&Atemp);
		
		// Aksi dipindahkan terlebih dahulu ke stack lain agar urutan eksekusinya dimulai dari aksi pertama
		while (!IsStackEmpty(StackAksi)){
			PopAksi(&StackAksi, &Atemp);
			PushAksi(&Sexecute, Atemp);
		}
		while (!IsStackEmpty(Sexecute)){
			Execute(InfoTop(Sexecute));
			PopAksi(&Sexecute, &Atemp);
		}
	}
	else if (IsKataEQStr(CKata, "UNDO") || IsKataEQStr(CKata, "undo")){
		// UNDO
		if (IsStackEmpty(StackAksi)){
			printf("Tidak ada aksi yang dapat di-undo!\n");
		}
		else {
			PopAksi(&StackAksi, &A);
		}
	}
	else if (IsKataEQStr(CKata, "MAIN") || IsKataEQStr(CKata, "main")){
		// MAIN
	}
}
