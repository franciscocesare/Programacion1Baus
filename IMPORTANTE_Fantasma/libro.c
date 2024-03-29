#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libro.h" ///cambiar por nombre entidad
#include "autor.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libro Array of libro
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libro_Inicializar(Libro array[], int size)                                    //cambiar libro
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array libro Array de libro
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libro_buscarEmpty(Libro array[], int size, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array libro Array de libro
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idLibro==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array libro Array de libro
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion)          ///cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)         ///cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array libro Array de libro
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice)       ///cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)      ///cambiar campo titulo
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array libro Array de libro
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libro_alta(Libro array[], Autor autores [], int size, int sizeAutores, int* contadorID)      ///cambiar libro
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libro_buscarEmpty(array,size,&posicion)==-1)      ///cambiar libro
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idLibro=*contadorID;         ///campo ID
            array[posicion].isEmpty=0;
            autor_listar(autores, sizeAutores);///para que muestre el listado de autores
            utn_getUnsignedInt("\n Elija un autor: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idAutor); ///GUARDAR EN UN BUFFER Y VALIDAR QUE EXISTA EN LISTADO DE AUTORES(LINEA SGTE)          //mensaje + cambiar campo varInt
            ///utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("ingrese el titulo\n: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo); ///titulo ingresado lo guarda en titulo                     //mensaje + cambiar campo titulo
            ///utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n titulo: %s\n",
                   posicion, array[posicion].idLibro,array[posicion].titulo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libro Array de libro
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_baja(Libro array[], int sizeArray)                                      //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idLibro=0;                                                                   //cambiar campo id
            ///array[posicion].varInt=0;                                                               //cambiar campo varInt
            ///array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].titulo,"");                                                   //cambiar campo titulo
            ///strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libro Array de libro
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idLibro==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idLibro=0;                                                                   //cambiar campo id
                ///array[i].varInt=0;                                                               //cambiar campo varInt
                ///array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].titulo,"");                                                   //cambiar campo titulo
               /// strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libro Array de libro
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libro_modificar(Libro array[], int sizeArray)          ///cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;                                                           ///cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   ///cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                    ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                               ///cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n titulo: %s\n ",
                       posicion, array[posicion].idLibro,array[posicion].titulo);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                       /// utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);  ///mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        /// utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);   ///mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);     ///mensaje + cambiar campo titulo
                        break;
                    case 'D':
                        ///utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);    ///mensaje + cambiar campo varLongString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array libro Array de libro
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libro_ordenarPorString(Libro array[],int size)                              ///cambiar libro
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               ///cambiar campo titulo
    int bufferId;
    int bufferIsEmpty;

    ///int bufferInt;                                              ///cambiar buffer int
    ///float bufferFloat;                                          ///cambiar buffer varFloat
    ///char bufferLongString[TEXT_SIZE];                           ///cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].titulo);                      //cambiar campo titulo
            bufferId=array[i].idLibro;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            ///bufferInt=array[i].varInt;                                //cambiar campo varInt
            ///bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            ///strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].titulo)<0)         //cambiar campo titulo                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].titulo,array[j].titulo);          //cambiar campo titulo
                array[j + 1].idLibro=array[j].idLibro;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

               /// array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
               /// array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                ///strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].titulo,bufferString);                     //cambiar campo titulo
            array[j + 1].idLibro=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

///            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
     ///       array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            ///strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array libro Array de libro
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libro_listar(Libro array[], int size)            ///cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d \n titulo: %s\n ",
                       array[i].idLibro,array[i].titulo);      ///cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
