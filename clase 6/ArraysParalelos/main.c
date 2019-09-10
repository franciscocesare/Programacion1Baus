#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void mostrarAlumnos(int legajos[], int edades[], char sexo[], int notaP1, int notaP2, float promedio);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexo[TAM];
    int notaP1[TAM];
    int notaP2[TAM];
    float promedio[TAM];

    for (int i=0; i<TAM; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajos[i]); ///le paso la direccion de memoria para que guarde en arrays legajos

        printf("Ingrese la edad: ");
        scanf("%d", &edades[i]);

        printf ("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese la nota del Parcial 1: ");
        scanf("%d", &notaP1[i]);

        printf("Ingrese la nota del Parcial 2: ");
        scanf("%d", &notaP2[i]);

        promedio[i]=(float) (notaP1[i] + notaP2 [i]) / 2;
    }

printf("\nLEGAJO EDAD SEXO NOTA P1 NOTA P2 PROMEDIO \n\n");

for (int i=0; i < TAM; i++)
{
    printf("\n%d    %d   %c     %d       %d      %2.f \n", legajos[i], edades[i], sexo[i], notaP1[i], notaP2[i], promedio[i]);
}

    return 0;
}
