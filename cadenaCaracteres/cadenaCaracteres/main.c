#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre [20];
    char auxCad [100];

    printf("Ingrese un nombre: ");
    gets(auxCad);

    while (strlen (auxCad) >19)///condicion de dato invalido, para que lo siga pidiendo
    {
        printf("Error, ingrese un nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy (nombre, auxCad); ///si el dato es valido, lo copio en nombre!

    return 0;
}
