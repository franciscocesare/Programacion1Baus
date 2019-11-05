#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"


int validarCararteres(char letra[], char mensaje[])
{

    for(int i=0; i<strlen(letra); i++)
    {
        while(!(isalpha(letra[i])))
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%s",letra);
        }
    }

    return 1;
}

int validarNumeros(char numero[],char mensaje[])
{

    for(int i=0; i<strlen(numero); i++)
    {
        while(!(isdigit(numero[i])))
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%s",numero);
        }
    }
    return 1;
}

int preguntarSiEstaSeguro(char mensaje[])
{
    char confirma;
    int i;

    printf("\n%s",mensaje);
    fflush(stdin);
    confirma = tolower(getche());

    while(confirma!='s' && confirma!='n')
    {
        printf("\n\n*** Error ***");
        printf("\n%s",mensaje);
        fflush(stdin);
        confirma = tolower(getche());
    }
    if (confirma == 's')
    {
        i=1;
    }
    else
    {
        i=0;
    }

    return i;
}

void obtenerCadenaChar(char dondeAsginar[], int tamMax, char mensaje[])
{
    char *auxChar = (char*) malloc(sizeof(char)*100);
    char letra;


    printf("\n%s",mensaje);
    fflush(stdin);
    gets(auxChar);

    letra=validarCararteres(auxChar, mensaje);

    if(letra==1)
    {

        while(strlen(auxChar)>tamMax || strlen(auxChar) < 1)
        {
            printf("\n*** Error ***");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(auxChar);
        }

        strlwr(auxChar);
        auxChar[0] = toupper(auxChar[0]);
        strcpy(dondeAsginar, auxChar);
        free(auxChar);
    }
}

void obtenerEmail(char dondeAsignar[], int tamMax, char mensaje [])
{
    int cantidadArrobas;
    int cantidadPuntos;
    int pusoArroba;
    int invalido;
    char *aux = (char*) malloc(sizeof(char)*tamMax);

    do
    {
        cantidadArrobas = 0, cantidadPuntos = 0, invalido = 0, pusoArroba = 0;
        fflush(stdin);
        printf("\n%s",mensaje);
        gets(aux);
        strlwr(aux);

        for(int i=0 ; i<strlen(aux)-1 ; i++)
        {

            if (aux[i] == ' ')
            {
                invalido = 1;
                break;
            }

            if (i==0 && (aux[i] == '@' || aux[i] == '.'))
            {
                invalido = 1;
                break;
            }

            if ( ((aux[i] < 'a' || aux[i] > 'z') && (aux[i]<'0' || aux[i]>'9')) && (aux[i] != '@') && (aux[i] != '.') && (aux[i] != '_') && (aux[i] =! '-')  )
            {
                invalido=1;
                break;
            }

            if (aux[i] == '@')
            {
                if (cantidadArrobas >= 1)
                {
                    invalido=1;
                    break;
                }
                pusoArroba = 1;
                cantidadArrobas ++;
            }

            if (aux[i] == '.')
            {

                if (cantidadPuntos >= 1 || pusoArroba == 0)
                {
                    invalido = 1;
                    break;
                }
                cantidadPuntos ++;
            }

        }

        if(cantidadPuntos == 0 || pusoArroba == 0)
        {
            invalido = 1;
        }

        if ( invalido == 1 )
        {
            printf("\n*** eMail invalido ***\n");
        }

    }
    while (invalido == 1);


    int len = strlen(aux);

    if(aux[len-1]=='\n')
    {

        aux[len-1]='\0';
    }

    strcpy(dondeAsignar, aux);
    free(aux);
}

void obtenerTelefono(char dondeAsignar[], int tamMax, char mensaje[])
{
    char *auxTel = (char*) malloc(sizeof(char)*100);
    char tel;

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(auxTel);

    tel=validarNumeros(auxTel, "## Ingresar telefono: ");

    if(tel==1)
    {

        while(strlen(auxTel)>tamMax || strlen(auxTel) < 7)
        {
            printf("*** Error ***\n");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(auxTel);
        }

        strcpy(dondeAsignar, auxTel);
    }

    free(auxTel);
}

void obtenerSexo(char * dondeAsignar, char mensaje[])
{

    char aux;

    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    aux =tolower(aux);

    while(!((aux=='f')||(aux=='m')) )
    {
        printf("\n*** Error ***\n");
        printf("\n%s",mensaje);
        scanf("%c",&aux);
        aux =tolower(aux);
    }

    *dondeAsignar=aux;
}

void obtenerNumeroEntre(int * dondeAsignar, int tamMax, int tamMin, char mensaje[])
{
    int aux;

    printf("\n%s",mensaje);
    scanf("%d",&aux);


    while(aux > tamMax || aux < tamMin)
    {
        printf("\n*** Error ***\n");
        printf("\n%s",mensaje);
        scanf("%d",&aux);
    }

    *dondeAsignar=aux;

}

void obtenerNumeroIgualA(int dondeAsignar, int tam, char mensaje[])
{
    int aux;

    printf("\n%s",mensaje);
    scanf("%d",&aux);


    while(aux != tam)
    {
        printf("\n*** Error ***\n");
        printf("\n%s",mensaje);
        scanf("%d",&aux);
    }

    dondeAsignar=aux;

}
