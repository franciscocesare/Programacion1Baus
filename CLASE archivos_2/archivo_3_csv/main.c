#include <stdio.h>
#include <stdlib.h>
#include "string.h"

///creamos una struct para guardar
typedef struct
{
    int legajo;
    char nombre [30];
    char apellido [30];
    float sueldo;


}eEmpleado;

/*crear un constuctor, siempre tienen que tener MALLOC

*/
eEmpleado* new_Empleado();



int main()
{
   ///Array de punteros, de direccones de memoria de
    eEmpleado* lista[50];
    eEmpleado* emple;

   FILE* miArchivo;
   char legajo [10];
   char nombre[20];
   char apellido [20];
   char sueldo [10];  ///son todas cadenas, porque del archivo leo cadenas, desues los convierto
   int i=0;



   miArchivo = fopen("datos.csv", "r"); ///guardo en mi archivo el csv que abro

   while (!feof(miArchivo))
   {
   fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n]\n",legajo, nombre, apellido, sueldo);

   emple = new_Empleado();                                      ///se puede setear para que tome pedacitos de cadenas.
   emple->legajo = atoi(legajo); ///aca parseo la cadena legajo                                    ///"%[^,]" es que va a leer hasta la coma, y excluye la coma. el de \n, es xq es el ultimo

   strcpy(emple->nombre, nombre); ///las -> es xq ahora es un puntero
   strcpy(emple->apellido, apellido);
   emple->sueldo = atof(sueldo);                                  ///y estan guardada asi en el archivo. uno abajo del otro

   *(lista+i) = emple;
   i++;

   ///printf("%d---%s---%s---%f---\n",emple.legajo, emple.nombre, emple.apellido, emple.sueldo);
   }

   fclose(miArchivo);

   for (i=0; i<50; i++)
   {
    printf("%2d---%10s---%10s---%f\n", lista[i]->legajo, lista[i]->apellido, lista[i]->nombre, lista[i]->sueldo);
   }


    return 0;
}

///constructor crea empleados en el heap, reserva memoria
eEmpleado* new_Empleado()
{
    eEmpleado* e;

    e=(eEmpleado*)malloc(sizeof(eEmpleado));

    return e;
}
