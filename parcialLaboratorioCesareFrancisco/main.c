#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAMClientes 10
#define TAMAlquiler 5
#define TAMJuegos 6
#define TAMCategoria 5


///PRIMERO DEFINO LAS ESTRUCTURAS
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int idJuego;
    char descripcion[20];
    ///char sexo;
    int importe;
    int idCategoria;
    ///int isEmpty;
} eJuego;

typedef struct
{
    int idCategoria;
    char descripcion[51];
} eCategoria;

typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51]; ///validar
    char sexo;
    char telefono[21];
    char direccion[51];
    int isEmpty;

} eCliente;

typedef struct
{
    int idAlquiler; ///autoincremental
    int idJuego; ///validar
    int idCliente; ///validar
    int isEmptyAlquiler;
    eFecha fechaAlquiler;

} eAlquileres;


int menuPrincipal();
int menuAlquileres();

///funciones validaciones

void getIntRange(int* dondeAsignar, int min, int max, char* mensaje);

///prototipos clientes
int menuClientes();
int hardcodearClientes( eCliente[], int tam, int cantidad);
void inicializarClientes(eCliente vec[], int tam);
int findFree(eCliente vec[], int tam);
int altaCliente(eCliente vec[], int tam, int idCliente);
eCliente newCliente(int idCliente,char name[],char lastName[],char sexo,char direccion[],char telefono[]);
int buscarCliente(int id, eCliente vec[], int tam);
void mostrarClientes(eCliente vec[], int tam);
void mostrarCliente(eCliente x);
int borrarCliente(eCliente vec[], int tam);
int modificarCliente(eCliente vec[], int tam);
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[]);

///prototipos Alquileres

void inicializarAlquileres(eAlquileres vec[], int tam);
int hardCodearAlquileres(eAlquileres vec[], int tam, int cantidad);
int findFreeAlquiler(eAlquileres vec[], int tam);
int altaAlquiler(eAlquileres vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id);
void mostrarAlquiler(eAlquileres vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
void mostrarAlquileres(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC);


///prototipos categorias

///int cargarDescCategoria(int idCategoria,eCategoria categorias[], int tamCat, char desc[]);
void mostrarCategorias(eCategoria categorias[], int tamCat);
void mostrarCategoria(eCategoria categorias);
void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[]);
void hardcodearCategoria(eCategoria vec[], int tam);

///prototipos juegos

void harcodearJuego(eJuego vec[], int tam);
void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[]);
void mostrarJuego(eJuego juegos, eCategoria categorias[], int tam);
void mostrarJuegos(eJuego juegos[],int tamJ, eCategoria categorias[], int tamC);





int main()
{
    ///int idCategoria = 0;
    int idCliente = 0;
    int idAlquiler=0;
    char salir = 'n';

    eCliente lista [TAMClientes];
    eAlquileres alquiler [TAMAlquiler];
    eJuego juegos [TAMJuegos];
    eCategoria categorias [TAMCategoria];

    inicializarClientes(lista, TAMClientes);
    inicializarAlquileres(alquiler, TAMAlquiler);

    idAlquiler+=hardCodearAlquileres(alquiler, TAMAlquiler, 5);
    idCliente += hardcodearClientes(lista, TAMClientes, 10);

    harcodearJuego(juegos, TAMJuegos);
    hardcodearCategoria(categorias, TAMCategoria);


    do
    {
        switch (menuPrincipal())
        {
        case 1:

            switch( menuClientes())
            {
            case 1:
                if (altaCliente(lista, TAMClientes, idCliente))
                {
                    idCliente ++;
                }
                mostrarClientes(lista, TAMClientes);
                system("pause");
                break;

            case 2:

                borrarCliente(lista, TAMClientes);
                system("pause");
                break;

            case 3:

                modificarCliente(lista, TAMClientes);
                system("pause");
                break;

            case 4:
                mostrarClientes(lista, TAMClientes);
                system("pause");
                break;
            case 5:
                printf("Volver al menu anterior\n");
                system("pause");
                break;

            default:
                printf("\nOpcion Invalida!\n\n");
                system("pause");

            }
            break;

        case 2:
            switch(menuAlquileres())
            {
            case 1:

                /*if (altaAlquiler(alquiler, TAMAlquiler, juegos, TAMJuegos, lista, TAMClientes, categorias, TAMCategoria, idAlquiler))
                {
                   idAlquiler++;
                }*/
                ///mostrarCategorias(categorias, TAMCategoria);
                mostrarJuegos(juegos, TAMJuegos,categorias, TAMClientes);

                system("pause");

                break;

            case 2:

                mostrarAlquileres(alquiler, TAMAlquiler, juegos, TAMJuegos, lista, TAMClientes);
                system("pause");
                break;
            case 3:
                printf("Volver al menu anterior\n");
                system("pause")
;                break;

            /*default:
                printf("\nOpcion Invalida!\n\n");
                system("pause");
*/
            }
            break;

        case 3:
            printf("hacer informes\n");
            ///informes
            system("pause");
            break;

        case 4:
            printf("Confirma salir?\n\n");
            fflush(stdin);
            salir = getche();

            system("pause");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
            system("pause");

        }

    }
    while(tolower(salir == 'n'));

    return 0;

}


///funciones que luego me tengo que llevar CLIENTES

int menuAlquileres()
{
    int opcion;

    system("cls");
    printf("*****Menu de Alquileres*****\n");
    printf("1-ALTA DE UN ALQUILER\n");
    printf("2-MOSTRAR ALQUILERES\n");
    printf("3-VOLVER AL MENU ANTERIOR\n");
    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int menuPrincipal()
{
    int opcion;

    system("cls");
    printf("****** Alquileres de Juegos BAUS *******\n\n");
    printf("1-CLIENTES\n");
    printf("2-ALQUILERES\n");
    printf("3-INFORMES\n");
    printf("4-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}
///funciones clientes


int menuClientes()
{
    int opcion;

    system("cls");
    printf("****** ABM Clientes *******\n\n");
    printf("1-Alta Cliente\n");
    printf("2-Baja Cliente\n");
    printf("3-Modificar Cliente \n");
    printf("4-Listar Clientes\n");
    printf("5-Volver al menu anterior\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int hardcodearClientes( eCliente vec[], int tam, int cantidad)
{
    int cont = 0;

    eCliente aux[]=
    {
        {1,   "JUAN", "GARAY", 'M', "1160313333", "Av San Juan 284"},
        {2,   "ROBERTO", "LARALALA", 'M', "1150315433", "San Lorenzo 351"},
        {3,   "ROMINA", "LESCANO", 'F', "1167413333", "Av San Jose 3617"},
        {4,   "PABLO", "PEREZ", 'M', "1140313953", "Corrientes 450"},
        {5,   "JIMENA", "GUTIERREZ", 'F', "1174314125", "9 de Julio 5000"},
        {6,   "NORMA", "ARIAS", 'F', "1161314569", "Santa Fe 3500"},
        {7,   "LUIS", "ARRIETA", 'M', "1165213458", "Av Medrano 2105"},
        {8,   "SILVIA", "LUGUERCIO", 'F', "1152313336", "Av San Juan 865"},
        {9,   "ANIBAL", "MONTE", 'M', "1160357896", "Libertad 65"},
        {10,   "DANIELA", "ERGO", 'F', "1121513612", "Av BraSil 444"},

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}


int buscarCliente(int idCliente, eCliente vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].idCliente == idCliente && vec[i].isEmpty == 0)
        {
            index = i;
            break;
        }

    }
    return index;
}


int findFree(eCliente vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

void inicializarClientes(eCliente vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int altaCliente(eCliente vec[], int tam, int idCliente)
{

    int todoOk = 0;
    int index;
    char name[51];
    char auxName[51];
    char lastName[51];
    char auxLastName[51];
    char sexo;
    char telefono [20];
    char auxTelefono[51];
    char auxDireccion[51];
    char direccion[51];

    system("cls");

    printf("*****Alta Cliente*****\n\n");

    index = findFree(vec, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {
        vec[index].idCliente = idCliente;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxName);
        while (strlen (auxName) >51)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error Nombre muy largo, ingrese el nombre: ");
            fflush(stdin);
            gets(auxName);
        }
        strcpy (name, auxName); ///si el dato es valido, lo copio en nombre!



        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxLastName);
        while (strlen (auxLastName) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error apellido muy largo, ingrese el Apellido: ");
            fflush(stdin);
            gets(auxLastName);
        }
        strcpy (lastName, auxLastName);

        printf("Ingrese sexo: ");
        scanf("%c", &sexo);

        printf("Ingrese direccion: ");
        fflush(stdin);
        gets(auxDireccion);
        while (strlen (auxDireccion) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error, ingrese el domicilio: ");
            fflush(stdin);
            gets(auxDireccion);
        }
        strcpy (direccion, auxDireccion);

        printf("Ingrese Telefono  ej. Bs As; 115-123-4567: ");
        fflush(stdin);
        gets(auxTelefono);
        while (strlen (auxTelefono) >20)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error, ingrese el telefono ej. Bs As; 115-123-4567: ");
            fflush(stdin);
            gets(auxTelefono);
        }
        strcpy (telefono, auxTelefono);

        vec[index] = newCliente(idCliente, name, lastName, sexo, direccion, telefono);
        todoOk = 1;
        printf("\nSe ha realizado el alta del cliente\n\n");

    }
    return todoOk;
}

eCliente newCliente(

    int idCliente,
    char name[],
    char lastName[],
    char sexo,
    char direccion[],
    char telefono[])
{

    eCliente cliente;
    cliente.idCliente = idCliente +1;
    strcpy( cliente.nombre, name);
    strcpy( cliente.apellido, lastName);
    strcpy( cliente.direccion, direccion);
    strcpy( cliente.telefono, telefono);
    cliente.sexo = sexo;
    cliente.isEmpty = 0;

    return cliente;
}

int borrarCliente(eCliente vec[], int tam)
{
    int todoOk = 0;
    int id;
    int index;
    char confirma;
    system("cls");
    printf("***** Baja Cliente *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    index = buscarCliente(id, vec, tam);/// hacer finCliente!!!!!!

    if( index == -1)
    {
        printf("No existe un cliente con ese ID\n\n");

    }
    else
    {

        mostrarCliente(vec[index]); ///hacer mostrar cliente

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[index].isEmpty = 1;
            todoOk = 1;
            printf("Baja de cliente exitosa!\n");
        }
        else
        {
            printf("\nNo se realizo la baja correspondiente ");
        }
    }

    return todoOk;
}
int modificarCliente(eCliente vec[], int tam)
{

    int todoOk = 0;
    int id;
    int index;
    system("cls");
    printf("\n***** Modificar Cliente *****\n\n");
    printf("Ingrese id del cliente: ");
    scanf("%d", &id);
    int opcion;

    index = buscarCliente(id, vec, tam);///hacer findCliente

    if( index == -1)
    {
        printf("No existe un cliente con ese id\n\n");

    }
    else
    {
        printf(" ID     APELLIDO     NOMBRE  SEXO    DIRECCION    TELEFONO\n\n");
        mostrarCliente(vec[index]);

        printf("\n\n***QUE DESEA MODIFICAR DEL CLIENTE***\n\n");
        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar domicilio\n");
        printf("4- Modificar telefono\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre nuevo: ");
            fflush(stdin);
            scanf("%s", vec[index].nombre);
            break;

        case 2:
            printf("Ingrese nuevo apellido : ");
            fflush(stdin);
            scanf("%s", vec[index].apellido);
            break;

        case 3:
            printf("Ingrese nueva direccion: ");
            scanf("%s", vec[index].direccion);
            break;

        case 4:
            printf("Ingrese nuevo telefono: ");
            scanf("%s", vec[index].telefono);


            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idCliente == id)
        {
            strcpy(dondeAsigar,vec[i].apellido);
            strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);
        }
    }
}


void mostrarCliente(eCliente x)
{
    printf(" %d  %10s   %10s    %c    %8s    %s \n",
           x.idCliente,
           x.apellido,
           x.nombre,
           x.sexo,
           x.direccion,
           x.telefono);
}

/** \brief print the content of employees array
*
* \param vec Employee[]
* \param tam int
* \return array printed
*
*/

void mostrarClientes(eCliente vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID   APELLIDO    NOMBRE    SEXO    DIRECCION   TELEFONO  \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarCliente(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay clientes que mostrar\n");
    }

    printf("\n\n");
}

///funciones que luego me tengo que llevar ALQUILERES

void inicializarAlquileres(eAlquileres vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmptyAlquiler = 1;
    }
}

int hardCodearAlquileres(eAlquileres vec [], int tam, int cantidad)
{

        int cont = 0;

    eAlquileres aux[]=
    {
        {1,100,5,1,{15,12,2019}},
        {3,102,7,1,{5,1,2019},},
        {2,104,8,1,{12,11,2019},},
        {4,103,6,1,{6,8,2019},},
        {5,102,9,1,{22,5,2019},}

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}

int findFreeAlquiler(eAlquileres vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmptyAlquiler == 1 )
        {
            index = i;
            break;
        }
    }
    return index;

}



void mostrarAlquiler(eAlquileres vec, eJuego juegos[], int tamJ, eCliente lista[], int tamC)
{
    char nomjuego[21];
    char nomCliente[51];

    obtenerNomJuego(juegos,tamJ,vec.idJuego,nomjuego);
    obtenerNomCliente(lista,tamC,vec.idCliente,nomCliente);

    printf(" %d  %10s  %20s       %02d/%02d/%d\n",vec.idAlquiler,nomjuego,nomCliente,
           vec.fechaAlquiler.dia,vec.fechaAlquiler.mes,vec.fechaAlquiler.anio);
}

void mostrarAlquileres(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC)
{
    int cont=0;

    system("cls");
    printf("  ID         JUEGO               CLIENTE           FECHA_ALQUILER\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmptyAlquiler==1)
        {
            mostrarAlquiler(vec[i],juegos,tamJ,lista,tamC);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay alquileres en el sistema\n\n");
    }
}


int altaAlquiler(eAlquileres vec[], int tam, eJuego juegos[], int tamJ, eCliente lista[], int tamC,eCategoria categorias[], int tCat, int id)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA ALQUILER ***  \n\n");

    indice=findFreeAlquiler(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        vec[indice].idAlquiler=id;

        mostrarJuegos(juegos,tamJ,categorias,tCat);
        getIntRange(&vec[indice].idJuego,100,105,"\nIngrese codigo de juego: ");

        mostrarClientes(lista,tamC);
        getIntRange(&vec[indice].idCliente,0,9999,"\nIngrese id del cliente: ");


        getIntRange(&vec[indice].fechaAlquiler.dia,1,31,"Ingrese dia de alquiler: ");
        getIntRange(&vec[indice].fechaAlquiler.mes,1,12,"Ingrese mes de alquiler: ");
        getIntRange(&vec[indice].fechaAlquiler.anio,1990,2019,"Ingrese anio de alquiler: ");

        vec[indice].isEmptyAlquiler=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}

///FUNCIONES DE JUEGOS!!!!!
void harcodearJuego(eJuego vec[], int tam)
{
    eJuego lista[]=
    {
        {100, "TEG",200, 3},
        {101, "CARRERA DE MENTES",250, 1},
        {102, "METEGOL",500, 4},
        {103, "AJEDRES",150, 1},
        {104, "RULETA",250, 2},
        {105, "DON MAGO",300, 5},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}



void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idJuego == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}

void mostrarJuego(eJuego juegos, eCategoria categorias[], int tam)
{
   char nombre[21];

   obtenerNomCat(categorias, tam, juegos.idCategoria,nombre);

   printf("%d    %10s    %.2f    %10s\n",juegos.idJuego,juegos.descripcion,
          juegos.importe,nombre);
}


void mostrarJuegos(eJuego juegos[],int tamJ, eCategoria categorias[], int tamC){

    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE     CATEGORIA\n\n");

    for(int i=0 ;i<tamJ; i++)
    {
        mostrarJuego(juegos[i],categorias,tamC);
    }
}



///CATEGORIAS
void mostrarCategoria(eCategoria categorias){

    printf(" %d     %s  \n", categorias.idCategoria, categorias.descripcion);
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

void hardcodearCategoria(eCategoria vec[], int tam)
{

   eCategoria categorias[] =
    {
        {1, "MESA"},
        {2, "AZAR"},
        {3, "ESTRATEGIA"},
        {4, "SALON"},
        {5, "MAGIA"},

    };

    for(int i=0 ;i<tam; i++)
    {
        vec[i] = categorias[i];
    }

}

void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0 ;i<tam; i++)
    {
        if(vec[i].idCategoria == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}



///funciones validaciones

void getIntRange(int* dondeAsignar, int min, int max, char* mensaje)
{

    int auxInt;
    char aux[20];

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(aux);


    for(int i=0; i<strlen(aux); i++)
    {
        while(isdigit(aux[i])==0)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxInt=atoi(aux);

    while(auxInt < min || auxInt > max)
    {
        printf("Error. %s",mensaje);
          fflush(stdin);
        scanf("%d",&auxInt);
    }


    *dondeAsignar = auxInt;

}
