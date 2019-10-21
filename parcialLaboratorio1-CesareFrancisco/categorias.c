
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "categorias.h"

/** \brief Lista 1 elemento de un array
* \param 1 array categorias
* \return Void, imprime en pantalla el listado de mostrar categorias
*
*/
void mostrarCategoria(eCategoria categorias)
{

    printf(" %d     %s  \n", categorias.idCategoria, categorias.descripcion);
}

/** \brief Lista los elementos de un array
* \param array categorias
* \param size int Tamaño del array
* \return Void, imprime en pantalla el listado de mcategorias de juegos
*
*/
void mostrarCategorias(eCategoria categorias[], int tamCat)
{
    int cont = 0;
    printf("  ID     DESCRIPCION\n");
    for(int i=0; i<tamCat; i++)
    {
        mostrarCategoria(categorias[i]);
        cont++;
    }
    if(!cont)
    {
        printf("NO HAY CATEGORIAS QUE MOSTRAR\n\n");
    }
}

/** \brief completa el array con valores hardcodeados
* \param array categorias
* \param size int Tamaño del array
* \return Void, carga datos en la estructura categoria, posicion a posicion
*
*/
void hardcodearCategoria(eCategoria vec[], int tam)
{

    eCategoria categorias[] =
    {
        {1, "MESA"},
        {2, "AZAR"},
        {3, "ESTRATEGIA"},
        {4, "SALON"},
        {5, "MAGIA"},

    };

    for(int i=0 ; i<tam; i++)
    {
        vec[i] = categorias[i];
    }

}

/** \brief obtiene descripcion de una categoria a traves del id
 *
 * \param estructura categorias
 * \param tamanio estructura categorias
 * \param id de la categoria a buscar
 * \param donde asignar categoria
 * \return VOID, nombre cargado
 *
 */
void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0 ; i<tam; i++)
    {
        if(vec[i].idCategoria == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}
