
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

/** \brief para ingresar un numero con limites max y min
 *
 * \param donde asignar el numero obtenido
 * \param numero minimo que se puede cargar
 * \param numero maximo que se puede cargar
 * \param mensaje para pedir el numero
 * \return 1 si el telefono es valido, 0 sino es valido
 *
 */

void getIntRange(int* dondeAsignar, int min, int max, char* mensaje)
{

    int auxInt;
    char aux[20];

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(aux);


    for(int i=0; i<strlen(aux); i++)
    {
        while(isdigit(aux[i])==0)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxInt=atoi(aux);

    while(auxInt < min || auxInt > max)
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        scanf("%d",&auxInt);
    }


    *dondeAsignar = auxInt;

}

/** \brief para ingresar el sexo de un cliente y cargarlo
 *
 * \param puntero adonde asignar el char obtenido
 * \param mensaje de pedido de dato
 * \param mensaje de error
 * \return VOID variable cargada
 *
 */
void pedirSexo(char* dondeAsignar, char* mensaje)
{
    char aux;

    printf("%s",mensaje);
    fflush(stdin);
    aux=getchar();

    while(aux !='f' && aux!='m' && aux!='F' && aux!= 'M')
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        aux=getchar();
    }
    aux=toupper(aux);
    *dondeAsignar = aux;
}

/** \brief para validar el telefono ingresado
 *
 * \param mensaje de pedido de telefono
 * \param mensaje de pedido de telefono, por error al ingresar
 * \param tamanio minimo a ingresar
 * \param tamanio maximo a ingresar
 * \param numero minimo que se puede ingresar
 * \param numero maximo que se puede ingresar
 * \param reintentos para cargar
 * \param puntero adonde asignar el valor cargado
 * \return 0 si el telefono se cargo
 *
 */
int getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* dondeAsignar)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && dondeAsignar!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidTelephone(bufferStr)==1)
                {
                    strncpy(dondeAsignar,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%sIntento numero 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/** \brief para validar el telefono ingresado
 *
 * \param string de telefono
 * \param
 * \return 1 si el telefono es valido, 0 sino es valido
 *
 */

int isValidTelephone(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief para validar el string ingresado
 *
 * \param string
* \param mensaje de pedido
* \param mensaje de error
* \param minimo a ingresar
* \param maximo a ingresar
* \param reintentos
 * \param buffer str para guardar aux
  * \param resultado, donde se va a guardar el valor
 * \return 0 si el string es valido, -1 sino es valido
 *
 */

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

/** \brief para obtener un string alfabetico
 *
 * \param tamanio maximo a ingresar
* \param mensaje de pedido de dato
 * \param AUX para guardar aux y medir el tamanio
  * \param donde asignar, puntero adonde se va a guardar el valor
 * \return VOid, carga un string en una variable
 *
 */
void getStringAlpha(int longMax, char* mensaje, char* dondeAsignar)
{

    char aux[longMax];

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while((isalpha(aux[i])==0) || strlen(aux) > longMax)
        {
            printf("Error. Intentelo nuevamente %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    strupr(aux);

    strcpy(dondeAsignar, aux);

}

/** \brief para obtener un string alfanumerico
 *
 * \param tamanio maximo a ingresar
* \param mensaje de pedido de dato
 * \param AUX para guardar aux y medir el tamanio
  * \param donde asignar, puntero adonde se va a guardar el valor
 * \return VOid, carga un string alfanum en una variable, aqui una direccion
 *
 */
void getStringAlphaNum(int longMax, char* mensaje, char* dondeAsignar)
{
    char aux[longMax];
    int i=0;

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while( strlen(aux) > longMax)
        {
            printf("Error. intentelo nuevamente %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    strlwr(aux);
    aux[0]=toupper(aux[0]);

    while( aux[i] != '\0')
    {
        if(aux[i] == ' ')
        {
            aux[i +1] = toupper(aux[i+1]);

        }
        i++;
    }

    strcpy(dondeAsignar, aux);

}
