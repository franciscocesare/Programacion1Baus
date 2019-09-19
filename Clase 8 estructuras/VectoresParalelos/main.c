#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5


void mostrarAlumnos(int legs[], char mat[][20], char sexos[], int ages[], int n1[], int n2[], float promedios[],  int tam);
void mostrarAlumno(int legajo, char mat[], char sexo, int edad, int nota1, int nota2, float promedio);
void sortAlumnosLeg(int legs[], char mat[][20], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio);
void sortAlumnosSexoLeg(int legs[], char mat[][20], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio);

int main()
{
    int legajos[TAM] = {423, 554, 125, 226, 327};
    int edades[TAM] = {30, 23 ,45, 32, 19};
    int nota1[TAM] = {8, 9 ,10, 2, 3};
    int nota2[TAM] = {8, 9 ,10, 2, 3};
    float promedios[TAM] = {8, 9, 10, 2, 3};
    char sexos[TAM] = {'f', 'm', 'f', 'm', 'f'};
    char nombres[TAM][20] = {"Juana", "Manuel", "Flor", "Andres", "Andrea"};

    printf("Muestro el listado: \n\n");
    mostrarAlumnos(legajos, nombres, sexos, edades, nota1, nota2, promedios, TAM);


    printf("Muestro Ordenado por legajo ascendente(1) o descendente(0): \n\n");
    sortAlumnosLeg(legajos, nombres, sexos, edades, nota1, nota2, promedios, TAM, 0);
    mostrarAlumnos(legajos, nombres, sexos, edades, nota1, nota2, promedios, TAM);

    printf("MUESTRO ORDENADO POR SEXO Y LEGAJO ASCENDENTE(1) O DESCENDENTE(0):\n\n");
    sortAlumnosSexoLeg(legajos, nombres, sexos, edades, nota1, nota2, promedios, TAM, 1);
    mostrarAlumnos(legajos, nombres, sexos, edades, nota1, nota2, promedios, TAM);


    return 0;
}

void mostrarAlumnos(int legs[], char mat[][20], char sexos[], int ages[], int n1[], int n2[], float promedios[],  int tam){

    printf("\n LEGAJO        NOMBRE       SEXO   EDAD      NOTA 1    NOTA 2     PROMEDIO\n\n");

    for(int i=0; i<tam; i++){
        mostrarAlumno(legs[i], mat[i], sexos[i], ages[i], n1[i], n2[i], promedios[i]);
    }
    printf("\n");
}

void mostrarAlumno(int legajo, char mat[], char sexo, int edad, int nota1, int nota2, float promedio){

     printf("  %2d      %10s       %2c     %3d    %5d     %5d     %10.2f\n", legajo, mat, sexo, edad, nota1, nota2, promedio);
}

void sortAlumnosLeg(int legs[], char mat[][20], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio){

    int auxInt;
    char auxChar;
    float auxFloat;
    char auxCad[20];

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(legs[i] > legs[j] && criterio){

                strcpy(auxCad, mat[i]);strcpy(mat[i], mat[j]);strcpy(mat[j], auxCad);

                auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

                auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

                auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

                auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

                auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

                auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
            }
            else if(legs[i] < legs[j] && !criterio){

                strcpy(auxCad, mat[i]);strcpy(mat[i], mat[j]);strcpy(mat[j], auxCad);

                auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

                auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

                auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

                auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

                auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

                auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
            }
        }
    }
}


void sortAlumnosSexoLeg(int legs[], char mat[][20], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio){
    int auxInt;
    int auxFloat;
    int auxChar;
    char auxCad[20];
    //int swap = 0;

    for(int i=0; i < tam-1; i++){
       for(int j=i+1; j<tam; j++){
        if(sexos[i] > sexos[j] && criterio){

            strcpy(auxCad, mat[i]);
            strcpy(mat[i], mat[j]);
            strcpy(mat[j], auxCad);

            auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

            auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

            auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

            auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

            auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

            auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
        }
        else if(sexos[i] == sexos[j] && legs[i]>legs[j] && criterio){

            strcpy(auxCad, mat[i]);strcpy(mat[i], mat[j]);strcpy(mat[j], auxCad);

            auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

            auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

            auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

            auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

            auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

            auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
        }
        else if(sexos[i] < sexos[j] && !criterio){

            strcpy(auxCad, mat[i]);strcpy(mat[i], mat[j]);strcpy(mat[j], auxCad);

            auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

            auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

            auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

            auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

            auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

            auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
        }
        else if(sexos[i] == sexos[j] && legs[i]<legs[j] && !criterio){

            strcpy(auxCad, mat[i]);strcpy(mat[i], mat[j]);strcpy(mat[j], auxCad);

            auxInt = legs[i];legs[i] = legs[j];legs[j] = auxInt;

            auxChar = sexos[i];sexos[i] = sexos[j];sexos[j] = auxChar;

            auxInt = ages[i];ages[i] = ages[j];ages[j] = auxInt;

            auxInt = nota1[i];nota1[i] = nota1[j];nota1[j] = auxInt;

            auxInt = nota2[i];nota2[i] = nota2[j];nota2[j] = auxInt;

            auxFloat = promedios[i];promedios[i] = promedios[j];promedios[j] = auxFloat;
        }
       }
    }
}






