#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "almuerzo.h"





void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
    for(int i=0; i<tam; i++){
        almuerzos[i].isEmpty = 1;
    }
}




int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad){
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20000, 5000, {12, 10, 2019}, 0},
        { 60001, 20001, 5001, {10, 10, 2019}, 0},
        { 60002, 20002, 5002, { 9, 10, 2019}, 0},
        { 60003, 20003, 5003, { 2, 10, 2019}, 0},
        { 60004, 20004, 5004, { 1, 10, 2019}, 0},
        { 60005, 20005, 5001, {20, 10, 2019}, 0},
        { 60006, 20006, 5002, {17, 10, 2019}, 0},
        { 60007, 20007, 5003, {21, 10, 2019}, 0},
        { 60008, 20008, 5004, {14, 10, 2019}, 0},
        { 60009, 20009, 5005, {12, 10, 2019}, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamC){
    char descComida[20];

    cargarDescComida(almuerzo.idComida, comidas, tamC, descComida );

    printf(" %d      %10s       %2d       %d/%d/%d \n\n", almuerzo.id, descComida, almuerzo.legajo, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
}


void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tam, eComida comidas[], int tamC){

    int flag = 0;

    system("cls");

    printf("\n  ID            COMIDA      LEGAJO       FECHA\n");
    printf("************************************************\n");


    for(int i=0; i<tam; i++){
        if(almuerzos[i].isEmpty == 0){
           mostrarAlmuerzo(almuerzos[i], comidas, tamC);
           flag = 1;
        }

    }
    if(flag == 0){
        printf("No hay almuerzos que mostrar");
    }
    printf("\n\n");
}




int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam){
    int indice = -1;

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}





int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eAlumno alumnos[], int tamAlumno, eCarrera carreras[], int tamCarr){
    int todoOk = 0;
    int indice;
    int esta;

    int legajo;
    eFecha fecha;
    int idComida;

        system("cls");
        printf("******* ALTA ALMUERZO *******\n\n");

        indice = buscarAlmuerzoLibre(almuerzos, tamAlm);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                mostrarAlumnos(alumnos, tamAlumno, carreras, tamCarr);

                printf("Ingrese Legajo: ");
                scanf(" %d", &legajo);
                getInt(&legajo, "Ingrese legajo: ", "Error, Reingrese legajo: ");

                esta = buscarAlumno(alumnos, tamAlumno, legajo);

                if(esta == -1){
                    printf("no existe ese elumno \n\n");
                }
                else{
                    mostrarComidas(comidas, tamCom);

                    getInt(&idComida, "Ingrese ID: ", "Error, Reingrese ID: ");


                    printf("Ingrese Fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );

                    almuerzos[indice] = newAlmuerzo(idAlmuerzo, idComida, legajo, fecha);

                    todoOk = 1;
                }


                if(todoOk){
                    printf("\n\nALTA ALMUERZO EXITOSA !!! \n\n");
                }
        }

    return todoOk;
}

eAlmuerzo newAlmuerzo(int id, int idComida, int legajo, eFecha fecha){
    eAlmuerzo al;

    al.id = id;
    al.idComida = idComida;
    al.legajo = legajo;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}




















