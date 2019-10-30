#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre [30];
    float salario;

} eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);


int main()
{
    //escribirBinario("miEmpleado.dat");///aca solo el pasas el PATH en la llamada
    escribirBinario("miEmpleado.dat");
    leerBinario("miEmpleado.dat");



    return 0;
}

void escribirBinario(char* path)
{
    int len =2;
    eEmpleado miEmpleado[2] = {{100, "Pepe", 1000}, {101, "Luis", 2000}};
    FILE* miArchivo;

    miArchivo = fopen (path, "wb");///(el path, la ruta. y si es Read Write y el tipo.)
    if (miArchivo!=NULL)
    {
        fwrite(&len, sizeof(int), 1,miArchivo); ///le paso el contenido de LEN, y el 1 es el tamaño de lo que queres guardar
        for (int i=0; i<2; i++)
        {
            ///fwrite(&miEmpleado, sizeof(eEmpleado),1/*el 1 es valores que hay, aca un empleado */,miArchivo);  ///puedo escribir binario o texto. pero con fprintf solo texto. le paso el &el contenido del puntero
            fwrite(&miEmpleado[i], sizeof(eEmpleado),1/*el 1 es valores que hay, aca un empleado */,miArchivo);///como es Array no lleva &                                                                   ///* a Void es un generico que despues se castea int, float
        }

        fclose(miArchivo);
    }
}

void leerBinario(char* path)

{
    int len;
    eEmpleado miEmpleado [2];
    FILE* miArchivo;

    miArchivo = fopen(path, "rb");
    ///preguntar antes si no es NULL

    if(miArchivo!=NULL)
    {
        fread (&len, sizeof(int), 1, miArchivo);///con este leo el LEN y lo cargo en miArchivo
        printf("%d\n", len);
        fread(miEmpleado,sizeof(eEmpleado),len, miArchivo);  ///(1donde vpy a guardar,TipodeEmpleado,cuantos empleados guarde, )


        for (int i=0; i<len; i++)
        {
            printf("%d-%s-%.2f \n", miEmpleado[i].legajo, miEmpleado[i].nombre,miEmpleado[i].salario);
        }

        fclose(miArchivo); ///siempre cerrar el archivo!! despues de fread
    }



}

