#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorInt(int v[], int tam);

void ordenarVectorInt(int v[], int tam, int criterio);

int main()
{
    int vec[TAM] = {7, 8, 1, 3, 5};
    int aux;

    printf("Muestro el vector en memoria\n");
    mostrarVectorInt( vec, TAM);

    ordenarVectorInt(vec, TAM, 1);

    printf("Muestro el vector ordenado ascendente\n");
    mostrarVectorInt( vec, TAM);

    ordenarVectorInt(vec, TAM, 0);


    printf("Muestro el vector ordenado descendente\n");
    mostrarVectorInt( vec, TAM);

    return 0;
}

void mostrarVectorInt(int v[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt(int v[], int tam, int criterio)
{

    int aux;


    for(int i=0; i < tam -1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if( v[i] > v[j]&& criterio)
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
            else if( v[i] <  v[j]&& !criterio){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;

            }
        }
    }
}
