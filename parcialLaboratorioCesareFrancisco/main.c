#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAMClientes 3


///PRIMERO DEFINO LAS ESTRUCTURAS
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int codigo;
    char descripcion[20];
    char sexo;
    int importe;
    int idCategoria;
    int isEmpty;
} Juego;

typedef struct
{
    int id;
    char descripcion[51];
} Categoria;

typedef struct
{
    int idCliente; ///autoincremental
    char nombre[51];
    char apellido[51]; ///validar
    char sexo;
    int telefono;
    int isEmpty;

} Cliente;

typedef struct
{
    int codigoAlquiler; ///autoincremental
    int codigoDeJuego; ///validar
    int codigoDeCliente; ///validar
    eFecha fechaAlquiler;

} eAlquileres;


int menu ();
///prototipos clientes
void inicializarClientes(Cliente vec[], int tam);
int findFree(Cliente vec[], int tam);
int altaCliente(Cliente vec[], int tam, int idCliente);


///prototipos




int main()
{
    int codigoCliente = 100;
    int idCategoria = 1;
    ///int idAlmuerzo = 60000;
    char salir = 's';
    Cliente lista [TAMClientes];

    inicializarClientes(lista, TAMClientes);


    /*eCategoria categorias[] = ///HARDCODEO DE ESTRUC categoria
    {
        {1, "MESA"},
        {2, "AZAR"},
        {3, "ESTRATEGIA"},
        {4, "SALON"},
        {5, "MAGIA"}
    };*/

    Cliente clientes[] = ///HARDCODEO DE ESTRUC CLIENTES
    {
        {100, "jose","Sand",'m',1153553489},
        {101, "Lautaro","Acosta",'m',1136684545}, ///ID, IdEMPLEADO, IdCOMIDA
        {102, "Diego","Valeri",'m',1154479884},
        {103, "Maria","Alvarez",'m',1131556556},
    };

    do
    {
        switch( menu())
        {
        case 1:
            if (altaCliente(lista, TAMClientes, idCliente))
            {
                idCliente ++;
            }

            break;

        /*case 2:
            if ( validsEmployees (lista, TAM)==1)
            {
                removeEmployee(lista, TAM);
            }
            break;

        case 3:
            if ( validsEmployees (lista, TAM)==1)
            {
                modifyEmployee(lista, TAM);
            }
            break;

        case 4:
            if ( validsEmployees(lista, TAM))

            {
                switch (menuReports())
                {
                case 1:
                    printf("empleados ordenados alfabeticamente por Apellido y Sector\n\n");
                    sortEmployeesByLastName(lista, TAM);
                    printEmployees(lista, TAM);
                    break;

                case 2:
                    totalEmployees(lista, TAM);
                    break;
                }

            }
            break;
        */
        case 5:
            printf("Confirma salir del ABM emplades?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(tolower(salir == 'n'));

    return 0;
}




return 0;
}

}


///funciones que luego me tengo que llevar CLIENTES

void inicializarClientes(Cliente vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int findFree(Cliente vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

int altaCliente(Cliente vec[], int tam, int idCliente)
{

    int todoOk = 0;
    int index;
    char name[51];
    char auxName[51];
    char lastName[51];
    char auxLastName[51];
    char sexo;
    char telefono[20];
    char auxTelefono[20];
    char direccion[30];
    char auxDireccion[30];
    int idCliente;

    system("cls");

    printf("*****Alta Cliente*****\n\n");

    index = findFree(vec, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {
        vec[index].id = idCliente;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxName);
        while (strlen (auxName) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error Nombre muy largo, ingrese el nombre: ");
            fflush(stdin);
            gets(auxName);
        }
        strcpy (name, auxName); ///si el dato es valido, lo copio en nombre!



        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxLastName);
        while (strlen (auxLastName) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error apellido muy largo, ingrese el Apellido: ");
            fflush(stdin);
            gets(auxLastName);
        }
        strcpy (lastName, auxLastName);

        printf("Ingrese telefono: ");
        fflush(stdin);
        gets(auxTelefono);
        while (strlen (auxTelefono) >20)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error Telefono muy largo, ingrese el telefono: ");
            fflush(stdin);
            gets(auxTelefono);
        }
        strcpy (telefono, auxTelefono); ///si el dato es valido, lo copio en telefono!

        printf("Ingrese direccion: ");
        fflush(stdin);
        gets(auxDireccion);
        while (strlen (auxDireccion) >30)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error, ingrese domicilio: ");
            fflush(stdin);
            gets(auxDireccion);
        }
        strcpy (direccion, auxDireccion); ///si el dato es valido, lo copio en telefono!



        vec[index] = newCliente(idEmployee, name, lastName, telefono, direccion);
        todoOk = 1;
        printf("\nSe ha realizado el alta del cliente\n\n");

    }
    return todoOk;
}

Cliente newCliente(

    int idCliente,
    char nombre[],
    char apellido[],
    char sexo,
    char telefono [],
    char direccion[])
{

    Cliente al;
    al.id = idEmployee;
    strcpy( al.name, name);
    strcpy( al.lastName, lastName);
    strcpy( al.telefono, telefono); //al.telefono = telefono;
    strcpy( al.direccion, direccion); //al.direccion = direccion;
    al.isEmpty = 0;

    return al;
}


///funciones que luego me tengo que llevar ALQUILERES
