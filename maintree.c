#include <stdio.h>
#include "tree.c"

int main(){
	
	/* Inisialisasi Binary Tree buat upgrade wahana 1, 2, dst. */
	SetUpgrade();
	
	/* U1: Pohon upgrade rollercoaster, U2: Pohon upgrade bungee jump, dst. */
	
	/* Akar(P) adalah ADT infoUpgrade */
	/* Jadi, cara mengakses atributnya (nama, harga, dll) pake selektor (upName, upPrice, dll) */
	/* Contoh cara mengakses nama P: upName(Akar(P))
	
	/* Akses nama bangunan dari wahana pertama rollercoaster (tanpa upgrade)*/
	printf("%s\n", upName(Akar(U1)));
	
	/* GetTree(P, K) mengembalikan BinTree dengan kode wahana K */
	/* Contoh untuk mengakses infoUpgrade untuk kode rollercoaster 11: Akar(GetTree(U1, 11)) */
	
	/* Akses nama bangunan dari wahana rollercoaster upgrade kode: 112 */
	printf("%s\n", upName(Akar(GetTree(U1, 112))));
	
	/* Akses harga wahana dari haunted house upgrade kode: 51 */
	printf("%d\n", upPrice(Akar(GetTree(U5, 51))));
	
	
	return 0;
}
