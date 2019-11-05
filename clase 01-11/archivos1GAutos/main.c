#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//eAuto* hacer newauto
//eAuto * new auto param(int id, char marca, int modelo, float precio);

//mostrarauto
//mostrarAutos
//sort(comparison)

geter y setter
seter setear un valor, con validaciones para proteger
geter obtener un valor de algun campo. retorna del mismo tipo de lo que estoy geteando

*/


typedef struct
{
    int id;
    char marca[32];
    int modelo;
    float precio;
} eAuto;

/// Mostrar
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);
/// Getters y Setters
int setIdAuto(eAuto* unAuto, int id);
int setModeloAuto(eAuto* unAuto, int modelo);
int setPrecioAuto(eAuto* unAuto, float precio);
int setMarcaAuto(eAuto* unAuto, char* marca);
int getIdAuto(eAuto* unAuto);
int getModeloAuto(eAuto* unAuto);
float getPrecioAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto, char* marca);
/// Constructores
eAuto* newAuto();
eAuto* newAutoParam(int id, char* marca, int modelo, float precio);
/// Comparison


/// Escritura/Lectura Archivos
int guardarAutosBinario( eAuto** lista, int tam, char* path);
int guardarAutosCSV( eAuto** lista, int tam, char* path);


int main()
{
    int tam = 0;
    int cant = 0;
    char buffer[4][30];

    ///buena practica a NULL, aca vamos a cargar el csv de autos
    ///buena practica inicializar en NULL cada puntero

    FILE* f = NULL;
    eAuto* auxAuto = NULL;
    eAuto** auxLista = NULL;

    /*creamos el primer puntero, que apunta a otro puntero, y pedimos un primer lugar donde
    vamos a poner la direccion de memoria de un auto. Despues con realloc vamos a ir
    sumandole mas punteros al array que apuntan a diferentes autos*/
    eAuto** lista = (eAuto**) malloc(sizeof(eAuto*));
    if( lista == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("listaAutos.csv", "r");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    /*fscanf devuelve la cantidad de elementos que pudo cargar, si devuelve 4 esta ok.
        lo almacenamos en cant*/
    while( !feof(f) )
    {
        cant =  fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if( cant < 4)
        {
            break;
        }
        else
        {   ///atoi parsea a int un string, atof parsea a float un string
            auxAuto = newAutoParam(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
            if(auxAuto != NULL)
            {    ///el contenido de auxAuto lo copiamos al array de punteros donde apunta lista
                *(lista + tam) = auxAuto;
                tam++;
                /*tam + 1 es porque tam= la cantidad de elementos y tam+1=es el proximo espacio libre
                ya preparado*/
                auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) * (tam + 1));
                if(auxLista != NULL)
                {
                    lista = auxLista;
                }
            }
        }
    }
    ///SIEMPRE despues de leerlo cerrar el archivo
    fclose(f);

    mostrarAutos(lista, tam);

    ///--------------- Guardo los autos en un archivo binario-----------

    if( guardarAutosBinario(lista, tam, "autos.bin"))
    {
        printf("Autos guardados en archivo binario\n");
    }
    else
    {
        printf("No se pudieron guardar los autos\n");
    }

    int tam2 = 0;
    eAuto** lista2 = (eAuto**) malloc(sizeof(eAuto*));
    if( lista2 == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    ///lo abrimos para leer el archivo
    f = fopen("autos.bin", "rb");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


    while( !feof(f) )
    {   ///conseguimos el espacio en memorio con newAuto y guardamos el puntero en auxAuto
        auxAuto = newAuto();
        if(auxAuto ==NULL)
        {
            break;
        }
        ///hacemos la lectura y la vamos guardando en la dir de memorio que apunta auxAuto
        cant = fread( auxAuto, sizeof(eAuto), 1, f);
        if( cant < 1)
        {
            break;
        }
        else
        {   ///el contenido de auxAuto lo copiamos al array de punteros donde apunta lista
            *(lista2 + tam2) = auxAuto;
            tam2++;
             /*tam + 1 es porque tam= la cantidad de elementos y tam+1=es el proximo espacio libre
            ya preparado*/
            auxLista = (eAuto**) realloc(lista2, sizeof(eAuto*) * (tam2 + 1));
            if(auxLista != NULL)
            {
                lista2 = auxLista;
            }
        }
    }
///SIEMPRE despues de leerlo cerramos el archivo
fclose(f);

mostrarAutos(lista2, tam2);

if( guardarAutosCSV(lista2, tam2, "listaAutos.csv"))
    {
        printf("Autos guardados en archivo de texto\n");
    }
    else
    {
        printf("No se pudieron guardar los autos\n");
    }




return 0;
}


int setIdAuto(eAuto* unAuto, int id)
{
    int todoOk=0;
    if( unAuto != NULL && id >= 1000 && id <= 2000)
    {
        unAuto->id = id;
        todoOk = 1;
    }
    return todoOk;
}


int getIdAuto(eAuto* unAuto)
{
    int id = -1;
    if( unAuto != NULL)
    {
        id = unAuto->id;
    }
    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if( unAuto != NULL && marca != NULL && strlen(marca) >= 3) ///cualquier regla que deba cumplir el campo lo valido aca
    {
        strcpy(unAuto->marca, marca);
        todoOk = 1;
    }
    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if( unAuto != NULL && marca != NULL)
    {
        strcpy( marca,unAuto->marca);
        todoOk = 1;
    }
    return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int todoOk=0;
    if( unAuto != NULL && modelo >= 1980 && modelo <= 2020) ///cualquier regla que deba cumplir el campo lo valido aca
    {
        unAuto->modelo = modelo;
        todoOk = 1;
    }
    return todoOk;
}


int getModeloAuto(eAuto* unAuto)
{
    int modelo = -1;
    if( unAuto != NULL)
    {
        modelo = unAuto->modelo;
    }
    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int todoOk=0;
    if( unAuto != NULL && precio >= 500 && precio <= 1500) ///cualquier regla que deba cumplir el campo lo valido aca
    {                                                    ///se podria validar que no sean letras
        unAuto->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}


float getPrecioAuto(eAuto* unAuto)
{
    float precio = -1;
    if( unAuto != NULL)
    {
        precio = unAuto->precio;
    }
    return precio;
}



int mostrarAuto(eAuto* unAuto)///le pasamos puntero a estruc Auto, para entrar en un auto
{
    int todoOk = 0;

    if( unAuto != NULL )
    {
        printf(" %d  %20s %d %6.2f\n", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);
        todoOk = 1;
    }
    return todoOk;
}

///le pasamos el puntero a punteros que guarda la dir de memoria a la estructura auto.
///Osea recibe directamente el array de punteros
int mostrarAutos(eAuto** autos, int tam) ///por eso doble **
{

    int todoOk = 0;

    if( autos != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
        {
            mostrarAuto(*(autos + i) );
        }
        todoOk = 1;
    }
    return todoOk;
}

///esta funcion se utiliza para designar el espacio en memoria para el nuevo auto y obtener el puntero

eAuto* newAuto()
{
    eAuto* nuevo = (eAuto*) malloc( sizeof(eAuto));
    if( nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->marca, " ");
        nuevo->modelo = 0;
        nuevo->precio = 0;
    }
    return nuevo;
}

eAuto* newAutoParam(int id, char* marca, int modelo, float precio)
{
    eAuto* nuevo = newAuto();
    if( nuevo != NULL)
    {
        if(
            setIdAuto(nuevo, id)
            && setModeloAuto(nuevo, modelo)
            && setMarcaAuto(nuevo, marca)
            && setPrecioAuto(nuevo, precio) == 0)
        {
            free(nuevo); ///liberamos ese espacio en memoria porque fallo la carga
            nuevo = NULL;
        }
    }
    return nuevo;
}

int guardarAutosBinario( eAuto** lista, int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if( lista != NULL && tam > 0 && path != NULL)
    {
        f = fopen(path, "wb");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return todoOk;
        }

        for(int i=0; i < tam; i++)
        {
            fwrite( *(lista + i),  sizeof(eAuto), 1, f);
        }

        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

int guardarAutosCSV( eAuto** lista, int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if( lista != NULL && tam > 0 && path != NULL)
    {
        f = fopen(path, "w");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return todoOk;
        }
        fprintf(f, "id,marca,modelo,precio\n");
        for(int i=0; i < tam; i++)
        {
            fprintf(f, "%d,%s,%d,%.2f\n", (*(lista+i))->id, (*(lista+i))->marca, (*(lista+i))->modelo, (*(lista+i))->precio);
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}


