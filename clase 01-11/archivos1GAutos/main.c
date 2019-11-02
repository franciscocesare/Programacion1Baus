#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[32];
    int modelo;
    float precio;
} eAuto;

// Mostrar
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);
// Getters y Setters
int setIdAuto(eAuto* unAuto, int id);
int setModeloAuto(eAuto* unAuto, int modelo);
int setPrecioAuto(eAuto* unAuto, float precio);
int setMarcaAuto(eAuto* unAuto, char* marca);
int getIdAuto(eAuto* unAuto);
int getModeloAuto(eAuto* unAuto);
float getPrecioAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto, char* marca);
// Constructores
eAuto* newAuto();
eAuto* newAutoParam(int id, char* marca, int modelo, float precio);
// Comparison


// Escritura/Lectura Archivos
int guardarAutosBinario( eAuto** lista, int tam, char* path);
int guardarAutosCSV( eAuto** lista, int tam, char* path);


int main()
{
    int tam = 0;
    int cant = 0;
    char buffer[4][30];

    FILE* f = NULL;
    eAuto* auxAuto = NULL;
    eAuto** auxLista = NULL;
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

    while( !feof(f) )
    {
        cant =  fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if( cant < 4)
        {
            break;
        }
        else
        {
            auxAuto = newAutoParam(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
            if(auxAuto != NULL)
            {
                *(lista + tam) = auxAuto;
                tam++;
                auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) * (tam + 1));
                if(auxLista != NULL)
                {
                    lista = auxLista;
                }
            }
        }
    }
    fclose(f);

    mostrarAutos(lista, tam);

    //--------------- Guardo los autos en un archivo binario-----------

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

    f = fopen("autos.bin", "rb");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


    while( !feof(f) )
    {
        auxAuto = newAuto();
        if(auxAuto ==NULL)
        {
            break;
        }

        cant = fread( auxAuto, sizeof(eAuto), 1, f);
        if( cant < 1)
        {
            break;
        }
        else
        {
            *(lista2 + tam2) = auxAuto;
            tam2++;
            auxLista = (eAuto**) realloc(lista2, sizeof(eAuto*) * (tam2 + 1));
            if(auxLista != NULL)
            {
                lista2 = auxLista;
            }
        }
    }

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
    if( unAuto != NULL && marca != NULL && strlen(marca) >= 3)
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
    if( unAuto != NULL && modelo >= 1980 && modelo <= 2020)
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
    if( unAuto != NULL && precio >= 500 && precio <= 1500)
    {
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



int mostrarAuto(eAuto* unAuto)
{
    int todoOk = 0;

    if( unAuto != NULL )
    {
        printf(" %d  %20s %d %6.2f\n", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAutos(eAuto** autos, int tam)
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
            free(nuevo);
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


