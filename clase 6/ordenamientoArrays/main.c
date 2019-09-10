#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenarVectorBurbujeo (int vec[], int tam);
void ordenarVectorPorCriterio (int vec[], int tam, int criterio);
void mostrarVectorInt(int vec [], int tam);
int cargarVectorInt(int vec[], int tam);}
int cargarVectorChar(vec[], int tam);

int main()
{
    int numeros [10];

    cargarVectorInt(numeros, TAM); ///funcion para ir cargando el array

    printf("\n muestro el vector: ");
    mostrarVectorInt(numeros, TAM);

    printf("\n muestro el vector ordenado: ");
    ordenarVectorBurbujeo(numeros, TAM);
    mostrarVectorInt(numeros, TAM);

    printf("\n muestro el vector ordenado por criterio: ");
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
int cargarVectorInt(int vec[], int tam)
{
   for (int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }
    return 0;
}

