#include <stdio.h>
#include <stdlib.h>

#define ESC 27
int CargarSistema(int legajos[20],char nombres[20][30],int anios[20]);
int BusquedaEnSistema(int legajos[20], int validos, int Numero);
void BusquedaNombre(int legajos[20],char nombres[20][30],int anios[20],int  legajo,int validos);
void OrdenSistema (int legajos[20],char nombres[20][30],int anios[20],int validos);
int buscaPosMenorString(char a[][20], int v, int comienzo);
void MostrarSistema(int legajos[20],char nombres[20][30],int anios[20],int validos);

int main()
{

}

int CargarSistema(int legajos[20],char nombres[20][30],int anios[20]){
int i=0;
char opcion=0;

do{
    printf("Ingrese el Numero de legajo");
    scanf("%d", legajos[i]);
    printf("Ingrese el Nombre del usuario");
    fflush(stdin);
    gets(nombres[i]);
    printf("Ingrese los anios del usuario");
    scanf("%d", anios[i]);
    i++;
     printf("\n Desea continuar? ESC para salir");
        opcion=getch();
}while(opcion!= ESC);
return i;
}

int BusquedaEnSistema(int legajos[20], int validos, int Numero){
int i=0;
int flag=0;
int ubi=-1;

while(i<validos && flag!=1){
        if(Numero== legajos[i]){
            flag=1;
        }else{
        i++;
        }
}

if(flag==1){
    ubi=i;
}
return ubi;
}
///------------------------------------------------------------------------------------------
/*Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y
 lo imprima por pantalla. Se debe invocar la función 2.
*/

void BusquedaNombre(int legajos[20],char nombres[20][30],int anios[20],int  legajo,int validos){
int ubi=0;
ubi= BusquedaEnSistema(legajos[20], validos, legajo);

printf("El nombre del legajo %d es:   %s",legajo,nombres[ubi]);
}
///-----------------------------------------------------------------------------------------------------
/*Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre.
(por el método de selección o inserción).
*/

void OrdenSistema (int legajos[20],char nombres[20][30],int anios[20],int validos){
int posMenor=0;
int Aux=0;
int Aux2=0;
    char aux[20];
    for(int i=0;i<validos-1;i++){
        posMenor = buscaPosMenorString(nombres, validos, i);
        strcpy(aux, nombres[posMenor]);
        strcpy(nombres[posMenor], nombres[i]);
        strcpy(nombres[i], aux);

        Aux= legajos[posMenor];
        legajos[posMenor]= legajos[i];
        legajos[i]= Aux;

        Aux= anios[posMenor];
        anios[posMenor]= anios[i];
        anios[i]= Aux;
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


///---------------------------------------------------------------------------------------------
/*
Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez
(es decir: muestra el legajo, nombre y años del 1er alumno, luego el legajo, nombre y años del 2do alumno, y así sucesivamente)
*/
void MostrarSistema(int legajos[20],char nombres[20][30],int anios[20],int validos){
    int i=0;
for (i=0;i<validos;i++)
    system("cls");
    printf("======================================================");
    printf("Legajo Numero...........: %d", legajos[i]);
    printf("Nombre..................: %s", nombres[i]);
    printf("Edad....................: %d", anios[i]);
    printf("======================================================");
    system("pause");
}

