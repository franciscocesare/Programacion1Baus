#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    float b;
}eDato;

eDato* constructor();

int main()
{
    eDato* p;

    p = constructor();
printf("\n");
    printf("%d--%f", p->a,p->b);
    return 0;
}

eDato* constructor()
{
    eDato d ={1,2.58};
    return &d;
}
