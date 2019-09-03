#include <stdio.h>
#include <stdlib.h>

int funcionCualquiera(int x);

int main()
{
    int x = 5;

    x = funcionCualquiera(x);

     printf("%d", x);
    return 0;
}

int funcionCualquiera(int x){

    return  x * 2;


}
