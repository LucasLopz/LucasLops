#include <stdio.h>
#include <stdlib.h>

#define DIM_LEGAJOS 1000
#define ESC 27

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno2;

stAlumno cargaUnAlumno();
int CarArreAlum(stAlumno Alumnos[],int dim);
void MostrarUnAlumno(stAlumno Alumno);
void MostrarArregloAlumnos(stAlumno Alumnos[], int validos);
void MostrarAlumnoMatricula(stAlumno Alumno[],int validos,int  Matricula);
void OrdenarSelecMatri(stAlumno Alumnos[],int validos);
int buscaPosMenorStrc(stAlumno Alumnos[], int v, int comienzo);
void MostrAlumGene(stAlumno Alumno[],int Validos, char G);
int CargarDatoNuvOrd(stAlumno Alumno[],int validos, int dim);
int CarArreAlumCargado(stAlumno Alumnos[],int validos,int dim);
int CantAlumGene(stAlumno Alumno[],int  validos,int G);

int main()
{

    return 0;
}


///------------------------------------------------------
///Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.

int CarArreAlum(stAlumno Alumno[],int dim){
char opcion=0;
    int i=0;
    while(i<dim && opcion!=ESC){
        system("cls");
        Alumno[i] = cargaUnAlumno();
        i++;
        printf("\n ESC para salir o cualquier tecla para continuar... ");
        opcion=getch();
    }
    return i;
}

stAlumno cargaUnAlumno(){
    stAlumno Alumno;

    printf("\n Ingrese el Num de Matricula.......: ");
    scanf("%c", &Alumno.genero);

    printf("\n Ingrese el nombre.................: ");
    fflush(stdin);
    gets(Alumno.nombre);

    printf("\n Ingrese el Genero.................: ");
    scanf("%c", &Alumno.genero);

    return Alumno;
}

///------------------------------------------------------------------------------------
///Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.

void MostrarUnAlumno(stAlumno Alumno){
printf("\n============================Alumno =====================================");
printf("\n Matricula...............: %d", Alumno.matricula);
printf("\n Nombre.............: %s", Alumno.nombre);
printf("\n Genero..................: %c", Alumno.genero);
printf("\n========================================================================");
}

void MostrarArregloAlumnos(stAlumno Alumnos[], int validos){
    int i=0;
    for(i=0;i<validos;i++){
        MostrarUnAlumno(Alumnos[i]);
    }
}
///-------------------------------------------------------------------------------------------------
///Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

void MostrarAlumnoMatricula(stAlumno Alumno[],int validos,int  Matricula){
int i=0;
int flag=0;
while(Alumno[i].matricula != Matricula && flag!=1){
if(Alumno[i].matricula == Matricula){
    flag=1;
}else{
i++;
}
}
if(flag==1){
    MostrarUnAlumno(Alumno[i]);
}
}
///------------------------------------------------------------------------------------------------------------
///Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
///El criterio de ordenación es el número de matrícula.

void OrdenarSelecMatri(stAlumno Alumnos[],int validos){
    int posMenor=0;
    stAlumno Auxiliar;
    for(int i=0;i<validos-1;i++){
        posMenor = buscaPosMenorStrc(Alumnos, validos, i);

         Auxiliar= Alumnos[posMenor];
        Alumnos[posMenor]= Alumnos[i];
       Alumnos[i]= Auxiliar;
    }
}
int buscaPosMenorStrc(stAlumno Alumnos[], int v, int comienzo){
    int i = comienzo;
    int posMenor = i;
    i++;
    while(i<v){
        if(Alumnos[i].matricula == Alumnos[posMenor].matricula){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

///--------------------------------------------------------------------------------
///Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado
///(se envía por parámetro). Modularizar.

void MostrAlumGene(stAlumno Alumno[],int Validos, char G){
int i=0;

for(i=0;i<Validos;i++){
    if(Alumno[i].genero== G){
        MostrarUnAlumno(Alumno[i]);
    }
}
}


///----------------------------------------------------------------------------------
///Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.

int CargarDatoNuvOrd(stAlumno Alumno[],int validos, int dim){

validos= validos + CarArreAlumCargado(Alumno,validos,dim);
OrdenarSelecMatri(Alumno,validos);
return validos;
}

int CarArreAlumCargado(stAlumno Alumnos[],int validos,int dim){
char opcion=0;
    int i=validos;
    while(i<dim && opcion!=ESC){
        system("cls");
        Alumnos[i]=cargaUnAlumno();
        i++;
        printf("\n ESC para salir o cualquier tecla para continuar... ");
        opcion=getch();
    }
    return i;
}

///--------------------------------------------------------------------------------------------------
///Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado
/// (se envía por parámetro) que tiene un arreglo de alumnos.

int CantAlumGene(stAlumno Alumno[],int  validos,int G){
 int cont=0;
 int i=0;

for(i=0;i<validos;i++){
    if(Alumno[i].genero == G){
cont++;
}
}
return cont;
}
///--------------------------------------------------------------------------------------------------
///==================================================================================================
///====================================TP de ARCHIVOS================================================
///==================================================================================================
///---------------------------------------------------------------------------------------------------


void cargaArchivoAlumnos(char nombreArchivo[]){
    char opcion=0;
    stAlumno2 Alumno;
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        while(opcion!=27){
            Alumno = cargaUnAlumno();
            fwrite(&Alumno, sizeof(stAlumno2), 1, archi);
            printf("\n ESC para salir o cualquier tecla para continuar... ");
            opcion=getch();
        }

        fclose(archi);
    }
}

void muestraArchivoDeAlumnos(char nombreArchivo[]){
    stAlumno2 Alumno;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&Alumno, sizeof(stAlumno2), 1, archi)>0){
           MostrarUnAlumno(Alumno);
        }
        fclose(archi);
    }
}
///-----------------------------------------------------------------------------------------------
int cuentaDatosArchivo(char nombreArchivo[]){
    int cont=0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        fseek(archi,0,SEEK_END);
        cont = ftell(archi)/sizeof(stAlumno2);
        fclose(archi);
    }
    return cont;
}
///------------------------------------------------------------------------------------------------
/*Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo
, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra. */

int AgregreAlumArchi(char nombreArchivo[], stAlumno2 Alumno[]){
FILE* archi=fopen(nombreArchivo, "ab");
if(archi){
    fwrite(&Alumno, sizeof(stAlumno2), 1, archi);
    fclose(archi);
}
}
///------------------------------------------------------------------------------------------------
///Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.

void PasaAPila (char nombreArchivo[], Pila* p, stAlumno2 Alumno[],int validos){
FILE* archi=fopen(nombreArchivo, "rb");
int i=0;
if(archi){
    for(i=0;i<validos;i++)
    if(Alumno[i].edad >= 18){
    apilar(p, Alumno[i].legajos);
    }
}
}

