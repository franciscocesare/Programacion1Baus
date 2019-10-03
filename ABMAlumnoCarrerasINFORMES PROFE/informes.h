#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "ABMalumnos.h"
#include "carreras.h"

void mostrarCarreras(eCarrera carreras[], int tam);
void mostrarCarrera(eCarrera carrera);
int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]);
int menuInformes();

void mostrarInformes(eAlumno alumnos[], ///le paso el vector de alumnos y el tamano
                     int tam,
                     eCarrera carreras[], ///le paso el vector de carreras y el tamano
                     int tamC);
void mostrarAlumnosCarrera( eAlumno alumnos[],///le paso el vector de alumnos y el tamano
                            int tam,
                            eCarrera carreras[],///le paso el vector de carreras y el tamano
                            int tamC,
                            int idCarrera);

void mostrarAlumnosCarreraSeleccionada( eAlumno alumnos[],///le paso el vector de alumnos y el tamano
                                        int tam,
                                        eCarrera carreras[],///le paso el vector de carreras y el tamano
                                        int tamC
                                      );
void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[],///le paso el vector de alumnos y el tamano
                                      int tam,
                                      eCarrera carreras[],///le paso el vector de carreras y el tamano
                                      int tamC);

int contarAlumnosCarrera(eAlumno alumnos[],///le paso el vector de alumnos y el tamano
                         int tam,
                         eCarrera carreras[],
                         int tamC,
                         int idCarrera);
void carreraMasInscriptos(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC);

void mostrarCantidadDeAlumnosPorCarrera(eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC);


#endif // INFORMES_H_INCLUDED

