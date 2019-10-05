#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

#include "comidas.h"
#include "alumno.h"
#include "carrera.h"


typedef struct{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;


eAlmuerzo newAlmuerzo(int id, int idComida, int legajo, eFecha fecha);
int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eAlumno alumnos[], int tamAlumno, eCarrera carreras[], int tamCarr);
void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tam, eComida comidas[], int tamC);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamC);
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam);


#endif // ALMUERZO_H_INCLUDED
