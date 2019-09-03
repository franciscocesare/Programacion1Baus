#include <stdio.h>
#include <stdlib.h>
int getIntRange (int *numero,
                 char* mensaje,
                 char* mensajeError,
                 int min, int max,
                 int intentos);
int main()
{
    int nota;
    int todoOk;

    todoOk = getIntRange(&nota,"ingrese nota: ", "Error, reingrese nota: ", 0, 10, 3);
    if (todoOk==0)
    {
        printf("%d", ) ///completar bien!!!!!!!
    }
    return 0;
}

int getIntRange (int *numero,
                 char* mensaje,
                 char* mensajeError,
                 int min, int max,
                 int intentos)
{

    int auxiliar;
    int todoOk =1;

    printf ("%s", mensaje);
    scanf("%d", &auxiliar);

    while (auxiliar<min || auxiliar>max)
    {
        intentos --; ///ante cada bucle resta un intento

        if (intentos==0)
        {
            todoOk=0;
            break;///para salir del bucle cuando retorno el error ya
        }
        printf ("%s", mensajeError);
        scanf("%d", &auxiliar);
    }
    if (intentos !=0)
    {
        *numero=auxiliar;
    }
    return todoOk;
}
