#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "boolean.h"
#include "matriks.h"
#include "point.h"
#include "peta.h"

extern Peta P1,P2,P3,P4;
extern Peta P;
extern Bangunan B1, B2, B5, B6;
extern Bangunan C1, C2, C5, C6;
extern Bangunan D1, D2, D5, D6;
extern Bangunan E1, E2, E5, E6;

boolean IsInputValid(char in);
boolean IsCurPeta1(Peta P);
boolean IsCurPeta2(Peta P);
boolean IsCurPeta3(Peta P);
boolean IsCurPeta4(Peta P);
void PindahPeta(Peta *P, Peta *P1, Peta *P2, Peta *P3, Peta *P4, char in);
void DisplayPeta();
void SetPeta();

#endif
