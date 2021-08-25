#include <stdlib.h>
#include "prioqueue.h"

void AlokasiQueue(address *P, Customer C)
/* I.S. P tidak terdefinisi
   F.S. P terdefinisi dengan Info(P) berisikan C */
{
	/* Kamus */
	/* Algoritma */
	*P = (Node*) malloc(sizeof(Node));
	if (*P != Nil){
		Info(*P) = C;
		PrioQ(*P) = Prio(C);
		DurationQ(*P) = CustDuration(C);
		Next(*P) = Nil;
	}
}

void MakeEmptyQueue(Queue *Q)
/* I.S. Q tidak terdefinisi
   F.S. Head(Q) menunjuk ke nil */
{
	/* Kamus */
	/* Algoritma */
	//AlokasiQueue(&(*P), C);
	Head(*Q) = Nil;
	CapacityQ(*Q) = MaxQ;
}

void MakeEmptySeat(Queue *Q, int X)
/* I.S. Q tidak terdefinisi
   F.S. Head(Q) menunjuk ke nil */
{
	/* Kamus */
	/* Algoritma */
	//AlokasiQueue(&(*P), C);
	Head(*Q) = Nil;
	CapacityQ(*Q) = X;
}

void Dealokasi(address P)
/* I.S. P teralokasi
   F.S. P telah di-dealokasi */
{
	/* Kamus */
	/* Algoritma */
	Next(P) = Nil;
	free(P);
}

boolean IsEmptyQ(Queue Q)
/* Mengecek apakah Q kosong. true jika kosong, false jika tidak kosong */
{
	/* Kamus */
	/* Algoritma */
	return (Head(Q) == Nil);
	
}

int NbElmtQ(Queue Q)
/* Mengembalikan banyaknya elemen pada Q */

{
	/* Kamus */
	address P;
	int cnt;
	/* Algoritma */
	if (!IsEmptyQ(Q)){
		P = Head(Q); cnt = 1;
		while (Next(P) != Nil){
			P = Next(P);
			cnt++;
		}
		return cnt;
	}
	else {
		return 0;
	}
}

boolean IsNotFullQ(Queue Q)
/* Mengecek apakah Q belum penuh */
{
	return (NbElmtQ(Q) < CapacityQ(Q));
}

void Enqueue(Queue *Q, Customer C)
/* I.S. Q mungkin kosong, C terdefinisi
   F.S. Node dengan info C ditambahkan ke antrean Q, sesuai dengan nilai prioritasnya */
{
	/* Kamus */
	address P, prec, dummyFirst;
	/* Algoritma */
	AlokasiQueue(&P, C);
	if ((P != Nil) & IsNotFullQ(*Q)){
		if (IsEmptyQ(*Q)){
			Head(*Q) = P;
		}

		else {
			/* Menggunakan dummyFirst agar elemen pertama Q dapat dibandingkan */
			dummyFirst = (Node*) malloc(sizeof(Node)); 
			Next(dummyFirst) = Head(*Q);
			Head(*Q) = dummyFirst;
			
			prec = dummyFirst;
			while ((Next(prec) != Nil) && ((PrioQ(Next(prec))) >= Prio(C))){
				prec = Next(prec);
			}
			/* Next(prec) == Nil atau Prioritas dari Next(prec) kurang dari Prioritas C */
			Next(P) = Next(prec);
			Next(prec) = P;
			
			Head(*Q) = Next(dummyFirst);
			Dealokasi(dummyFirst);
		}
	} /* else, alokasi gagal, Q tetap */
}

void EnqueueSeat(Queue *Q, Customer C)
/* Enqueue untuk seat, yaitu urutannya berdasarkan durasi
   I.S. Q Mungkin kosong, C terdefinisi
   F.S. Node dengan info C ditambahkan ke antrean Q, sesuai dengan nilai durasinya */
{
	/* Kamus */
	address P, prec, dummyFirst;
	/* Algoritma */
	AlokasiQueue(&P, C);
	if ((P != Nil) && IsNotFullQ(*Q)){
		if (IsEmptyQ(*Q)){
			Head(*Q) = P;
		}

		else {
			/* Menggunakan dummyFirst agar elemen pertama Q dapat dibandingkan */
			dummyFirst = (Node*) malloc(sizeof(Node)); 
			Next(dummyFirst) = Head(*Q);
			Head(*Q) = dummyFirst;
			
			prec = dummyFirst;
			while ((Next(prec) != Nil) && ((DurationQ(Next(prec))) <= CustDuration(C))){
				prec = Next(prec);
			}
			/* Next(prec) == Nil atau Prioritas dari Next(prec) kurang dari Prioritas C */
			Next(P) = Next(prec);
			Next(prec) = P;
			
			Head(*Q) = Next(dummyFirst);
			Dealokasi(dummyFirst);
		}
	} /* else, alokasi gagal, Q tetap */
}

void Dequeue(Queue *Q, address *P)
/* I.S. Q tidak kosong, P terdefinisi/teralokasi
   F.S. Elemen Q dengan prioritas/durasi paling tinggi akan dikeluarkan dari antrean, kemudian P akan menunjuk elemen tersebut */
{
	/* Kamus */
	/* Algoritma */
	(*P) = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	Next(*P) = Nil;
}

void PrintAntrean(Queue Q)
/* I.S. Q terdefinisi
   F.S. Jika kosong, program hanya menampilkan "Antrean: ".
        Jika tidak kosong, program akan menuliskan setiap nama, daftar wahana, prioritas, dan kesabaran customer. */
{
	/* Kamus */
	address P;
	/* Algoritma */
	if (!(IsEmptyQ(Q))){
		printf("Antrean: [%d/%d]\n", NbElmtQ(Q), CapacityQ(Q));
		P = Head(Q);
		while (P != Nil){
			PrintRideCust(Info(P));
			P = Next(P);
		}
	}
}



