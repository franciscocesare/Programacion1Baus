#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


int main()
{
    char nombre[10];
    char apellido[10];
    char nombreCompleto[20];
    int i=0;

    printf("Ingrese nombre: ");
    fflush(stdin);
        gets(nombre);
//
    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    strlwr(nombre);
    nombre[0] = toupper(nombre[0]);
    strlwr(apellido);
    apellido[0]= toupper(apellido[0]);

    strcpy(nombreCompleto, apellido);///copia en nomComp el apellido
    strcat(nombreCompleto, " ");///concatena el apellido con un espacio
    strcat(nombreCompleto, nombre); ///concatena el apellido ya guardado y con el espacio con el nombre

    ///strlwr(nombreCompleto);///pone toda la cadena en minuscula

    ///nombreCompleto[0] = toupper(nombreCompleto[0]); ///en el indice 0, o sea la primer letra, las pasa a mayuscula


    printf("%s\n", nombreCompleto);
/*
    while( nombreCompleto[i] != '\0')
    {
        if(nombreCompleto[i] == ' ')///si despues de una cadena hay un espacio
        {
            nombreCompleto[i +1] = toupper(nombreCompleto[i+1]); ///a la cadena que sigue el espacio pasar la primera letra a mayuscula

        }
         i++;
    }
    printf("%s\n", nombreCompleto);*/

    return 0;
}
