
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "categorias.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"


int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE INFORMES ***   \n\n");
    printf("1. Mostrar juegos de categoria mesa\n");
    printf("2. Mostrar alquileres efectuados por algun cliente\n");
    printf("3. Mostrar total de todos los importes pagados por el cliente seleccionado\n");
    printf("4. Listar clientes que no alquilaron juegos\n");
    printf("5. Listar juegos que no han sido alquilados\n");
    printf("6. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

/** \brief muestra solo juegos de Mesa
 *
 * \param estructura juegos
 * \param tamanio de Juegos
 * \param estructura categorias
 * \param tamanio de Categorias
 *
 */
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)
{
    char categoria[21];

    system("cls");
    printf("*******JUEGOS DE CATEGORIA MESA: ******\n\n");
    printf(" IDcat    NOMBRE    IMPORTE     CATEGORIA\n\n");

    for(int i=0; i<tamJ; i++)
    {
        for(int j=0; j<tamC; j++)
        {
            if(juego[i].idCategoria == cat[j].idCategoria)
            {
                obtenerNomCat(cat,tamC,juego[i].idCategoria,categoria);

                if(strcmpi(categoria,"mesa")==0)
                {
                    mostrarJuego(juego[i],cat,tamC);
                }
            }
        }
    }

}

/** \brief muestra los alquileres dados de alta por un cliente seleccionado
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return listado de juegos alquilados por cliente selccionado
 *
 */
void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                               eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese el id del cliente: ");


    esta=buscarCliente(idCliente, cliente, tamC);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de un cliente: ");


        esta=buscarCliente(idCliente, cliente, tamC);

    }
    if(esta != -1)
    {
        system("cls");
        printf("\n\nEl cliente numero %d Alquilo: \n\n",idCliente);
        printf("  ID  JUEGO     CLIENTE       FECHA_ALQUILER\n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmptyAlquiler == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);
            }
        }


    }

}

/** \brief muestra el importe total de los alquileres efectuados por un cliente seleccionado, busca por ID
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return VOID, listado de importes por cliente seleccionado
 *
 */
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;
    int cont=0;
    float total;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");
    esta=buscarCliente(idCliente, cliente, tamC);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de un cliente : ");
        esta=buscarCliente(idCliente, cliente, tamC);

    }
    if(esta != -1)
    {
        system("cls");

        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n");


        printf("El cliente numero %d alquilo: \n\n",idCliente);
        printf("Id      Juego    Id Cliente    Fecha \n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmptyAlquiler == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for(int j=0; j<tamJ; j++)
                {
                    if(juegos[j].idJuego == alq[i].idJuego)
                    {
                        total=total+juegos[j].importe;
                        cont++;

                    }
                }
            }
        }

        if(cont == 0)
        {
            system("cls");
            printf("\nNO HAY ALQUILERES DEL CLIENTE");
        }
        else
        {
            printf("\n\nImporte total del cliente %.2f \n\n",total);
        }


    }

}

/** \brief muestra clientes con o sin alquileres efectuados, buscando por ID
 *
 * \param id del cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return 1 para mostrar clientes con alquiler, 0 para mostrar clientes sin alquileres
 *
 */
int mostrarAlquileresClientes(int idCliente,eAlquileres vecAlquiler[],int tamAl)
{
    int alquiler=0;

    for(int i=0; i<tamAl; i++)
    {
        if(vecAlquiler[i].isEmptyAlquiler==0 && vecAlquiler[i].idCliente == idCliente)
        {
            alquiler=1;
        }
    }

    return alquiler;
}

/** \brief muestra clientes sin alquileres efectuados
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return sin retorno
 *
 */
void clientesSinAlquiler(eCliente vecClientes[],int tamCl, eAlquileres vecAlquiler[],int tamAl)
{
    int cont=0;

    system("cls");
    printf("Clientes que no han alquilado juegos:\n\n");

    for(int i=0; i<tamCl; i++)
    {
        if(mostrarAlquileresClientes(vecClientes[i].idCliente,vecAlquiler,tamAl)==0)
        {
            mostrarCliente(vecClientes[i]);
            cont++;
        }


    }

    if(cont==0)
    {
        printf("\nNo hay clientes sin alquileres");
    }

}

/** \brief muestra juegos con o sin alquileres efectuados
 *
 * \param id del juego
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return 1 para mostrar juegos con alquiler, 0 para mostrar juegos sin alquileres
 *
 */
int mostrarJuegosAlquilados(int idJuego,eAlquileres vec[],int tam)
{
    int alquiler=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmptyAlquiler==0 && vec[i].idJuego == idJuego)
        {
            alquiler=1;
        }
    }

    return alquiler;
}

/** \brief muestra juegos sin alquilear
 *
 * \param estructura Juegos
 * \param tamanio juegos
* \param estructura Alquiler
 * \param tamanio Alquiler
 * \param estructura categorias
 * \param tamanio categorias
 *\return VOID, imprime listado de juegos sin alquilar
 */

void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquileres vecAl[],int tamAl, eCategoria vecCa[], int tamCa)
{
    int cont=0;

    system("cls");
    printf("ESTOS JUEGOS NO FUERON ALQUILADOS:\n\n");

    for(int i=0; i<tamJ; i++)
    {
        if(mostrarJuegosAlquilados(vecJ[i].idJuego,vecAl,tamAl)==0)///si no fueron alquilados
        {
            mostrarJuego(vecJ[i],vecCa,tamCa);
            cont++;
        }

    }

    if(cont == 0)
    {
        printf("\nTODOS LOS JUEGOS TUVIERON ALGUN ALQUILER");
    }

}


