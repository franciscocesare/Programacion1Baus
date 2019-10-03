#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carreras.h" ///TENGO QUE INCLUIR EL .H DE LOS PROTOTIPOS DE LAS FUNCIONES
#include "ABMalumnos.h"


void mostrarCarreras(eCarrera carreras[], int tam)
{
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarCarrera( carreras[i]);
    }
    printf("\n");
}

void mostrarCarrera(eCarrera carrera)
{

    printf("  %d      %10s\n", carrera.id, carrera.descripcion);

}

int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == carreras[i].id) ///el for itera hasta que el ID ingresado coincida con un ID cargado
        {
            strcpy(desc, carreras[i].descripcion);///copia la descrip de descripcion de la estruc. a la Var desc
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

