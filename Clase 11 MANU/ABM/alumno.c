#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "alumno.h"
#include "biblioteca.h"



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


void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC){

    int flag = 0;

    system("cls");

    printf("\n LEGAJO   NOMBRE    EDAD   SEXO   NOTA 1    NOTA 2     PROMEDIO    FECHA INGRESO     CARRERA\n");
    printf("********************************************************************************\n");


    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty == 0){
           mostrarAlumno(vec[i], carreras, tamC);
           flag = 1;
        }

    }
    if(flag == 0){
        printf("No hay alumnos que mostrar");
    }
    printf("\n\n");
}

void mostrarAlumno( eAlumno al, eCarrera carreras[], int tam){
    char descCarrera[20];

    cargarDescCarrera(al.idCarrera, carreras, tam, descCarrera);

    printf("%6d  %10s      %2d    %3c       %d    %6d    %8.2f       %02d/%02d/%d       %s\n",
            al.legajo,
            al.nombre,
            al.edad,
            al.sexo,
            al.nota1,
            al.nota2,
            al.promedio,
            al.fechaIngreso.dia,
            al.fechaIngreso.mes,
            al.fechaIngreso.anio,
            descCarrera
            );
}


int altaAlumno(eAlumno vec[], int tam, int leg, eCarrera carreras[], int tamC){
    int todoOk = 0;
    int indice;

    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    eFecha fecha;
    int idCarrera;

        system("cls");
        printf("******* ALTA *******\n\n");

        indice = buscarLibre(vec, tam);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                //printf("Ingrese Nombre: ");
                //fflush(stdin);
                getString(nombre, "Ingrese Nombre: ", "Error. Reingrese Nombre: ", 3,19);
//                gets(nombre);
//                strlwr(nombre);
//                nombre[0] = toupper(nombre[0]);

                //printf("Ingrese edad: ");
                //scanf("%d", &edad);
                getIntRange(&edad, "Ingrese Edad: ", "Error. Ingrese Edad entre 17 y 100: ", 17, 100);

                // printf("Ingrese Sexo: ");
                //fflush(stdin);
                //sexo = tolower(getchar());
                getCharSex(&sexo, "Ingrese Sexo: ", "Error. Ingrese Sexo (F o M): ", 'F', 'M');

                //printf("Ingrese Nota 1: ");
                //scanf("%d", &nota1);
                getIntRange(&nota1, "Ingrese Nota 1: ", "Error. Ingrese Nota 1 entre 1 y 10: ", 1, 10);

                //printf("Ingrese Nota 2: ");
                //scanf("%d", &nota2);
                getIntRange(&nota2, "Ingrese Nota 2: ", "Error. Ingrese Nota 2 entre 1 y 10: ", 1, 10);

                printf("Ingrese Fecha de Ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );

                mostrarCarreras(carreras, tamC);
                //printf("Ingrese ID carrera: ");
                //scanf("%d", &idCarrera);
                getIntCarrera(&idCarrera, "Ingrese ID carrera: ", "Error. Ingrese ID valido: ", 1000, 1002, 1002);

                vec[indice] = newAlumno(leg, nombre, edad, sexo, nota1, nota2, fecha, idCarrera);

                todoOk = 1;
                if(todoOk){
                    printf("\n\nALTA EXITOSA !!! \n\n");
                }
        }

    return todoOk;
}

eAlumno newAlumno(int leg, char nombre[], int edad, char sexo, int nota1, int nota2, eFecha fecha, int idCarrera){
    eAlumno al;

    al.legajo = leg;
    strcpy( al.nombre, nombre );
    al.edad = edad;
    al.sexo = sexo;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.fechaIngreso = fecha;
    al.idCarrera = idCarrera;
    al.promedio = (float) (nota1 + nota2) / 2;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC){

    int todoOk = 0;
    int legajo;
    char confirma;
    int esta;

        system("cls");
        printf("******* BAJA *******\n\n");

        //printf("Ingrese legajo: ");
        //scanf("%d", &legajo);
        getIntRange(&legajo,"Ingrese legajo: ", "Error. Ingrese legajo de 20000 al 50000: ", 20000, 50000);

        esta = buscarAlumno(vec, tam, legajo);

        if(esta == -1){
            printf("NO EXISTE ALUMNO CON ESE LEGAJO\n\n");
        }
        else{
            mostrarAlumno(vec[esta], carreras, tamC);
            printf("Confirma la baja? ");
            fflush(stdin);
            confirma = getchar();
            confirma = toupper(confirma);

            if(confirma == 'S'){
                vec[esta].isEmpty = 1;
                todoOk = 1;
                printf("BAJA EXITOSA\n\n");
            }
            else{
                printf(" SE CANCELO LA OPERACION!! \n\n");
            }
        }
        return todoOk;
}


int modificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC){

    int todoOk = 0;
    int legajo;
    char confirma;
    int indice;

        system("cls");
        printf("******* MODIFICAR *******\n\n");

        //printf("Ingrese legajo: ");
        //scanf("%d", &legajo);
        getIntRange(&legajo,"Ingrese legajo: ", "Error. Ingrese legajo de 20000 al 50000: ", 20000, 50000);

        indice = buscarAlumno(vec, tam, legajo);

        if(indice == -1){
            printf("NO EXISTE ALUMNO CON ESE LEGAJO\n\n");
        }
        else{
            mostrarAlumno(vec[indice], carreras, tamC);

            switch(menuModificarAlumno()){
                case 1:
                    //printf("Ingrese nueva nota: ");
                    //scanf("%d", &vec[indice].nota1);
                    getIntRange(&vec[indice].nota1, "Ingrese nueva Nota 1: ", "Error. Ingrese nueva Nota 1 entre 1 y 10: ", 1, 10);

                    vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
                    break;

                case 2:
                   // printf("Ingrese nueva nota: ");
                   // scanf("%d", &vec[indice].nota2);
                    getIntRange(&vec[indice].nota2, "Ingrese nueva Nota 2: ", "Error. Ingrese nueva Nota 2 entre 1 y 10: ", 1, 10);
                    vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
                    break;
                case 3:
                    printf("Se ha cancelado la mofdificacion ");
                    break;

            }

            printf("Confirma la baja? ");
            confirma = getchar();
            if(confirma == 's'){
                vec[indice].isEmpty = 1;
                todoOk = 1;
                printf("BAJA EXITOSA\n\n");
            }
            else{
                printf(" SE CANCELO LA OPERACION!! \n\n");
            }
        }
        return todoOk;
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].sexo > vec[j].sexo )
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("Alumnos Ordenados\n\n");
}


int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad){
    int cont = 0;

    eAlumno suplentes[]=
    {
        { 20000, "Juan", 20, 'M', 5, 7, 6, {12, 5, 2015}, 1000, 0},
        { 20001, "Alberto", 21, 'M', 2, 8, 5, {12, 5, 2019},1001, 0},
        { 20002, "Ana", 22, 'F', 4, 5, 4.5, {2, 7, 2018},1002, 0},
        { 20003, "Luis", 20, 'M', 9, 8, 8.5, {21, 5, 2018},1000, 0},
        { 20004, "Alicia", 21, 'F', 6, 7, 6.5, {11, 9, 2017},1001, 0},
        { 20005, "Diego", 23, 'M', 2, 2, 2, {12, 4, 2014},1000, 0},
        { 20006, "Sofia", 19, 'F', 8, 9, 8.5, {12, 2, 2014},1002, 0},
        { 20007, "Clara", 21, 'F', 2, 4, 3, {28, 8, 2018},1001, 0},
        { 20008, "Mauro", 20, 'M', 4, 7, 5.5, {23, 3, 2015},1001, 0},
        { 20009, "Daniela", 22, 'F', 2, 8, 4, {10, 10, 2016},1000, 0},
        { 20010, "Agustin", 24, 'M', 6, 7, 6.5, {1, 7, 2017},1002, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}



int menuModificarAlumno(){
    int opcion;
        printf("1- Modificar nota 1\n");
        printf("2- Modificar nota 2\n");
        printf("3- Salir\n\n");

        getIntRange(&opcion, "Ingrece opcion: ", "Error. Ingrese opcion entre 1 y 3", 1, 3);

    return opcion;
}






