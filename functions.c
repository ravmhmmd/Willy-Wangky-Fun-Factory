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
            CopyPeta(*P, &P1);
            TukarPeta(P, &Tetangga(P1)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &P1);
            TukarPeta(P, &Tetangga(P1)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta2(*P)) {
        if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &P2);
            TukarPeta(P, &Tetangga(P2)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &P2);
            TukarPeta(P, &Tetangga(P2)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta3(*P)) {
        if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &P3);
            TukarPeta(P, &Tetangga(P3)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
        else if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &P3);
            TukarPeta(P, &Tetangga(P3)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
    }
    else if(IsCurPeta4(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, &P4);
            TukarPeta(P, &Tetangga(P4)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &P4);
            TukarPeta(P, &Tetangga(P4)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
} 

void DisplayPeta() {
    //Algoritma Utama Gerak dan Pindah Peta
    PindahPeta(&P, CKata.TabKata[0]);
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
    
    B1.lokasi = B;
    B1.nilai = 'O';
    B2.lokasi = C;
    B2.nilai = 'W';
    B5.lokasi = F;
    B5.nilai = 'v';
    B6.lokasi = G;
    B6.nilai = '>';
    

    ElBangunan(P1,0) = B1;
    ElBangunan(P1,1) = B2;
    Pemain(P1) = A;
    Gerbang1(P1) = B5;
    Gerbang2(P1) = B6;
    Tetangga(P1)[0] = P2;
    Tetangga(P1)[1] = P4;
    
    //Peta 2 (Atas kanan)
	POINT H = MakePOINT(5,5);
    POINT I = MakePOINT(3,1);
    POINT J = MakePOINT(6,5);
    POINT K = MakePOINT(9,4);
    POINT L = MakePOINT(5,0);
    
    C1.lokasi = I;
    C1.nilai = 'A';
    C2.lokasi = J;
    C2.nilai = 'W';
    C5.lokasi = K;
    C5.nilai = 'v';
    C6.lokasi = L;
    C6.nilai = '<';
    

    ElBangunan(P2,0) = C1;
    ElBangunan(P2,1) = C2;
    Pemain(P2) = H;
    Gerbang1(P2) = C5;
    Gerbang2(P2) = C6;
    Tetangga(P2)[0] = P1;
    Tetangga(P2)[1] = P3;

    //Peta 3 (Bawah kanan)
    
    POINT M = MakePOINT(5,5);
    POINT N = MakePOINT(6,7);
    POINT O = MakePOINT(8,3);
    POINT R = MakePOINT(0,4);
    POINT Q = MakePOINT(8,0);
    
    D1.lokasi = N;
    D1.nilai = 'N';
    D2.lokasi = O;
    D2.nilai = 'A';
    D5.lokasi = R;
    D5.nilai = '^';
    D6.lokasi = Q;
    D6.nilai = '<';
    

    ElBangunan(P3,0) = D1;
    ElBangunan(P3,1) = D2;
    Gerbang1(P3) = D5;
    Gerbang2(P3) = D6;
    Pemain(P3) = M;
    Tetangga(P3)[0] = P2;
    Tetangga(P3)[1] = P4;

    //Peta 4 (Kiri bawah)
    POINT S = MakePOINT(5,5);
    POINT T = MakePOINT(6,7);
    POINT U = MakePOINT(8,3);
    POINT V = MakePOINT(0,5);
    POINT W = MakePOINT(8,19);
    
    E1.lokasi = T;
    E1.nilai = 'N';
    E2.lokasi = U;
    E2.nilai = 'A';
    E5.lokasi = V;
    E5.nilai = '^';
    E6.lokasi = W;
    E6.nilai = '>';
    

    ElBangunan(P4,0) = E1;
    ElBangunan(P4,1) = E2;
    Gerbang1(P4) = E5;
    Gerbang2(P4) = E6;
    Pemain(P4) = S;
    Tetangga(P4)[0] = P1;
    Tetangga(P4)[1] = P3;
    
    TukarPeta(&P, &P1);
}

/*
void PindahPeta(Peta *P, char in) {
    if(IsCurPeta1(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, &P1);
            TukarPeta(P, &Tetangga(P1)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &P1);
            TukarPeta(P, &Tetangga(P1)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta2(*P)) {
        if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &P2);
            TukarPeta(P, &Tetangga(P2)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
        else if(IsGoingDown(*P, in)) {
            CopyPeta(*P, &P2);
            TukarPeta(P, &Tetangga(P2)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//+1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
    else if(IsCurPeta3(*P)) {
        if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &P3);
            TukarPeta(P, &Tetangga(P3)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
        else if(IsGoingLeft(*P, in)) {
            CopyPeta(*P, &P3);
            TukarPeta(P, &Tetangga(P3)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//-1;
        }
    }
    else if(IsCurPeta4(*P)) {
        if(IsGoingRight(*P, in)) {
            CopyPeta(*P, &P4);
            TukarPeta(P, &Tetangga(P4)[1]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang2(*P).lokasi);
            Ordinat(Pemain(*P)) = Ordinat(Gerbang2(*P).lokasi);//+1;
        }
        else if(IsGoingUp(*P, in)) {
            CopyPeta(*P, &P4);
            TukarPeta(P, &Tetangga(P4)[0]);
            //pindahin lokasi pemain ke depan gerbang.
            Absis(Pemain(*P)) = Absis(Gerbang1(*P).lokasi);//-1;
            Ordinat(Pemain(*P)) = Ordinat(Gerbang1(*P).lokasi);
        }
    }
} 
*/