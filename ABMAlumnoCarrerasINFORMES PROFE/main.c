#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carreras.h"///porque voy a usar los prototipos de carreras y alumnos, y las estucturas
#include "ABMalumnos.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
# define TAMAL 10


typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eComida;

typedef struct
{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;

} eAlmuerzo;

///prototipos comidas

void mostrarComida (eComida comida);///no es vector xq es una sola comida
void mostrarComidas(eComida comida[], int tam);
int cargarDescComida(int id, eComida comida[], int tam, char desc[]);

///prototipos almuerzo

void inicializarAlmuerzo(eAlmuerzo[], int tam);
int hardcodearAlmuerzos( eAlmuerzo[], int tam, int cantidad);

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eAlumno lista[TAM];
    eComida comida [TAMCOM] = { {5000, "bife", 250},
        {5001, "fideos", 200},
        {5002, "pizza", 190},
        {5003, "arroz", 200},
        {5004, "milanesa", 220}
    };///hardcodeado menus

    eAlmuerzo almuerzos [TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzo(almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 6);

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
            mostrarInformes(lista, TAM, carreras, TAMC);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            mostrarComidas(comida, TAMCOM);
            break;
        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comida, TAMCOM);
            break;

        case 11:
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
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzos\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarComidas(eComida comida[], int tam)
{
    printf(" Id   Descripcion   precio \n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarComida(comida[i]);///comidas en el indice I
    }
    printf("\n");
}

void mostrarComida(eComida comida)
{

    printf("%d    %10s   %3.2f \n", comida.id, comida.descripcion, comida.precio);

}

void inicializarAlmuerzo(eAlmuerzo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        /// idAlmuer legaj idcomida fecha
        { 60000, 20000, 5000,{1, 10, 2019},0},
        { 60001, 20001, 5002,{1, 10, 2019},0},
        { 60002, 20005, 5002,{1, 10, 2019},0},
        { 60003, 20003, 5004,{1, 10, 2019},0},
        { 60004, 20004, 5001,{2, 10, 2019},0},
        { 60005, 20001, 5000,{2, 10, 2019},0},
        { 60006, 20002, 5002,{2, 10, 2019},0},
        { 60007, 20004, 5004,{2, 10, 2019},0},
        { 60008, 20003, 5000,{3, 10, 2019},0},
        { 60009, 20001, 5001,{3, 10, 2019},0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }
}

    void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comida[], int tam)
    {
        char descComida[20];

        cargarDescComida(id, comida, tam, descComida);
        printf("  %d  %d   %s   %02d/%02d/%d    \n",
               almuerzo.id,
               almuerzo.legajo,///es el mismo legajo que el alumno
               descComida,
               almuerzo.fecha.dia,
               almuerzo.fecha.mes,
               almuerzo.fecha.anio
              );
    }

    void mostrarAlmuerzos(eAlmuerzo vec[], int tam,eComida comida[], int tamC)
    {

        int flag = 0;
        system("cls");

        printf(" IDcomida    Legajo    Comida     Fecha \n\n");

        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0)
            {
                mostrarAlmuerzo(vec[i], comida, tamC);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("\nNo hay almuerzos que mostrar\n");
        }

        printf("\n\n");
    }

    int cargarDescComida(int id, eComida comida[], int tam, char desc[])
    {
        int todoOk = 0;

        for(int i=0; i < tam; i++)
        {
            if( id == comida[i].id) ///el for itera hasta que el ID ingresado coincida con un ID cargado
            {
                strcpy(desc, comida[i].descripcion);///copia la descrip de descripcion de la estruc. a la Var desc
                todoOk = 1;
                break;
            }
        }
        return todoOk;
    }



