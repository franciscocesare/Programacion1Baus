//#ifndef ABMALUMNOS_H_INCLUDED

#ifndef CARRERAS_H_INCLUDED
//#define ABMALUMNOS_H_INCLUDED ///ESTA BIEN ESTO? NO ME RECONOCIA LAS STRUCT DE ALUMNOS////////////////
#define CARRERAS_H_INCLUDED

///CONSULTAR AL PROFE POR LOS WARNINGS,

typedef struct ///ESTRUCTURAS DE CARRERAS Y DESCRIPCION. agregue la de alumnos
{

    int id;
    char descripcion[20];

} eCarrera;
/*typedef struct
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
} eAlumno; */



//#endif // ABMALUMNOS_H_INCLUDED
#endif // CARRERAS_H_INCLUDED


/// PROTOTIPOS Funciones Carrera y Informes


int menu();


