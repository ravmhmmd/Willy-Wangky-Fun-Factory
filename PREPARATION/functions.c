#include <stdio.h>
#include "functions.h"
#include "mesinkata.h"

Peta P1,P2,P3,P4;
Peta P;

Bangunan B1, B2, B5, B6;
Bangunan C1, C2, C5, C6;
Bangunan D1, D2, D5, D6;
Bangunan E1, E2, E5, E6;

boolean IsInputValid(char in) {
    return (in=='W' || in=='w' || in=='A' || in=='a' || in=='S' || in=='s' || in=='D' || in=='d');
}

boolean IsCurPeta1(Peta P) {
    return ((Gerbang1(P).value == '>' && Gerbang2(P).value == 'v') || (Gerbang1(P).value == 'v' && Gerbang2(P).value == '>'));
}

boolean IsCurPeta2(Peta P) {
    return ((Gerbang1(P).value == '<' && Gerbang2(P).value == 'v') || (Gerbang1(P).value == 'v' && Gerbang2(P).value == '<'));
}

boolean IsCurPeta3(Peta P) {
    return ((Gerbang1(P).value == '<' && Gerbang2(P).value == '^') || (Gerbang1(P).value == '^' && Gerbang2(P).value == '<'));
}

boolean IsCurPeta4(Peta P) {
    return ((Gerbang1(P).value == '>' && Gerbang2(P).value == '^') || (Gerbang1(P).value == '^' && Gerbang2(P).value == '>'));
}

void PindahPeta(Peta *P, Peta *P1, Peta *P2, Peta *P3, Peta *P4, char in) {
    if(IsCurPeta1(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, P1);
            TukarPeta(P, P2);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).adress);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).adress);//+1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, P1);
            TukarPeta(P, P4);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).adress);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).adress);
        }
    }
    else if(IsCurPeta2(*P)) {
        if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, P2);
            TukarPeta(P, P1);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).adress);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).adress);//-1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, P2);
            TukarPeta(P, P3);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).adress);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).adress);
        }
    }
    else if(IsCurPeta3(*P)) {
        if(IsGoingUp(*P, in)) {
            CopyPeta(*P, P3);
            TukarPeta(P, P2);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).adress);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).adress);
        }
        else if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, P3);
            TukarPeta(P, P4);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).adress);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).adress);//-1;
        }
    }
    else if(IsCurPeta4(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, P4);
            TukarPeta(P, P3);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).adress);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).adress);//+1;
        }
        else if(IsGoingUp(*P, in)) {
            CopyPeta(*P, P4);
            TukarPeta(P, P1);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).adress);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).adress);
        }
    }
}

void DisplayPeta() {


    //Algoritma Utama Gerak dan Pindah Peta
    PindahPeta(&P, &P1, &P2, &P3, &P4, CKata.TabKata[0]);
    MovePemain(&P, CKata.TabKata[0]);

}

void SetPeta(){
	MakeEmptyPeta(&P);
	MakeEmptyPeta(&P1);
    MakeEmptyPeta(&P2);
    MakeEmptyPeta(&P3);
    MakeEmptyPeta(&P4);

    //Peta 1 (Atas Kiri)
    POINT A = MakePOINT(5,5);
    POINT B = MakePOINT(2,2);
    POINT C = MakePOINT(1,3);
    POINT F = MakePOINT(9,5);
    POINT G = MakePOINT(5,19);
    
    B1.adress = B;
    B1.value = 'O';
    B2.adress = C;
    B2.value = 'W';
    B5.adress = F;
    B5.value = 'v';
    B6.adress = G;
    B6.value = '>';
    

    ElBangunan(P1,0) = B1;
    ElBangunan(P1,1) = B2;
    Pemain(P1) = A;
    Gerbang1(P1) = B5;
    Gerbang2(P1) = B6;
    
    //Peta 2 (Atas kanan)
	POINT H = MakePOINT(5,5);
    POINT I = MakePOINT(3,1);
    POINT J = MakePOINT(6,5);
    POINT K = MakePOINT(9,4);
    POINT L = MakePOINT(5,0);
    
    C1.adress = I;
    C1.value = 'A';
    C2.adress = J;
    C2.value = 'W';
    C5.adress = K;
    C5.value = 'v';
    C6.adress = L;
    C6.value = '<';
    

    ElBangunan(P2,0) = C1;
    ElBangunan(P2,1) = C2;
    Pemain(P2) = H;
    Gerbang1(P2) = C5;
    Gerbang2(P2) = C6;

    //Peta 3 (Bawah kanan)
    
    POINT M = MakePOINT(5,5);
    POINT N = MakePOINT(6,7);
    POINT O = MakePOINT(8,3);
    POINT R = MakePOINT(0,4);
    POINT Q = MakePOINT(8,0);
    
    D1.adress = N;
    D1.value = 'N';
    D2.adress = O;
    D2.value = 'A';
    D5.adress = R;
    D5.value = '^';
    D6.adress = Q;
    D6.value = '<';
    

    ElBangunan(P3,0) = D1;
    ElBangunan(P3,1) = D2;
    Gerbang1(P3) = D5;
    Gerbang2(P3) = D6;
    Pemain(P3) = M;

    //Peta 4 (Kiri bawah)
    POINT S = MakePOINT(5,5);
    POINT T = MakePOINT(6,7);
    POINT U = MakePOINT(8,3);
    POINT V = MakePOINT(0,5);
    POINT W = MakePOINT(8,19);
    
    E1.adress = T;
    E1.value = 'N';
    E2.adress = U;
    E2.value = 'A';
    E5.adress = V;
    E5.value = '^';
    E6.adress = W;
    E6.value = '>';
    

    ElBangunan(P4,0) = E1;
    ElBangunan(P4,1) = E2;
    Gerbang1(P4) = E5;
    Gerbang2(P4) = E6;
    Pemain(P4) = S;
    
    TukarPeta(&P, &P1);
}
