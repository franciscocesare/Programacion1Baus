#include <stdio.h>
#include <stdlib.h>

long long factorial( long  numero);

int main()
{
    printf("%ld", factorial(31));
    return 0;
}

long long factorial( long n){

    long long fact;

    if( n == 1){
        fact = 1;
    }
    else{

        fact = n * factorial (n-1);
    }
    return fact;

}
