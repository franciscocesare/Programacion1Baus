#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10
#define TAMC 3

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
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
} eAlumno;

typedef struct ///lo que tengo en apuntes para vincular con la struc Alumnos
{
    int id;
    char descripcion[20];

} eCarrera;

void mostrarAlumno(eAlumno x,eCarrera carrera);
void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carrera [], int tamC);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int leg);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f);
int bajaAlumno(eAlumno vec[], int tam);
int ModificarAlumno(eAlumno vec[], int tam);
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad);
void mostrarCarrera(eCarrera carrera);
void mostrarCarreras(eCarrera carreras[], int tam);

int menu();

int main()
{
    eCarrera carreras []= {{1000, "TUP"},{1001, "TUSI"},{1002, "LIC"}};
    eAlumno lista[TAM];
    char salir = 'n';
    int legajo=2000;

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 5);///el numero final es la cantidad a mostrar hardcodeados
    ///legajo=legajo+...es para que se vayan sumando los legajos a los hardcodeados
    do
    {
        switch( menu())
        {
        case 1:
            if (altaAlumno(lista, TAM, legajo))
            {
                legajo ++;///va incrementando legajo cuando damos de alta
            }
            break;

        case 2:
            bajaAlumno(lista, TAM);
            break;

        case 3:
            ModificarAlumno(lista, TAM);
            break;

        case 4:
            mostrarAlumnos(lista, TAM,carreras, TAMC);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            printf("Informes Alumno\n\n");
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
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
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void mostrarAlumno(eAlumno x, eCarrera carrera)
{
    printf("%d  %10s   %2d    %c   %2d     %2d     %3.2f     %02d/%02d/%d %s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           carrera.descripcion);
}

void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carrera [], int tamC)///tamC es el tamaño del vector de la estructura carrera
{

    int flag = 0;
    system("cls");

    printf(" Legajo  Nombre  Edad Sexo  Nota1 Nota2  Promedio   FIngreso  Carrera\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            for (int j=0; j<tamC; j++)
            {
                if (vec[i].idCarrera==carrera[j].id)
                {
                    mostrarAlumno(vec[i],carrera[j]);
                    flag = 1;
                }
            }

        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
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

void inicializarAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
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

int buscarAlumno(int legajo, eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno vec[], int tam, int leg)
/*

*/
{
    int todoOk = 0;
    int indice;
    int esta;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam); ///a ver si hay lugar libre, lo guarda en indice 1 si hay, -1 sino

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota 1: ");
        scanf("%d", &n1);

        printf("Ingrese nota 2: ");
        scanf("%d", &n2);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        vec[indice] = newAlumno(leg, nombre, edad, sexo, n1, n2, fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");

    }

    return todoOk;

}


eAlumno newAlumno(
    int leg,
    char nombre[],
    int edad,
    char sexo,
    int nota1,
    int nota2,
    eFecha fecha)
{

    eAlumno al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice], carrera[]);///xq me tira error?

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
int ModificarAlumno(eAlumno vec[], int tam)
{

    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice]);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota1);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 2:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota2);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}


int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad)  ///recibe el vector, el tamaño y la cantidad de elementos a cargar, devuelve la cantidad de alumnos cargados, o 0.
{

    int cont = 0; ///siempre declarar una variabla del tipo que va a devolver

    eAlumno suplentes[]=
    {
        { 2000, "Juan", 20, 'm', 5, 7, 6,{1,5,2015}, 0},
        { 2001, "Alberto", 22, 'm', 7, 8, 7.5,{30,7,2017}, 0},
        { 2002, "Ana", 24, 'f', 10, 9, 9,{11,3,2014}, 0},
        { 2003, "Matias", 25, 'm', 4, 6, 5,{22,4,2016}, 0},
        { 2004, "Jimena", 29, 'f', 9, 7, 8,{4,3,2016}, 0},
        { 2005, "Pablo", 22, 'm', 8, 5, 6.5,{3,4,2019}, 0},
        { 2006, "Rodrigo", 23, 'm', 8, 8, 8,{1,7,2018}, 0},
        { 2007, "Lucia", 20, 'f', 4, 8, 6,{2,9,2017}, 0},
        { 2008, "Daniela", 21, 'f', 9, 9, 9,{1,4,2017}, 0},
        { 2009, "Paula", 28, 'f', 7, 7, 7,{15,5,2016}, 0},
    };

    if (cantidad <=10 && tam>=cantidad)  ///condicion para cargar, la cantidad tiene que ser <= que lo que me piden
    {
        for (int i=0; i<cantidad; i++)
        {

            vec[i]=suplentes[i];
            cont ++;

        }

    }
    return cont;


}

void mostrarCarrera(eCarrera carrera)
{
    printf("%d %s \n", carrera.id, carrera.descripcion);
}
void mostrarCarreras(eCarrera carreras[], int tam)
{
    printf("\n\n Id   Descripcion \n\n");
    for (int i=0; i<tam; i++)
    {
        mostrarCarrera(carreras[i]);///llama a mostrar carrera
    }
    printf("\n");


}
