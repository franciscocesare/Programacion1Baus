#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define TAM 5

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int ocupado;
}eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos(eAlumno vec[], int tam);
void sortAlumnosLeg(eAlumno vec[], int tam, int criterio);
void sortAlumnosNombre( eAlumno vec[], int tam, int criterio);
void sortAlumnosFecha(eAlumno vec[], int tam, int criterio);
int compararFecha(eFecha f1, eFecha f2);
void altaAlumno(eAlumno vec[], int tam);
void bajaAlumno(eAlumno vec[], int tam);
int buscarLugar(eAlumno vec[], int tam);
int buscarAlumno(eAlumno vec[], int tam, int legajo);
void modificarAlumno(eAlumno vec[], int tam);


int main()
{
    eAlumno listaAlumnos[TAM] = {
        {1354, "anuel", 25, 'M', 8, 10, 9, {12,4,2019}, 1 },
        {1267, "Lucia", 27, 'F', 8, 8, 8, {15,7,2019}, 1 },
        {1464, "Florencia", 22, 'F', 8, 9, 8.5, {3,4,2019}, 1 },
        {1154, "Eduardo", 23, 'M', 8, 9, 8.5, {5,7,2018}, 1 },
        {1154, "Carlos", 19, 'M', 10, 9, 9.5, {13,7,2018}, 0 }
    };

/*
    for(int i=0; i<TAM; i++){
        printf("Ingrese Legajo: ");
        scanf("%d", &listaAlumnos[i].legajo);

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(listaAlumnos[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d", &listaAlumnos[i].edad);

        printf("Ingrese Sexo: ");
        fflush(stdin);
        getche(listaAlumnos[i].sexo);
        //scanf("%c", &lista[i].sexo);

        printf("Ingrese Nota 1: ");
        scanf("%d", &listaAlumnos[i].nota1);

        printf("Ingrese Nota 2: ");
        scanf("%d", &listaAlumnos[i].nota2);

        printf("Ingrese Fecha de Ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &listaAlumnos[i].fechaIngreso.dia, &listaAlumnos[i].fechaIngreso.mes, &listaAlumnos[i].fechaIngreso.anio );


        listaAlumnos[i].promedio = (float) (listaAlumnos[i].nota1 + listaAlumnos[i].nota2) / TAM;
        system("cls");
    }*/


    mostrarAlumnos(listaAlumnos, TAM);

    altaAlumno(listaAlumnos, TAM);

    sortAlumnosLeg(listaAlumnos, TAM, 1);// 1 ASCENDENTE o 0 DESCENDENTE
    mostrarAlumnos(listaAlumnos, TAM);

    sortAlumnosNombre(listaAlumnos, TAM, 0);// 1 ASCENDENTE o 0 DESCENDENTE
    mostrarAlumnos(listaAlumnos, TAM);

    sortAlumnosFecha(listaAlumnos, TAM, 0);
    mostrarAlumnos(listaAlumnos, TAM);

    bajaAlumno(listaAlumnos, TAM);
    mostrarAlumnos(listaAlumnos, TAM);

    modificarAlumno(listaAlumnos, TAM);
    mostrarAlumnos(listaAlumnos, TAM);

    return 0;
}


void mostrarAlumnos(eAlumno vec[], int tam){
    printf("\n LEGAJO     NOMBRE      EDAD   SEXO   NOTA 1    NOTA 2     PROMEDIO    FECHA INGRESO      ESTADO\n");
    printf("*******************************************************************************************\n");

    for(int i=0; i<tam; i++){
        mostrarAlumno(vec[i]);
    }
    printf("\n\n");
}

void mostrarAlumno( eAlumno al){
    printf("%6d  %10s      %2d    %3c       %d    %6d    %8.2f       %02d/%02d/%d       %d\n", al.legajo, al.nombre, al.edad, al.sexo, al.nota1, al.nota2, al.promedio, al.fechaIngreso.dia, al.fechaIngreso.mes, al.fechaIngreso.anio, al.ocupado );
}

void altaAlumno(eAlumno vec[], int tam){
    int indice;
    int legajo;
    int esta;

        indice = buscarLugar(vec, tam);
        if(indice == -1){
            printf("No hay vacante, busca otra institucion.");
        }
        else{
            printf("Ingrese Legajo: ");
            scanf("%d", &legajo);
            esta = buscarAlumno(vec, tam, legajo);

            if(esta == -1){
                vec[indice].legajo = legajo;

                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(vec[indice].nombre);

                printf("Ingrese edad: ");
                scanf("%d", &vec[indice].edad);

                printf("Ingrese Sexo: ");
                fflush(stdin);
                //getche(vec[indice].sexo);
                vec[indice].sexo = tolower(getche());
                //scanf("%c", &vec[indice].sexo);

                printf("Ingrese Nota 1: ");
                scanf("%d", &vec[indice].nota1);

                printf("Ingrese Nota 2: ");
                scanf("%d", &vec[indice].nota2);

                printf("Ingrese Fecha de Ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio );

                vec[indice].ocupado = 1;

                vec[indice].promedio = (float) (vec[indice].nota1 + vec[indice].nota2) / TAM;
                }
                else{
                    printf("El alumno ya esta ingresado en el sistema.");
                }
        }
}

void bajaAlumno(eAlumno vec[], int tam){
    int legajo;
    int esta;

        printf("Ingrese Legajo: ");
        scanf("%d", &legajo);
        esta = buscarAlumno(vec, tam, legajo);
        if(esta != -1){
           vec[esta].ocupado = 0;
           printf("BAJA EXITOSA");
        }
        else{
            printf("No existe alumno con ese legajo.");
        }

}

int buscarLugar(eAlumno vec[], int tam){
    int indice = -1;
        for(int i=0; i<tam; i++){
            if(vec[i].ocupado == 0){
                indice = i;
                break;
            }
        }
    return indice;
}

int buscarAlumno(eAlumno vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void sortAlumnosLeg(eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if(vec[i].legajo > vec[j].legajo && criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if(vec[i].legajo < vec[j].legajo && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}

void sortAlumnosNombre( eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if(stricmp(vec[i].nombre, vec[j].nombre) > 0 && criterio ){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if(stricmp(vec[i].nombre, vec[j].nombre) < 0 && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}

void sortAlumnosFecha(eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if( compararFecha(vec[i].fechaIngreso, vec[j].fechaIngreso) > 0 && criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if( compararFecha(vec[i].fechaIngreso, vec[j].fechaIngreso) < 0 && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}


/* Función comparaFecha, devuelve:
   -1 si fecha1 < fecha2
   0 si fecha1 = fecha2
   1 si fecha1 > fecha2
*/
int compararFecha(eFecha f1, eFecha f2){
    int rta;

        if(f1.anio < f2.anio){
            rta = -1;
        }
        else if(f1.anio > f2.anio){
            rta = 1;
        }
         else {
            if(f1.mes < f2.mes){
                rta = -1;
            }
            else if( f1.mes > f2.mes ){
                 rta = 1;
            }
            else{
                if(f1.dia < f2.dia){
                     rta = -1;
                }
                else if ( f1.dia > f2.dia ){
                    rta = 1;
                }
                else{
                    rta = 0;
                }
            }
    }

    return rta;
}

void modificarAlumno(eAlumno vec[], int tam){
    int legajo;
    int notaUnoNueva;
    char confirma;
    int esta;

        printf("Ingrese Legajo: ");
        scanf("%d", &legajo);
        esta = buscarAlumno(vec, tam, legajo);
        if(esta == -1){
           printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
        }
        else{
            mostrarAlumno(vec[esta]);

            printf("Modificar nota uno? ");
            confirma = tolower(getche());

            if( confirma == 's' ){
                printf("\nIngrese nueva nota uno: ");
                scanf("%d", &notaUnoNueva);
                vec[esta].nota1 = notaUnoNueva;

            }
            else{
                printf("No se pudo cargar la opcion.\n");
            }
        }
}

