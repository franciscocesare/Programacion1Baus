#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "biblioteca.h"

#define TAMCAT 5
#define TAMJUEGO 5
#define TAMCLI  12
#define TAMALQ 12

/////////////////////////// ESTRUCTURAAS
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct{
    int idCategoria;
    char descripcion[51];
}eCategoria;


typedef struct{
    int idJuego;
    char descripcion[51];
    float importe;
    int idCategoria;
    int isEmpty;
}eJuego;

typedef struct{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int isEmpty;
}eCliente;

typedef struct{
    int idAlquiler;
    int idJuego;
    int idCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;


//////////////////////// PROTOTIPOS

////////////////////// CLIENTES
int altaCliente(eCliente clientes[], int tamCli, int idCliente);
int isEmptyCliente(eCliente clientes[], int tamCli);
int inicializarClientes(eCliente clientes[], int tamCli);
eCliente newCliente(int idCliente, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);
void ordenarClientes(eCliente cli[], int tamCli);
void mostrarClientes(eCliente clientes[], int tamCli);
void mostrarCliente(eCliente cliente);
int hardcodearClientes( eCliente clientes[], int tamCli, int cantidad);
int bajaCliente(eCliente clientes[], int tamCli);
int buscarIdCliente(eCliente clientes[], int tamCli, int idCliente);
int modificarCliente(eCliente clientes[], int tamCli);
int cargarDescCliente(int idCliente, eCliente clientess[], int tamCli, char desc[]);


/////////////////////// ALQUILERES
int inicializarAlquileres(eAlquiler alquileres[], int tamAlq);
int altaAlquileres(eAlquiler alquileres[], int tamAlq, int idAlquiler, eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat, eCliente clientes[], int tamCli);
eAlquiler newAlquiler(int idAlquiler, int idJuego, int idCliente, eFecha fecha);
void mostrarAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego);
void mostrarAlquiler(eAlquiler alquiler, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli);
int hardcodearAlquileres( eAlquiler alquileres[], int tamAlq, int cantidad);
///////////////////////// JUEGOS

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat);
void mostrarJuegos(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat);
int cargarDescJuego(int idJuego, eJuego juegos[], int tamJuego, char desc[]);

/////////////////////////////  CATEGORIAS
int cargarDescCategoria(int idCategoria, eCategoria categorias[], int tamCat, char desc[]);
void mostrarCategorias(eCategoria categorias[], int tamCat);
void mostrarCategoria(eCategoria categoria);


char menu();

///////////////////////  MAIN
int main()
{
    char salir = 'N';
    int idAlquiler = 0;
    int idCliente = 0;
    int flag = 0;

    eCategoria categorias[TAMCAT]= {
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "Salon"},
        {5, "Magia"}
    };

    eJuego juegos[TAMJUEGO]=  {
        {1, "MONOPOLI", 200, 1},
        {2, "POKER", 250, 2},
        {3, "TEG", 300, 3},
        {4, "BOCHAS", 150, 4},
        {5, "LOL", 500, 5}
    };

    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    inicializarClientes(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMALQ);

    idCliente = idCliente + hardcodearClientes(clientes, TAMCLI, 10);
    idAlquiler = idAlquiler + hardcodearAlquileres(alquileres, TAMALQ, 10);

     do{
        switch(menu()){
        case 'A':
            if(altaCliente(clientes, TAMCLI, idCliente)){
                idCliente++;
                flag++;
            }
            break;
        case 'B':
                // MODIFICAR
                modificarCliente(clientes, TAMCLI);
            break;
        case 'C':
                 // BAJA CLIENTE
                 bajaCliente(clientes, TAMCLI);
            break;
        case 'D':
                // LISTAR CLIENTES
                mostrarClientes(clientes, TAMCLI);
            break;
        case 'E':
                // LISTAR JUEGOS
                mostrarJuegos(juegos, TAMJUEGO, categorias, TAMCAT);
            break;
        case 'F':
                mostrarCategorias(categorias, TAMCAT);
            break;
        case 'G':
                altaAlquileres(alquileres, TAMALQ, idAlquiler, juegos, TAMJUEGO, categorias, TAMCAT, clientes, TAMCLI);
            break;
        case 'H':
                mostrarAlquileres(alquileres, TAMALQ, clientes, TAMCLI, juegos, TAMJUEGO);
            break;
        case 'I':
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

///////////////////////////// DESARROLLO


char menu(){
    char option;

    system("cls");
    printf("************* PARCIAL *************\n");
    printf("*************   ABM   *************\n");
    printf("A- Alta Cliente\n");
    printf("B- Modificacion Cliente\n");
    printf("C- Baja Cliente\n");
    printf("D- Listar Clientes\n");
    printf("E- Listar Juegos\n");
    printf("F- Listar Categoria\n");
    printf("G- Alta Alquiler\n");
    printf("H- Listar Alquileres\n");
    printf("I-  Salir\n\n");

    getCh(&option,"Ingrese Opcion: ", "Error. Ingrese Opcion: ");

    return option;
}

int subMenu(){
    int option;

        printf("1- NOMBRE\n");
        printf("2- APELLIDO\n");
        printf("3- TELEFONO\n");
        printf("4- CANCELAR\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 4);

    return option;
}

int altaCliente(eCliente clientes[], int tamCli, int idCliente){
    int todoOk = 0;
    int indice;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];

        system("cls");
        printf("******* ALTA *******\n\n");

        indice = isEmptyCliente(clientes, tamCli);

        if(indice == -1){
            printf("\nNO HAY LUGAR!! \n\n");
        }
        else{
            getString(nombre, "Ingrese Nombre: ", "Error. Reingrese nombre hasta 50 caracteres: ", 3, 50);

            getString(apellido, "Ingrese Apellido: ", "Error. Reingrese Apellido hasta 50 caracteres: ", 3, 50);

            getCharSex(&sexo, "Ingrese Sexo: ", "Error. Ingrese Sexo.  S o N: ", 'F', 'M');

            getString(telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);
            //getIntRange(&telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);

            getString(domicilio, "Ingrese Direccion: ", "Error. Reingrese Direccion: ", 10, 51);

            clientes[indice] = newCliente(idCliente, nombre, apellido, sexo, telefono, domicilio);
            todoOk = 1;
        }
        if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }

    return todoOk;
}

eCliente newCliente(int idCliente, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]){
    eCliente aux;

    aux.idCliente = idCliente + 1;
    strcpy(aux.nombre, nombre);
    strcpy(aux.apellido, apellido);
    aux.sexo = sexo;
    strcpy(aux.telefono, telefono);
    strcpy(aux.domicilio, domicilio);

    aux.isEmpty = 0;

    return aux;
}


int isEmptyCliente(eCliente clientes[], int tamCli){
    int index = -1;
    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int isEmptyAlquiler(eAlquiler alquiler[], int tamAlq){
    int index = -1;
    for(int i=0; i<tamAlq; i++){
        if(alquiler[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int isEmptyJuego(eJuego juegos[], int tamJuego){
    int index = -1;
    for(int i=0; i<tamJuego; i++){
        if(juegos[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}


int inicializarClientes(eCliente clientes[], int tamCli){
    int rta = 0;
    for(int i=0; i<tamCli; i++){
        clientes[i].isEmpty = 1;
        if(i == tamCli -1){
            rta=1;
        }
    }
    return rta;
}

int inicializarAlquileres(eAlquiler alquileres[], int tamAlq){
    int rta = 0;
    for(int i=0; i<tamAlq; i++){
        alquileres[i].isEmpty = 1;
        if(i == tamAlq -1){
            rta=1;
        }
    }
    return rta;
}

void mostrarCliente(eCliente cliente){
    printf(" %d    %10s     %10s     %5c     %10s      %10s\n", cliente.idCliente, cliente.nombre, cliente.apellido, cliente.sexo, cliente.telefono, cliente.domicilio);
}

void mostrarClientes(eCliente clientes[], int tamCli){
    int cont = 0;

    printf(" ID         NOMBRE       APELLIDO        SEXO     TELEFONO        DOMICILIO  \n");

    ordenarClientes(clientes, tamCli);

    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 0){
            mostrarCliente(clientes[i]);
            cont++;
        }
    }
    if(!cont){
        printf("NO HAY CLIENTES QUE MOSTRAR\n\n");
    }
}


void ordenarClientes(eCliente cli[], int tamCli){
    eCliente aux;

        for(int i=0; i<tamCli-1; i++){
            for(int j=i+1; j<tamCli; j++){
                if(stricmp(cli[i].apellido, cli[j].apellido) > 0){
                    aux = cli[i];
                    cli[i] = cli[j];
                    cli[j] = aux;
                }
                else if( stricmp(cli[i].apellido, cli[j].apellido) == 0 && stricmp(cli[i].nombre, cli[j].nombre) > 0 ){
                    aux = cli[i];
                    cli[i] = cli[j];
                    cli[j] = aux;
                }
            }
        }
}

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat){
    char desc[51];
    cargarDescCategoria(juego.idCategoria, categorias, tamCat, desc);
    printf(" %2d     %10s      %2.2f     %10s  \n", juego.idJuego, juego.descripcion, juego.importe, desc);
}

void mostrarJuegos(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat){
    int cont = 0;
    printf("  ID     DESCRIPCION    IMPORTE     CATEGORIA \n");
    for(int i=0; i<tamJuego; i++){
            if(juegos[i].isEmpty == 0){
                mostrarJuego(juegos[i], categorias, tamCat);
                cont++;
            }
    }
    if(!cont){
        printf("NO HAY MARCAS QUE MOSTRAR\n\n");
    }
}



int cargarDescCategoria(int idCategoria, eCategoria categorias[], int tamCat, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamCat; i++){
        if( idCategoria == categorias[i].idCategoria){
            strcpy(desc, categorias[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int cargarDescJuego(int idJuego, eJuego juegos[], int tamJuego, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamJuego; i++){
        if( idJuego == juegos[i].idJuego){
            strcpy(desc, juegos[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int cargarDescCliente(int idCliente, eCliente clientes[], int tamCli, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamCli; i++){
        if( idCliente == clientes[i].idCliente){
            strcpy(desc, clientes[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


void mostrarCategoria(eCategoria categoria){

    printf(" %d     %s  \n", categoria.idCategoria, categoria.descripcion);
}

void mostrarCategorias(eCategoria categorias[], int tamCat){
    int cont = 0;
    printf("  ID     DESCRIPCION\n");
    for(int i=0; i<tamCat; i++){
        mostrarCategoria(categorias[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY CATEGORIAS QUE MOSTRAR\n\n");
    }
}



int hardcodearClientes( eCliente clientes[], int tamCli, int cantidad){
    int cont = 0;

    eCliente aux[]=
    {
       {1,   "PABLO", "LESCANO", 'M', "1160313333", "Av San Juan 284"},
       {2,   "LUCAS", "LUGUERZIO", 'M', "1150315433", "San Lorenzo 351"},
       {3,   "ROMINA", "CHACON", 'F', "1167413333", "Av San Jose 3617"},
       {4,   "EZEQUIEL", "PEREZ", 'M', "1140313953", "Corrientes 450"},
       {5,   "ANA", "LOPEZ", 'F', "1174314125", "9 de Julio 5000"},
       {6,   "RAQUEL", "GONZALES", 'F', "1161314569", "Santa Fe 3500"},
       {7,   "MIGUEL", "GOMEZ", 'M', "1165213458", "Av Medrano 2105"},
       {8,   "CRISTINA", "MONTANIA", 'F', "1152313336", "Av San Juan 865"},
       {9,   "PEDRO", "MONTANIA", 'M', "1160357896", "Libertad 65"},
       {10,   "SABRINA", "ESCOBAR", 'F', "1121513612", "Av Brazil 444"},

    };

    if( cantidad <= 10 && tamCli >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            clientes[i] = aux[i];
            cont++;
        }
    }

    return cont;
}


int hardcodearAlquileres( eAlquiler alquileres[], int tamAlq, int cantidad){
    int cont = 0;

    eAlquiler aux[]=
    {
       {1,   1, 1,{12,10,2019},0},
       {2,   2, 2,{21,10,2019},0},
       {3,   3, 3,{6,10,2019},0},
       {4,   4, 4,{4,10,2019},0},
       {5,   5, 5,{3,10,2019},0},
       {6,   1, 6,{21,10,2019},0},
       {7,   2, 7,{16,10,2019},0},
       {8,   3, 8,{19,10,2019},0},
       {9,   4, 9,{24,10,2019},0},
       {10,  5,10,{25,10,2019},0}
    };

    if( cantidad <= 10 && tamAlq >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            alquileres[i] = aux[i];
            cont++;
        }
    }

    return cont;
}


int bajaCliente(eCliente clientes[], int tamCli){
    int rta = 0;
    int idCliente;
    int esta;
    char confirma;

    getInt(&idCliente, "Ingrese ID del Cliente: ", "Error. Ingrese ID del cliente: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    if(esta != -1){

        mostrarCliente(clientes[esta]);

        getChar(&confirma, "Confirma baja?  S o N: ", "Error. Reingrese S o N: ", 'S', 'N');

        if(confirma == 'S')
        {
            clientes[esta].isEmpty = 1;
            printf("BAJA EXITOSA!! \n\n");
            rta = 1;
        }
        else
        {
            printf("\nLA ELIMINACION HA SIDO CANCELADA\n");
        }

    }
    else{
        printf("NO EXISTE ESE CLIENTE!! \n\n");
        system("pause");
    }
    return rta;
}



int buscarIdCliente(eCliente clientes[], int tamCli, int idCliente){

    int indice = -1;

    for(int i=0; i<tamCli; i++){
        if(clientes[i].idCliente == idCliente){
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarIdJuego(eJuego juegos[], int tamJuego, int idJuego){

    int indice = -1;

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].idJuego == idJuego){
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarCliente(eCliente clientes[], int tamCli){
    int todoOk = 0;
    int esta;
    int idCliente;
    int flag = 0;

    system("cls");
    printf("************* MODIFICACION *************\n");

    getInt(&idCliente, "Ingrese ID del Cliente: ", "Error. Ingrese ID cliente: ");


    esta = buscarIdCliente(clientes, tamCli, idCliente);

    if(esta != -1){

        mostrarCliente(clientes[esta]);

        switch(subMenu()){
        case 1:
            getString(clientes[esta].nombre, "Ingrese Nuevo de Nombre: ", "Error. Reingrese Nuevo nombre: ", 3, 51);
            todoOk = 1;
            flag = 1;
            break;
        case 2:
            getString(clientes[esta].apellido, "Ingrese Nuevo de Apellido: ", "Error. Reingrese Nuevo Apellido: ", 3, 51);
            todoOk = 1;
            flag = 2;
            break;
        case 3:
            // TELEGONO
            getString(clientes[esta].telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);
            //getIntRange(&clientes[esta].telefono,"Ingrese Nuevo de Telefono: ", "Error. Reingrese Nuevo Telefono: ", 10, 21);
            todoOk = 1;
            flag = 3;
            break;
        case 4:
            printf("\nSE CANCELO MODIFICAION\n\n");
            break;
        default:
            printf("\nOPCION INVALIDA !! \n\n");
            break;
        }
    }
    else{
        printf("NO EXISTE CLIENTE CON ESE ID\n\n");
    }

    if(flag == 1){
            printf("\nSE MODIFICO NOMBRRE CON EXITO !! \n\n");

        }else if(flag == 2){
            printf("\nSE MODIFICO APELLIDO CON EXITO !!\n\n");
        }
        else if(flag == 3){
            printf("\nSE MODIFICO TELEFONO CON EXITO !!\n\n");
        }
    return todoOk;
}


int altaAlquileres(eAlquiler alquileres[], int tamAlq, int idAlquiler, eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat, eCliente clientes[], int tamCli){
    int todoOk = 0;
    int indice;
    int indiceJuego;
    int indiceCli;
    int idJuego;
    int idCliente;
    eFecha fecha;

        system("cls");
        printf("******* ALTA ALQUILER *******\n\n");

        indice = isEmptyAlquiler(alquileres, tamAlq);

        if(indice == -1){
            printf("\nNO HAY LUGAR!! \n\n");
        }
        else{
            mostrarJuegos(juegos, tamJuego, categorias, tamCat);

            getInt(&idJuego, "Ingrese ID: ", "Error. Reingrese ID: ");
            indiceJuego = buscarIdJuego(juegos, tamJuego, idJuego);
            while(indiceJuego == -1){
                printf("No existe ese juego!!");
                getInt(&idJuego, "Ingrese ID: ", "Error. Reingrese ID: ");
                indiceJuego = buscarIdJuego(juegos, tamJuego, idJuego);
            }
                mostrarClientes(clientes, tamCli);
                printf("\n");
                getInt(&idCliente, "Ingrese ID cliente: ", "Error. Reingrese ID Cliente: ");
                indiceCli = buscarIdCliente(clientes, tamCli, idCliente);

                while(indiceCli == -1){
                    printf("No existe ese Cliente!!");
                    getInt(&idCliente, "Ingrese ID cliente: ", "Error. Reingrese ID Cliente: ");
                    indiceCli = buscarIdCliente(clientes, tamCli, idCliente);
                }

                printf("Ingrese Fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                alquileres[indice] = newAlquiler(idAlquiler, idJuego, idCliente, fecha);
                todoOk = 1;


        }
        if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }

    return todoOk;
}

eAlquiler newAlquiler(int idAlquiler, int idJuego, int idCliente, eFecha fecha){
    eAlquiler aux;

    aux.idAlquiler = idAlquiler + 1;

    aux.idJuego = idJuego;
    aux.idCliente = idCliente;
    aux.fecha.dia = fecha.dia;
    aux.fecha.mes = fecha.mes;
    aux.fecha.anio = fecha.anio;
    aux.isEmpty = 0;

    return aux;
}

void mostrarAlquiler(eAlquiler alquiler, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli){
    char descJuego[51];
    char descCli[51];
    cargarDescJuego(alquiler.idJuego, juegos, tamJuego, descJuego);
    cargarDescCliente(alquiler.idCliente, clientes, tamCli, descCli);
    printf(" %2d     %10s      %10s     %0d/%d/%d  \n", alquiler.idAlquiler, descJuego, descCli, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
}

void mostrarAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego){
    int cont = 0;
    printf("  ID        JUEGO           CLIENTE       FECHA \n");
    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].isEmpty == 0){
            mostrarAlquiler(alquileres[i], juegos, tamJuego, clientes, tamCli);
        cont++;
        }

    }
    if(!cont){
        printf("NO HAY ALQUILERES QUE MOSTRAR\n\n");
    }
}

