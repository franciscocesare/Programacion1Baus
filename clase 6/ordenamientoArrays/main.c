#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenarVectorBurbujeo (int vec[], int tam);
void ordenarVectorPorCriterio (int vec[], int tam, int criterio);
void mostrarVectorInt(int vec [], int tam);

int main()
{
    int numeros [10] = {1,8,2,6,3,4,5,7,9,0};

    printf("muestro el vector: ");
    mostrarVectorInt(numeros, TAM);

    printf("muestro el vector ordenado: ");
    ordenarVectorBurbujeo(numeros, TAM);
    mostrarVectorInt(numeros, TAM);

    printf("muestro el vector ordenado por criterio: ");
    ordenarVectorPorCriterio(numeros, TAM, 0);///aca modificas el dato de criterio
    mostrarVectorInt(numeros, TAM);

    return 0;
}

void mostrarVectorInt(int vec [], int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorBurbujeo (int vec [],int tam)
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
void ordenarVectorPorCriterio (int vec[], int tam, int criterio)
{
    int aux;
    for (int i=0; i < tam -1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (vec[i] > vec [j] && criterio)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j] = aux;
            }
            else if (vec[i] < vec [j] && !criterio)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j] = aux;
            }
        }
    }
}
