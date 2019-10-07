#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "biblioteca.h"

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMSERV 4
#define TAMAUTO 10
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


char menu();

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
                            if(bajaAuto(autos, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA)){
                                flag--;
                            }

                    }
                    else{
                        printf("NO HAY AUTOS!!!!! \n\n");
                    }

                    break;
                case 'C':
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


void mostrarAuto(eAuto car, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    char descMarca[21];
    char descColor[21];
    cargarDescColor(car.idColor, colores, tamColor, descColor);
    cargarDescMarca(car.idMarca, marcas, tamMarca, descMarca);
    printf(" %d    %s    %s    %s    %d\n\n", car.idAuto, car.patente, descMarca, descColor, car.modelo);
}

void mostrarAutos(eAuto autos[], int tamAuto, eColor colores[], int tamColor, eMarca marcas[], int tamMarca){
    int cont = 0;
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
    printf(" %d    %s    %s     %d/%d/%d\n\n", trabajo.idTrabajo, trabajo.patente, descServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServ){
    int cont = 0;
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

            getString(patente, "Ingrese Patente: ", "Error. Reingrese Patente: ", 3,3);

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

    mostrarAutos(autos, tamAuto, colores, tamColor, marcas, tamMarca);

    getString(patente, "Ingrese Patente: ", "Error. Reingrese Patente: ", 1, 6);

    esta = buscarPatente(autos, tamAuto, patente);

    if(esta != -1){
        autos[esta].isEmpty = 1;
        rta = 1;
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


