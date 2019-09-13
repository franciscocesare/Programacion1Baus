#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(int[], int[], char[], int[], int[], float[], int tam);
void mostrarAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio);
void ordenarAlumnosLegajos (int vec[], int tam);


int main()
{
    int legajos[TAM] = { 1234, 3322, 4556, 1122, 4532};
    int edades[TAM] = {22, 34, 21, 45, 20};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasP1[TAM] = { 2, 5, 6, 9, 10};
    int notasP2[TAM] = { 4, 4, 2, 10, 8};
    float promedios[TAM] = {3, 4.5, 4, 9.5, 9};

   /* for( int i=0; i < TAM; i++){
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese Nota parcial 1: ");
        scanf("%d", &notasP1[i]);

        printf("Ingrese Nota parcial 2: ");
        scanf("%d", &notasP2[i]);

        promedios[i] = (float)  (notasP1[i] + notasP2[i]) / 2;
    }*/

    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM );
    ordenarAlumnosLegajos(legajos,TAM);
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

void ordenarAlumnosLegajos(int vec[],int tam)
{
    int aux;
    for (int i=0; i < tam -1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {

            if (vec[i] > vec [j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j] = aux;

            }
        }
    }

}

