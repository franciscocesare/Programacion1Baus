#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "categorias.h"
#include "juegos.h"

/** \brief completa el array con valores hardcodeados
* \param array juegos
* \param size int Tamaño del array
* \param  cantidad de elementos a cargar
* \return Void, carga datos en la estructura juegos, posicion a posicion
*
*/
void harcodearJuego(eJuego vec[], int tam)
{
    eJuego lista[]=
    {
        {100, "TEG",200, 3},
        {101, "DAMAS",250, 1},
        {102, "METEGOL",500, 4},
        {103, "AJEDREZ",150, 1},
        {104, "RULETA",250, 2},
        {105, "DON MAGO",300, 5},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}


/** \brief obtiene nombre de un juego a traves del id
 *
 * \param estructura juegos
 * \param tamanio estructura
 * \param id del juego a buscar
 * \param donde asignar nombre
 * \return VOID, nombre cargado
 *
 */
void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idJuego == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}

/** \brief Lista un elemento de un array
* \param array juegos
* \param array categoriass
* \param size int Tamaño del array categorias
* \return Void, imprime en pantalla el  nombre de un juego
*
*/
void mostrarJuego(eJuego juegos, eCategoria categorias[], int tam)
{
    char nombre[21];

    obtenerNomCat(categorias, tam, juegos.idCategoria,nombre);

    printf("%d    %8s    %.2f    %10s\n",juegos.idJuego,juegos.descripcion,
           juegos.importe,nombre);
}

/** \brief Lista los elementos de un array
* \param array juegos
* \param tamanio array juegos
* \param array categorias
* \param tamanio array categorias
* \return Void, imprime en pantalla el listado de juegos
*
*/
void mostrarJuegos(eJuego juego[],int tamJ, eCategoria categoria[], int tamC)
{

    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE   CATEGORIA\n\n");

    for(int i=0 ; i<tamJ; i++)
    {
        mostrarJuego(juego[i],categoria,tamC);
    }
}

