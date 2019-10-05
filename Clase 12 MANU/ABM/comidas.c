#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "comidas.h"


void mostrarComida(eComida comida){
    printf(" %d   %s      %.2f  \n\n", comida.id,  comida.descripcion, comida.precio);
}

void mostrarComidas(eComida comidas[], int tam){
    system("cls");

    printf("\n COMIODA   PRECIO \n");
    printf("**********************\n");

    for(int i=0; i<tam; i++){
        mostrarComida(comidas[i]);
    }
}


int cargarDescComida(int id, eComida comidas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


















