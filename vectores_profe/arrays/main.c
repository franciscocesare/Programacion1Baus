#include <stdio.h>
#include <stdlib.h>

#define TAM 5


void mostrarVectorInt( int vec[], int tam);

int obtenerMayor( int vec[], int tam);

void cargarVectorInt(int vec[], int tam);

void mostrarIndices( int vec[], int tam, int num);

int main()
{
    int numeros[TAM];
    int maximo;

    const float PI = 3.14;



    cargarVectorInt(numeros, TAM);

    mostrarVectorInt(numeros, TAM);

    printf("\n\n");

    // Me fijo cual es el mayor numero ingresado
    maximo = obtenerMayor(numeros, TAM);


    printf("El mayor numero ingresado es %d y fue ingresado en los indices ", maximo);

    for( int i=0; i < TAM; i++)
    {
       if( numeros[i] == maximo){
           printf("%d ", i);
       }
    }



    return 0;
}

void mostrarVectorInt( int vec[], int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

int obtenerMayor( int vec[], int tam){
    int max;
    int flag = 0;

     for( int i=0; i < tam; i++)
    {
       if( vec[i] > max || flag ==0){
            max = vec[i];
            flag = 1;
       }
    }
    return max;
}

void cargarVectorInt(int vec[], int tam){

     for( int i=0; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }

}



