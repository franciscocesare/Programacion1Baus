#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "carrera.h"
#include "alumno.h"
#include "biblioteca.h"

#define TAM 10
#define TAMC 3

int menu();


int main()
{
    int legajo = 20000;

    eAlumno lista[TAM];
    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

    inicializarAlumnos(lista, TAM);

    hardcodearAlumnos(lista, TAM, 4);
    legajo = legajo + hardcodearAlumnos(lista, TAM, 4);

    char salir = 'n';

    do{

        switch(menu()){

        case 1:
            //  ALTA ALUMNO
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC)){
                legajo++;
            }

            break;
        case 2:
           //  BAJA ALUMNJO
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;
        case 3:
            // MODIFICAR ALUMNO
            modificarAlumno(lista, TAM, carreras, TAMC);
            break;
        case 4:
            // MOSTRAR ALUMNOS
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;
        case 5:
            // ORDENAR ALUMNOS
            ordenarAlumnos(lista, TAM);
            break;
        case 6:
            // IFORMES
            printf("Informes \n");
            break;
        case 7:
            // MOSTRAR CARRERAS
            mostrarCarreras(carreras, TAMC);
            break;
        case 8:
            printf("Confirma Salir?  ");
            fflush(stdin);
            salir = getchar();
            salir = tolower(salir);
            printf("\n\n");
            break;


        default:
            printf("Opcion invalida.");
            break;
        }

        system("pause");
    }while(salir == 'n');



    return 0;
}


int menu(){

    int opcion;

    system("cls");

    printf("\n***** ABM de Alumnos  ********\n\n");
    printf("1- Alta \n");
    printf("2- Baja \n");
    printf("3- Modificar  \n");
    printf("4- Mostrar Alumnos \n");
    printf("5- Ordenar Alumnos \n");
    printf("6- Informes \n");
    printf("7- Listar CARRERAS \n");
    printf("8- Salir \n");


    getIntRange(&opcion, "Ingrese Opcion: ", "Error. Ingrese un entero entre 1 y 8: ", 1, 8);

    return opcion;
}




