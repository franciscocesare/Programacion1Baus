#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;
    eFecha fechaIngreso;

} eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos( eAlumno vec[], int tam);
void ordenarAlumnosLeg( eAlumno vec[], int tam);
void ordenarAlumnosNombre( eAlumno vec[], int tam);

int main()
{
    //eAlumno alumno1;
    eAlumno lista[TAM] =
    {
        {1234, "Juan", 20, 'm', 4, 6, 5,{16, 9, 2019}},
        {1111, "Juana", 19, 'f', 7, 4, 5.5,{20, 3, 2018}},
        {1221, "Ariel", 21, 'm', 10, 2, 6,{12, 11, 2013}},
        {1001, "Jazmin", 20, 'f', 8, 8, 8,{9, 8, 2018}},
        {1020, "Abril", 22, 'f', 4, 5, 4.5,{4, 5, 2015}}
    };
    /*
        for(int i=0; i < TAM; i++){

        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d", &lista[i].edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf("Ingrese nota parcial 1: ");
        scanf("%d", &lista[i].notaParcial1);

        printf("Ingrese nota parcial 2: ");
        scanf("%d", &lista[i].notaParcial2);
        /*
        printf("Ingrese dia ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.dia);

        printf("Ingrese mes ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.mes);

        printf("Ingrese anio ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.anio);

        printf("Ingrese fecha ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio );

        lista[i].promedio = (float) (lista[i].notaParcial1 + lista[i].notaParcial2) / 2;

        }*/
    mostrarAlumnos(lista, TAM);

    ordenarAlumnosLeg(lista, TAM);

    mostrarAlumnos(lista, TAM);

    ordenarAlumnosNombre(lista, TAM);

    mostrarAlumnos(lista, TAM);

    return 0;
}

void mostrarAlumno(eAlumno al)
{

    printf("%d %10s  %d  %c  %2d  %2d  %.2f %02d/%02d/%d\n",
           al.legajo,
           al.nombre,
           al.edad,
           al.sexo,
           al.notaParcial1,
           al.notaParcial2,
           al.promedio,
           al.fechaIngreso.dia,
           al.fechaIngreso.mes,
           al.fechaIngreso.anio
          );
}

void mostrarAlumnos( eAlumno vec[], int tam)
{

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio fechaIngreso\n");
    for(int i= 0; i < tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
    printf("\n\n");
}

void ordenarAlumnosLeg( eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

    void ordenarAlumnosNombre( eAlumno vec[], int tam)
    {
        eAlumno auxAlumno;

        for(int i=0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
                {
                    auxAlumno = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxAlumno;
                }
            }
        }
    }






