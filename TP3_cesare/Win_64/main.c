#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagAltaTxt=0;
    int flagAltaBin=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("\n\t\t Trabajo Practico Nro.3\n");

    do
    {
        getIntInRange(&option,"\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n 3. Alta de empleado\n 4. Modificar datos de empleado\n 5. Baja de empleado\n 6. Listar empleados\n 7. Ordenar empleados\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n 10. Salir\nSu opcion: ","\nOPCION INVALIDA!",1,10,2);

        switch(option)
        {
        case 1:
            if (flagAltaTxt)
            {
                printf("\n***EL ARCHIVO YA FUE CARGADO***\n");
                system("pause");
                system ("cls");
            }
            else if(controller_loadFromText("data.csv",listaEmpleados))
            {
                flagAltaTxt=1;
                system("cls");
                printf("\n***EL ARCHIVO TEXTO SE CARGO CORRECTAMENTE!***");
            }
            break;
        case 2:
            if (flagAltaBin)
            {
                printf("\n***EL ARCHIVO YA FUE CARGADO***\n");
                system("pause");
                system ("cls");
            }
            else if(controller_loadFromBinary("data.csv", listaEmpleados))
            {
                flagAltaBin=1;
                system("cls");
                printf("\n***EL ARCHIVO BINARIO SE CARGO CORRECTAMENTE!***\n");
            }
            break;
        case 3:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("\n***AUN NO SE CARGARON ARCHIVOS***\n");
            }
            else
            {
                if(controller_addEmployee(listaEmpleados))
                {
                    system("cls");
                    printf("\n***SE DIO DE ALTA EL EMPLEADO***\n");
                }
                else
                {
                    system("cls");
                    printf("Algo fallo. Alta no realizada");
                }
            }
            break;
        case 4:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("\n***AUN NO SE CARGARON ARCHIVOS***\n");
            }
            else
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("\n Modificacion exitosa");
                }
                else
                {
                    printf("Algo fallo. Modificacion no realizada");
                }
            }
            break;
        case 5:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("\n***AUN NO SE CARGARON ARCHIVOS***\n");
            }
            else
            {
                if(controller_removeEmployee(listaEmpleados))
                {
                    system("cls");
                    printf("Se ha eliminado al empleado");
                }
                else
                {
                    printf("Error. Baja no realizada");
                }
            }
            break;
        case 6:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("\n***AUN NO SE CARGARON ARCHIVOS***\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }
            break;
        case 7:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("No se ha cargado el archivo aun");
            }
            else {
                controller_sortEmployee(listaEmpleados);
                printf("EL ARCHIVO HA SIDO ORDENADO POR ORDEN ALFABETICO ");
                system("cls");
            }
            break;
        case 8:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("No se ha cargado el archivo aun");
            }
            else
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    system("cls");
                    printf("El archivo se ha guardado");
                }
            }
            break;
        case 9:
            if(flagAltaTxt==0 && flagAltaBin==0)
            {
                system("cls");
                printf("No se ha cargado el archivo aun");
            }
            else
            {
                if(controller_saveAsBinary("data.csv",listaEmpleados))
                {
                    system("cls");
                    printf("El archivo se ha guardado");
                }
            }
            break;
        }
    }
    while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
