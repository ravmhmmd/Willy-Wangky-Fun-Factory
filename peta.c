#include <stdio.h>
#include <stdlib.h>
#include "peta.h"
#include "mesinkata.h"

Peta Peta1,Peta2,Peta3,Peta4,PetaM;
Bangunan B5, B6, C5, C6, D5, D6, E5, E6;

void MakeEmptyPeta(Peta *P) {
	int i;
    *P = (ElPeta*) malloc(sizeof(ElPeta));
    Pemain(*P) = MakePOINT(valundef, valundef);
    Gerbang1(*P).lokasi = MakePOINT(valundef, valundef);
    Gerbang1(*P).nilai = charundef;
    Gerbang2(*P).lokasi = MakePOINT(valundef, valundef);
    Gerbang2(*P).nilai = charundef;
    Office(*P).lokasi = MakePOINT(5, 9); // lokasi fixed office.
    Office(*P).nilai = 'O';
    Antrean(*P).lokasi = MakePOINT(6, 13); // lokasi fixed office.
    Antrean(*P).nilai = 'A';
    for(i=0; i<IdxMax; i++) {
        Ride elR;
        MakeRide(&elR, -1);
        ElRide(*P, i) = elR;
    }
    Tetangga(*P)[0] = Nil;
    Tetangga(*P)[1] = Nil;
}

void CopyPeta(Peta Pin, Peta *Pout) {
    int i,j;
    Pemain(*Pout) = Pemain(Pin);
    Gerbang1(*Pout).lokasi = Gerbang1(Pin).lokasi;
    Gerbang1(*Pout).nilai = Gerbang1(Pin).nilai;
    Gerbang2(*Pout).lokasi = Gerbang2(Pin).lokasi;
    Gerbang2(*Pout).nilai = Gerbang2(Pin).nilai;
    Office(*Pout).lokasi = Office(Pin).lokasi;
    Office(*Pout).nilai = Office(Pin).nilai;
    Antrean(*Pout).lokasi = Antrean(Pin).lokasi;
    Antrean(*Pout).nilai = Antrean(Pin).nilai;
    i = 0;
    j = 0;
    while(ElRide(*Pout, i).Number != -1) {
        Ride elR;
        MakeRide(&elR, -1);
        ElRide(*Pout, i) = elR;
        i++;
    }
    while(ElRide(Pin,j).Number != -1) {
        ElRide(*Pout, j).symbol = ElRide(Pin, j).symbol;
        ElRide(*Pout, j).Price = ElRide(Pin, j).Price;
        ElRide(*Pout, j).Seat = ElRide(Pin, j).Seat;
        ElRide(*Pout, j).Duration = ElRide(Pin, j).Duration;
        ElRide(*Pout, j).Capacity = ElRide(Pin, j).Capacity;
        ElRide(*Pout, j).Number = ElRide(Pin, j).Number;
        ElRide(*Pout, j).Safe = ElRide(Pin, j).Safe;
        ElRide(*Pout, j).Location.X = ElRide(Pin, j).Location.X;
        ElRide(*Pout, j).Location.Y = ElRide(Pin, j).Location.Y;
        ElRide(*Pout, j).Upgrade = ElRide(Pin, j).Upgrade;
        ElRide(*Pout, j).Broken = ElRide(Pin, j).Broken;
        ElRide(*Pout, j).Count = ElRide(Pin, j).Count;
        ElRide(*Pout, j).Countdaily = ElRide(Pin, j).Countdaily;
        ElRide(*Pout, j).Income = ElRide(Pin, j).Income;
        ElRide(*Pout, j).Incomedaily = ElRide(Pin, j).Incomedaily;
        j++;
    }
    Tetangga(*Pout)[0] = Tetangga(Pin)[0]; 
    Tetangga(*Pout)[1] = Tetangga(Pin)[1]; 
}

void TukarPeta(Peta *P1, Peta *P2) {
    Peta P;
    MakeEmptyPeta(&P);
    CopyPeta(*P1, &P);
    CopyPeta(*P2, P1);
    CopyPeta(P, P2);
    free(P);
}

void TulisPeta(Peta P) 
{
	int i, j, n;
    MATRIKS M;
    POINT G1 = Gerbang1(P).lokasi;
    POINT G2 = Gerbang2(P).lokasi;
    POINT Of = Office(P).lokasi;
    POINT An = Antrean(P).lokasi;
    MakeMATRIKS(10, 20, &M);
    
    n = 0;
    while(ElRide(P, n).Number !=valundef) {
        n++;
    }
    
    FILE * file = fopen("map.txt", "r");
    for(i = 0; i <= 9; i++) {
    	fscanf(file, "%*[^;];");
        for(j = 0; j <= 19; j++) {
            fscanf(file, "%c", &Elmt(M, i, j));
        }
    }
    fclose(file);
    for(i=0; i<n; i++) {
        POINT B = ElRide(P,i).Location;
        Elmt(M, (int)Absis(B), (int)Ordinat(B)) = ElRide(P,i).symbol;
    }
    
    Elmt(M, (int)Absis(G1), (int)Ordinat(G1)) = Gerbang1(P).nilai;
    Elmt(M, (int)Absis(G2), (int)Ordinat(G2)) = Gerbang2(P).nilai;
    Elmt(M, (int)Absis(Of), (int)Ordinat(Of)) = Office(P).nilai;
    Elmt(M, (int)Absis(An), (int)Ordinat(An)) = Antrean(P).nilai;
    Elmt(M, (int)Absis(Pemain(P)), (int)Ordinat(Pemain(P))) = 'P';

    TulisMATRIKS(M);
    printf("\n");
}

void MovePemain(Peta *P, char input) {
    if(input=='W' || input=='w') {
        if(Absis(Pemain(*P))>1) {
            Absis(Pemain(*P))--;
        }
    }
    else if(input=='A' || input=='a') {
       if(Ordinat(Pemain(*P))>1) {
            Ordinat(Pemain(*P))--;
        }
    }
    else if(input=='S' || input=='s') {
        if(Absis(Pemain(*P))<8) {
            Absis(Pemain(*P))++;
        }
    }
    else if(input=='D' || input=='d') {
        if(Ordinat(Pemain(*P))<18) {
            Ordinat(Pemain(*P))++;
        }
    }
}

void TambahRide(Peta *P, Ride R) {
    int i=0;
    while(ElRide(*P, i).Number != -1) {
        i++;
    }  
    ElRide(*P,i) = R; 
}

boolean IsGoingUp(Peta P, char in) {
    if(in=='W' || in=='w') {
        float xp = Absis(Pemain(P))-1;
        float yp = Ordinat(Pemain(P));
        POINT pp = MakePOINT(xp,yp);
        return(EQPoint(pp, Gerbang1(P).lokasi) || EQPoint(pp, Gerbang2(P).lokasi));
    }
    else {
        return false;
    }
}

boolean IsGoingLeft(Peta P, char in) {
    if(in=='A' || in=='a') {
        float xp = Absis(Pemain(P));
        float yp = Ordinat(Pemain(P))-1;
        POINT pp = MakePOINT(xp,yp);
        return(EQPoint(pp, Gerbang1(P).lokasi) || EQPoint(pp, Gerbang2(P).lokasi));
    }
    else {
        return false;
    }
}

boolean IsGoingDown(Peta P, char in) {
    if(in=='S' || in=='s') {
        float xp = Absis(Pemain(P))+1;
        float yp = Ordinat(Pemain(P));
        POINT pp = MakePOINT(xp,yp);
        return(EQPoint(pp, Gerbang1(P).lokasi) || EQPoint(pp, Gerbang2(P).lokasi));
    }
    else {
        return false;
    }
    
}

boolean IsGoingRight(Peta P, char in) {
    if(in=='D' || in=='d') {
        float xp = Absis(Pemain(P));
        float yp = Ordinat(Pemain(P))+1;
        POINT pp = MakePOINT(xp,yp);
        return(EQPoint(pp, Gerbang1(P).lokasi) || EQPoint(pp, Gerbang2(P).lokasi));
    }
    else {
        return false;
    }
}

boolean IsPetaSama(Peta P1, Peta P2) {
	boolean sama;
	if (IsCurPeta1(PetaM)){
		TukarPeta(&PetaM, &Peta1);
		sama = IsCurPeta1(P2);
		TukarPeta(&PetaM, &Peta1);
	}
	else if (IsCurPeta2(PetaM)){
		TukarPeta(&PetaM, &Peta2);
		sama = IsCurPeta2(P2);;
		TukarPeta(&PetaM, &Peta2);
	}
	else if (IsCurPeta3(PetaM)){
		TukarPeta(&PetaM, &Peta3);
		sama = IsCurPeta3(P2);
		TukarPeta(&PetaM, &Peta3);
	}
	else if (IsCurPeta4(PetaM)){
		TukarPeta(&PetaM, &Peta4);
		sama = IsCurPeta4(P2);;
		TukarPeta(&PetaM, &Peta4);
	}
	return sama;	
}

boolean IsDekatAntrean(Peta P) {
    float a = Absis(Pemain(P));
    float b = Ordinat(Pemain(P));
    float c = Absis(Antrean(P).lokasi);
    float d = Ordinat(Antrean(P).lokasi);
    if(a==c) {
        return (b-d)==1||(d-b)==1;
    }
    else if(b==d) {
        return (a-c)==1||(c-a)==1;
    }
    else {
        return false;
    }
}

boolean IsDiOffice(Peta P) { 
    return EQPoint(Pemain(P), Office(P).lokasi);
}

Ride WahanaTerdekat(Peta P) {
    int i = 0;
    POINT Dwinta = Pemain(P);
    while(ElRide(P,i).Number!=-1) {
        POINT TitikRide = ElRide(P,i).Location;
        if(Dwinta.X == TitikRide.X) {
            if(Dwinta.Y+1==TitikRide.Y) {
                break;
            }
            else if(Dwinta.Y-1==TitikRide.Y){
                break;
            }
        }
        else if(Dwinta.Y == TitikRide.Y) {
            if(Dwinta.X+1==TitikRide.X) {
                break;
            }
            else if(Dwinta.X-1==TitikRide.X){
                break;
            }
        }
        i++;
    }
    if(i!=0) {
        return ElRide(P, i);
    }
    else {
        return ElRide(P, 0);
    }
}

boolean IsInputValid(char in) {
    return (in=='W' || in=='w' || in=='A' || in=='a' || in=='S' || in=='s' || in=='D' || in=='d');
}

boolean IsCurPeta1(Peta P) {
    return ((Gerbang1(P).nilai == '>' && Gerbang2(P).nilai == 'v') || (Gerbang1(P).nilai == 'v' && Gerbang2(P).nilai == '>'));
}

boolean IsCurPeta2(Peta P) {
    return ((Gerbang1(P).nilai == '<' && Gerbang2(P).nilai == 'v') || (Gerbang1(P).nilai == 'v' && Gerbang2(P).nilai == '<'));
}

boolean IsCurPeta3(Peta P) {
    return ((Gerbang1(P).nilai == '<' && Gerbang2(P).nilai == '^') || (Gerbang1(P).nilai == '^' && Gerbang2(P).nilai == '<'));
}

boolean IsCurPeta4(Peta P) {
    return ((Gerbang1(P).nilai == '>' && Gerbang2(P).nilai == '^') || (Gerbang1(P).nilai == '^' && Gerbang2(P).nilai == '>'));
}

void PindahPeta(Peta *P, char in) {
    if(IsCurPeta1(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, &Peta1);
            TukarPeta(P, &Tetangga(Peta1)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &Peta1);
            TukarPeta(P, &Tetangga(Peta1)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta2(*P)) {
        if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &Peta2);
            TukarPeta(P, &Tetangga(Peta2)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &Peta2);
            TukarPeta(P, &Tetangga(Peta2)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta3(*P)) {
        if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &Peta3);
            TukarPeta(P, &Tetangga(Peta3)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
        else if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &Peta3);
            TukarPeta(P, &Tetangga(Peta3)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
    }
    else if(IsCurPeta4(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, &Peta4);
            TukarPeta(P, &Tetangga(Peta4)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &Peta4);
            TukarPeta(P, &Tetangga(Peta4)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
} 

void DisplayPeta() {
    int i = 0;
    boolean isLokasiSama = false;
    char go;
    //Algoritma Utama Gerak dan Pindah Peta
    PindahPeta(&PetaM, CKata.TabKata[0]);
    MovePemain(&PetaM, CKata.TabKata[0]);
    while(ElRide(PetaM,i).Number != -1) {
        if(EQPoint(ElRide(PetaM,i).Location, Pemain(PetaM))) {
            isLokasiSama = true;
        }
        i++;
    }
    if(isLokasiSama) {
        if(CKata.TabKata[0]=='W' || CKata.TabKata[0]=='w') {
            go = 's';
            MovePemain(&PetaM, go);
        }
        else if(CKata.TabKata[0]=='A' || CKata.TabKata[0]=='a') {
            go = 'd';
            MovePemain(&PetaM, go);
        }
        else if(CKata.TabKata[0]=='S' || CKata.TabKata[0]=='s') {
            go = 'w';
            MovePemain(&PetaM, go);
        }
        else if(CKata.TabKata[0]=='D' || CKata.TabKata[0]=='d') {
            go = 'a';
            MovePemain(&PetaM, go);
        }
    }
}

void SetPeta(){
    /* Menginisialisasi peta-peta */
	MakeEmptyPeta(&PetaM);
	MakeEmptyPeta(&Peta1); // Peta 1, kiri atas
    MakeEmptyPeta(&Peta2); // Peta 2, kanan atas
    MakeEmptyPeta(&Peta3); // Peta 3, kanan bawah
    MakeEmptyPeta(&Peta4); // Peta 4, kiri bawah

    //Peta 1
    POINT A = MakePOINT(5,5);
    POINT F = MakePOINT(9,5);
    POINT G = MakePOINT(5,19);
    
    B5.lokasi = F;
    B5.nilai = 'v';
    B6.lokasi = G;
    B6.nilai = '>';
    
    Pemain(Peta1) = A;
    Gerbang1(Peta1) = B5;
    Gerbang2(Peta1) = B6;
    Tetangga(Peta1)[0] = Peta2;
    Tetangga(Peta1)[1] = Peta4;
    
    //Peta 2
	POINT H = MakePOINT(5,5);
    POINT K = MakePOINT(9,4);
    POINT L = MakePOINT(5,0);

    C5.lokasi = K;
    C5.nilai = 'v';
    C6.lokasi = L;
    C6.nilai = '<';
    
    Pemain(Peta2) = H;
    Gerbang1(Peta2) = C5;
    Gerbang2(Peta2) = C6;
    Tetangga(Peta2)[0] = Peta1;
    Tetangga(Peta2)[1] = Peta3;

    //Peta 3 
    
    POINT M = MakePOINT(5,5);
    POINT R = MakePOINT(0,4);
    POINT Q = MakePOINT(8,0);
    
    D5.lokasi = R;
    D5.nilai = '^';
    D6.lokasi = Q;
    D6.nilai = '<';

    Gerbang1(Peta3) = D5;
    Gerbang2(Peta3) = D6;
    Pemain(Peta3) = M;
    Tetangga(Peta3)[0] = Peta2;
    Tetangga(Peta3)[1] = Peta4;

    //Peta 4
    POINT S = MakePOINT(5,5);
    POINT V = MakePOINT(0,5);
    POINT W = MakePOINT(8,19);
    
    E5.lokasi = V;
    E5.nilai = '^';
    E6.lokasi = W;
    E6.nilai = '>';
  
    Gerbang1(Peta4) = E5;
    Gerbang2(Peta4) = E6;
    Pemain(Peta4) = S;
    Tetangga(Peta4)[0] = Peta1;
    Tetangga(Peta4)[1] = Peta3;
    
    TukarPeta(&PetaM, &Peta1);
}
