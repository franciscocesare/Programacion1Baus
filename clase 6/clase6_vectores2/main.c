#include <stdio.h>
#include <stdlib.h>

void mostrarVectorChar (char vec [], int tam);
int esPar(int a);
int obtenerMayor (int vec [], int tam);
void ordenarAlfabeticamente (char vec[], int tam);
int main()


{
    char letras[5]= {'b','c', 'a','d','e'};

    ordenarAlfabeticamente(letras, 5);


        printf("%s", letras);



    /*int numero [10] = {1,2,3,14,35,6,7,8,9,10};
    int mayor;

    mayor=obtenerMayor(numero, 10);
    printf("el mayor es: %d ", mayor);

    int num;

    printf("ingrese un numero entre 200 y 500: ");
    scanf("%d", &num);

    while (num<200 || num>500)
    {
        printf("error ingrese otro numero en el rango ");
        scanf("%d", &num);
    }
    printf("el numero es: %d", num);

    ///llamado a esPar
    int numero=6;

    esPar(numero);///le paso el numero 4


    int i=0;

    for (i=0;i<10;i++)
    {
        if (!(i%2))
        {
            printf("\n\n%d", i);
        }
    }

       char vocales [] = {'a', 'e','i', 'o', 'u'};
     float edad [15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

       mostrarVectorChar(vocales, 5);

       //for (int i=0; i<5; i++)
       //{

           printf("\n%.3f", edad[14]);
       //}*/

    return 0;
}

void ordenarAlfabeticamente (char vec[], int tam)
{
    int aux;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
            if (vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
    }
}


int obtenerMayor (int vec [], int tam)
{
    int mayor=vec[0];

    for (int i=0; i<tam; i++)
    {
        if(vec[i]>mayor)
        {
            mayor=vec[i];
        }
    }
    return mayor;
}

int esPar(int a)
{
    int todoOk=0;

    if (a%2==0)
    {
        printf("\n%d Es un numero PAR", a);
        todoOk=1;

    }
    else
    {
        printf("\n%d, es un numero IMPAR", a);
    }
    return todoOk;
}


void mostrarVectorChar (char vec [], int tam)
{
    for (int i=0; i<5; i++)
    {
        printf("%c", vec [i]);
    }

}
