#include "aksi.h"

Stack StackAksi;

int totalAksi = 0;
int totalDuration = 0;
int totalCost = 0;

char *ArrAksiName[30] = {"Build", "Upgrade", "Buy"};
char *ArrBahanName[5] = {"Kayu", "Batu", "Besi"};
int ArrBahanCost[10] = {10, 15, 20};

int CurrentMoney = 1000;
int CurrentBahan[3] = {0, 0, 0};

void MakeEmptyAksi(Aksi *A)
/* I.S. A sembarang
   F.S. A terdefinisi kosong */
{
	/* Kamus */
	int i;
	/* Algoritma */
	
	/* In case A sudah terdefinisi sebelumnya, akan direset semua nilai AksiNamanya jadi empty char */
	for (i = 0; i < 30; i++){
		AksiName(*A)[i] = '\0';
	}
	
	AksiNomor(*A) = 0;
	AksiDuration(*A) = 0;
	AksiCost(*A) = 0;
}

void Build(Aksi *A)
/* I.S. A dan R terdefinisi
   F.S. A merupakan aksi Build, dan R merupakan target A, yaitu wahana yang akan dibangun 
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */
{
	/* Kamus */
	Ride R;
	/* Algoritma */
	
	printf("Pilih bangunan yang ingin dibangun: Rollercoaster, Bungee Jump, Hurricane, Bumping Car, Haunted House\n");
	
	/* Nama dari aksi (build/upgrade/buy) disimpan pada (*A).AksiNama */
	strcpy(AksiName(*A), ArrAksiName[0]);
	
	STARTKATA();
	AksiNomor(*A) = 1;
	AksiDuration(*A) = 13500; //3 jam 45 menit
	AksiCost(*A) = 100;
	
	/* Penyesuaian durasi dan biaya yang dibutuhkan oleh aksi */
	
	if (IsKataEQStr(CKata, "rollercoaster")){
		MakeRide(&R, 1);
	}
	else if (IsKataEQStr(CKata, "bungee jump")){
		MakeRide(&R, 2);
	}
	else if (IsKataEQStr(CKata, "hurricane")){
		MakeRide(&R, 3);
	}
	else if (IsKataEQStr(CKata, "bumping car")){
		MakeRide(&R, 4);
	}
	else if (IsKataEQStr(CKata, "Haunted House")){
		MakeRide(&R, 5);
	}
	
	
	AksiTarget(*A) = R;
}

void Upgrade(Aksi *A)
/* I.S. A dan R terdefinisi, R telah dibangun 
   F.S. A merupakan aksi Upgrade, dan R merupakan target A, yaitu wahana yang akan diupgrade 
   		Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */
{
	/* Kamus */
	Ride R;
	/* Algoritma */
	
	printf("Pilih bangunan yang ingin diupgrade: Rollercoaster, Bungee Jump, Hurricane, Bumping Car, Haunted House\n");
	
	/* Nama dari aksi (build/upgrade/buy) disimpan pada (*A).AksiNama */
	strcpy(AksiName(*A), ArrAksiName[1]);

	STARTKATA();
	AksiNomor(*A) = 2;
	AksiDuration(*A) = 10800; //3 jam
	AksiCost(*A) = 200;
	
	/* Penyesuaian durasi dan biaya yang dibutuhkan oleh aksi */
	
	if (IsKataEQStr(CKata, "rollercoaster")){
		MakeRide(&R, 1);
	}
	else if (IsKataEQStr(CKata, "bungee jump")){
		MakeRide(&R, 2);
	}
	else if (IsKataEQStr(CKata, "hurricane")){
		MakeRide(&R, 3);
	}
	else if (IsKataEQStr(CKata, "Bumping Car")){
		MakeRide(&R, 4);
	}
	else if (IsKataEQStr(CKata, "Haunted House")){
		MakeRide(&R, 5);
	}
	
	
	AksiTarget(*A) = R;
}

void Buy(Aksi *A)
/* I.S. A terdefinisi
   F.S. A merupakan aksi buy
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan Bahan */
{
	/* Kamus */
	Bahan B;
	/* Algoritma */
	
	printf("Pilih bahan yang ingin dibeli: Kayu, Batu, Besi\n");
	
	/* Nama dari aksi (build/upgrade/buy) disimpan pada (*A).AksiNama */
	strcpy(AksiName(*A), ArrAksiName[2]);
	
	STARTTOKEN();
	STARTKATA();
	//STARTKATA();
	AksiNomor(*A) = 3;
	AksiDuration(*A) = 3600; //1 jam
	
	/* Penyesuaian durasi dan biaya yang dibutuhkan oleh aksi */
	
	if (IsKataEQStr(CKata, "kayu")){
		MakeEmptyBahan(&B, 1); BahanNomor(B) = 1;
		AksiCost(*A) = CToken.val * ArrBahanCost[0];
	}
	else if (IsKataEQStr(CKata, "batu")){
		MakeEmptyBahan(&B, 2); BahanNomor(B) = 2;
		AksiCost(*A) = CToken.val * ArrBahanCost[1];
	}
	else if (IsKataEQStr(CKata, "besi")){
		MakeEmptyBahan(&B, 3); BahanNomor(B) = 3;
		AksiCost(*A) = CToken.val * ArrBahanCost[2];
	}
	
	BahanQty(B) = CToken.val;
	AksiTargetB(*A) = B;
}

void Execute(Aksi A)
{
	/* Kamus */
	/* Algoritma */
	switch (AksiNomor(A)){
		case 1:
			printf("%s berhasil dibangun!\n", RideName(AksiTarget(A)));
			break;
			
		case 2:
			printf("%s berhasil dibangun!\n", RideName(AksiTarget(A)));
			break;
			
		case 3:
			printf("%s berhasil dibeli sebanyak %d buah!\n", BahanName(AksiTargetB(A)), BahanQty(AksiTargetB(A)));
			CurrentBahan[BahanNomor(AksiTargetB(A)) - 1] += BahanQty(AksiTargetB(A));
			break;
	}
	CurrentMoney -= AksiCost(A);
}

void MakeEmptyStack(Stack *S)
/* I.S. S sembarang
   F.S. S terdefinisi kosong */
{
	/* Kamus */
	/* Algoritma */
	Top(*S) = IdxNil;
}

boolean IsStackEmpty(Stack S)
{
	/* Kamus */
	/* Algoritma */
	return (Top(S) == IdxNil);
}

void PushAksi(Stack *S, Aksi A)
/* Menambahkan A sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh. A terdefinisi */
/* F.S. A menjadi TOP yang baru,TOP bertambah 1
        totalAksi di-inkremen, totalDuration, dan totalCost ditambahkan sesuai dengan durasi dan biaya aksi A */
{
	/* Kamus */
	/* Algoritma */
	Top(*S) += 1;
	InfoTop(*S) = A;
	totalAksi += 1;
	totalDuration += AksiDuration(A);
	totalCost += AksiCost(A);
}

void PopAksi(Stack *S, Aksi *A)
/* Mengeluarkan A dari elemen Stack S. */
/* I.S. S TIDAK mungkin kosong. A sembarang/teralokasi */
/* F.S. A dikeluarkan dari TOP, TOP berkurang 1
        totalAksi di-dekremen, totalDuration, dan totalCost dikurangi sesuai dengan durasi dan biaya aksi InfoTop(S) */
{
	/* Kamus */
	/* Algoritma */
	totalAksi -= 1;
	totalDuration -= AksiDuration(InfoTop(*S));
	totalCost -= AksiCost(InfoTop(*S));
	*A = InfoTop(*S);
	Top(*S) -= 1;
	
}

void MakeEmptyBahan(Bahan *B, BahanNo x)
/* I.S. B tidak terdefinisi
   F.S. B terdefinisi dengan nomor bahan ke-x */
{
	/* Kamus */
	/* Algoritma */
	strcpy(BahanName(*B), ArrBahanName[x-1]);
	BahanCost(*B) = ArrBahanCost[x-1];
}
