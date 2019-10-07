#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "carrera.h"


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
    int idCarrera;
    int isEmpty;
}eAlumno;


eAlumno newAlumno(int leg, char nombre[], int edad, char sexo, int nota1, int nota2, eFecha fecha, int idCarrera);
void mostrarAlumno( eAlumno al, eCarrera carreras[], int tam);
void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
void inicializarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
int modificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int altaAlumno(eAlumno vec[], int tam, int leg, eCarrera carreras[], int tamC);
int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(eAlumno vec[], int tam, int legajo);
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad);
int menuModificarAlumno();

#endif // ALUMNO_H_INCLUDED
