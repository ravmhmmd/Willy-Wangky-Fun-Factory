#include <stdio.h>
#include <stdlib.h>
#include "mainphase.h"
#include "peta.h"
#include "prep.h"


Queue Antrean; // Antrean utama
boolean quitmain = false;
int timer = 0;

void mainphase() 
/* Fungsi utama di main phase */
/* I.S. Preparation phase sudah dilewati, elemen2 wahana sudah terdefinisi/teralokasi */
/* F.S. Mainphase dijalankan sekali */
{
	/* Kamus */
	Customer C1;
	int k;
	long delta;
	/* Algoritma */
	if (timer <= 0){
		k = rand() % 2;
		if (k == 1){
			MakeRandomCust(&C1);
			Enqueue(&Antrean, C1);
			timer = 480;
		}
	}
	
	delta = 0;
	printf("Masukkan perintah:\n");
	STARTKATA();
	printf("\n");
	if (IsKataEQStr(CKata, "Preparation") || IsKataEQStr(CKata, "preparation")){
		quitmain = true;
		MakeEmptyQueue(&Antrean);
	}
	else if (IsKataEQStr(CKata, "A") || IsKataEQStr(CKata, "a") || IsKataEQStr(CKata, "S") || IsKataEQStr(CKata, "s") \
	|| IsKataEQStr(CKata, "D") || IsKataEQStr(CKata, "d") || IsKataEQStr(CKata, "W") || IsKataEQStr(CKata, "w")){
		DisplayPeta(); delta = 120;
	}
	else if (IsKataEQStr(CKata, "serve rollercoaster")){
		Serve(&Antrean, &R1); delta = 180;
	}
	else if (IsKataEQStr(CKata, "serve bungee jump")){
		Serve(&Antrean, &R2); delta = 180;
	}
	else if (IsKataEQStr(CKata, "serve hurricane")){
		Serve(&Antrean, &R3); delta = 180;
	}
	else if (IsKataEQStr(CKata, "serve bumping car")){
		Serve(&Antrean, &R4); delta = 180;
	}
	else if (IsKataEQStr(CKata, "serve haunted house")){
		Serve(&Antrean, &R5); delta = 180;
	}
	else if (IsKataEQStr(CKata, "Repair")){
		Repair(&R1); Repair(&R2); Repair(&R3); Repair(&R4); Repair(&R5);
	}
	else if (IsKataEQStr(CKata, "Office")){
		if ((Pemain(PetaM).X == Office(PetaM).lokasi.X) && (Pemain(PetaM).Y == Office(PetaM).lokasi.Y) ){
			printf("Apa yang ingin Anda cek?\n");
			printf("Detail / Report\n");
			STARTKATA();
			
			if (IsKataEQStr(CKata, "Detail")){
				Detail(R1); Detail(R2); Detail(R3); Detail(R4); Detail(R5);
			}
			else if (IsKataEQStr(CKata, "Report")){
				Report(R1); Report(R2); Report(R3); Report(R4); Report(R5);
			}
		}
		else{
			printf("Anda tidak berada pada office\n");
		}
	}
	else if (IsKataEQStr(CKata, "Detail")){
		Ride RDwin;
		if(WahanaTerdekat(PetaM).Number != -1) {
			RDwin = WahanaTerdekat(PetaM);
			if(RDwin.Number==1){
				Detail(R1);
			}
			else if(RDwin.Number==2){
				Detail(R2);
			}
			else if(RDwin.Number==3){
				Detail(R3);
			}
			else if(RDwin.Number==4){
				Detail(R4);
			}
			else if(RDwin.Number==5){
				Detail(R5);
			}
		}
		else{
			printf("Anda tidak berada di dekat wahana manapun!");
		}
	}
	
	
	durasi -= delta; timer -= delta;
	
	CekAntrean(&Antrean, delta);
	
	UpdateSeat(&R1, delta); UpdateSeat(&R2, delta); UpdateSeat(&R3, delta); UpdateSeat(&R4, delta); UpdateSeat(&R5, delta);
	CekSeat(&R1); CekSeat(&R2); CekSeat(&R3); CekSeat(&R4); CekSeat(&R5);
}
 
void Serve(Queue *Q, Ride *R)
/* I.S. Q dan R terdefinisi
   F.S. Customer dari Q dipindahkan ke RideSeat(*R), uang bertambah */
{
	/* Kamus */
	address P;
	/* Algoritma */
	if(IsDekatAntrean(PetaM)) {
		if ((!IsEmptyQ(*Q)) && (IsNotFullQ(RideSeat(*R)) && (RideSafe(*R)))){	// Jika antrean tidak kosong dan wahana tidak penuh,
			Dequeue(&(*Q), &P);							// Customer keluarkan dari antrean
			CustDuration(Info(P)) = RideDuration(*R);	// Durasi customer sesuai dengan durasi wahana
			EnqueueSeat(&RideSeat(*R), Info(P));		// Customer dimasukkan ke wahana
			CurrentMoney += RidePrice(*R);				// Uang diperoleh
			CountReport(*R) += 1; CountReportD(*R) += 1;
			IncomeReport(*R) += RidePrice(*R); IncomeReportD(*R) += RidePrice(*R);
		}
		else if (!IsNotFullQ(RideSeat(*R))){
			printf("Wahana sudah penuh!\n");
		}
		else if (!RideSafe(*R))
		{
			printf("Wahana Rusak\n");
		}
	}
	else {
		printf("Anda tidak berada di dekat antrian.\n");
	}	
}

void CekAntrean(Queue *Q, long time)
{
	/* Kamus */
	address P, dummy, temp;
	/* Algoritma */
	if (!IsEmptyQ(*Q)){
		P = Head(*Q);
		while (P != Nil){
			CustDuration(Info(P)) -= time;
			if (CustDuration(Info(P)) <= 0){ // Jika durasi kesabarannya habis,
				CustDuration(Info(P)) = 600; // Durasi kesabarannya direset, patiencenya dikurangi
				Patience(Info(P)) -= 1;
				UpdatePrio(&Info(P));		 // Prioritasnya diupdate
			}
			P = Next(P);
		}
		AlokasiQueue(&dummy, InfoHead(*Q));
		Next(dummy) = Head(*Q);
		P = dummy;
		while (Next(P) != Nil){
			if (Patience(Info(Next(P))) <= 0){ // Jika kesabarannya sudah habis, akan dikeluarkan dari antrean.
				temp = Next(P);
				Next(P) = Next(Next(P));
				Dealokasi(temp);
			}
			else{
				P = Next(P);
			}
		}
		Head(*Q) = Next(dummy);
		Dealokasi(dummy);
	}
}

void UpdatePrio(Customer *C)
{
	/* Kamus */
	/* Algoritma */
	if (Prio(*C) < 5){
		Prio(*C) += 1;
	}
}


void UpdateSeat(Ride *R, long time)
/* Setiap durasi customer di wahana R dikurangi agar sinkron dengan waktu game */
/* I.S. R terdefinisi
   F.S. Setiap customer di wahana R (jika ada) dikurangi durasinya */
{
	/* Kamus */
	address P;
	/* Algoritma */
	if (!IsEmptyQ(RideSeat(*R))){			// Jika wahana tidak penuh,
		P = Head(RideSeat(*R));				// P menunjuk ke elemen pertama
		CustDuration(Info(P)) -= time;		// Durasi customer di node P dikurangi
		while (Next(P) != Nil){				// Algoritma diatas diterapkan untuk tiap node (tiap customer)
			P = Next(P);
			CustDuration(Info(P)) -= time;
		}
	}
}

void CekSeat(Ride *R)
/* I.S. R terdefinisi
   F.S. Jika customer pertama (yang datang paling awal) pada wahana R sudah habis durasinya, maka akan dikeluarkan.
        Jika terdapat wahana lain yang dipesan, maka akan kembali ke antrean
        Jika wahananya sudah dilayani semua, maka akan dikeluarkan dari taman bermain */
{
	/* Kamus */
	address P;
	int i;
	/* Algoritma */
	if ((!IsEmptyQ(RideSeat(*R)))){										// Jika wahana tidak penuh,
		if ((CustDuration(InfoHead(RideSeat(*R))) <= 0)){				// dan jika durasi dari pengunjung pertama sudah habis,
			Dequeue(&(RideSeat(*R)), &P);								// Customer akan dikeluarkan dari wahana
		
			i = 0;
			while (CustRideNo(Info(P))[i] != RideNumber(*R)){			// Mencari nilai i, yaitu indeks pada list wahana dari wahana yang sedang customer naiki.
				i++;													// Misal wahana yg dinaiki rollercoaster, maka RideNumber(*R) = 1.
			}															// Misal list wahana pengunjung adalah [2, 3, 1], maka i = 2.
			for (i; i < (NeffCust(Info(P)) - 1); i++){
				CustRideNo(Info(P))[i] = CustRideNo(Info(P))[i+1];		// Wahana akan dihapus dari list wahana pengunjung,
			}															// Dengan cara 'menggeser' elemen list
			NeffCust(Info(P)) -= 1;										// Neff customer, yaitu banyaknya wahana yg ingin dinaiki customer berkurang 1.
			
			if (NeffCust(Info(P)) != 0){								// Jika masih ada yang ingin dinaiki, maka akan dipindahkan ke antrean
				CustDuration(Info(P)) = 600;
				UpdatePrio(&Info(P));									// Dengan prioritas yang ditambah 1
				Enqueue(&Antrean, Info(P));								// Customer dipindahkan ke antrean
				Patience(Info(P)) = 5;
			}
			else{														// Jika tidak ada yang ingin dinaiki lagi,
				Dealokasi(P);											// Maka customer akan dikeluarkan dari taman bermain, yaitu nodenya didealokasi.
			}
		}
	}
}

void Broke(Ride *R)
{
	address P;
	while ((!IsEmptyQ(RideSeat(*R)))) //Pengunjung dikembalikan ke antrian dengan prio yg lebih tinggi
	{
		Dequeue(&(RideSeat(*R)), &P);
		UpdatePrio(&Info(P));
		if (IsNotFullQ(Antrean)){
			Enqueue(&Antrean, Info(P));	
		}
		else
		{
			Dealokasi(P);
		}
	}
	RideSafe(*R) = false;
	//RideBroken(*R) += 1;
}

void Repair (Ride *R)
{
	int i = 0;
	while(ElRide(PetaM, i).Number!=-1) {
		if(Panjang(Pemain(PetaM), ElRide(PetaM, i).Location)==1) {
			RideSafe(*R) = true;
			RideBroken(*R) += 1;
		}
		i++;
	}
	if(i==0) {
		printf("Tidak ada wahana di sekitar anda!\n");
	}
}

void SetBroke(Ride *R, long time)
{
	if (hourRemaining <= time && RideBroken(*R)==0){
		printf("Broken : %s\n", RideName(*R));
		Broke(R);
	}
}

void Detail(Ride R)
{
	/* Kamus */
	/* Algoritma */
	printf("1. Nama: %s\n", RideName(R));
	printf("2. Tipe: *****\n");
	printf("3. Harga: %d\n", RidePrice(R));
	printf("4. Lokasi: (%.1f, %.1f)\n", RideLocation(R).X, RideLocation(R).Y);
	printf("5. Deskripsi: %s\n", RideDesk(R));
	printf("6. Kapasitas: %d\n", RideCapacity(R));
	printf("7. Durasi: %d menit\n", RideDuration(R)/60);
	switch (RideNumber(R)){
		case 1:
			printf("8. Upgrade: "); PrintInfoUpgrade(LU1, U1);
			printf("9. History: "); PrintHistoryUpgrade(LU1, U1);
			break;
		case 2:
			printf("8. Upgrade: "); PrintInfoUpgrade(LU2, U2);
			printf("9. History: "); PrintHistoryUpgrade(LU2, U2);
			break;
		case 3:
			printf("8. Upgrade: "); PrintInfoUpgrade(LU3, U3);
			printf("9. History: "); PrintHistoryUpgrade(LU3, U3);
			break;
		case 4:
			printf("8. Upgrade: "); PrintInfoUpgrade(LU4, U4);
			printf("9. History: "); PrintHistoryUpgrade(LU4, U4);
			break;
		case 5:
			printf("8. Upgrade: "); PrintInfoUpgrade(LU5, U5);
			printf("9. History: "); PrintHistoryUpgrade(LU5, U5);
			break;
	}
	printf("\n");
}

void Report(Ride R)
{
	/* Kamus */
	/* Algoritma */
	printf("===== Report wahana %s =====\n", RideName(R));
	printf("1. Banyaknya pelanggan yang naik: %d kali\n", CountReport(R));
	printf("2. Total penghasilan: %d\n", IncomeReport(R));
	printf("3. Banyaknya pelanggan yang naik hari ini: %d kali\n" , CountReportD(R));
	printf("4. Penghasilan hari ini: %d\n", IncomeReportD(R));
}
