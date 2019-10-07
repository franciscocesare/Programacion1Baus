#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define TAMMARCAS
#define TAMCOLOR
#define TAM

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idMarca; ///comienza en 1000 HARDCODEAR
    char descripcion[20];
    /// int isEmpty;
} eMarca;

typedef struct
{
    int idColor; ///comienza en 5000  HARDCODEAR
    char nombreColor[20];
} eColor;

typedef struct
{
    int idAuto;
    int isEmpty;
    char patente [10];
    int idMarca;
    int idColor;
    int modelo; ///(año de fabricacion)

} eAuto;

typedef struct
{
    int id;///comienza en 20000  HARDCODEAR
    char descripcion[25];
    int precio;
} eServicio;

typedef struct
{
    int id;///autoincremental
    char patente [10];
    char idServicio;
    int precio;
    eFecha fecha;
} eTrabajo;

///prototipos funciones
int altaAuto(eAuto vec[], int tam, int idAuto,char patente [], eMarca marcas[], eColor colores[], int tamM, int tamC);
int buscarLibre( eAuto x[], int tam);
void inicializarAuto(eAuto vec[], int tam);
int menu();
int elegirColor(eColor colores[], int tam);
void mostrarAuto(eAuto autos, eMarca marcas[], int tamMarcas, eColor color[], int tamColor);
void cargarDescripcionMarca(eMarca marcas[], int tamMarcas, int idMarca, char cadena[]);
void cargarDescripcionColor(eColor color[], int tamColor, int idColor, char cadena[]);
int elegirMarca(eMarca marcas[], int tam);
int buscarAuto(eAuto x[], int tamAuto, int idAuto);





int main()
{
    int idColor = 5000;
    int idMarca = 1000;
    int idServicio = 20000;
    char salir = 'n';

    eMarca marca[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor color[]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };


    eServicio servicio[]=
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600},
    };

    do
    {
        switch( menu())
        {
        case 1:

            ///buscarLibre(autos, 5);
            ///"1-Alta auto
            break;

            /* case 2:
                 bajaAlumno(lista, TAM, carreras, TAMC);
                 break;
                 "2-Baja auto

             case 3:
                 ModificarAlumno(lista, TAM, carreras, TAMC);
                 break;
                 "3-Listar Autos

             case 4:
                 mostrarAlumnos(lista, TAM, carreras, TAMC);
                 break;
                 "4-Listar Marcas

             case 5:
                 ordenarAlumnos(lista, TAM);
                 break;
                 "5-Listar colores

             case 6:
                 mostrarInformes(lista, TAM, carreras, TAMC);
                 break;
                 "6-Listar servicios

             case 7:
                 mostrarCarreras(carreras, TAMC);
                 break;
                 "7-ALTA trabajo



             case 11:
                 printf("Confirma salir?:");
                 fflush(stdin);
                 salir = getche();
                 break;

             default:
                 printf("\nOpcion Invalida!\n\n");*/
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
    printf("****** ABM LAVADERO *******\n\n");
    printf("1-Alta auto\n");
    printf("2-Baja auto\n");
    printf("3-Listar Autos\n");
    printf("4-Listar Marcas\n");
    printf("5-Listar colores\n");
    printf("6-Listar servicios\n");
    printf("7-ALTA trabajo\n");
    printf("8-Listar trabajos\n");
    ///printf("9-Mostrar Almuerzos\n");
    ///printf("10-Alta Almuerzos\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}






void inicializarAuto(eAuto vec[], int tam)
{
    for (int i; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre( eAuto x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            ///printf("%d", indice);
            break;
        }
    }
    return indice;
}

void agregarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor color[],int tamColor)
{
    eAuto nuevoAuto;
    int indice;
    int esta;
    int idAuto;

    system("cls");
    printf("  *** Alta Auto ***\n\n");

    indice = buscarLibre(autos, tamAutos);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese Id auto: ");
        scanf("%d", &idAuto);

        esta = buscarAuto(autos, tamAutos, idAuto); ///hacer buscar auto OK

        if(esta != -1)
        {
            printf("Existe un auto con ese idAuto %d\n", idAuto);
            ///mostrarAuto( autos,marcas, tamMarcas, color, tamColor);///hacer mostrar auto
        }
        else
        {
            nuevoAuto.idAuto = idAuto;

            printf("Ingrese Marca: ");
            nuevoAuto.idMarca = elegirMarca(marcas, TAMMARCAS);
            ///fflush(stdin);
            ///scanf("%d",&idMarca);


            printf("Ingrese color: ");
            //nuevoAuto.idColor =
            elegirColor(color, TAMCOLOR);
            scanf("%d", &idColor);

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(nuevoAuto.patente);

            printf("Ingrese modelo: ");
            fflush(stdin);
            scanf("%d", &nuevoAuto.modelo);

            nuevoAuto.isEmpty = 1;

            autos[indice] = nuevoAuto;

        }
    }

}


int elegirColor(eColor colores[], int tam)
{
    int idColor;
    printf("\nColores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", colores[i].idColor, colores[i].nombreColor);
    }
    printf("\nSeleccione color: ");
    scanf("%d", &idColor);


    return idColor;
}

int elegirMarca(eMarca marcas[], int tam)
{
    int idMarca;
    printf("\nMarcass\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", marcas[i].idMarca, marcas[i].descripcion);
    }
    printf("\nSeleccione marca: ");
    scanf("%d", &idMarca);


    return idMarca;
}
int buscarAuto(eAuto x[], int tamAuto, int idAuto)
{
    int indice = -1;
    for(int i=0; i < tamAuto; i++)
    {


        if( x[i].idAuto == idAuto && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
/*
void mostrarAuto(eAuto car, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    char descMarca[21];
    char descColor[21];
    cargarDescColor(car.idColor, colores, tamColor, descColor);
    cargarDescMarca(car.idMarca, marcas, tamMarca, descMarca);
    printf(" %d    %s    %s    %s    %d\n\n", car.idAuto, car.patente, descMarca, descColor, car.modelo);
}
*/
void mostrarAuto(eAuto autos, eMarca marcas[], int tamMarcas, eColor color[], int tamColor)

{
    char nombreColor[20];
    char descMarca[20];

    cargarDescripcionMarca(marcas, tamMarcas,  autos.idMarca, descMarca);
    cargarDescripcionColor(color, tamColor, autos.idColor, nombreColor);
///    printf(" %d    %s    %s    %s    %d\n\n", car.idAuto, car.patente, descMarca, descColor, car.modelo);

    printf("%d %s  %s  %s    %d \n\n", autos.idAuto, autos.patente, descMarca, nombreColor, autos.modelo);

}

void cargarDescripcionColor(eColor color[], int tamColor, int idColor, char cadena[])
{

    for(int i=0; i < tamColor; i++)
    {
        if( color[i].idColor == idColor)
        {
            strcpy(cadena, color[i].nombreColor);
            break;
        }
    }
}

void cargarDescripcionMarca(eMarca marcas[], int tamMarcas, int idMarca, char cadena[])
{

    for(int i=0; i < tamMarcas; i++)
    {
        if( marcas[i].idMarca == idMarca)
        {
            strcpy(cadena, marcas[i].descripcion);
            break;
        }
    }
}

/*
int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);


    return idSector;
}

*/
