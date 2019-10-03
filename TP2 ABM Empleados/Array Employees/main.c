#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"

#define TAM 2

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

///prototipos funciones para despues llevarme

///cambiar todas por empleado

void inicializarEmpleados(Employee vec[], int tam);
int buscarLibre(Employee vec[], int tam);
int altaEmpleado(Employee vec[], int tam);
Employee newEmployee(int id, char name[],char lastName[], float salary, int sector);
void mostrarEmpleado(Employee x);
void mostrarEmpleados(Employee vec[], int tam);
int buscarEmpleado(int id, Employee vec[], int tam);
int ModificarEmpleado(Employee vec[], int tam);
void ordenarEmpleados(Employee vec[], int tam);
int bajaEmpleado(Employee vec[], int tam);
int menu();

int main()
{
    Employee lista[TAM];
    char salir = 'n';

    inicializarEmpleados( lista, TAM);

    ///hardcodearEmpleados(lista, TAM, 5);///el numero final es la cantidad a mostrar hardcodeados

    do
    {
        switch( menu())
        {
        case 1:
            altaEmpleado(lista, TAM);
            break;

        case 2:
            bajaEmpleado(lista, TAM);
            break;

        case 3:
            ModificarEmpleado(lista, TAM);
            break;

        case 4:
            mostrarEmpleados(lista, TAM);
            break;

        case 5:
            printf("Confirma salir del ABM emplados?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Alta Empleado\n");
    printf("2-Baja Empleado\n");
    printf("3-Modificar Empleado \n");
    printf("4-Listar Empleados\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

///desarrollo funciones que despues me llevo a employees.c
int altaEmpleado(Employee vec[], int tam)
{

    int todoOk = 0;
    int indice;
    int esta;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
 ///   int isEmpty;

    system("cls");

    printf("*****Alta Empleado*****\n\n");

    indice = buscarLibre(vec, tam); ///a ver si hay lugar libre, lo guarda en indice 1 si hay, -1 sino

    if( indice == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {

        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarEmpleado(id, vec, tam);

        if( esta != -1)
        {
            printf("\nEse id ya se encuentra registrado\n\n");
            mostrarEmpleado(vec[esta]);

        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(lastName);

            printf("Ingrese salario: ");
            scanf("%f", &salary);

            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &sector);

            vec[indice] = newEmployee(id, name, lastName, salary, sector);
            todoOk = 1;
            printf("Alta exitosa!!\n\n");

        }

    }

    return todoOk;
}

Employee newEmployee(

    int id,
    char name[],
    char lastName[],
    float salary,
    int sector)
{

    Employee al;
    al.id = id;
    strcpy( al.name, name);
    strcpy( al.lastName, lastName);
    al.sector = sector;
    al.salary = salary;
    al.isEmpty = 0;

    return al;
}

void mostrarEmpleado(Employee x)
{
    printf(" %d  %10s   %10s      %d    %3.2f \n",
           x.id,
           x.name,
           x.lastName,
           x.sector,
           x.salary);
}

void mostrarEmpleados(Employee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID    NOMBRE    APELLIDO   SECTOR      SALARIO\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    printf("\n\n");
}

void ordenarEmpleados(Employee vec[], int tam) ///por nombre por ahora
{
    Employee auxEmployee;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].name > vec[j].name)
            {
                auxEmployee = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployee;
            }
        }
    }
    printf("Empleados Ordenados\n\n");
}

int bajaEmpleado(Employee vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese ID\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int ModificarEmpleado(Employee vec[], int tam)
{

    int todoOk = 0;
    int id;
    int indice;
    ///char confirma;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese id\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar salario\n");
        printf("4- Modificar sector\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre nuevo: ");
            scanf("%s", &vec[indice].name);
            break;

        case 2:
            printf("Ingrese apellido nuevo: ");
            scanf("%s", &vec[indice].lastName);
            ///vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 3:
            printf("Ingrese nueva salario: ");
            scanf("%f", &vec[indice].salary);
            break;

        case 4:
            printf("Ingrese nueva sector: ");
            scanf("%d", &vec[indice].sector);
            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

void inicializarEmpleados(Employee vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(Employee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(int id, Employee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


