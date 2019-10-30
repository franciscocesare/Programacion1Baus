#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
} eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);
int main()
{


    escribirBinario("miEmpleado.dat");
    leerBinario("miEmpleado.dat");



    return 0;
}

void escribirBinario(char* path)
{
    eEmpleado miEmpleado[2] = {{100,"Pepe",1000},{101,"Luis",1200}};
    FILE* miArchivo;
    int i;
    int len = 2;


    miArchivo = fopen(path,"wb");
    if(miArchivo!=NULL)
    {
        fwrite(&len,sizeof(int),1,miArchivo);

        for(i=0; i<2; i++)
            fwrite(miEmpleado+i,sizeof(eEmpleado),1,miArchivo);

        fclose(miArchivo);
    }

}

void leerBinario(char* path)
{
    eEmpleado miEmpleado[10];
    FILE* miArchivo;
    int i=0;
    int len;

    miArchivo = fopen(path,"rb");

    fread(&len,sizeof(int),1,miArchivo);
    printf("%d\n\n",len);



    fread(miEmpleado,sizeof(eEmpleado),len,miArchivo);
    /*
    while(!feof(miArchivo))
    {

        i++;
    }*/


    fclose(miArchivo);

    for(i=0; i<2; i++)
    {
        printf("%d-%s-%f\n", miEmpleado[i].legajo, miEmpleado[i].nombre,
               miEmpleado[i].salario);
    }


}
