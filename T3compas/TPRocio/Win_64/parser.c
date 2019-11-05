#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int estado=0;
    int cant;
    char buffer[4][40];
    Employee* list = employee_new();

    if(pArrayListEmployee != NULL && pFile != NULL )
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(list !=NULL)
            {
                list = employee_newParametros(buffer[0],buffer[1], buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,list);
                estado=1;
            }
            if(cant < 4)
            {
                if( feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }

        }
    }

    return estado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int estado=0;
    Employee* listBin;

    do
    {
        listBin = employee_new();
        if(fread(listBin,sizeof(Employee),1, pFile)==1) //porque cuento con 1
        {
            ll_add(pArrayListEmployee,listBin);
            estado=1;
        }
        else
        {
            employee_delete(listBin);
        }

    }while( !feof(pFile));

    return estado;
}
