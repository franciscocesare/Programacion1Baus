#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int auxId;
    int auxSueldo;
    int auxHoras;

    Employee* this = employee_new();

    auxId = atoi(idStr);
    auxHoras = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldoStr);

    employee_setId(this, auxId);
    employee_setNombre(this, nombreStr);
    employee_setSueldo(this, auxSueldo);
    employee_setHorasTrabajadas(this, auxHoras);

    return this;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
    int estado=0;

    if(this != NULL && id > 0)
    {
        this->id=id;
        estado=1;
    }
    return estado;
}

int employee_getId(Employee* this,int* id)
{
    int estado=0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        estado=1;
    }

    return estado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre!= NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre, nombre);
        estado=1;
    }

    return estado;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        estado=1;
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        estado=1;
    }
    return estado;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        estado=1;
    }

    return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int estado=0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        estado=1;
    }
    return estado;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int estado=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        estado=1;
    }

    return estado;
}

void mostrarEmployee(Employee* emp)
{
    printf("%d  %s  %d  %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}

int menu()
{
    int opcion;

    system("cls");
    printf("                    ###   Menu   ###\n");
    printf("--------------------------------------------------------\n\n");
    printf("1_ Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2_ Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3_ Alta de empleado\n");
    printf("4_ Modificar datos de empleado\n");
    printf("5_ Baja de empleado\n");
    printf("6_ Listar empleados\n");
    printf("7_ Ordenar empleados\n");
    printf("8_ Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9_ Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10_ Salir\n\n");

    printf("INGRESE OPCION: ");
    scanf("%d",&opcion);

    return opcion;

}

int menuModify()
{
    int opcion;

    system("cls");
    printf("                    ###   Menu Modificacion   ###\n");
    printf("--------------------------------------------------------\n\n");
    printf("1_ Modificar nombre\n");
    printf("2_ Modificar horas trabajadas\n");
    printf("3_ EModificar sueldo\n");
    printf("4_ Salir\n");

    printf("\n\nINGRESE OPCION: ");
    scanf("%d",&opcion);

    return opcion;

}

int menuListar()
{
    int opcion;

    system("cls");
    printf("                    ###   Menu Listar   ###\n");
    printf("--------------------------------------------------------\n\n");
    printf("1_ Por Id\n");
    printf("2_ Por nombre\n");
    printf("3_ Por horas trabajadas\n");
    printf("4_ Por sueldo\n");
    printf("5_ Salir\n");

    printf("\n\nINGRESE OPCION: ");
    scanf("%d",&opcion);

    return opcion;
}

int listarEmployee(Employee* this)
{
    int estado=0;

    if(this != NULL)
    {
        printf("%d %10s %10d %15d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        estado=1;
    }

    return estado;
}

int ordenarPorNombre(void* employee1, void* employee2)
{
    int estado=0;
    Employee* emp1;
    Employee* emp2;

    if(employee1 != NULL && employee2 != NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(strcmp(emp1->nombre,emp2->nombre)>0)
        {
            estado=1;
        }
        else if(strcmp(emp1->nombre,emp2->nombre)<0)
        {
            estado=-1;
        }
        else
        {
            estado=0;
        }
    }
    return estado;
}

int ordenarPorSueldo(void* employee1, void* employee2)
{
    int estado=0;
    Employee* emp1;
    Employee* emp2;

    if(employee1 != NULL && employee2 !=NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(emp1->sueldo > emp2->sueldo)
        {
            estado = 1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            estado = -1;
        }
        else
        {
            estado = 0;
        }

    }

    return estado;
}

int ordenarPorHoras(void* employee1, void* employee2)
{
    int estado=0;
    Employee* emp1;
    Employee* emp2;

    if(employee1 != NULL && employee2 !=NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            estado = 1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            estado = -1;
        }
        else
        {
            estado = 0;
        }

    }

    return estado;
}

int ordenarPorId(void* employee1, void* employee2)
{
    int estado=0;
    Employee* emp1;
    Employee* emp2;

    if(employee1 != NULL && employee2 !=NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(emp1->id > emp2->id)
        {
            estado = 1;
        }
        else if(emp1->id < emp2->id)
        {
            estado = -1;
        }
        else
        {
            estado=0;
        }
    }

    return estado;
}


