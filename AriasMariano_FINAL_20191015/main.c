#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"

int main()
{
    int option;
    int flag=0;
    int flagD=0;

    FILE *pArch;

    LinkedList* listaLibros=ll_newLinkedList();
    LinkedList* listaConDescuentos;

    // char nombre[20]; Variable para recibir el nombre de archivo por teclado

    do
    {
        option=menuInicio();
        switch(option)
        {
        case 1:
            // getString("\nIngrese el nombre y ruta del archivo que desea abrir: (datosMF_20191015.csv)",nombre);
            if((pArch=fopen( "datosMF_20191015.csv","r"))==NULL)
            {
                printf("\nEl archivo no pudo ser abierto");
                // printf("\nEl archivo %s no pudo ser abierto",nombre);
            }
            else
            {
                system("cls");
                if(parser_FromText(pArch, listaLibros))
                {
                    printf(" ---- Archivo abierto exitosamente ! --- \n");
                    flag=1;
                }
            }
            fclose(pArch);
            break;

        case 2:
            if(!flag)
            {
                system("cls");
                printf("\n No se cargo el archivo aun");
            }
            else
            {
                ll_sort(listaLibros, ordenar,1);
                system("cls");
                printf("\n ------ Se ha ordenado la lista -------\n ");
                // printerList(listaLibros);
            }

            break;
        case 3:

            if(flag)
            {
                printerList(listaLibros);
            }
            else
            {
                system("cls");
                printf("No se cargo el archivo aun");
            }
            break;

        case 4:
            if(flag)
            {
                listaConDescuentos=ll_map(listaLibros, setDescuento);
                printerList(listaConDescuentos);
                flagD=1;
                printf("\n\n ------ Se han cargado los descuentos correspondientes a la lista ------- \n");
            }
            else
            {
                system("cls");
                printf("\n No se cargo el archivo aun");
            }
            break;

        case 5:
            if(flag)
            {
                if(flagD)
                {
                    if(parser_SaveToText(listaConDescuentos, "mapeado.csv"))
                    {
                        system("cls");
                        printf("\n ----- Archivo ha sido creado! ------");
                    }
                    else
                    {
                        system("cls");
                        printf("Error. El archivo no ha sido creado.");
                    }
                }
                else
                {
                    system("cls");
                    printf("Error. El archivo no ha sido creado.");
                }
            }
            else
            {
                system("cls");
                printf("\n No se cargo el archivo aun");
            }
            break;
        }
    }
    while(option != 0);

    return 0;
}


