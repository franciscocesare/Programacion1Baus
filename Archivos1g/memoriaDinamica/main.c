#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* aux;///puntero a int auxiliar, pata cuando pide realloc, no se pierda lo guardado
    int* numeros = (int*) malloc( sizeof(int)*5);///pedido de espacio a Malloc paea puntero a int numeros

    for(int i=0; i< 5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", numeros + i);///ante ada iteracion se guarda en numeros, y numeros +i, y asi
    }

    for(int i=0; i< 5; i++){
        printf("%d ", *(numeros + i) );
    }

    aux = (int*)   realloc( numeros, sizeof(int) *10);///pide mas espacio pa puntero a numeros y guarda en aux los ingresados
    if( aux != NULL){///si es distinto de NULL
        numeros = aux;///los guarda en numeros
    }

     for(int i=5; i< 10; i++){///y pide 5 mas, a partit de 5 guardados
        printf("Ingrese un numero: ");
        scanf("%d", numeros + i);
    }

    for(int i=0; i< 10; i++){///muestra los 10 guardados con realloc
        printf("%d ", *(numeros + i) );
    }

    numeros = (int*) realloc(numeros, sizeof(int)*6);

    for(int i=0; i< 6; i++){
        printf("%d ", *(numeros + i) );
    }


    free(numeros);///libera el espacio pedido
    return 0;
}
