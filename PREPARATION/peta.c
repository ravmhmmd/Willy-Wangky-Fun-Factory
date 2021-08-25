#include <stdio.h>
#include "peta.h"

void MakeEmptyPeta(Peta *P) {
	int i;
    Pemain(*P) = MakePOINT(valundef, valundef);
    Gerbang1(*P).adress = MakePOINT(valundef, valundef);
    Gerbang1(*P).value = charundef;
    Gerbang2(*P).adress = MakePOINT(valundef, valundef);
    Gerbang2(*P).value = charundef;
    for(i=0; i<IdxMax; i++) {
        ElBangunan(*P, i).adress = MakePOINT(valundef, valundef);
        ElBangunan(*P, i).value = charundef;
    }
}

void CopyPeta(Peta Pin, Peta *Pout) {
    Pemain(*Pout) = Pemain(Pin);
    Gerbang1(*Pout) = Gerbang1(Pin);
    Gerbang2(*Pout) = Gerbang2(Pin);
    int i = 0;
    while(ElBangunan(Pin,i).value != charundef) {
        ElBangunan(*Pout, i).adress.X = ElBangunan(Pin, i).adress.X;
        ElBangunan(*Pout, i).adress.Y = ElBangunan(Pin, i).adress.Y;
        ElBangunan(*Pout, i).value = ElBangunan(Pin, i).value;
        i++;
    }
}

void TukarPeta(Peta *P1, Peta *P2) {
    Peta P;
    MakeEmptyPeta(&P);
    CopyPeta(*P1, &P);
    CopyPeta(*P2, P1);
    CopyPeta(P, P2);
}

void TulisPeta(Peta P) 
{
	int i, j;
    MATRIKS M;
    POINT G1 = Gerbang1(P).adress;
    POINT G2 = Gerbang2(P).adress;
    MakeMATRIKS(10, 20, &M);
    int n = sizeof(P.TabBangunan)/sizeof(P.TabBangunan[0]);
    for(i = 0; i <= 9; i++) {
        for(j = 0; j <= 19; j++) {
            if(i==0 || i==9 || j==0 || j==19) {
                Elmt(M, i, j) = '*';
            }
            else {
                Elmt(M, i, j) = '-';
            }
        }
    }
    for(i=0; i<n; i++) {
        POINT B = ElBangunan(P,i).adress;
        Elmt(M, (int)Absis(B), (int)Ordinat(B)) = ElBangunan(P,i).value;
    }
    
    Elmt(M, (int)Absis(Pemain(P)), (int)Ordinat(Pemain(P))) = 'P';
    Elmt(M, (int)Absis(G1), (int)Ordinat(G1)) = Gerbang1(P).value;
    Elmt(M, (int)Absis(G2), (int)Ordinat(G2)) = Gerbang2(P).value;

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

boolean IsGoingUp(Peta P, char in) {
    if(in=='W' || in=='w') {
        float xp = Absis(Pemain(P))-1;
        float yp = Ordinat(Pemain(P));
        POINT pp = MakePOINT(xp,yp);
        return(EQPoint(pp, Gerbang1(P).adress) || EQPoint(pp, Gerbang2(P).adress));
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
        return(EQPoint(pp, Gerbang1(P).adress) || EQPoint(pp, Gerbang2(P).adress));
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
        return(EQPoint(pp, Gerbang1(P).adress) || EQPoint(pp, Gerbang2(P).adress));
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
        return(EQPoint(pp, Gerbang1(P).adress) || EQPoint(pp, Gerbang2(P).adress));
    }
    else {
        return false;
    }
}
