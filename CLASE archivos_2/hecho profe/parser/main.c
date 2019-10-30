#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float sueldo;
} eEmpleado;

eEmpleado* new_Empleado();

int main()
{
    eEmpleado* lista[50];
    eEmpleado* emple ;
    int i=0;
    FILE* miArchivo;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[10];
    int primero = 0;



    miArchivo = fopen("datos.csv","r");

    fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n", legajo, nombre, apellido, sueldo);


    while(!feof(miArchivo))
    {
           fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n", legajo, nombre, apellido, sueldo);

         emple =new_Empleado();
        emple->legajo = atoi(legajo);

        strcpy(emple->nombre,nombre);

        strcpy(emple->apellido,apellido);

        emple->sueldo = atof(sueldo);

        *(lista+i) = emple; //lista[i]=emple;
        i++;

    }


    fclose(miArchivo);

    for(i=0; i<50;i++)
    {
        printf("%d--%s--%s--%f\n", lista[i]->legajo,lista[i]->nombre,lista[i]->apellido,lista[i]->sueldo);
    }

    return 0;
}

eEmpleado* new_Empleado()
{
    eEmpleado* e;

    e = (eEmpleado*) malloc(sizeof(eEmpleado));

    return e;
}
