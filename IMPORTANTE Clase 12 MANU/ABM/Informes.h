#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "carrera.h"
#include "alumno.h"
#include "almuerzo.h"

int menuInformes();
void mostrarInformes(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom);

void mostrarAlumnosCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);
void mostrarAlumnoPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

int cantidadDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera);
void mostrarCantidaDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void carrerasInscriptos(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void mostrarAlumnosVarones(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);


void mostrarMejorPromedioPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void mostrarMujeresPorCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void alumnosMayores(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC);

void almuerzosPorFecha(eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamC);

void alumnosPorComidaSeleccionada(eAlumno alumnos[], int tamA,eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eCarrera carreras[], int tamC);

int cantidadDeAlmuerzosPorCarrera(eAlmuerzo almuerzos[], int tamAlm, eAlumno alumnos[], int tamA,  eCarrera carreras[], int tamC, int idCarrera);
void mostrarCantidaDeAlmuerzosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAlm);

int cantidadDeMilangasPorCarrera(eAlmuerzo almuerzos[], int tamAlm, eAlumno alumnos[], int tamA,  eCarrera carreras[], int tamC, int idCarrera);
void mostrarAmanteDeMilanesa(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAlm);

void mostrarDeudaAlumno(eAlumno alumnos[], int tamA, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eCarrera carreras[], int tamC);

#endif // INFORMES_H_INCLUDED
