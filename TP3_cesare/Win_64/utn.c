#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/** \brief Obtiene un string
* \param array de char sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error
*/
int getString(char* pStr, char* msg, char*msgE)
{
    char bufferStr[20];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pStr!=NULL)
    {
        strncpy(pStr,bufferStr,20);
    }
    else
    {
        printf("%s",msgE);
    }
    return 0;
}

/** \brief Obtiene una variable int
* \param array de int sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getInt (int *pNum, char* msg, char* msgE)

{
    int number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&number)==1)
    {
        (*pNum)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
    }
    return ret;
}

/** \brief Obtiene una variable int dentro de cierto rango
* \param array de int sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param min delimita el minimo del rango
* \param max delimita el maximo del rango
* \param la cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getIntInRange(  int *pNum,
                    char *msg,
                    char *msgE,
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno = -1;
    char bufferStr[20];
    int bufferInt;
    if( pNum != NULL &&
            reintentos >= 0)
    {
        if(!getString(bufferStr,msg,msgE) &&
                isNumberInt(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pNum = bufferInt;
            }
        }
    }
    return retorno;
}

/** \brief Obtiene un array de letras
* \param array de string (validado con letras)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isLetter(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}
/** \brief Obtiene un array de numeros int
* \param array de string (validado con int)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getStringNumerosInt (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumberInt(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}


/** \brief Ordena array de mayor a menor
* \param array de char
* \param tamaño del array
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int ordenarArrayMayorMenor(char* pArray, int len,int limit)
{
    int i;
    int j;
    char buffer[limit];
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(pArray[i]>pArray[j])
            {
                buffer[i]=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=buffer[i];
            }
        }
    }
    return 0;
}
/** \brief Muestra un array de int
* \param array de int
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int showArrayInt(int* pArray,int len)

{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}
/** \brief Muestra array de char
* \param array de char
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int showArrayChar(char* pArray,int len)

{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}
/** \brief Valida numeros enteros
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isNumberInt (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Valida letras minusculas y mayusculas
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isLetter (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

char getChar(char mensaje[]){
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    tolower(aux);
    return aux;
}


/*
int getIn ( char mensaje[]) {
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
    }

float getFloat (char mensaje[]){
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}

char getChar(char mensaje[]){
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}


int esNumerico (char str []){
    int i=0;
    while (str[i]!='\0'){
        if(str[i]<'0' || str[i]>'9'){
        return 0;
        }
        i++;
    }
    return 1;
}

int esLetras (char str[]){
int i=0;
    while (str[i]!='\0'){
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}


int esAlfaNumerico (char str[]) {
    int i=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}

int esTelefono (char str[]){
    int i=0;
    int contGuion=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]!='-')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        if (str[i]=='-'){
            contGuion++;
        }
        i++;
    }
    if (contGuion==1)
        return 1;

    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int checkLenght(char str[], int i){
if (strlen(str)>i){
    return 0;
}
return 1;
}
int checkLenghtTelefono(char str[], int i){
if (strlen(str)!=i){
    return 0;
}
return 1;
}

int limitadorInt(float valor, int lowLimit, int highLimit){
if( valor < lowLimit || valor > highLimit )
    {
        printf("Error. No respeta los limites");
        return 0;
    }
return 1;
}

int validarOpcion(int opcion, int a, int b){
    if(opcion<0 || opcion>9){
        return -1;
        }
    if (opcion==0){
        return opcion;
    }else if(opcion>a || opcion<b){
        return opcion;
    }
    return -1;
}

char getCharSexo(void){
    char auxiliar;
    printf("\nIngrese el sexo [f/m]: ");
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar = toupper(auxiliar);
    while(auxiliar != 'F' && auxiliar != 'M')
    {
        printf("\nError! Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%c",&auxiliar);
        auxiliar = toupper(auxiliar);
    }
    return auxiliar;
}

int getIntLimitado(char mensaje[], char eMensaje[], int lowLimit, int highLimit)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    while( auxiliar < lowLimit || auxiliar > highLimit )
    {
        printf( "%s" , eMensaje );
        scanf( "%i" , &auxiliar );
    }

    return auxiliar;
}

int checkMail(char email[]){
int i;
for(i = 0; email[i]; i++){
    if (email[i] == '@'){
    printf("Valido.\n");
    return 1;
    }
}
return 0;
}
*/

