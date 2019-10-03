



/*
2.1 Función initEmployees

void inicializarEmpleados(Employee vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.

int initEmployees(Employee* list, int len)
{
return 0;
}
Ejemplo uso:
r = initEmployees(arrayEmployees, ELEMENTS);

2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
return -1;
}
Ejemplo uso:
r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);


2.3 Función findEmployeeById
Busca un empleado recibiendo como parámetro de búsqueda su Id.

int findEmployeeById(Employee* list, int len,int id)
{
return NULL
}
Ejemplo uso:
int index = findEmployeeById(arrayEmployees, ELEMENTS,9);

2.4 Función removeEmployee
Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.

int removeEmployee(Employee* list, int len, int id)
{
return -1;
}
Ejemplo uso:
r = removeEmployee(arrayEmployees, ELEMENTS,20);



2.5 Función sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.

int sortEmployees(Employee* list, int len, int order)
{
return 0;
}
Ejemplo uso:
r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);



2.6 Función printEmployees
Imprime el array de empleados de forma encolumnada.

int printEmployees(Employee* list, int length)
{
return 0;
}
Ejemplo uso:
r = printEmployees(arrayEmployees, ELEMENTS);
*/
