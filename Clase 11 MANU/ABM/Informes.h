#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "carrera.h"
#include "alumno.h"

int menuInformes();
void mostrarInformes(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void mostrarAlumnosCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);
void mostrarAlumnoPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

int cantidadDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarCantidaDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void carrerasInscriptos(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void mostrarAlumnosVarones(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

#endif // INFORMES_H_INCLUDED
