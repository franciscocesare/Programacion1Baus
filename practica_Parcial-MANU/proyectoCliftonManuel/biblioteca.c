
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "biblioteca.h"

int getIntRange(int* number, char* message,char* messageError,int lowLimit, int hiLimit){

    char aux[10];
    int numeroValido;
    int num;
    int todoOk = 0;
    printf("%s", message);
    fflush(stdin);
    scanf("%s", aux);
    numeroValido = validarNumero(aux);
    num = atoi(aux);

        while( (numeroValido == 0) || (num < lowLimit || num > hiLimit) ){

            printf("%s", messageError);
            fflush(stdin);
            //scanf("%d", &aux);
            scanf("%s", aux);
            numeroValido = validarNumero(aux);
            num = atoi(aux);
        }
        if(num >= lowLimit && num <= hiLimit ){

            *number = atoi(aux);
            todoOk = 1;
        }
        return todoOk;
}





int getInt(int* number, char* message,char* messageError){

    char aux[10];
    int numeroValido;
    int num;
    int todoOk = 0;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", aux);
    numeroValido = validarNumero(aux);
    num = atoi(aux);

        while(numeroValido == 0){

            printf("%s", messageError);
            fflush(stdin);
            //scanf("%d", &aux);
            scanf("%s", aux);
            numeroValido = validarNumero(aux);
            num = atoi(aux);
        }
        if(num){
            *number = atoi(aux);
            todoOk = 1;
        }
        return todoOk;
}









int validarNumero(char num[]){
    int res = 1;
    for(int i=0; i<strlen(num); i++){
        if( !(isdigit(num[i])) ){
            res = 0;
        }
    }
    return res;
}

int getIntCarrera(int* number, char* message,char* messageError,int lowLimit, int mediumLimit, int hiLimit){

    char aux[10];
    int numeroValido;
    int num;
    int todoOk = 0;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", aux);
    num = validarNumero(aux);
    numeroValido = atoi(aux);

        while( (num == 0) || (numeroValido != lowLimit && numeroValido != mediumLimit && numeroValido != hiLimit) ){

            printf("%s", messageError);
            fflush(stdin);
            //scanf("%d", &aux);
            scanf("%s", aux);
            num = validarNumero(aux);
            numeroValido = atoi(aux);
        }
        if(numeroValido == lowLimit || numeroValido == mediumLimit || numeroValido == hiLimit ){

            *number = atoi(aux);
            todoOk = 1;
        }
        return todoOk;
}

int getFloat(float* number, char* message,char* messageError,float lowLimit, float hiLimit){
    float aux;
    int todoOk = 1;

    printf("%s", message);
     fflush(stdin);
    scanf("%f", &aux);

        while(aux < lowLimit || aux > hiLimit ){
            printf("%s", messageError);
            scanf("%f", &aux);
        }
        if(aux >= lowLimit && aux <= hiLimit ){
            *number = aux;
        }
    return todoOk;
}

int getCharSex(char* input,char* message,char* messageError, char lowLimit, char hiLimit){

    char aux;
    int todoOk = 1;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &aux);
    aux = toupper(aux);

        while(aux != lowLimit && aux != hiLimit ){
            printf("%s", messageError);
            fflush(stdin);
            scanf("%c", &aux);
            aux = toupper(aux);
        }
        if(aux == lowLimit || aux == hiLimit ){
            *input = aux;
        }
    return todoOk;
}

int getChar(char* input,char* message,char* messageError, char lowLimit, char hiLimit){

    char aux;
    int todoOk = 1;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &aux);
    aux = toupper(aux);

        while(aux != lowLimit && aux != hiLimit ){
            printf("%s", messageError);
            fflush(stdin);
            scanf("%c", &aux);
            aux = toupper(aux);
        }
        if(aux == lowLimit || aux == hiLimit ){
            *input = aux;
        }
    return todoOk;
}

int getCh(char* input,char* message,char* messageError){

    char aux;
    int todoOk = 1;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &aux);
    aux = toupper(aux);

    *input = aux;

    return todoOk;
}

int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit){

    char aux[100];  // PREGUNTAR PORQUE SOLO TOMA HASTA EL ESPACIO.
    int todoOk = 1;

    printf("%s", message);
    fflush(stdin);
    //strupr(gets(aux));
    strlwr(gets(aux));
    aux[0] = toupper(aux[0]);

        while(strlen(aux) < lowLimit || strlen(aux) > hiLimit ){
            printf("%s", messageError);
            fflush(stdin);
            //strupr(gets(aux));
           gets(aux);
           strlwr(aux);
           aux[0] = toupper(aux[0]);
        }
        if(strlen(aux) >= lowLimit || strlen(aux) <= hiLimit){
            strcpy(strig, aux);
        }
    return todoOk;
}


/*
int comparaFecha(eFecha f1, eFecha f2){
    int rta;

        if(f1.anio < f2.anio){
            rta = -1;
        }
        else if(f1.anio > f2.anio){
            rta = 1;
        }
         else {
            if(f1.mes < f2.mes){
                rta = -1;
            }
            else if( f1.mes > f2.mes ){
                 rta = 1;
            }
            else{
                if(f1.dia < f2.dia){
                     rta = -1;
                }
                else if ( f1.dia > f2.dia ){
                    rta = 1;
                }
                else{
                    rta = 0;
                }
            }
    }

    return rta;
}*/


