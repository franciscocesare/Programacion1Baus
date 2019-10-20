#include <stdio.h>
#include <stdlib.h>

#define FILAS 5
#define COLUMNAS 20

void mostrarNombres( char mat[][20], int filas);

int main()
{
    char nombres[FILAS][COLUMNAS]= {"juan", "Lucia", "Pedro", "Ana", "Miguel"};

    char auxCad[100];

    /* for(int i=0; i < FILAS; i++)
     {
         printf("Ingrese un nombre: ");
         fflush(stdin);
         gets(auxCad);
         while( strlen(auxCad) > 19)
         {
             printf("Error. nombre demasiado largo. Ingrese un nombre: ");
             fflush(stdin);
             gets(auxCad);
         }
         strcpy(nombres[i], auxCad);
     }*/

    mostrarNombres(nombres, FILAS);

    ordenarNombres(nombres, FILAS);

    mostrarNombres(nombres, FILAS);




    return 0;
}


void mostrarNombres( char mat[][20], int filas)
{

    for(int i=0; i < filas; i++)
    {
        printf("%s\n", mat[i]);
    }
    printf("\n\n");
}

void ordenarNombres( char mat[][20], int filas)
{
    char auxCad[20];

    for(int i=0; i < filas -1; i++)
    {
        for(int j= i+1; j < filas; j++)
        {
            if( stricmp( mat[i], mat[j]) > 0  )
            {
                strcpy( auxCad, mat[i]);
                strcpy( mat[i], mat[j]);
                strcpy( mat[j], auxCad);
            }
        }
    }
}
