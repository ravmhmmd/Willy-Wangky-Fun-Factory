/* File: mesintoken.h */
/* Implementasi Mesin Token: Model Akuisisi Versi I */
/* Nama: Rafi Naufal Aziz
   NIM: 10119057 */

#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
	/* Kamus */
	/* Algoritma */
	START();
	if (CC == MARK) {
		EndToken = true;
	}
	else {
		EndToken = false;
		SalinToken();
	}
	
}

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* Kamus */
	/* Algoritma */
	if (CC == MARK){
		EndToken = true;
	}
	else {
		SalinToken();
		if (CC == MARK){
			EndToken = true;
		}
	}

}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* Kamus */
	int i, num, ans;
	/* Algoritma */
	i = 0; num = 0; ans = 0;
	if (CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^'){
		CToken.tkn = CC;
		CToken.val = -1;
	}
	else {
		CToken.tkn = 'b';
		while ( (CC != MARK) && (CC != BLANK) && (i < NMax)){
			num = CC - '0';
			ans = (ans*10) + num;
			ADV();
			i++;
		}
		CToken.val = ans;
	}
}
