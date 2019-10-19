#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"

/** \brief parsea el puntero a pFile que recibe
 *
 * \param pFile puntero a la estructura FILE
 * \param linkedlist
 * \return
 *
 */

int parser_FromText(FILE* pFile , LinkedList* lista){
    char campo_1[5];
    char campo_2[75];
    char campo_3[75];
    char campo_4[10];
    char campo_5[10];

    int charge;
    charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", campo_1, campo_2, campo_3, campo_4, campo_5);
    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", campo_1, campo_2, campo_3, campo_4, campo_5);
        if(charge!=5){
            printf("\nError");
        }else{
            eLibro* pLibro=libro_new();
            if (pLibro!=NULL){

                    entidad_setCampo1(pLibro, campo_1);
                    entidad_setCampo2(pLibro, campo_2);
                    entidad_setCampo3(pLibro, campo_3);
                    entidad_setCampo4(pLibro, campo_4);
                    entidad_setCampo5(pLibro, campo_5);
            }

           ll_add(lista, pLibro);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return 1;
}
/** \brief funciones Setters para cada campo de la escructura
 *
 * \param
 * \param
 * \return
 *
 */

int entidad_setCampo1(eLibro* pLibro, char *aux){
    int retorno=0;
    if(pLibro!=NULL && aux!=NULL){
        pLibro->id=atoi(aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo2(eLibro* pLibro, char *aux){
    int retorno=0;
    if(pLibro!=NULL && aux!=NULL){
        strcpy(pLibro->titulo,aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo3(eLibro* pLibro, char *aux){
    int retorno=0;
    if(pLibro!=NULL && aux!=NULL){
        strcpy(pLibro->autor,aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo4(eLibro* pLibro, char *aux){
    int retorno=0;
    if(pLibro!=NULL && aux!=NULL){
        pLibro->precio=atoi(aux);
        retorno=1;
    }
   return retorno;
}
int entidad_setCampo5(eLibro* pLibro, char *aux){
    int retorno=0;
    if(pLibro!=NULL && aux!=NULL){
        pLibro->editorialId=atoi(aux);
        retorno=1;
    }
    return retorno;
}


/** \brief Reservo memoria mediante funcion malloc y casteo a estructura
 *          y seteo todos los campos en Cero o vacios usando get und set
 * \param
 * \param
 * \return devuelvo puntero a estructura
 *
 */

eLibro* libro_new(){

eLibro* pLibro=(eLibro*)malloc(sizeof(eLibro));

    char* aux=0;

    entidad_setCampo1(pLibro,aux);
    strcpy(eEntidad_getCampo2(pLibro)," ");
    strcpy(eEntidad_getCampo3(pLibro)," ");
    entidad_setCampo4(pLibro,aux);
    entidad_setCampo5(pLibro,aux);

return pLibro;
}

/** \brief tomo el valor del campo solicitado y lo asigno a la variable valor la cual retorno
 *
 * \param eLibro entidad
 * \param
 * \return retorna valor -1 si no asigno, o el valor asignado del campo correspondiente
 *
 */

int eEntidad_getCampo1(eLibro* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->id;
    }
    return valor;
}

char* eEntidad_getCampo2(eLibro* thisIs){
    char* valor;
    if(thisIs!=NULL)
    {
       valor=thisIs->titulo;
    }
    return valor;
}

char* eEntidad_getCampo3(eLibro* thisIs){
    char* valor;
    if (thisIs!=NULL)
    {
        valor=thisIs->autor;
    }
    return valor;
}

int eEntidad_getCampo4(eLibro* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->precio;
    }
    return valor;
}

int eEntidad_getCampo5(eLibro* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->editorialId;
    }
    return valor;
}

/** \brief Recibo la lista y grabo en archivo de salida
 *
 * \param LinkedList
 * \param archivo recivo el nombre de archivo de salida
 * \return 1 si ha sido correcto
 *
 */

int parser_SaveToText(LinkedList* lista, char* archivo)
{
    FILE* pFile;
    int retorno = 0;
    eLibro* aux;
    int len; ;
    int i;

    pFile=fopen(archivo, "w");
    if(pFile != NULL && lista!= NULL)
    {
        len=ll_len(lista);
        fprintf(pFile,"Id , Titulo, Autor, Precio,EditorialId\n");

        for(i=0;i<len;i++)
        {
            aux = ll_get(lista,i);

            fprintf(pFile,"%d,%s,%s,%d,%d\n",eEntidad_getCampo1(aux), eEntidad_getCampo2(aux), eEntidad_getCampo3(aux), eEntidad_getCampo4(aux), eEntidad_getCampo5(aux));

        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Imprimo lista por pantalla
 *
 * \param LinkedList recibe lista ll
 * \param
 * \return
 *
 */

void printerList (LinkedList* lista){
int i;
int largo=ll_len(lista);
eLibro* libro;


printf("\n %3s %20s %20s %10s %10s","Id", "Titulo","Autor","Precio", "Editorial");
printf("\n");
    for (i=0;i<largo;i++){

        libro=ll_get(lista, i);

        printf("\n%3d %5s %5s %5d %d",eEntidad_getCampo1(libro),eEntidad_getCampo2(libro),eEntidad_getCampo3(libro), eEntidad_getCampo4(libro), eEntidad_getCampo5(libro));

        if(libro->editorialId==1){
            printf(" - PLANETA");
        }else if(libro->editorialId==2){
            printf(" - SIGLO XXI");
        }else if(libro->editorialId==3){
            printf(" - PEARSON");
        }else if(libro->editorialId==4){
            printf(" - MINOTAURO");
        }else if (libro->editorialId==5){
            printf(" - SALAMANDRA");
        }else if (libro->editorialId==6){
            printf(" - PENGUIN BOOKS");
        }
    }
}

/** \brief Seteo el costo valor en funcion del campo editorialID
 *
 * \param casteo el puntero a element a mi entidad Struct
 * \param
 * \return void
 *
 */


void setDescuento(void* element){

    int auxEditorial=((eLibro*)element)->editorialId;

   // int descuento=((eLibro*)element)->precio;
    //Editorial PLANETA 20 % de descuento
    if(auxEditorial==1){
        ((eLibro*)element)->precio=((eLibro*)element)->precio-((((eLibro*)element)->precio)*20/100);
    }else if (auxEditorial==2){
        ((eLibro*)element)->precio=((eLibro*)element)->precio-((((eLibro*)element)->precio)*10/100);
    }
}
/** \brief Ordena el linkedList
 *
 * \param void puntero a void que luego sera casteado a la entidad correspondiente
 * \param
 * \return
 *
 */

int ordenar(void* element, void* elementB){

    return (((eLibro*)element)->editorialId>((eLibro*)elementB)->editorialId);

}

