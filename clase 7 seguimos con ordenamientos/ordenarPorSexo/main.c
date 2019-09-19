#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void mostrarAlumnos(int[], int[], char[], int[], int[], float[], int tam);
void mostrarAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio);
void ordenarAlumnosSexLeg (int legajo [], int edad [], char sexo [], int nota1 [], int nota2 [], float promedio [], int tam);
void ordenarAlumnosLegajos(int legajo [], int edad [], char sexo [], int nota1 [], int nota2 [], float promedio [], int tam);

int main()
{
    int legajos[TAM] = { 1234, 3322, 9556, 1122, 4532, 3321, 7898, 0988, 8878, 4521};
    int edades[TAM] = {22, 34, 21, 45, 20};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasP1[TAM] = { 2, 5, 6, 9, 10};
    int notasP2[TAM] = { 4, 4, 2, 10, 8};
    float promedios[TAM] = {3, 4.5, 4, 9.5, 9};


    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM );
    ordenarAlumnosLegajos(legajos, edades,sexos, notasP1, notasP2, promedios,TAM);
    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    return 0;
}


void mostrarAlumnos(int legs[], int ages[], char sexs[], int n1[], int n2[], float proms[], int tam){

    printf("Legajo  Edad Sexo Nota1 Nota2 Promedio\n\n");
    for(int i=0; i < tam; i++){
        mostrarAlumno( legs[i], ages[i], sexs[i], n1[i], n2[i], proms[i]);
    }
    printf("\n\n");
}


void mostrarAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio){

    printf("  %d     %d   %c   %d    %d     %.2f\n",
            legajo, edad, sexo, nota1, nota2, promedio);
}

void ordenarAlumnosLegajos(int legajo [], int edad [], char sexo [], int nota1 [], int nota2 [], float promedio [], int tam)
{
    int aux;
    char auxChar;
    float auxFloat;   ///funcion para ordenar por legajo

    for (int i=0; i < tam -1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {

            if (legajo[i] > legajo[j])
            {
                aux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j] = aux;

                aux=edad[i];
                edad[i]=edad[j];
                edad[j] = aux;

                auxChar=sexo[i];
                sexo[i]=sexo[j];
                sexo[j] = auxChar;

                aux=nota1[i];
                nota1[i]=nota1[j];
                nota1[j] = aux;

                aux=nota2[i];
                nota2[i]=nota2[j];
                nota2[j] = aux;

                auxFloat=promedio[i];
                promedio[i]=promedio[j];
                promedio[j] = auxFloat;

            }
        }
    }

}

void ordenarAlumnosSexLeg (int legajo [], int edad [], char sexo [], int nota1 [], int nota2 [], float promedio [], int tam)

{
    int aux;
    char auxChar;
    float auxFloat;   ///funcion para ordenar por sexo y legajo
    int swap =0;

    for (int i=0; i < tam -1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {

            if (sexo[i] > sexo[j]) ///compara sexo y pone bandera swap en 1
            {
                swap=1;
            }
            else if (sexo[i]==sexo[j] && legajo[i] > legajo[j]) ///compara sexo y orden de lagajo y pone swap en 1
            {
                swap=1;
            }
            if (swap)
            {
                aux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j] = aux;

                aux=edad[i];
                edad[i]=edad[j];
                edad[j] = aux;

                auxChar=sexo[i];
                sexo[i]=sexo[j];
                sexo[j] = auxChar;

                aux=nota1[i];
                nota1[i]=nota1[j];
                nota1[j] = aux;

                aux=nota2[i];
                nota2[i]=nota2[j];
                nota2[j] = aux;

                auxFloat=promedio[i];
                promedio[i]=promedio[j];
                promedio[j] = auxFloat;

            }
        }
    }

}
