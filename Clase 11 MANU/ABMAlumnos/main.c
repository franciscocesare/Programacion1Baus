#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

#define TAM 10
#define TAMC 3

int menu();
int menuInformes();
void mostrarInformes(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void mostrarAlumnosCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);
void mostrarAlumnoPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

int cantidadDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarCantidaDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void carrerasInscriptos(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

int main()
{
    int legajo = 20000;
    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            //printf("Informes Alumno\n\n");
            mostrarInformes(lista, TAM, carreras, TAMC);

            break;
        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int menuInformes(){
    int opcion;

    system("cls");
    printf("****** INFORMES *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de Alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas Inscriptos\n");
    printf("5-Mostrar mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarInformes(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    char salir = 'n';
    do{
                switch( menuInformes()){
                case 1:
                    //printf("1-Mostrar Alumnos de una Carrera\n");
                    mostrarAlumnosCarreraSeleccionada(alumnos, tamA, carreras, tamC);
                    break;
                case 2:
                    //printf("2-Mostrar Alumnos por Carrera\n");
                    mostrarAlumnosDeTodasLasCarreras(alumnos, tamA, carreras, tamC);
                    break;
                case 3:
                    //printf("3-Mostrar Cantidad de Alumnos por Carrera\n");
                    mostrarCantidaDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC);
                    break;
                case 4:
                    //printf("4-Mostrar La Carrera con mas Inscriptos\n");
                    carrerasInscriptos(alumnos, tamA, carreras, tamC);
                    break;
                case 5:
                    printf("5-Mostrar mejor Promedio por Carrera\n");
                    break;
                case 6:
                    printf("6-Mostrar Alumnos Varones\n");
                    break;
                case 7:
                    printf("7-Mostrar Mujeres de Alguna carrera\n");
                    break;
                case 8:
                    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
                    break;
                case 9:
                    printf("Confirma salir?:");
                    fflush(stdin);
                    salir = getchar();
                    printf("\n\n");
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                    break;
            }
            system("pause");
            }while(salir == 'n');
}

void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    char desc[20];

    system("cls");
    printf("***** MOSTRAR ALUMNOS DE TODAS LAS CARRERA  ******** \n\n");

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s \n\n", desc);
        mostrarAlumnoPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
    }
}

void mostrarAlumnosCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int idCarrera;
    system("cls");
    printf("***** MOSTRAR ALUMNOS POR CARRERA SELECCIONADA  ******** \n\n");

    mostrarCarreras(carreras, tamC);
    printf("Ingrese ID de la carrera: ");
    scanf(" %d", &idCarrera);

    mostrarAlumnoPorCarrera(alumnos, tamA, carreras, tamC, idCarrera);
}

void mostrarAlumnoPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera){
    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
    printf("\n\n");
}


void mostrarCantidaDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    char desc[20];
    int cantidad;

    system("cls");
    printf("***** MOSTRAR CANTIDAD DE ALUMNOS POR CARRERA  ******** \n\n");

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera %s ", desc);
        cantidad = cantidadDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
        printf("Cantidad: %d \n\n", cantidad);
    }
}

int cantidadDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera){
    int contador = 0;
    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){
            contador++;
        }
    }
    return contador;
}

void carrerasInscriptos(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int inscriptos[tamC];
    int mayor;
    int flag = 0;

    system("cls");
    printf("***** CARRERA CON MAS ALUMNOS******** \n\n");

    for(int i=0; i<tamC; i++){
       inscriptos[i] = cantidadDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
    }
    for(int i=0; i<tamC; i++){
        if(inscriptos[i] > mayor || flag == 0){
        mayor = inscriptos[i];
        flag = 1;
        }
    }
    for(int i=0; i<tamC; i++){
        if(inscriptos[i] == mayor){
            printf(" %s \n", carreras[i].descripcion);
        }
    }
     printf("cantidad incriptos %d\n\n", mayor);
}
