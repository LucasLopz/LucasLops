#include "TPn2Dim.h"
#include <conio.h>
#include <math.h>
#include <strings.h>
#include <malloc.h>

/// a. Crear un arreglo estático de 30 elementos de esta estructura y cargarlo mediante una función.

int CargaStaticPer(){
static struct *C = NULL;
(*C)= (*struct) malloc (sizeof(persona)* 30);
char opcion=0;
int i=0;

while( i< Dim && opcion!= 27){
printf("Ingrese El Nombre de la Persona \n");
fflush("stdin");
gets(*C[i].Nombre);
printf("Ingrese El Genero de la Persona M/F \n");
fflush("stdin");
*C[i].Genero = getch()
printf("Ingrese La Edad de la Persona \n")
scanf("%d", *C[i]);

i++;

printf("Si quiere continuar cargando Personas aprete cualquier tecla sino ESC \n");
fflush("stdin");
opcion=getch
}
return i;
}


///-------------------------------------------------------------------------------------------------------------
///b. Hacer una función que cuente la cantidad de un género determinado.

int ContPerGen (persona *A, int v, char g){
int i=0;
int cont=0;

for(i=0;i<v;i++){
    if(*A[i].genero = g){
        cont++;
    }
}
return cont;
}

///------------------------------------------------------------------------------------------------------------------------
///c. Hacer una función que copie los datos de todos los registros de un género determinado del arreglo anterior en otro
///arreglo del tamaño justo. Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y crear el arreglo
///dinámico antes de la invocación.


persona* ArrayToArrayG(persona *A,int v, int g){
int Cont= ContPerGen(*A,v,g);
int i=0;
int i2=0;
persona *C= NULL;
(*C) = (persona*) malloc(sizeof(persona)* Cont);
for(i=0;i<v;i++){
        if(*A[i].genero= g){
                *C[i2].edad = *A[i].edad
                *C[i2].nombre = *A[i].nombre
                *C[i2].genero = *A[i].genero
            i2++;
        }}
}


