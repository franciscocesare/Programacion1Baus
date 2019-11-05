#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputDiaz.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int estado=0;
    FILE* f;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "r");

        if(f==NULL)
        {
            estado=0;
            exit(1);
        }
        else
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            fclose(f);
            estado=1;
        }

    }

    return estado;
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
    FILE* f;
    int estado=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path,"rb");

        if(f != NULL)
        {
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            fclose(f);
            estado=1;
        }
        else
        {
            fclose(f);
            estado=0;
            exit(1);
        }

    }

    return estado;
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
    int estado=0;
    int auxSueldo;
    int auxId;
    int auxHoras;
    char *auxChar = (char*) malloc(sizeof(char)*31);
    Employee* this;

    if(pArrayListEmployee != NULL)
    {
        obtenerNumeroEntre(&auxId, 99999, 0,"Ingresar id del empleado: ");

        obtenerCadenaChar(auxChar, 128, "Ingrese nombre: ");

        obtenerNumeroEntre(&auxHoras,1000,0,"Ingresar horas trabajadas: ");

        obtenerNumeroEntre(&auxSueldo,500000,0,"Ingresar sueldo del empleado: ");

        this = employee_new();

        if(this != NULL)
        {
            if( employee_setId(this,auxId) == 1 &&
                    employee_setNombre(this,auxChar) == 1 &&
                    employee_setHorasTrabajadas(this,auxHoras) == 1 &&
                    employee_setSueldo(this,auxSueldo) == 1 )
            {
                ll_add(pArrayListEmployee,this);
                estado=1;
            }
            else
            {
                estado=0;
                exit(1);
            }
        }

    }

    free(auxChar);
    return estado;
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
    int auxId;
    int auxSueldo;
    int auxHoras;
    int len;
    int estado=0;
    char salir;
    char *auxChar = (char*) malloc(sizeof(char)*31);
    Employee *this;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        obtenerNumeroEntre(&auxId, 99999, 0,"Ingresar id del empleado: ");
        system("cls");

        for( int i = 0; i <len ; i++ )
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);

            if( auxId == this->id )
            {
                do
                {
                    switch(menuModify())
                    {
                    case 1:
                        obtenerCadenaChar(auxChar, 128, "Ingrese nombre: ");
                        if(employee_setNombre(this,auxChar)==1)
                        {
                            estado=1;
                        }
                        break;
                    case 2:
                        obtenerNumeroEntre(&auxHoras,1000,0,"Ingresar horas trabajadas: ");
                        if(employee_setHorasTrabajadas(this, auxHoras)==1)
                        {
                            estado=1;
                        }
                        break;
                    case 3:
                        obtenerNumeroEntre(&auxSueldo,500000,0,"Ingresar sueldo del empleado: ");
                        if(employee_setSueldo(this, auxSueldo)==1)
                        {
                            estado=1;
                        }
                        break;
                    case 4:
                        printf("\nDesea salir? s/n: ");
                        fflush(stdin);
                        scanf("%c",&salir);
                        salir=tolower(salir);
                        break;
                    default:
                        printf("Opcion invalida\n");
                        break;
                    }
                }
                while(salir != 's');

            }
        }
    }
    return estado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* this;
    int len;
    int auxId;
    int estado=0;
    char confirma;

    if(pArrayListEmployee !=NULL)
    {
        len=ll_len(pArrayListEmployee);
        obtenerNumeroEntre(&auxId, 99999, 0,"Ingresar id del empleado: ");

        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);

            if(this->id == auxId)
            {
                printf("\nSeguro desea dar de baja el empleado? s/n: ");
                fflush(stdin);
                scanf("%c",&confirma);
                confirma=tolower(confirma);

                if(confirma=='s')
                {
                    ll_remove(pArrayListEmployee, i);
                    printf("Empleado dado de baja con exito!\n");
                    employee_delete(this);
                    estado=1;
                    break;
                }
                else
                {
                    printf("Operacion cancelada!!\n");
                }

            }
        }
    }

    return estado;
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

    int estado=0;
    int len;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);

        if(len > 0)
        {
            printf("\n\nID     NOMBRE   HORAS TRABAJADAS   SUELDO\n\n");

            for(int i=0; i<len; i++)
            {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
                listarEmployee(auxEmployee);
                estado=1;
            }
        }

    }
    printf("\n\n");

    return estado  ;
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
    int estado=0;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        switch(menuListar())
        {
        case 1:
            if(ll_sort(pArrayListEmployee, ordenarPorId, 1)==1)
            {
                estado=1;
            }
            system("pause");
            break;
        case 2:
            if(ll_sort(pArrayListEmployee, ordenarPorNombre, 1)==1)
            {
                estado=1;
            }
            system("pause");
            break;
        case 3:
            if(ll_sort(pArrayListEmployee, ordenarPorHoras, 1)==1)
            {
                estado=1;
            }
            system("pause");
            break;
        case 4:
            if(ll_sort(pArrayListEmployee, ordenarPorSueldo, 1)==1)
            {
                estado=1;
            }
            system("pause");
            break;
        case 5:
            estado=-1;
            menu();
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            break;
        }
    }

    return estado;
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
    int len;
    int i;
    int estado=0;
    FILE* f;
    Employee* emp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f=fopen(path,"w");
        len=ll_len(pArrayListEmployee);

        if(f != NULL)
        {
            for(i=0; i<len; i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(f, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            }

            fclose(f);

            if(i == len)
            {
                estado=1;
            }
            else
            {
                estado=0;
            }
        }
        else
        {
            estado=0;
        }
    }

    return estado;
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
     int len;
    int i;
    int estado=0;
    FILE* f;
    Employee* emp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f=fopen(path,"wb");
        len=ll_len(pArrayListEmployee);

        if(f != NULL)
        {
            for(i=0; i<len; i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(emp,sizeof(Employee),1,f);
            }

            fclose(f);

            if(i == len)
            {
                estado=1;
            }
            else
            {
                estado=0;
            }
        }
        else
        {
            estado=0;
        }
    }

    return estado;
}

