/* File: jam.c */
/* Body ADT jam */
/* Nama   : Mohammad Dwinta Harits Cahyana
   NIM    : 13519041
   Tanggal: 02 September 2020 */
#include <stdio.h>
#include "math.h"
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P1;
    Absis(P1) = X;
    Ordinat(P1) = Y;

    return P1;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    float x; float y;
    scanf("%f %f", &x, &y);

    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    float x = Absis(P); 
    float y = Ordinat(P);

    printf ("(%.2f,%.2f)", x, y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return(Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}
boolean NEQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return !(Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return ((Absis(P) == 0)&&(Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P) == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    if ((Absis(P)>0) && (Ordinat(P)>0)){
        return 1;
        }
    else if ((Absis(P)<0) && (Ordinat(P)>0)){
        return 2;
        }
    else if ((Absis(P))<0 && (Ordinat(P)<0)){
        return 3;
        }
    else // Absis(P)>0 && Ordinat(P)<0
        {
        return 4;
        }    
}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
    POINT newP;
    Absis(newP) = Absis(P) + 1;
    Ordinat(newP) = Ordinat(P);
    
    return newP;
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    POINT newP;
    Absis(newP) = Absis(P);
    Ordinat(newP) = Ordinat(P) + 1;
    
    return newP;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    Absis(P) = Absis(P)+deltaX;
    Ordinat(P) = Ordinat(P)+deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    POINT newP;
    float x = Absis(P);
    float y = Ordinat(P);

    if(SbX == true){
        Absis(newP) = x;
        Ordinat(newP) = -y;
    }
    else //SbX == false
    {
       Absis(newP) = -x;
       Ordinat(newP) = y; 
    }
    return newP;
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    float bedax = Absis(P1)-Absis(P2);
    float beday = Ordinat(P1) - Ordinat(P2);
    return sqrt(bedax*bedax + beday*beday);
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    POINT newP;
    newP = *P;
    *P =PlusDelta(newP, deltaX, deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    *P = MirrorOf (*P, SbX);
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
{
    Sudut = (Sudut/180)*acos(-1); // mengubah sudut ke satuan radian. 
    *P = MakePOINT(((cos(Sudut))*(Absis(*P)))-((sin(Sudut))*(Ordinat(*P))), (((cos(Sudut))*Ordinat(*P)))+((sin(Sudut))*(Absis(*P))));
}
