#include <stdio.h>
#include "ride.h"
#include "customer.h"
#include "prioqueue.h"


int main() {
	/* Kamus */
	Customer C1, C2, C3, C4, C5;
	Queue Q;
	
	/* Algoritma */
	MakeRandomCust(&C1); MakeRandomCust(&C2); MakeRandomCust(&C3); MakeRandomCust(&C4), MakeRandomCust(&C5);
	MakeEmptyQueue(&Q);
	
	Enqueue(&Q, C1); Enqueue(&Q, C2); Enqueue(&Q, C3); Enqueue(&Q, C4); Enqueue(&Q, C5);
	
	PrintAntrean(Q); printf("\n");
	return 0;
}

// Compile: gcc -Wall customer.c ride.c mainride.c -o [NAMAFILE]
// Run: ./[NAMAFILE]
