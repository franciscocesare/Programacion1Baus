#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
///revisar todasssss

int menuInformes();
void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC);
int mostrarAlquileresClientes(int idCliente,eAlquileres vec[],int tamAl);
void clientesSinAlquiler(eCliente vecClientes[],int tamCl, eAlquileres vecAlquiler[],int tamAl);
int mostrarJuegosAlquilados(int idJuego,eAlquileres vec[],int tam);
void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquileres vecAl[],int tamAl, eCategoria vecCa[], int tamCa);

