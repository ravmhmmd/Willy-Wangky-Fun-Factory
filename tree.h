/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */

#ifndef _TREE_H_
#define _TREE_H_

#include "boolean.h"
#include "ride.h"

#define Nil NULL

typedef int UpgradeNo;
typedef struct
{
	UpgradeNo Number;
	char Name[30];
	char Desk[50];
	int UpBCost[3];
	int Price;
	int Capacity;	
} infoUpgrade;

typedef struct tNodetree *addrNode;
typedef struct tNodetree
{
  infoUpgrade info;
  addrNode left;
  addrNode right;
} treeNode;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

extern BinTree U1, U2, U3, U4, U5;

/* *** Selektor *** */
/* Selektor node */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* Selektor info */
#define upNumber(U) (U).Number
#define upName(U) (U).Name
#define upDesk(U) (U).Desk
#define upBCost(U, i) (U).UpBCost[(i)]
#define upPrice(U) (U).Price
#define upCapacity(U) (U).Capacity

/* *** Konstruktor *** */
void MakeTree(UpgradeNo No, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
		
void MakeUpgrade(infoUpgrade *U, UpgradeNo X);

void MakeUpgradeTree(BinTree *P, UpgradeNo X);

void CopyNode(BinTree *P1, BinTree *P2);
		
/* Manajemen Memory */
addrNode AlokNode(UpgradeNo X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
BinTree GetTree(BinTree P, UpgradeNo X);

boolean SearchTree(BinTree P, UpgradeNo X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

void SetUpgrade();

BinTree LeftorRight(BinTree P, int x);

void PrintTree(BinTree P, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

#endif
