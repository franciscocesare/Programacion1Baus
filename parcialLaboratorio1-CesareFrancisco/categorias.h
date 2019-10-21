#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED

typedef struct
{
    int idCategoria;
    char descripcion[51];
} eCategoria;

#endif // CATEGORIAS_H_INCLUDED

void mostrarCategorias(eCategoria categorias[], int tamCat);
void mostrarCategoria(eCategoria categorias);
void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[]);
void hardcodearCategoria(eCategoria vec[], int tam);
