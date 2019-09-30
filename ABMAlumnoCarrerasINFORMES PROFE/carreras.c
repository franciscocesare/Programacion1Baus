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

int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas inscriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{


    char salir = 'n';

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosCarreraSeleccionada(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosDeTodasLasCarreras(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadDeAlumnosPorCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            carreraMasInscriptos(alumnos, tam, carreras, tamC);
            break;

        case 5:

            printf("Informe 5\n");
            break;

        case 6:
            printf("Informe 6\n");
            break;
        case 7:
            printf("Informe 7\n");
            break;
        case 8:
            printf("Informe 8\n");
            break;


        case 9:
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
}

void mostrarAlumnosCarrera( eAlumno alumnos[],
                            int tam,
                            eCarrera carreras[],
                            int tamC,
                            int idCarrera)
{
    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
    printf("\n\n");
}

void mostrarAlumnosCarreraSeleccionada( eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC
                                      )
{
    int idCarrera;
    system("cls");
    printf("**** Mostrar Alumnos de una Carrera ******\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[],
                                      int tam,
                                      eCarrera carreras[],
                                      int tamC)
{
    ///int idCarrera;
    char desc[20];
    system("cls");
    printf("*** Mostrar Alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s\n\n", desc);
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);

    }
}

void mostrarCantidadDeAlumnosPorCarrera(eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC)
{
  ///  int idCarrera;
    char desc[20];
    int cantidad;
    system("cls");
    printf("*** Mostrar Cantidad de alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s: ", desc);
        cantidad = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
        printf(" %d\n\n",cantidad);
    }
}

int contarAlumnosCarrera(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC,
                         int idCarrera)
{
    int cantidad = 0;

    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void carreraMasInscriptos(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC)
{
    int inscriptos[tamC];
    int mayor;
    int flag = 0;

///    int idCarrera;
///    char desc[20];
  ///  int cantidad;
    system("cls");
    printf("*** Carrera mas cursada ***\n\n");
    for(int i=0; i < tamC; i++)    {
        inscriptos[i] = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

     for(int i=0; i < tamC; i++) {
        if( mayor < inscriptos[i]|| flag == 0){
            mayor = inscriptos[i];
            flag = 1;
        }
     }

      for(int i=0; i < tamC; i++) {
        if( inscriptos[i] == mayor){void mostrarCarreras(eCarrera carreras[], int tam)
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
        if( id == carreras[i].id)
        {
            strcpy(desc, carreras[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas inscriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{


    char salir = 'n';

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosCarreraSeleccionada(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosDeTodasLasCarreras(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadDeAlumnosPorCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            carreraMasInscriptos(alumnos, tam, carreras, tamC);
            break;

        case 5:

            printf("Informe 5\n");
            break;

        case 6:
            printf("Informe 6\n");
            break;
        case 7:
            printf("Informe 7\n");
            break;
        case 8:
            printf("Informe 8\n");
            break;


        case 9:
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
}

void mostrarAlumnosCarrera( eAlumno alumnos[],
                            int tam,
                            eCarrera carreras[],
                            int tamC,
                            int idCarrera)
{
    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
    printf("\n\n");
}

void mostrarAlumnosCarreraSeleccionada( eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC
                                      )
{
    int idCarrera;
    system("cls");
    printf("**** Mostrar Alumnos de una Carrera ******\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[],
                                      int tam,
                                      eCarrera carreras[],
                                      int tamC)
{
  ///  int idCarrera;
    char desc[20];
    system("cls");
    printf("*** Mostrar Alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s\n\n", desc);
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);

    }
}

void mostrarCantidadDeAlumnosPorCarrera(eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC)
{
    ///int idCarrera;
    char desc[20];
    int cantidad;
    system("cls");
    printf("*** Mostrar Cantidad de alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s: ", desc);
        cantidad = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
        printf(" %d\n\n",cantidad);
    }
}

int contarAlumnosCarrera(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC,
                         int idCarrera)
{
    int cantidad = 0;

    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void carreraMasInscriptos(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC)
{
    int inscriptos[tamC];
    int mayor;
    int flag = 0;

///    int idCarrera;
///    char desc[20];
///    int cantidad;
    system("cls");
    printf("*** Carrera mas cursada ***\n\n");
    for(int i=0; i < tamC; i++)    {
        inscriptos[i] = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

     for(int i=0; i < tamC; i++) {
        if( mayor < inscriptos[i]|| flag == 0){
            mayor = inscriptos[i];
            flag = 1;
        }
     }

      for(int i=0; i < tamC; i++) {
        if( inscriptos[i] == mayor){
         printf(" %s \n", carreras[i].descripcion );
        }
      }

      printf("cantidad incriptos %d\n\n", mayor);


}

         printf(" %s \n", carreras[i].descripcion );
        }
      }

      printf("cantidad incriptos %d\n\n", mayor);


}
