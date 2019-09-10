#include <stdio.h>
#include <stdlib.h>

void mostrarVectorChar (char vec [], int tam);

int main()
{
    char vocales [] = {'a', 'e', 'i', 'o', 'u'};

    mostrarVectorChar(vocales [], 5);


    return 0;
}

void mostrarVectorChar (char vec [], int tam)
{
 for (int i=0; i<5; i++)
    {
        printf("%c", vocales [i]);
    }

}
