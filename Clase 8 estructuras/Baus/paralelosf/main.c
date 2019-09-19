#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define COLUMNAS 20

void mostrarAlumnos(char nom[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(char nom[], int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordenarAlumnosLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarAlumnosSex( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarAlumnosSexNom(char nom[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);


int main()
{
    int legajos[TAM] = {123, 102, 767, 479, 376};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'m', 'm', 'f', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};
    char nombres[TAM][COLUMNAS]= {"Juan", "Pedro", "Lucia", "Ana", "Miguel"};
    char auxCad[100];

   /* for(int i = 0; i < TAM; i++){

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

         printf("Ingrese un nombre: ");
         fflush(stdin);
         gets(auxCad);
         while( strlen(auxCad) > 19)
         {
             printf("Error. nombre demasiado largo. Ingrese un nombre: ");
             fflush(stdin);
             gets(auxCad);
         }
         strcpy(nombres[i], auxCad);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese Nota Primer Parcial: ");
        scanf("%d", &notasp1[i]);

        printf("Ingrese Nota Segundo Parcial: ");
        scanf("%d", &notasp2[i]);

        promedios[i] = (float) (notasp1[i] + notasp2[i]) / 2;
    }*/

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    ordenarAlumnosSexNom(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM);


  //  ordenarAlumnosLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

  //  mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

  //  ordenarAlumnosSex(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

 //   mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

 //   ordenarAlumnosSexLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

 //   mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(char nom[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    printf(" Legajo    Nombre   Edad  Sexo  Nota1  Nota2  Promedio\n\n");
    for(int i=0; i < tam; i++){
      mostrarAlumno(nom[i], leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(char nom[], int leg, int age, char sexo, int nota1, int nota2, float promedio){

    printf(" %d    %10s   %d    %c      %2d    %2d     %.2f\n", leg, nom,  age, sexo, nota1, nota2, promedio);

}

void ordenarAlumnosLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( leg[i] > leg[j]){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;

            }
        }
    }
}

void ordenarAlumnosSex( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( sex[i] > sex[j]){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;

            }
        }
    }
}

void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){
            // condicion para ordenar por sexo ascendente
            if( sex[i] > sex[j]){
                    swap = 1;
            }
            // SI TIENEN EL MISMO SEXO LOS ORDENO POR LEGAJO ASCENDETE
            else if( sex[i] == sex[j] && leg[i] > leg[j]){

                    swap = 1;
            }
            // SI ENTRO A ALGUNO DE LOS IF ANTERIORES ES PORQUE TENGO QUE SWAPEAR
            if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }

            swap = 0;
        }
    }
}


void ordenarAlumnosSexNom(char nom[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[20];
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){
            // condicion para ordenar por sexo ascendente
            if( sex[i] > sex[j]){
                    swap = 1;
            }
            // SI TIENEN EL MISMO SEXO LOS ORDENO POR LEGAJO ASCENDETE
            else if( sex[i] == sex[j] &&  strcmp(nom[i], nom[j]) > 0){

                    swap = 1;
            }
            // SI ENTRO A ALGUNO DE LOS IF ANTERIORES ES PORQUE TENGO QUE SWAPEAR
            if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;

               strcpy( auxCad, nom[i]);
                strcpy( nom[i], nom[j]);
                strcpy( nom[j], auxCad);
            }

            swap = 0;
        }
    }
}

