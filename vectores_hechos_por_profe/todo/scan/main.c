#include <stdio.h>
#include <stdlib.h>

int main()
{
   int retorno;
   int num1 = 10;
   int num2 = 20;



   printf("Ingrese dos numeros: ");

   retorno = scanf("%d %d", &num1, &num2);

   printf("Retorno: %d  num1: %d  num2: %d\n", retorno, num1, num2);
    return 0;
}
