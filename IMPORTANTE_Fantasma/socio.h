#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#define TEXT_SIZE 20


typedef struct  ///typedef hace que no se repita la estructura
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE]; ///reemplazar por nombre
    /*int varInt;
    float varFloat; las elimino el profe
    char varChar;*/
    char varLongString[TEXT_SIZE];///reemplazo por apellido

}Socio;


#endif // FANTASMA_H_INCLUDED

int socio_Inicializar(Socio array[], int size);                                    //cambiar socio
int socio_buscarEmpty(Socio array[], int size, int* posicion);                    //cambiar socio
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice);                    //cambiar socio
int socio_alta(Socio array[], int size, int* contadorID);                          //cambiar socio
int socio_baja(Socio array[], int sizeArray);                                      //cambiar socio
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado);
int socio_modificar(Socio array[], int sizeArray);                                //cambiar socio
int socio_ordenarPorString(Socio array[],int size);                              //cambiar socio
int socio_listar(Socio array[], int size);                      //cambiar socio





