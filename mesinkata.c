/* File: mesinkata.h */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */
/* Rafi Naufal Aziz / 10119057 */

#include "boolean.h"
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	/* Kamus */
	/* Algoritma */
	while (CC == BLANK){
		ADV();
	}
	
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* Kamus */
	/* Algoritma */
	START();
	if (CC == MARK) {
		EndKata = true;
	}
	else {
		EndKata = false;
		SalinKata();
	}
	
}


void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* Kamus */
	/* Algoritma */
	IgnoreBlank();
	if (CC == MARK){
		EndKata = true;
	}
	else {
		SalinKata();
		IgnoreBlank();
		if (CC == MARK){
			EndKata = true;
		}
	}

}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* Kamus */
	int i;
	/* Algoritma */
	i = 0;
	while ( (CC != MARK) && (i < NMax)){
		CKata.TabKata[i] = CC;
		ADV();
		i++;
	}
	while ((CC != MARK)){
		ADV();
	}
	CKata.Length = i;

}

void SaveKata(Kata *K)
{
	/* Kamus */
	int i;
	/* Algoritma */
	(*K).Length = CKata.Length;
	for (i = 0; i < CKata.Length; i++){
		(*K).TabKata[i] = CKata.TabKata[i];
	}
}

void PrintKata(Kata K)
{
	/* Kamus */
	int i;
	/* Algoritma */
	for (i = 0; i < K.Length; i++){
		printf("%c", K.TabKata[i]);
	}
	printf("\n");
}

boolean IsKataEQStr(Kata K, char arr[])
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	/* Kamus */
	int i, j;
	/* Algoritma */
	for (j = 0; arr[j] != '\0'; ++j);
	if (K.Length == j){
		for (i = 0; i < K.Length; i++){
			if (K.TabKata[i] != arr[i]){
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}
