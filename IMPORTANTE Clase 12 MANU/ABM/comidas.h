#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eComida;

void mostrarComida(eComida comida);
void mostrarComidas(eComida comidas[], int tam);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);



#endif // COMIDAS_H_INCLUDED
