#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

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

#endif // CLIENTES_H_INCLUDED

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
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[]);///modificar eso en la funcion de donde asignar
void ordenarCliente(eCliente vec[], int tam);
