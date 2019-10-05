
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "biblioteca.h"

int getIntRange(int* number, char* message,char* messageError,int lowLimit, int hiLimit){

    int aux;
    int todoOk = 0;
    printf("%s", message);
    fflush(stdin);
    scanf("%d", &aux);

        while(aux < lowLimit || aux > hiLimit ){

            printf("%s", messageError);
             fflush(stdin);
            scanf("%d", &aux);
        }
        if(aux >= lowLimit && aux <= hiLimit ){
            *number = aux;
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


int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit, int attempts){

    char aux[100];  // PREGUNTAR PORQUE SOLO TOMA HASTA EL ESPACIO.
    int todoOk = 1;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", aux);

        while(strlen(aux) < lowLimit || strlen(aux) > hiLimit ){
            attempts--;
                if(attempts == 0){
                        todoOk = 0;
                    break;
                }
            printf("%s", messageError);
            fflush(stdin);
            scanf("%s", aux);
        }
        if(attempts != 0){
            strcpy(strig, aux);
        }
    return todoOk;
}



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
}


