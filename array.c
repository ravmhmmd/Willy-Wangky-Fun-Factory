#include "array.h"
#include <stdio.h>
TabBahan ArrBahan;
TabAksi ArrAksi;

int totalBahan[3] = {0, 0, 0};
int CurrentBahan[3] = {5000, 5000, 5000};

void SetAksi()
{
	TabAksiName(ArrAksi, 0) = "Build";
	TabAksiName(ArrAksi, 1) = "Upgrade";
	TabAksiName(ArrAksi, 2) = "Buy";
	TabAksiDuration(ArrAksi, 0) = 13500;
	TabAksiDuration(ArrAksi, 1) = 10800;
	TabAksiDuration(ArrAksi, 2) = 3600;
}


void SetBahan()
{
	int i;
	FILE * file = fopen("material.txt", "r");
	
	for (i = 0; i < 3; i++){
		fscanf(file, "\n%[^:]:%d;", TabBahanName(ArrBahan, i), &TabBahanCost(ArrBahan, i));
	}
	fclose(file);
}
