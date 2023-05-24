#include <stdio.h>
#include <stdlib.h>

#define DIM_LEGAJOS 1000
#define ESC 27

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

stLegajo cargaUnAlum();
int CarArreAlum(stAlumno Alumnos[],int dim);


int main()
{

    return 0;
}


///------------------------------------------------------
///Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.

int CarArreAlum(stAlumno Alumnos[],int dim){
char opcion=0;
    int i=0;
    while(i<dim && opcion!=ESC){
        system("cls");
        Alumnos[i]=cargaUnAlumno();
        i++;
        printf("\n ESC para salir o cualquier tecla para continuar... ");
        opcion=getch();
    }
    return i;
}

stLegajo cargaUnAlum(){
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
printf("\n============================Alumno =====================================", )
printf("\n Matricula...............: %d", Alumno.matricula);
printf("\n Nombre.............: %s", Alumno.nombre);
printf("\n Genero..................: %c", Alumno.genero);
printf("\n========================================================================");
}

void MostrarArregloAlumnos(stAlumno Alumnos, int validos){
    int i=0;
    for(i=0;i<validos;i++){
        MostrarUnAlumno(Alumnos[i]);
    }
}
///-------------------------------------------------------------------------------------------------
///Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

void MostrarAlumnoMatricula(stAlumno Alumno,int validos,int  Matricula){
int i=0;
int flag=0;
while(Alumno.matricula[i] != Matricula && Flag!=1){
if(Alumno.matricula == Matricula){
    Flag=1;
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

void OrdenarSelecMatri(stAlumno Alumno,int validos){
    int posMenor=0;
    char aux[20];
    int AuxInt=0;
    for(int i=0;i<v-1;i++){
        posMenor = buscaPosMenorString(a, v, i);
        strcpy(aux, Alumno.nombre[posMenor]);
        strcpy(Alumno.nombre[posMenor], Alumno.nombre[i]);
        strcpy(Alumno.nombre[i], aux);

         strcpy(aux, Alumno.genero[posMenor]);
        strcpy(Alumno.genero[posMenor], Alumno.genero[i]);
        strcpy(Alumno.genero[i], aux);

         AuxInt= Alumno.matricula[posMenor];
        Alumno.matricula[posMenor]= Alumno.matricula[i];
       Alumno.matricula[i]= AuxInt;
    }
}
int buscaPosMenorString(char a[][20], int v, int comienzo){
    int i = comienzo;
    int posMenor = i;
    i++;
    while(i<v){
        if(strcmp(a[i],a[posMenor])<0){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

///--------------------------------------------------------------------------------
///Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado
///(se envía por parámetro). Modularizar.

void MostrAlumGene(stAlumno Alumno,int Validos, char G){
int i=0;

for(i=0;i<Validos;i++){
    if(Alumno.genero[i]== G){
        MostrarUnAlumno(Alumno[i])
    }
}
}


///----------------------------------------------------------------------------------
///Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.

int CargarDatoNuvOrd(stAlumno Alumno,int validos, int dim){

validos= validos + CarArreAlumCargado(stAlumno Alumnos[],validos,dim);
OrdenarSelecMatri(stAlumno Alumno,validos);
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

int CantAlumGene(stAlumno Alumno,int  validos,int G){
 int cont=0;

for(i=0;i<Validos;i++){
    if(Alumno.genero[i]== G){
cont++;
}
}
return cont;
}
///--------------------------------------------------------------------------------------------------
///==================================================================================================
///====================================TP de ARCHIVOS================================================
///==================================================================================================



