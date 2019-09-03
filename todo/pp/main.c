#include <stdio.h>
#include <stdlib.h>

void changeX( int* q );

int main()
{
   // int x = 5;

  //  changeX( &x);

    char x = '1';



    printf("%d\n", x);


    return 0;
}

void changeX( int* q ){

       printf("Ingrese un numero: ");
       scanf("%d", q);

}
