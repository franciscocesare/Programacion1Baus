#include <stdio.h>
#include <stdlib.h>

void mostrarVectorChar( char vec[], int tam);

int main()
{
    char vocales[] = {'a', 'e', 'i', '\0', 'u'};
    char nombre[10] = "Juan";

    mostrarVectorChar(nombre, 10);
   printf("%s", nombre);

    return 0;
}

void mostrarVectorChar( char vec[], int tam){

    for(int i = 0; i < tam; i++){
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}
