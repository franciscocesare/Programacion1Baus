#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define TAM 2

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
}eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
eAlumno newAlumno(int leg, char nombre[], int edad, char sexo, int nota1, int nota2, eFecha fecha);
int altaAlumno(eAlumno vec[], int tam, int leg);
int bajaAlumno(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(eAlumno vec[], int tam, int legajo);
int modificarAlumno(eAlumno vec[], int tam);
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad);
int menu();

int main()
{
    int legajos = 20000;
    eAlumno lista[TAM];
    inicializarAlumnos(lista, TAM);

    hardcodearAlumnos(lista, TAM, 5);
    legajos = legajos + hardcodearAlumnos(lista, TAM, 5);

    char salir = 'n';

    do{

        switch(menu()){

        case 1:
            if(altaAlumno(lista, TAM, legajos)){
                legajos++;
            }

            break;
        case 2:
            printf("Baja alumno");
            break;
        case 3:
            printf("Modificar alumno");
            break;
        case 4:
            //printf("Listar alumnos");
            mostrarAlumnos(lista, TAM);
            break;
        case 5:
            printf("Ordenar alumnos");
            break;
        case 6:
            printf("Informes ");
            break;
        case 7:
            printf("Confirma Salir?  ");
            fflush(stdin);
            salir = getche();
            printf("\n\n");
            break;

        default:
            printf("Opcion invalida.");
            break;
        }

        system("pause");
    }while(salir == 'n');



    return 0;
}


int menu(){

    int opcion;

    system("cls");

    printf("\n***** ABM de Alumnos  ********\n\n");
    printf("1- Alta \n");
    printf("2- Baja \n");
    printf("3- Modificar  \n");
    printf("4- Mostrar Alumnos \n");
    printf("5- Ordenar Alumnos \n");
    printf("6- Informes \n");
    printf("7- Salir \n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarAlumnos(eAlumno vec[], int tam){
    for(int i=0; i<tam; i++){
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno vec[], int tam){
    int indice = -1;

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(eAlumno vec[], int tam, int legajo){
    int indice = -1;
        for(int i=0; i<tam; i++){
            if(vec[i].legajo == legajo && vec[i].isEmpty == 0){
                indice = i;
                break;
            }
        }
    return indice;
}


void mostrarAlumnos(eAlumno vec[], int tam){

    int flag = 0;

    printf("\n LEGAJO   NOMBRE    EDAD   SEXO   NOTA 1    NOTA 2     PROMEDIO    FECHA INGRESO\n");
    printf("********************************************************************************\n");


    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty == 0){
           mostrarAlumno(vec[i]);
        }

    }
    if(flag == 0){
        printf("No hay alumnos que mostrar");
    }
    printf("\n\n");
}

void mostrarAlumno( eAlumno al){
    printf("%6d  %10s      %2d    %3c       %d    %6d    %8.2f       %02d/%02d/%d\n", al.legajo, al.nombre, al.edad, al.sexo, al.nota1, al.nota2, al.promedio, al.fechaIngreso.dia, al.fechaIngreso.mes, al.fechaIngreso.anio );
}


int altaAlumno(eAlumno vec[], int tam, int leg){
    int todoOk = 0;
    int indice;

    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    eFecha fecha;

        system("cls");
        printf("******* ALTA *******\n\n");


        indice = buscarLibre(vec, tam);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese edad: ");
                scanf("%d", &edad);

                printf("Ingrese Sexo: ");
                fflush(stdin);
                sexo = tolower(getchar());

                printf("\nIngrese Nota 1: ");
                scanf("%d", &nota1);

                printf("Ingrese Nota 2: ");
                scanf("%d", &nota2);

                printf("Ingrese Fecha de Ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );

                vec[indice] = newAlumno(leg, nombre, edad, sexo, nota1, nota2, fecha);

                todoOk = 1;
        }

    return todoOk;
}

eAlumno newAlumno(int leg, char nombre[], int edad, char sexo, int nota1, int nota2, eFecha fecha){
    eAlumno al;

    al.legajo = leg;
    strcpy( al.nombre, nombre );
    al.edad = edad;
    al.sexo = sexo;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.fechaIngreso = fecha;
    al.promedio = (float) (nota1 + nota2) / 2;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam){

    int todoOk = 0;
    int legajo;
    char confirma;
    int esta;

        system("cls");
        printf("******* BAJA *******\n\n");

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumno(vec, tam, legajo);

        if(esta == -1){
            printf("NO EXISTE ALUMNO CON ESE LEGAJO\n\n");
        }
        else{
            mostrarAlumno(vec[esta]);
            printf("Confirma la baja? ");
            confirma = getchar();
            if(confirma == 's'){
                vec[esta].isEmpty = 1;
                todoOk = 1;
                printf("BAJA EXITOSA");
            }
            else{
                printf(" SE CANCELO LA OPERACION!! \n\n");
            }

        }
        return todoOk;
}



int modificarAlumno(eAlumno vec[], int tam){
 int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec , tam);

    if( indice == -1){
        printf("No existe un alumno con ese legajo\n\n");

    }
    else{

        mostrarAlumno(vec[indice]);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
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
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad){
     int cont = 0;

    eAlumno suplentes[] = {
        { 20000, "Juan", 20, 'm', 5, 7, 6, {12,5,2015}, 0 },
        { 20001, "Alberto", 21, 'm', 2, 8, 5, {17,8,2019}, 0 },
        { 20002, "Ana", 22, 'f', 4, 5, 4.5, {20,6,2018}, 0 },
        { 20003, "Luis", 20, 'm', 9, 8, 8.5, {21,5,2018}, 0 },
        { 20004, "Alicia", 21, 'f', 6, 7, 6.5, {14,6,2017}, 0 },
        { 20005, "Diego", 23, 'm', 2, 2, 2, {26,8,2014}, 0 },
        { 20006, "Sofia", 19, 'f', 8, 9, 8.5, {9,7,2015}, 0 },
        { 20007, "Clara", 21, 'f', 2, 4, 3, {8,4,2016}, 0 },
        { 20008, "Mauro", 20, 'm', 4, 7, 5.5, {12,6,2015}, 0 },
        { 20009, "Daniela", 22, 'f', 4, 7, 5.5, {24,8,2018}, 0 },
        { 20010, "Agustin", 24, 'm', 6, 7, 6.5, {15,5,2019}, 0 }
    };

    if( cantidad <= 10 && tam >= cantidad ){

        for(int i=0; i<cantidad; i++){
            vec[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

















