#include "string.h"
#include "aksi.h"


/* Total resource yang dibutuhkan untuk melakukan aksi dalam stack */
int totalAksi = 0;
long totalDuration = 0;
int totalCost = 0;

/* Resource yang dimiliki oleh player */
int CurrentMoney = 1000;

void MakeEmptyAksi(Aksi *A)
/* I.S. A sembarang
   F.S. A terdefinisi kosong */
{
	/* Kamus */
	/* Algoritma */
	AksiNomor(*A) = ValUndef;
	AksiUNomor(*A) = ValUndef;
	AksiRNomor(*A) = ValUndef;
	AksiBNomor(*A) = ValUndef;
	AksiRBCost(*A)[0] = ValUndef;
	AksiRBCost(*A)[1] = ValUndef;
	AksiRBCost(*A)[2] = ValUndef;
	AksiBQty(*A) = ValUndef;
	AksiCost(*A) = ValUndef;
	AksiLokasi(*A).lokasiAksi.X = ValUndef;
	AksiLokasi(*A).lokasiAksi.Y = ValUndef;
}

void Build(Aksi *A)
/* I.S. A dan R terdefinisi
   F.S. A merupakan aksi Build, dan R merupakan target A, yaitu wahana yang akan dibangun 
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */
{
	/* Kamus */
	int i;
	boolean lokasiSama;
	/* Algoritma */
	lokasiSama = false;
	i = 0;
	while(ElRide(PetaM, i).Number!=-1) {
		POINT BB = ElRide(PetaM,i).Location;
		if(EQPoint(BB, Pemain(PetaM))) {
			lokasiSama=true;
		}
		i++;
	}
	
	if(!(lokasiSama|EQPoint(Pemain(PetaM), Office(PetaM).lokasi)|EQPoint(Pemain(PetaM),Antrean(PetaM).lokasi))){
		printf("Pilih bangunan yang ingin dibangun: Rollercoaster, Bungee Jump, Hurricane, Bumping Car, Haunted House\n");
		
		STARTKATA();
		AksiNomor(*A) = 1;
		AksiCost(*A) = 100;
		if (IsKataEQStr(CKata, "rollercoaster")){
			AksiRNomor(*A) = 1;
		}
		else if (IsKataEQStr(CKata, "bungee jump")){
			AksiRNomor(*A) = 2;
		}
		else if (IsKataEQStr(CKata, "hurricane")){
			AksiRNomor(*A) = 3;
		}
		else if (IsKataEQStr(CKata, "bumping car")){
			AksiRNomor(*A) = 4;
		}
		else if (IsKataEQStr(CKata, "haunted house")){
			AksiRNomor(*A) = 5;
		}
		AksiLokasi(*A).lokasiAksi = Pemain(PetaM);
		if(IsCurPeta1(PetaM)) {
			AksiLokasi(*A).petaAksi = Peta1;
		}
		else if(IsCurPeta2(PetaM)) {
			AksiLokasi(*A).petaAksi = Peta2;
		}
		else if(IsCurPeta3(PetaM)) {
			AksiLokasi(*A).petaAksi = Peta3;
		}
		else if(IsCurPeta4(PetaM)) {
			AksiLokasi(*A).petaAksi = Peta4;
		}
	}
	
	else{
		AksiNomor(*A) = ValUndef;
	}
	
}

void Upgrade(Aksi *A)
/* I.S. A dan R terdefinisi, R telah dibangun 
   F.S. A merupakan aksi Upgrade, dan R merupakan target A, yaitu wahana yang akan diupgrade 
   		Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan wahana */
{
	/* Kamus */
	Ride RDwin;
	/* Algoritma */
	AksiNomor(*A) = 2;
	AksiCost(*A) = 200;
	//
	if(WahanaTerdekat(PetaM).Number != -1) {
		RDwin = WahanaTerdekat(PetaM);
		if(RDwin.Number==1){
			AksiRNomor(*A) = 1;
			PilihUpgrade(A, U1, R1);
		}
		else if(RDwin.Number==2){
			AksiRNomor(*A) = 2;
			PilihUpgrade(A, U2, R2);
		}
		else if(RDwin.Number==3){
			AksiRNomor(*A) = 3;
			PilihUpgrade(A, U3, R3);
		}
		else if(RDwin.Number==4){
			AksiRNomor(*A) = 4;
			PilihUpgrade(A, U4, R4);
		}
		else if(RDwin.Number==5){
			AksiRNomor(*A) = 5;
			PilihUpgrade(A, U5, R5);
		}
	}
	else{
		printf("Anda tidak berada di dekat wahana manapun\n");
	}
}

void PilihUpgrade(Aksi *A, BinTree T, Ride R)
{
	/* Kamus */
	BinTree UP;
	int i;
	/* Algoritma */
	UP = GetTree(T, RideUp(R));
	printf("Pilih bangunan selanjutnya: %s %s\n", upName(Akar(Left(UP))), upName(Akar(Right(UP))));
	STARTKATA();
	
	if (IsKataEQStr(CKata, upName(Akar(Left(UP))))){
		AksiUNomor(*A) = 1;
	}
	else if (IsKataEQStr(CKata, upName(Akar(Right(UP))))){
		AksiUNomor(*A) = 2;
	}
	for (i = 0; i < 3; i++){
		BahanCost[RideNumber(R) - 1][i] = upBCost(Akar(UP), i);
	}
}

void Buy(Aksi *A)
/* I.S. A terdefinisi
   F.S. A merupakan aksi buy
        Durasi dan biaya yang dibutuhkan aksi A disesuaikan dengan Bahan */
{
	/* Kamus */
	/* Algoritma */
	
	printf("Pilih bahan yang ingin dibeli: Kayu, Batu, Besi\n");
	
	STARTTOKEN();
	STARTKATA();
	//STARTKATA();
	AksiNomor(*A) = 3;
	
	/* Penyesuaian durasi dan biaya yang dibutuhkan oleh aksi */
	
	if (IsKataEQStr(CKata, "kayu")){
		AksiBNomor(*A) = 1;
		AksiCost(*A) = CToken.val * TabBahanCost(ArrBahan, 0);
	}
	else if (IsKataEQStr(CKata, "batu")){
		AksiBNomor(*A) = 2;
		AksiCost(*A) = CToken.val * TabBahanCost(ArrBahan, 1);
	}
	else if (IsKataEQStr(CKata, "besi")){
		AksiBNomor(*A) = 3;
		AksiCost(*A) = CToken.val * TabBahanCost(ArrBahan, 2);
	}
	
	AksiBQty(*A) = CToken.val;
}

void Execute(Aksi A)
{
	/* Kamus */
	int i, no;
	BinTree UP;
	/* Algoritma */
	switch (AksiNomor(A)){
		case 1:
			switch (AksiRNomor(A)){
				case 1:
					R1.Location = AksiLokasi(A).lokasiAksi;
					R1.symbol = 'R';
					if(IsPetaSama(PetaM, AksiLokasi(A).petaAksi)) {
						TambahRide(&PetaM, R1);
					}
					else {
						TambahRide(&AksiLokasi(A).petaAksi, R1);
					}
					printf("%s berhasil dibangun!\n", RideName(R1));
					break;
				case 2:
					R2.Location = AksiLokasi(A).lokasiAksi;
					R2.symbol = 'B';
					if(IsPetaSama(PetaM, AksiLokasi(A).petaAksi)) {
						TambahRide(&PetaM, R2);
					}
					else {
						TambahRide(&AksiLokasi(A).petaAksi, R2);
					}
					printf("%s berhasil dibangun!\n", RideName(R2));
					break;
				case 3:
					R3.Location = AksiLokasi(A).lokasiAksi;
					R3.symbol = 'H';
					if(IsPetaSama(PetaM, AksiLokasi(A).petaAksi)) {
						TambahRide(&PetaM, R3);
					}
					else {
						TambahRide(&AksiLokasi(A).petaAksi, R3);
					}
					printf("%s berhasil dibangun!\n", RideName(R3));
					break;
				case 4:
					R4.Location = AksiLokasi(A).lokasiAksi;
					R4.symbol = 'C';
					if(IsPetaSama(PetaM, AksiLokasi(A).petaAksi)) {
						TambahRide(&PetaM, R4);
					}
					else {
						TambahRide(&AksiLokasi(A).petaAksi, R4);
					}
					printf("%s berhasil dibangun!\n", RideName(R4));
					break;
				case 5:
					R5.Location = AksiLokasi(A).lokasiAksi;
					R5.symbol = 'N';
					if(IsPetaSama(PetaM, AksiLokasi(A).petaAksi)) {
						TambahRide(&PetaM, R5);
					}
					else {
						TambahRide(&AksiLokasi(A).petaAksi, R5);
					}
					printf("%s berhasil dibangun!\n", RideName(R5));
					break;			
				}
			//printf("%s berhasil dibangun!\n", Name);
			break;
			
		case 2:
			switch (AksiRNomor(A)){
				case 1:
					UP = LeftorRight(GetTree(U1, RideUp(R1)), AksiUNomor(A));
					ExeUpgrade(Akar(UP), &R1);
					InsVFirst(&LU1, RideUp(R1));
					printf("%s berhasil diupgrade!\n", RideName(R1));
					break;
				case 2:
					UP = LeftorRight(GetTree(U2, RideUp(R2)), AksiUNomor(A));
					ExeUpgrade(Akar(UP), &R2);
					InsVFirst(&LU2, RideUp(R2));
					printf("%s berhasil diupgrade!\n", RideName(R2));
					break;
				case 3:
					UP = LeftorRight(GetTree(U3, RideUp(R3)), AksiUNomor(A));
					ExeUpgrade(Akar(UP), &R3);
					InsVFirst(&LU3, RideUp(R3));
					printf("%s berhasil diupgrade!\n", RideName(R3));
					break;
				case 4:
					UP = LeftorRight(GetTree(U4, RideUp(R4)), AksiUNomor(A));
					ExeUpgrade(Akar(UP), &R4);
					InsVFirst(&LU4, RideUp(R4));
					printf("%s berhasil diupgrade!\n", RideName(R4));
					break;
				case 5:
					UP = LeftorRight(GetTree(U5, RideUp(R5)), AksiUNomor(A));
					ExeUpgrade(Akar(UP), &R5);
					InsVFirst(&LU5, RideUp(R5));
					printf("%s berhasil diupgrade!\n", RideName(R5));
					break;
			}
			break;
			
		case 3:
			printf("%s berhasil dibeli sebanyak %d buah!\n", TabBahanName(ArrBahan, (AksiBNomor(A) - 1)), AksiBQty(A));
			CurrentBahan[AksiBNomor(A) - 1] += AksiBQty(A);
			break;
	}
}

void ExeUpgrade(infoUpgrade U, Ride *R)
{
	/* Kamus */
	int i;
	/* Algoritma */
	RideUp(*R) = upNumber(U);
	RidePrice(*R) = upPrice(U);
	RideCapacity(*R) = upCapacity(U);
	strcpy(RideName(*R), upName(U));
	strcpy(RideDesk(*R), upDesk(U));
	for (i = 0; i < 3; i++){
		BahanCost[RideNumber(*R) - 1][i] = upBCost(U, i);
	}
}


boolean IsMoneyCukup(Aksi A)
/* Mengembalikan true jika uang masih tersisa setelah melakukan aksi A */
{
	/* Kamus */
	/* Algoritma */
	return ((totalCost + AksiCost(A) - CurrentMoney) <= 0);
}

boolean IsBahanCukup(Aksi A)
/* Mengembalikan true jika bahan masih tersisa setelah melakukan aksi A */
{
	/* Kamus */
	int i;
	/* Algoritma */
	for (i = 0; i < 3; i++){
		if ((totalBahan[i] + BahanCost[AksiRNomor(A) - 1][i] - CurrentBahan[i]) > 0){
			return false;
		}
	}
	return true;
}

boolean IsDurationCukup(Aksi A)
/* Mengembalikan true jika durasi masih tersisa setelah melakukan aksi A */
{
	/* Kamus */
	/* Algoritma */
	return (Durasi(tutup, buka) - totalDuration - TabAksiDuration(ArrAksi, AksiNomor(A) - 1) > 0);
	
}
