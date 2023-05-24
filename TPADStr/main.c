#include <stdio.h>
#include <stdlib.h>

int cargaStrings(char n[][20], int dim);

int main()
{



    return 0;
}

int cargaStrings(char n[][20], int dim){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        system("cls");
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        gets(n[i]);
        i++;

        printf("ESC para salir o cualquier tecla para continuar ...");
        opcion = getch();
    }

    return i;
}

///-------------------------------------------------------------------------------------------
/*Hacer una función que teniendo en cuenta la longitud de un palabra, inicialice un segundo arreglo con el
carácter “-”. (Pista: primero hay que copiar la palabra en el segundo arreglo y luego modificarlo).*/


void InicString (char Prim[][[20], int Sec[][20]){

int i=0;
int cont=0;
cont= strlen(Prim);

for(i=0;i<cont;i++){
    sec[i] = '-';
}
}
}

///---------------------------------------------------------------------------------------
/*
Hacer una función que teniendo la posición de la letra copie esa letra en otro arreglo inicializado con la
función anterior en la misma posición que la palabra original.
*/

int CopLetr(char Prim[][20], Sec[][20], char L){

int i=0;

while(Prim[i]!=L && Prim[i]!= '/0')



}



