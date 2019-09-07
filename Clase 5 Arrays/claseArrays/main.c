#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt (int vec[], int tam);
int obtenerMayor(int vec[], int tam);

int main()
{
    int numeros [5];
    int suma=0;
    int numeroMayor;
    int indice;

    for (int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    mostrarVectorInt(numeros, 5); //llamadas a la funcion
    obtenerMayor(numeros, 5);

    /* for (int i=0; i<5; i++)
     {
         if (i==0)
         {
             numeroMayor = numeros[i];
         }

         else if  (numeros[i] > numeroMayor)
         {
             numeroMayor = numeros[i];
         }

     }
     printf("\n\nNumero mayor: %d", numeroMayor);

      for (int i=0; i<5; i++)
      {
          printf("%d ", numeros[i]);
          //scanf("%d", &numeros[i]);
      }

      for (int i=0; i<5; i++)
      {
          suma+=numeros[i];
      }
      printf("\nLa suma es %d ", suma);*/


    return 0;
}

void mostrarVectorInt (int vec[], int tam)
{
    for (int i=0; i < tam; i++)
    {
        printf("%d", vec[i]);
    }
    printf("\n\n");
}
int obtenerMayor(int vec[], int tam)
{
    for (int i=0; i < tam; i++)
        if (i==0)
        {
            numeroMayor = numeros[i];
        }

        else if  (numeros[i] > numeroMayor)
        {
            numeroMayor = numeros[i];
        }

}
