#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "categorias.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

int menuAlquileres()
{
    int opcion;

    system("cls");
    printf("*****Menu de Alquileres*****\n");
    printf("1-ALTA DE UN ALQUILER\n");
    printf("2-MOSTRAR ALQUILERES\n");
    printf("3-VOLVER AL MENU ANTERIOR\n");
    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief  para indicar que el array esta vacio pone en todas las posiciones,
el isEmpty en 1, vacio
* \param array alquileres
* \param size int tamanio del array
* \return funcion VOID, todas las posiciones inicializadas
*
*/
void inicializarAlquileres(eAlquileres vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmptyAlquiler = 1;
    }
}

/** \brief completa el array con valores hardcodeados
* \param array alquileres
* \param size int Tamaño del array
* \param  cantidad de elementos a cargar
* \return inicia la estructura con valores precargados, cont=cuantos se cargaron
*
*/
int hardcodearAlquileres(eAlquileres vec [], int tam, int cantidad)
{

    int cont = 0;

    eAlquileres aux[]=
    {
        {1,100,1003,{15,12,2019},0},
        {2,102,1002,{5,1,2019},0},
        {3,104,1001,{12,11,2019},0},
        {4,103,1006,{6,8,2019},0},
        {5,102,1007,{22,5,2019},0},
        {6,103,1009,{20,5,2019},0}

    };

    if( cantidad <= tam && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}

/** \brief Busca el primer lugar vacio en un array
* \param array alquiler
* \param size int Tamaño del array
* \param
* \return posicion del array donde se encuentra el valor buscado, el indice vacio
*
*/

int findFreeAlquiler(eAlquileres vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmptyAlquiler == 1 )
        {
            index = i;
            break;
        }
    }
    return index;

}


/** \brief Lista el array completo de alquileres
* \param vector alquileres
* \param vector juegos
* \param tamanio vector juegos
* \param vector clientes
* \param tamanio vector clientes
* \return Void, muestra el array cargado de alquileres
*
*/
void mostrarAlquiler(eAlquileres vec, eJuego juegos[], int tamJ, eCliente lista[], int tamC)
{
    char nomjuego[21];
    char nomCliente[51];

    obtenerNomJuego(juegos,tamJ,vec.idJuego,nomjuego);
    obtenerNomCliente(lista,tamC,vec.idCliente,nomCliente);

    printf(" %2d  %8s  %8d       %02d/%02d/%d\n",vec.idAlquiler,nomjuego,vec.idCliente,
           vec.fechaAlquiler.dia,vec.fechaAlquiler.mes,vec.fechaAlquiler.anio);
}

/** \brief Lista 1 elemento de un array
* \param vector alquileres
* \param vector juegos
* \param tamanio vector juegos
* \param vector clientes
* \param tamanio vector clientes
* \return Void, muestra 1 posicion del array
*
*/
void mostrarAlquileres(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC)
{
    int cont=0;

    system("cls");
    printf("  ID  JUEGO    Id CLIENTE    FECHA_ALQUILER\n\n");



    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmptyAlquiler==0)
        {
            mostrarAlquiler(vec[i],juegos,tamJ,lista,tamC);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay alquileres en el sistema\n\n");
    }
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array alquileres
* \param size int Tamaño del array
* \param contadorID unico que se va a asignar al nuevo elemento
* \return int Return(1) si se agrega un nuevo elemento exitosamente
*
*/
int altaAlquiler(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC,eCategoria categorias[], int tCat, int id)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA ALQUILER ***  \n\n");

    indice=findFreeAlquiler(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        vec[indice].idAlquiler=id;

        mostrarJuegos(juegos,tamJ,categorias,tCat);
        getIntRange(&vec[indice].idJuego,100,105,"\nIngrese codigo de juego: ");

        mostrarClientes(lista,tamC);
        getIntRange(&vec[indice].idCliente,0,9999,"\nIngrese id del cliente: ");


        getIntRange(&vec[indice].fechaAlquiler.dia,1,31,"Ingrese dia de alquiler: ");
        getIntRange(&vec[indice].fechaAlquiler.mes,1,12,"Ingrese mes de alquiler: ");
        getIntRange(&vec[indice].fechaAlquiler.anio,1990,2019,"Ingrese anio de alquiler: ");

        vec[indice].isEmptyAlquiler=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}
