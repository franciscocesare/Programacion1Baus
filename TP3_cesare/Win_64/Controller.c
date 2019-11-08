#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path, "r");

    if(pFile==NULL)
    {
        printf("Error");
        return -1;
    }
    else
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path, "rb");
    if (pFile==NULL)
    {
        return -1;
    }
    else
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    //FALTAN VALIDACIONES
    Employee* pEmpleado;

    int todoOk=0;
    char buffer_id[10];
    int idExiste=0;
    char buffer_nombre[30];
    char buffer_horasTrabajadas[30];
    char buffer_sueldo[20];
    int i;

    if(pArrayListEmployee!=NULL)
    {
        do
        {
            idExiste=0;
            system("cls");
            printf("\n\t***ALTA DE EMPLEADO***\n");
            if (getStringNumerosInt(buffer_id,"\nINGRESE EL ID: ", "ERROR INTENTELO DE NUEVO!", 2));
            {

                for(i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    pEmpleado=ll_get(pArrayListEmployee,i);

                    if(pEmpleado->id==atoi(buffer_id))
                    {
                        printf("\nESE ID YA EXISTE, INTENTE CON OTRO\n");
                        idExiste=1;
                        system("pause");
                    }
                }

            }
        }
        while(idExiste);

        getStringLetras(buffer_nombre,"\nINGRESE EL NOMBRE: ","\nERROR INTENTELO NUEVAMENTE", 2);
        getStringNumerosInt(buffer_horasTrabajadas,"\nINGRESE LAS HORAS TRABAJADAS: ", "ERROR, NO SE CARGO EL DAT0",2);
        getStringNumerosInt(buffer_sueldo, "INGRESE EL SUELDO: ","ERROR, NO SE CARGO EL SUELDO",2);

        pEmpleado = employee_newParametros(buffer_id, buffer_nombre, buffer_horasTrabajadas, buffer_sueldo);

        if(pEmpleado != NULL)
        {
            if(ll_add(pArrayListEmployee,pEmpleado) == 0)
            {
                todoOk = 1;
            }
        }
    }

    return todoOk;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmpleado;
    int id;
    char bufferNombre[30];
    char bufferHorasTrabajadas[10];
    char bufferSueldo[10];
    int i;
    int option;

    if (pArrayListEmployee != NULL)
    {
        // busco el empleado a modificar:
        if(!getIntInRange(&id, "\nIngrese el ID del empleado a modificar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListEmployee), 2))
        {
            for (i=0; i<ll_len(pArrayListEmployee); i++) // recorro la lista de empleados
            {
               pEmpleado= ll_get(pArrayListEmployee, i); // me guardo el empleado actual

                if(pEmpleado->id == id) // pregunto si el empleado actual es el que busco
                {

                    do
                    {
                        printf("\nESE ID CORRESPONDE AL EMPLEADO:\n\n ID   NOMBRE    \n%d %6s \n",pEmpleado->id,pEmpleado->nombre);
                    system("pause");
                        getIntInRange(&option,"\nSeleccione un campo a modificar: \n\n"
                                      "1)Modificar Nombre\n"
                                      "2)Modificar Horas Trabajadas\n"
                                      "3)Modificar Sueldo\n"
                                      "4)Salir\n",
                                      "\nIngreso invalido\n",1,4,1);

                        switch(option)
                        {
                        case 1:
                            if(!getStringLetras(bufferNombre, "\nNUEVO NOMBRE: ", "\nERROR\n", 2))
                            {
                                employee_setNombre(pEmpleado, bufferNombre);
                                system("cls");
                                retorno = 0;

                            }

                            break;

                        case 2:
                            if(!getStringNumerosInt(bufferHorasTrabajadas, "\nNUEVAS HORAS TRABAJADAS: ", "\nERROR\n", 2))
                            {
                                employee_setHorasTrabajadas(pEmpleado, bufferHorasTrabajadas);
                                system("cls");
                                retorno = 0;

                            }

                            break;

                        case 3:
                            if(!getStringNumerosInt(bufferSueldo, "\nINGRESE NUEVO SUELDO: ", "\nERROR\n", 2))
                            {
                                employee_setSueldo(pEmpleado, bufferSueldo);
                                system("cls");
                                retorno = 0;
                            }

                            break;

                        }
                    }
                    while(option != 4);
                }
            }
        }
    }

    return retorno;
}

/*int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* eEmpleado;
    int aux=0;
    int aux_id;
    char aux_nombre[30];
    int aux_horasTrabajadas;
    int aux_sueldo;
    int i;
    char answer;

    if(pArrayListEmployee==NULL)
    {
        printf("\nError");
    }
    else
    {
        getInt(&aux_id,"INGRESE EL ID A MODIFICAR","ERROR AL CARGAR EL DATO");
        ///aux_id=getIn("\n Ingrese numero de Id a modificar: ");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            eEmpleado=ll_get(pArrayListEmployee,i);
            if(aux_id==eEmpleado->id)
            {
                printf("\nESE ID CORRESPONDE AL EMPLEADO:\n %d %s %d %d\n",eEmpleado->id,eEmpleado->nombre,eEmpleado->horasTrabajadas,eEmpleado->sueldo);

                answer=getChar("\nDESEA MODIFICAR NOMBRE? s/n : ");
                if(answer=='s' || answer=='S')
                {
                    getStringLetras(aux_nombre,"\nINGRESE EL NOMBRE: ","E\nRROR INTENTELO NUEVAMENTE", 2);
                    ///getString("\n Ingrese nombre: ", aux_nombre);
                    aux=employee_setNombre(eEmpleado, aux_nombre);
                    answer=' ';
                }
                fflush(stdin);
                answer=getChar("\nDESEA MODIFICAR HORAS TRABAJADAS? s/n : ");
                if(answer=='s' || answer=='S')
                {
                    getIntInRange(&aux_horasTrabajadas,"\nINGRESE LAS HORAS TRABAJADAS: ", "ERROR, NO SE CARGO EL DAT0",1,72,2);
                    ///aux_horasTrabajadas=getIn("\n Ingrese horas trabajadas: ");
                    aux=employee_setHorasTrabajadas(eEmpleado,aux_horasTrabajadas);
                    answer=' ';
                }
                fflush(stdin);
                answer=getChar("\nDESEA MODIFICAR SUELDO? s/n : ");
                if(answer=='s' || answer=='S')
                {
                    getInt(&aux_sueldo, "INGRESE EL SUELDO: ","ERROR, NO SE CARGO EL SUELDO");
                    ///aux_sueldo=getIn("\n Ingrese nuevo sueldo: ");
                    aux=employee_setSueldo(eEmpleado,aux_sueldo);
                }
                fflush(stdin);
                ll_set(pArrayListEmployee, i, eEmpleado);
                aux=1;

            }
        }
    }
    return aux;
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
   int retorno = 1;
   Employee* pEmpleado;
   int id;
   int i;

   if (pArrayListEmployee != NULL)
   {
       // busco el empleado a eliminar:
       if(!getIntInRange(&id, "\nIngrese el ID del empleado a eliminar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListEmployee), 2))
       {
           for (i=0;i<ll_len(pArrayListEmployee);i++) // recorro la lista de empleados
           {
               pEmpleado = ll_pop(pArrayListEmployee, i); //VER POP me guardo el empleado actual

               if(pEmpleado->id == id) // pregunto si el empleado actual es el que busco
               {
                   ll_remove(pArrayListEmployee, id);
                   employee_delete(pEmpleado); // para hacer el free
                   retorno = 0;
                   printf("\nSE ELIMINO AL EMPLEADO\n");
                   system("pause");
                   system("cls");
                   break;
               }
           }
       }
   }

   return retorno;
}*/
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* eEmpleado;

    int aux=0;
    int aux_id;
    int i;
    char confirma='n';

    if(pArrayListEmployee==NULL)
    {
        printf("\nError");
    }
    else
    {
        getInt(&aux_id,"\n Ingrese numero de Id: ", "Error");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {

            eEmpleado=ll_get(pArrayListEmployee,i);

            if(aux_id==eEmpleado->id)
            {
                printf("\nSe ha encontrado la siguiente informacion:\n%d %s %d %d\n",eEmpleado->id,eEmpleado->nombre,eEmpleado->horasTrabajadas,eEmpleado->sueldo);
                ///system("pause");
                confirma=getChar("\nCONFIRMA ELIMINAR?");
                if (confirma=='s')
                {
                    ll_remove(pArrayListEmployee,i);
                    aux=1;
                    break;

                }
            }
        }

    }

    return aux;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int largo;
    int i;
    Employee* eEmpleado;

    if(pArrayListEmployee==NULL)
    {
        printf("\nError");
    }
    else
    {
        largo=ll_len(pArrayListEmployee);

        printf("\n %5s %15s %5s %s ","Id","Nombre","Horas Trabajadas", "Sueldo");
        for (i=0; i<largo; i++)
        {
            eEmpleado=ll_get(pArrayListEmployee, i);
            printf("\n %5d %-15s %5d %d",eEmpleado->id, eEmpleado->nombre,eEmpleado->horasTrabajadas, eEmpleado->sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_sort, 1);

        retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile=fopen(path, "w");
    Employee* eEmpleado;
    ///int i;
    int len=ll_len(pArrayListEmployee);
    int aux=0;
    if(pFile==NULL)
    {
        printf("\n Hay un error");
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            eEmpleado= (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d, %s, %d, %d\n", eEmpleado->id, eEmpleado->nombre, eEmpleado->horasTrabajadas, eEmpleado->sueldo);
        }
        aux=1;
    }

    fclose(pFile);
    return aux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path, "wb");
    Employee* eEmpleado;
    //eEmpleado=employee_new();
    ///int i;
    int len=ll_len(pArrayListEmployee);
    int aux=0;

    if(pFile==NULL)
    {
        printf("\n Hay un error");
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            eEmpleado= (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d, %s, %d, %d\n", eEmpleado->id, eEmpleado->nombre, eEmpleado->horasTrabajadas, eEmpleado->sueldo);
        }
        aux=1;
    }

    fclose(pFile);
    return aux;
}


