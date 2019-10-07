#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "carrera.h"
#include "alumno.h"
#include "biblioteca.h"
#include "Informes.h"
#include "almuerzo.h"
#include "comidas.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMALM 10

// ESTRUCTURAS


////////////////////////////////// PROTOTIPOS

int menu();




//////////////////////////////// MAIN
int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;

    eComida comidas[TAMCOM] = {
        {5000, "Bife", 250},
        {5001, "Fideos", 200},
        {5002, "Pizza", 190},
        {5003, "Arroz", 200},
        {5004, "Milanesa", 220}
    };

    eAlmuerzo almuerzos[TAMALM];

    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

    eAlumno lista[TAM];

    inicializarAlumnos(lista, TAM);

    inicializarAlmuerzos(almuerzos, TAMALM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMALM, 6);

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
            mostrarInformes(lista, TAM, carreras, TAMC, almuerzos, TAMALM, comidas, TAMCOM);
            break;
        case 7:
            // MOSTRAR CARRERAS
            mostrarCarreras(carreras, TAMC);
            break;
        case 8:
            // MOSTRAR comidas
            mostrarComidas(comidas, TAMCOM);
            break;
         case 9:
            // MOSTRAR ALMUERZO
            mostrarAlmuerzos(almuerzos, TAMALM, comidas, TAMCOM);
            break;
         case 10:
               if(altaAlmuerzo(idAlmuerzo, almuerzos, TAMALM, comidas, TAMCOM, lista, TAM, carreras, TAMC)){
                    idAlmuerzo++;
                }
            break;
        case 11:
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
    printf("8- Mostrar Comidas \n");
    printf("9- Mostrar Almuerzos \n");
    printf("10- Alta Almuerzos \n");

    printf("11- Salir \n");


    getIntRange(&opcion, "Ingrese Opcion: ", "Error. Ingrese un entero entre 1 y 8: ", 1, 11);

    return opcion;
}














