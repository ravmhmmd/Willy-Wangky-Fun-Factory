#include <stdio.h>
#include "string.h"
#include "bahan.h"

TabBahan ArrBahan;

int totalBahan[3] = {0, 0, 0};
int CurrentBahan[3] = {5000, 5000, 5000};


void SetBahan()
{
	int i;
	FILE * file = fopen("material.txt", "r");
	
	for (i = 0; i < 3; i++){
		fscanf(file, "\n%[^:]:%d;", TabBahanName(ArrBahan, i), &TabBahanCost(ArrBahan, i));
	}
	fclose(file);
}
