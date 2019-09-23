#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
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
    int isEmpty;

} eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos( eAlumno vec[], int tam);
void ordenarAlumnosLeg( eAlumno vec[], int tam);
void ordenarAlumnosNombre( eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(eAlumno vec [], int tam, int legajo);
int altaAlumno(eAlumno vec[], int tam);
///eAlumno newAlumno(legajo, nombre, edad, sexo, notaP1, notaP2, promedio, )


int menu ();

int main()
{
    eAlumno lista [TAM];
    char salir= 'n';

    do
    {

        switch (menu())
        {
        case 1:
            printf("1-Alta Alumno \n");
            break;

        case 2:
            printf("2-Baja Alumno \n");
            break;

        case 3:
            printf("3-Modificar Alumno \n");
            break;

        case 4:
            printf("4-Listar Alumno \n");
            break;

        case 5:
            printf("5-ordenar Alumno \n");
            break;

        case  6:
            printf("6-Informes Alumno \n");
            break;

        case 7:
            printf("7-CONFIRMA SALIR? \n");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("opcion invalida");

        }

    }
    while (salir == 'n');

    return 0 ;
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

int menu ()
{

    int opcion;

    system("cls");
    printf("*******ABM Alumnos*******\n\n");
    printf("1-Alta Alumno \n");
    printf("2-Baja Alumno \n");
    printf("3-Modificar Alumno \n");
    printf("4-Listar Alumno \n");
    printf("5-Ordenar Alumno \n");
    printf("6-Informes Alumno \n");
    printf("7-SALIR \n");

    printf("Ingrese opcion\n");
    scanf ("%d", &opcion);

    return opcion;

}

void inicializarAlumnos(eAlumno vec [], int tam)
{

    for (int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarAlumno(eAlumno vec [], int tam, int legajo)  ///funcion para buscar alumno por legajo
{

    int indice = -1;

    for (int i=0; i<tam; i++)
    {

        if (legajo == vec[i].legajo && vec [i].isEmpty == 0) ///pregunto si el legajo ingresado existe en algun legajo existente o esta vacio
        {
            /// 0 esta activo
            indice = i;
            break;
        }
        return indice;
    }

}

int buscarLibre(eAlumno vec[], int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (vec[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaAlumno(eAlumno vec[], int tam)
{
    int todoOk = 0;
    int lugarLibre;
    int esta;
    int legajo;
    char nombre [20];
    int edad;
    char sexo;
    int notaP1;
    int notaP2;
    eFecha fecha;


    lugarLibre=buscarLibre(vec,tam);

               if (lugarLibre==-1)
    {
        printf("\n No hay lugar \n\n");

    }
    else
    {
        printf("Ingrese el legajo: ");
        scanf ("%d", &legajo);
        esta=buscarAlumno(vec, tam, legajo);
        if (esta != -1)
        {
            printf("El legajo ya existe!");
            mostrarAlumno(vec[esta]);///porque si existe me muestra en que posicion guardado en ESTA
        }
        else {

            printf("Ingrese legajo: "); ///vamos a cargar todos los datos en variables y despues en una funcion cargarlo al vector
            scanf("%d",&legajo);

            printf("Ingrese nombre: ");
            fflush(stdin);
            /*if (nombre)
            */
            gets(nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c",&sexo);

            printf("Ingrese edad: ");
            scanf("%d",&edad);

            printf("Ingrese nota Parcial 1: ");
            scanf("%d",&notaP1);

            printf("Ingrese nota Parcial 2: ");
            scanf("%d",&notaP2);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d",&fecha.dia, &fecha.mes, &fecha.anio);


        }

    }


    return todoOk;


}

/*void ordenarAlumnosNombre( eAlumno vec[], int tam)
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
}*/
