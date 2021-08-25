#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinTree U1, U2, U3, U4, U5;

/* *** Konstruktor *** */
void MakeTree(RideNo No, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
	/* Kamus */
	/* Algoritma */
	*P = AlokNode(No);
	if (*P != Nil){
		Left(*P) = L;
		Right(*P) = R;
	}
}

void MakeUpgrade(infoUpgrade *U, UpgradeNo X)
{
	/* Kamus */
	UpgradeNo No;
	/* Algoritma */
	FILE * file = fopen("wahana.txt", "r");
	fscanf(file, "\n%d,", &No);
	while (X != No){
		fscanf(file, "%*[^;];");
		fscanf(file, "\n%d,", &No);
	}
	fscanf(file, "%[^:]:%d,[%d,%d,%d],%d,%[^;];", upName(*U), &upPrice(*U), &upBCost(*U, 0), \
	&upBCost(*U, 1), &upBCost(*U, 2), &upCapacity(*U), upDesk(*U));
	fclose(file);
}

void MakeUpgradeTree(BinTree *P, UpgradeNo X)
{
	/* Kamus */
	addrNode L, R;
	infoUpgrade UP;
	/* Algoritma */
	if (X >= 1000){
		*P = Nil;
	}
	else{
		MakeUpgradeTree(&L, (X*10 + 1)); MakeUpgradeTree(&R, (X*10 + 2));
		MakeTree(X, L, R, P);
		MakeUpgrade(&Akar(*P), X);
	}
	
}
void CopyNode(BinTree *P1, BinTree *P2)
{
	
}

/* Manajemen Memory */
addrNode AlokNode(RideNo X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus */
	addrNode P;
	/* Algoritma */
	P = (treeNode*) malloc(sizeof(treeNode));
	if (P != Nil){
		upNumber(Akar(P)) = X;
		Left(P) = Nil;
		Right(P) = Nil;
		return P;
	}
	else{
		return Nil;
	}
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
	/* Kamus */
	/* Algoritma */
	free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	/* Kamus */
	/* Algoritma */
	return (P == Nil);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
	/* Kamus */
	/* Algoritma */
	if (!IsTreeEmpty(P)){
		return ((Left(P) == Nil) && Right(P) == Nil);
	}
	else{
		return false;
	}
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
	/* Kamus */
	/* Algoritma */
	if (!IsTreeEmpty(P)){
		return ((Left(P) != Nil) && Right(P) != Nil);
	}
	else{
		return false;
	}
}

BinTree GetTree(BinTree P, UpgradeNo X)
{
	/* Kamus */
	/* Algoritma */
	if (IsTreeEmpty(P)){
		return Nil;
	}
	else{
		if (upNumber(Akar(P)) == X){
			return P;
		}
		else if (SearchTree(Left(P), X)){
			return (GetTree(Left(P), X));
		}
		else{
			return (GetTree(Right(P), X));
		}
	}
	
}

boolean SearchTree(BinTree P, UpgradeNo X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	/* Kamus */
	/* Algoritma */
	if (IsTreeOneElmt(P)){
		return (upNumber(Akar(P)) == X);
	}
	else{
		if (IsTreeEmpty(P)){
			return false;
		}
		else if (upNumber(Akar(P)) == X){
			return true;
		}
		else{
			return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
		}
	}
}

void SetUpgrade()
{
	/* Kamus */
	/* Algoritma */
	MakeUpgradeTree(&U1, 1); MakeUpgradeTree(&U2, 2); MakeUpgradeTree(&U3, 3); MakeUpgradeTree(&U4, 4); MakeUpgradeTree(&U5, 5);
}

BinTree LeftorRight(BinTree P, int x)
{
	/* Kamus */
	/* Algoritma */
	if (x == 1){
		return Left(P);
	}
	else{
		return Right(P);
	}
}

void PrintTree(BinTree P, int h)
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
{
	/* Kamus */
	int i;
	/* Algoritma */
	if (IsTreeEmpty(P)){
	}
	else{
		printf("%s", upName(Akar(P)));
		if (!IsTreeEmpty(Left(P))){
			printf("\n");
			for (i = 0; i < h; i++){
				printf(" ");
			}
			PrintTree(Left(P), 2*h);
		}
		if (!IsTreeEmpty(Right(P))){
			printf("\n");
			for (i = 0; i < h; i++){
				printf(" ");
			}
			PrintTree(Right(P), 2*h);
		}
	}
}
