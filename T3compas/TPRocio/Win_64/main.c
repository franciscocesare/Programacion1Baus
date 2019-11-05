#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    LinkedList* listEmp = ll_newLinkedList();
    char salir;
    int flag=0;
    int chargeBin=0;
    int chargeTxt=0;

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listEmp) == 1)
            {
                printf("Archivo cargado correctamente.\n\n");
                chargeTxt=1;
            }
            else
            {
                printf("Error al cargar archivos.\n\n");
            }
            system("pause");
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listEmp) == 1)
            {
                printf("Archivo cargado correctamente.\n\n");
                chargeBin=1;
            }
            else
            {
                printf("Error al cargar archivos.\n\n");
            }
            system("pause");
            break;
        case 3:
            if(controller_addEmployee(listEmp)==1)
            {
                printf("\nEmpleado dado de alta con exito.\n\n");
            }
            else
            {
                printf("\nError al ingresar el empleado.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(controller_editEmployee(listEmp)==1)
            {
                printf("\nEmpleado modificado con exito.\n\n");
            }
            else
            {
                printf("Error al modificar empleado.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(ll_isEmpty(listEmp)!=1)
            {
                if(controller_removeEmployee(listEmp)==1)
                {
                    printf("Empleado dado de baja con exito.\n\n");
                }
                else
                {
                    printf("Error al dar de baja.\n\n");
                }
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(ll_isEmpty(listEmp)!=1)
            {
                controller_ListEmployee(listEmp);
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 7:
            if(chargeBin == 1 || chargeTxt == 1)
            {
                if(controller_sortEmployee(listEmp)==1)
                {
                    printf("Se ordeno la lista con exito.\n\n");
                }
                else if(controller_sortEmployee(listEmp)==0)
                {
                    printf("Error al ordenar la lista.\n\n");
                }
                else
                {
                    printf("No se han realizado cambios.\n\n");
                }
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 8:
            if(ll_isEmpty(listEmp)!=1)
            {
                if(controller_saveAsText("data.csv",listEmp)==1)
                {
                    printf("\nDatos guardados con exito.\n\n");
                    flag=1;
                }
                else
                {
                    printf("\nError al guardar archivo.\n\n");
                }
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 9:
             if(ll_isEmpty(listEmp)!=1)
            {
                if(controller_saveAsBinary("data.bin",listEmp)==1)
                {
                    printf("\nDatos guardados con exito.\n\n");
                    flag=1;
                }
                else
                {
                    printf("\nError al guardar archivo.\n\n");
                }
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 10:
            if(flag == 0)
            {
                printf("\nNo se han guardado los datos, desea salir de todas formas? s/n: ");
                fflush(stdin);
                scanf("%c",&salir);
                salir=tolower(salir);
            }
            else
            {
                printf("Desea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&salir);
                salir=tolower(salir);
            }
            break;
        default:
            printf("Opcion invalida\n");
            break;

        }
    }
    while(salir != 's');

    return 0;
}




