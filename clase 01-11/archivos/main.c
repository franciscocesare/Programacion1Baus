#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//eAuto* hacer newauto
//eAuto * new auto param(int id, char marca, int modelo, float precio);

//mostrarauto
//mostrarAutos
//sort(comparison)

geter y setter
seter setear un valor, con validaciones para proteger
geter obtener un valor de algun campo. retorna del mismo tipo de lo que estoy geteando





*/


typedef struct
{

    int id;
    char marca[30];
    int modelo;
    float precio;

} eAuto;




int main()
{
    int setIdAuto(eAuto* unAuto, int id ) ///sabiendo que unAuto debe tener un valor entre , se puede setear
    {

        int todoOk=0;
        if(unAuto!=NULL && id>=1000 && id<=2000)
        {
            unAuto->id = id;
            todoOk = 1;
        }
        return todoOk;
    }

    //////

    int getIdAuto(eAuto* unAuto)
    {

        int id=-1;
        if(unAuto!=NULL)
        {
           id = unAuto->id;
        }
        return id;
    }

    //////

    int setMarcaAuto(eAuto* unAuto, char* marca ) ///sabiendo que unAuto debe tener un valor entre , se puede setear
    {

        int todoOk=0;
        if(unAuto!=NULL && marca!=NULL && strlen(marca)>=3) ///cualquier regla que deba cumplir el campo lo valido aca
        {
            strcpy(unAuto->marca, marca);
            todoOk = 1;
        }
        return todoOk;
    }

    /////

    int getMarcaAuto(eAuto* unAuto, char* marca ) ///sabiendo que unAuto debe tener un valor entre , se puede setear
    {

        int todoOk=0;
        if(unAuto!=NULL && marca != NULL) ///cualquier regla que deba cumplir el campo lo valido aca
        {
            strcpy(unAuto->marca, marca);
            todoOk = 1;
        }
        return todoOk;
    }


    return 0;
}
