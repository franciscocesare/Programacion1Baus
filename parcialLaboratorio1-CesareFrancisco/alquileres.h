#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idAlquiler; ///autoincremental
    int idJuego; ///validar
    int idCliente; ///validar
    eFecha fechaAlquiler;
    int isEmptyAlquiler;

} eAlquileres;


#endif // ALQUILERES_H_INCLUDED

int menuAlquileres();
void inicializarAlquileres(eAlquileres vec[], int tam);
int hardcodearAlquileres(eAlquileres vec[], int tam, int cant);
int findFreeAlquiler(eAlquileres vec[], int tam);
int altaAlquiler(eAlquileres vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id);
void mostrarAlquiler(eAlquileres vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
void mostrarAlquileres(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC);
