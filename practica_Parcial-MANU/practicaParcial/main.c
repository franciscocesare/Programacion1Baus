#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "biblioteca.h"

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMSERV 4
#define TAMAUTO 11
#define TAMT 10

////////////////////////////////////// ESTRUCTURAS
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idMarca;
    char descripcion[21];
}eMarca;

typedef struct{
    int idColor;
    char descripcion[21];
}eColor;

typedef struct{
    int idAuto;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

typedef struct{
    int idServicio;
    char descripcion[26];
    float precio;
}eServicio;

typedef struct{
    int idTrabajo;
    char patente[7];
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;
//////////////////////////////////// PROTOTIPOS

//AUTOS
int inicializarAutos(eAuto vec[], int tam);
int isEmptyAuto(eAuto vec[], int tam);
eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo);
int altaAuto(eAuto autos[], int tamAuto, int idAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);
void mostrarAutos(eAuto autos[], int tamAuto, eColor colores[], int tamColor, eMarca marcas[], int tamMarca);
void mostrarAuto(eAuto car, eColor colores[], int tamColor, eMarca marcas[], int tamMarca);
int buscarPatente(eAuto autos[], int tamAuto, char patente[]);
int bajaAuto(eAuto autos[], int tamAuto, eColor colores[], int tamColor, eMarca marcas[], int tamMarca);
int modificarAuto(eAuto autos[], int tamAuto, eColor colores[], int tamColor);
void ordenarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca);
int hardcodearAutos( eAuto autos[], int tamAuto, int cantidad);

//COLORES
void mostrarColores(eColor colores[], int tamColor);
void mostrarColor(eColor color);
int cargarDescColor(int idColor, eColor colores[], int tamColor, char desc[]);

//MARCAS
void mostrarMarcas(eMarca marcas[], int tamMarca);
void mostrarMarca(eMarca marca);
int cargarDescMarca(int idMarca, eMarca marcas[], int tamMarca, char desc[]);

// SERVICIOS
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tamServ);
int cargarDescServicio(int idServicio, eServicio servicios[], int tamServ, char desc[]);

// TRABAJOS
int inicializarTrabajos(eTrabajo trabajos[], int tamTrabajo);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ);
void mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServ);
int altaTrabajo(eTrabajo trabajos[], int tamT, int idTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ);
eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha);

char menu();
int subMenu();

///////////////////////////////////// MAIN
int main()
{
    char salir = 'N';
    int idAuto = 0;
    int idTrabajo = 0;
    int flag = 0;

    eMarca marcas[TAMMARCA] = {
         {1000, "Renault"},
         {1001, "Fiat"},
         {1002, "Ford"},
         {1003, "Chevrolet"},
         {1004, "Peugeot"}
        };

    eColor colores[TAMCOLOR] = {
         {5000, "Negro"},
         {5001, "Blanco"},
         {5002, "Gris"},
         {5003, "Rojo"},
         {5004, "Azul"}
        };

    eServicio servicios[TAMSERV] = {
         {20000, "Lavado", 250},
         {20001, "Pulido", 300},
         {20002, "Encerado", 400},
         {20003, "Completo", 600}
        };

    eAuto autos[TAMAUTO];
    eTrabajo trabajos[TAMT];

    inicializarAutos(autos, TAMAUTO);
    inicializarTrabajos(trabajos, TAMT);

    idAuto = idAuto + hardcodearAutos(autos, TAMAUTO, 10);

    do{
            switch(menu()){
                case 'A':
                    if(altaAuto(autos,TAMAUTO, idAuto, marcas, TAMMARCA, colores, TAMCOLOR)){
                        idAuto++;
                        flag++;
                    }
                    break;
                case 'B':
                    if(flag != 0){
                        modificarAuto(autos, TAMAUTO, colores, TAMCOLOR);
                    }
                    else{
                        printf("NO HAY AUTOS !!  \n\n");
                    }

                    break;
                case 'C':
                     if(flag != 0){
                            if(bajaAuto(autos, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA)){
                                flag--;
                            }

                    }
                    else{
                        printf("NO HAY AUTOS!!!!! \n\n");
                    }
                    break;
                case 'D':
                    mostrarAutos(autos, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA);
                    break;
                case 'E':
                    mostrarMarcas(marcas, TAMMARCA);
                    break;
                case 'F':
                    mostrarColores(colores, TAMCOLOR);
                    break;
                case 'G':
                    mostrarServicios(servicios, TAMSERV);
                    break;
                case 'H':
                    if(altaTrabajo(trabajos, TAMT, idTrabajo, autos, TAMAUTO, servicios, TAMSERV)){
                        idTrabajo++;
                    }

                    break;
                case 'I':
                    mostrarTrabajos(trabajos, TAMT, servicios, TAMSERV);
                    break;
                case 'J':
                    getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese si S o N: ", 'S', 'N');
                    printf("\n\n");
                    break;
                default:
                    printf("\n\nOPCION INVALIDA!! \n\n");
                    break;
            }
        system("pause");
    }while(salir == 'N');


    return 0;
}

///////////////////////////////////////////// DESARROLLO




char menu(){
    char option;

    system("cls");
    printf("************* PRACTICA DE PARCIAL *************\n");
    printf("*************        ABM         *************\n");
    printf("A- Alta Auto\n");
    printf("B- Modificacion Auto\n");
    printf("C- Baja Auto\n");
    printf("D- Listar Autos\n");
    printf("E- Listar Marcas\n");
    printf("F- Listar Colores\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta Trabajo\n");
    printf("I- Listar Trabajos\n");
    printf("J- Salir\n\n");

    getCh(&option,"Ingrese Opcion: ", "Error. Ingrese Opcion: ");

    return option;
}

int subMenu(){
    int option;

        printf("1- COLOR\n");
        printf("2- MODELO\n");
        printf("3- CANCELAR");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 3);

    return option;
}

int modificarAuto(eAuto autos[], int tamAuto, eColor colores[], int tamColor){
    int todoOk = 0;
    char patente[7];
    int esta;
    int flag = 0;

    system("cls");
    printf("************* MODIFICACION *************\n");

    getString(patente, "Ingrese Patente: ", "Error. Reingrese patente: ", 6, 6);

    esta = buscarPatente(autos, tamAuto, patente);

    if(esta != -1){
        switch(subMenu()){
        case 1:
            mostrarColores(colores, tamColor);
            getIntRange(&autos[esta].idColor, "Ingrese ID de color: ", "Error. Reingrese ID Color: ",5000,5004);
            todoOk = 1;
            flag = 1;
            break;
        case 2:
            getInt(&autos[esta].modelo, "Ingrese Modelo: ", "Error. Reingrese Modelo: ");
            todoOk = 1;
            flag = 2;
            break;
        case 3:
            printf("\nSE CANCELO MODIFICAION\n\n");
            break;
        default:
            printf("\nOPCION INVALIDA !! \n\n");
            break;
        }
    }
    else{
        printf("NO EXISTE AUTO CON ESA PATENTE\n\n");
    }

    if(flag == 1){
            printf("\nSE MODIFICO COLOR CON EXITO !! \n\n");

        }else if(flag == 2){
            printf("\nSE MODIFICO MODELO CON EXITO !!\n\n");
        }
    return todoOk;
}


int inicializarAutos(eAuto autos[], int tamAuto){
    int rta = 0;
    for(int i=0; i<tamAuto; i++){
        autos[i].isEmpty = 1;
        if(i == tamAuto -1){
            rta=1;
        }
    }
    return rta;
}

int inicializarTrabajos(eTrabajo trabajos[], int tamTrabajo){
    int rta = 0;
    for(int i=0; i<tamTrabajo; i++){
        trabajos[i].isEmpty = 1;
        if(i == tamTrabajo -1){
            rta=1;
        }
    }
    return rta;
}

int isEmptyAuto(eAuto autos[], int tamAuto){
    int index = -1;
    for(int i=0; i<tamAuto; i++){
        if(autos[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int isEmptyTrabajo(eTrabajo trabajos[], int tamT){
    int index = -1;
    for(int i=0; i<tamT; i++){
        if(trabajos[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

void mostrarAuto(eAuto car, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    char descMarca[21];
    char descColor[21];
    cargarDescColor(car.idColor, colores, tamColor, descColor);
    cargarDescMarca(car.idMarca, marcas, tamMarca, descMarca);
    printf(" %d      %s       %s       %s       %d\n", car.idAuto, car.patente, descMarca, descColor, car.modelo);
}

void mostrarAutos(eAuto autos[], int tamAuto, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    int cont = 0;

    printf(" ID    PATENTE    MARCA     COLOR     MODELO  \n");

    ordenarAutos(autos, tamAuto, marcas, tamMarca);

    for(int i=0; i<tamAuto; i++){
        if(autos[i].isEmpty == 0){
            mostrarAuto(autos[i], colores, tamColor, marcas, tamMarca);
            cont++;
        }
    }
    if(!cont){
        printf("NO HAY AUTOS QUE MOSTRAR\n\n");
    }
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ){
    char descServicio[21];
    cargarDescServicio(trabajo.idServicio, servicios, tamServ, descServicio);
    printf(" %d    %s       %s       %0d/%0d/%d\n", trabajo.idTrabajo, trabajo.patente, descServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServ){
    int cont = 0;

    printf(" ID     PATENTE    SERVICIO      FECHA \n");

    for(int i=0; i<tamT; i++){
        if(trabajos[i].isEmpty == 0){
            mostrarTrabajo(trabajos[i], servicios, tamServ);
            cont++;
        }
    }


    if(!cont){
        printf("NO HAY TRABAJOS QUE MOSTRAR\n\n");
    }
}

void mostrarMarca(eMarca marca){
    printf(" %d     %s \n", marca.idMarca, marca.descripcion);
}

void mostrarMarcas(eMarca marcas[], int tamMarca){
    int cont = 0;
    printf("  ID     MARCA   \n");
    for(int i=0; i<tamMarca; i++){
        mostrarMarca(marcas[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY MARCAS QUE MOSTRAR\n\n");
    }
}

void mostrarColor(eColor color){
    printf(" %d     %s \n", color.idColor, color.descripcion);
}

void mostrarColores(eColor colores[], int tamColor){
    int cont = 0;
    printf("  ID     COLOR   \n");
    for(int i=0; i<tamColor; i++){
        mostrarColor(colores[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY MARCAS QUE MOSTRAR\n\n");
    }
}

void mostrarServicio(eServicio servicio){
    printf(" %d     %s     %.2f\n", servicio.idServicio, servicio.descripcion, servicio.precio);
}

void mostrarServicios(eServicio servicios[], int tamServ){
    int cont = 0;
    printf("  ID     SERVICIO     PRECIO \n");
    for(int i=0; i<tamServ; i++){
        mostrarServicio(servicios[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY SERVICIOS QUE MOSTRAR\n\n");
    }
}

int altaAuto(eAuto autos[], int tamAuto, int idAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor){
    int todoOk = 0;
    int indice;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;

        system("cls");
        printf("******* ALTA *******\n\n");

        indice = isEmptyAuto(autos, tamAuto);
        if(indice == -1){
            printf("NO HAY LUGAR!!\n\n");
        }
        else{

            getString(patente, "Ingrese Patente: ", "Error. Reingrese Patente: ", 6,6);

            mostrarMarcas(marcas, tamMarca);

            getIntRange(&idMarca, "Ingrese ID: ", "Error. Reingrese: ", 1000, 1004);

            mostrarColores(colores, tamColor);

            getIntRange(&idColor,"Ingrese ID: ", "Error. Reingrese: ", 5000, 5004);

            getInt(&modelo, "Ingrese Modelo: ", "Error. Reingrese Modelo: ");

            autos[indice] = newAuto(idAuto, patente, idMarca, idColor, modelo);

            todoOk = 1;
            if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }
        }

    return todoOk;
}


eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo){
    eAuto car;

    car.idAuto = idAuto + 1;
    strcpy(car.patente, patente);
    car.idMarca = idMarca;
    car.idColor = idColor;
    car.modelo = modelo;
    car.isEmpty = 0;

    return car;
}

int bajaAuto(eAuto autos[], int tamAuto, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    int rta = 0;
    char patente[7];
    int esta;
    char confirma;

    mostrarAutos(autos, tamAuto, colores, tamColor, marcas, tamMarca);

    getString(patente, "Ingrese Patente: ", "Error. Reingrese Patente: ", 6, 6);

    esta = buscarPatente(autos, tamAuto, patente);

    if(esta != -1){

        mostrarAuto(autos[esta], colores, tamColor, marcas, tamMarca);

        getChar(&confirma, "Confirma baja?  S o N: ", "Error. Reingrese S o N: ", 'S', 'N');

        if(confirma == 'S')
        {
            autos[esta].isEmpty = 1;
            printf("BAJA EXITOSA!! \n\n");
            rta = 1;
        }
        else
        {
            printf("\nLA ELIMINACION HA SIDO CANCELADA\n");
        }

    }
    else{
        printf("NO EXISTE ESE AUTO!! \n\n");
        system("pause");
    }
    return rta;
}

int buscarPatente(eAuto autos[], int tamAuto, char patente[]){

    int indice = -1;

    for(int i=0; i<tamAuto; i++){
        if(strcmp(autos[i].patente, patente) == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarDescMarca(int idMarca, eMarca marcas[], int tamMarca, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamMarca; i++){
        if( idMarca == marcas[i].idMarca){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


int cargarDescColor(int idColor, eColor colores[], int tamColor, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamColor; i++){
        if( idColor == colores[i].idColor){
            strcpy(desc, colores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int cargarDescServicio(int idServicio, eServicio servicios[], int tamServ, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamServ; i++){
        if( idServicio == servicios[i].idServicio){
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


eTrabajo newTrabajo(int idTrabajo, char patente[], int idServicio, eFecha fecha){
    eTrabajo aux;

    aux.idTrabajo = idTrabajo + 1;
    strcpy(aux.patente, patente);
    aux.idServicio = idServicio;
    aux.fecha.dia = fecha.dia;
    aux.fecha.mes = fecha.mes;
    aux.fecha.anio = fecha.anio;
    aux.isEmpty = 0;

    return aux;
}

int altaTrabajo(eTrabajo trabajos[], int tamT, int idTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ){
    int todoOk = 0;
    int indice;
    char patente[7];
    int existe;
    int idServicio;
    eFecha fecha;

        system("cls");
        printf("******* ALTA TRABAJO*******\n\n");

        indice = isEmptyTrabajo(trabajos, tamT);
        if(indice == -1){
            printf("NO HAY LUGAR!!\n\n");
        }
        else{

            getString(patente, "Ingrese Patente: ", "Error. Reingrese Patente: ", 6,6);

            existe = buscarPatente(autos, tamAuto, patente);
            if(existe == -1 ){
                printf("\n NO EXISTE \n\n");
            }
            else{
                mostrarServicios(servicios, tamServ);
                getIntRange(&idServicio, " Ingrese ID Servicio: ", "Error. Reingrese ID Servicio: ", 20000, 20003);

                printf("Ingrese Fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                trabajos[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
                todoOk = 1;
            }

            if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }
        }
    return todoOk;
}

void ordenarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca){
    eAuto aux;

        for(int i=0; i<tamAuto-1; i++){
            for(int j=i+1; j<tamAuto; j++){
                if(autos[i].idMarca > autos[j].idMarca){
                    aux = autos[i];
                    autos[i] = autos[j];
                    autos[j] = aux;
                }
                else if(autos[i].idMarca == autos[j].idMarca && stricmp(autos[i].patente, autos[j].patente) > 0 ){
                    aux = autos[i];
                    autos[i] = autos[j];
                    autos[j] = aux;
                }
            }
        }
}


int hardcodearAutos( eAuto autos[], int tamAuto, int cantidad){
    int cont = 0;

    eAuto aux[]=
    {
       {1,   "AAA201", 1000, 5001, 1995, 0},
       {2,   "DFR234", 1003, 5000, 2002, 0},
       {3,   "GFT564", 1002, 5003, 2007, 0},
       {4,   "ACD321", 1002, 5003, 1995, 0},
       {5,   "HTD656", 1004, 5002, 2008, 0},
       {6,   "QSZ435", 1003, 5001, 1994, 0},
       {7,   "LGX201", 1001, 5000, 2012, 0},
       {8,   "SUZ324", 1001, 5002, 1991, 0},
       {9,   "HCU762", 1000, 5003, 2008, 0},
       {10,  "DYC735", 1003, 5001, 2002, 0},
       {11, "JJK879", 1003, 5001, 2010, 0},
       {12, "FED322", 1004, 5002, 2006, 0},
       {13, "GHV332", 1001, 5003, 2007, 0},
       {14, "BDE221", 1000, 5004, 1996, 0},
       {15, "OPD332", 1000, 5001, 2014, 0},
       {16, "PPD121", 1002, 5001, 2015, 0},
       {17, "IIT230", 1001, 5000, 2009, 0},
       {18, "KOD220", 1004, 5002, 2011, 0},
       {19, "QSZ305", 1004, 5002, 1993, 0},
       {20, "SSD128", 1002, 5003, 1992, 0},
       {21, "SSD240", 1003, 5004, 1992, 0},
       {22, "EDF213", 1001, 5000, 2001, 0}
    };

    if( cantidad <= 10 && tamAuto >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            autos[i] = aux[i];
            cont++;
        }
    }

    return cont;
}
