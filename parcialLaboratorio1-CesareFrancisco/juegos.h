#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[20];
    float importe;
    int idCategoria;
} eJuego;

#endif // JUEGOS_H_INCLUDED
#include "categorias.h"

void harcodearJuego(eJuego vec[], int tam);
void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[]);
void mostrarJuego(eJuego juegos, eCategoria categorias[], int tam);
void mostrarJuegos(eJuego juego[],int tamJ, eCategoria categoria[], int tamC);
