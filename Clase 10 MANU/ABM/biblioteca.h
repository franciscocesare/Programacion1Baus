#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include "alumno.h"

int getIntRange(int* number, char* message,char* messageError,int lowLimit, int hiLimit);
int getFloat(float* number, char* message,char* messageError,float lowLimit, float hiLimit);
int getCharSex(char* input,char* message,char* messageError, char lowLimit, char hiLimit);
int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit, int attempts);
int comparaFecha(eFecha f1, eFecha f2);

#endif // BIBLIOTECA_H_INCLUDED
