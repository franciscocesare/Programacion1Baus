#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];
    int i=0;

    printf("Ingrese nombre: ");
    gets(nombre);
    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);


    while( nombreCompleto[i] != '\0')
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i +1] = toupper(nombreCompleto[i+1]);

        }
         i++;
    }
    printf("%s\n", nombreCompleto);

    return 0;
}
