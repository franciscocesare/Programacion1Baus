#include <stdio.h>
#include <stdlib.h>

int getIntRange(int* numero, char* mensaje, char* mensajeError, int min, int max, int intentos);

int main()
{
    int nota;
    int todoOk;

    todoOk = getIntRange(&nota, "Ingrese nota ", "Error. Reingrese nota ",0, 10,3);

    if(todoOk == 0){
        printf("No se pudo conseguir la nota\n");
    }
    else{
        printf("La nota ingresada es %d\n", nota);
    }

    return 0;
}

int getIntRange(int* numero,
                char* mensaje,
                char* mensajeError,
                int min,
                int max,
                int intentos
                )
{
    int auxiliar;
    int todoOk = 1;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    while( auxiliar < min || auxiliar > max)
    {
        intentos--;
        if(intentos == 0){
            todoOk = 0;
            break;
        }
        printf("%s", mensajeError);
        scanf("%d", &auxiliar);
    }

    if( intentos != 0){
        *numero = auxiliar;
    }
    return todoOk;

}
