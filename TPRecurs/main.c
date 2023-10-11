#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <strings.h>
#include <malloc.h>

int main()
{
    return 0;
}
///----------------------------------------------------------------------------------------------------------
///1. Calcular el factorial de un número en forma recursiva.

int factorial(int x){
    int rta;
    if(x==0){
        rta = 1;
    }else{
        printf("\n Viaje de IDA - valor de x = %d",x);
        rta = x * factorial(x-1);
        printf("\n Viaje de VUELTA - valor de x = %d",x);
    }
    return rta;
}

int factorial1(int x){
    int rta = 1;
    if(x > 0){
        rta = x * factorial1(x-1);
    }
    return rta;
}

int factorial2(int x){
    return (x > 0) ? x * factorial2(x-1) : 1;
}
///----------------------------------------------------------------------------------------------------------------------------------
///2. Calcular la potencia de un número en forma recursiva.


int potencia(int base, int exponente){
    int rta;
    if(exponente == 0){
        rta = 1;
    }else{
        rta = base * potencia(base, exponente - 1);
    }
    return rta;
}

int potencia1(int base, int exponente){
    int rta = 1;
    if(exponente > 0){
        rta = base * potencia1(base, exponente - 1);
    }
    return rta;
}

int potencia2(int base, int exponente){
    return (exponente > 0) ? base * potencia(base, exponente - 1) : 1;
}
///-----------------------------------------------------------------------------------------------------------------------------
///3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void muestraArreglo(int a[], int v, int i){
    if(i < v){
        printf("%d - ", a[i]);
        muestraArreglo(a, v, i + 1);
    }
}
///-----------------------------------------------------------------------------------------------------------------------------
///4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

void muestraArregloInvertido(int a[], int v, int i){
    if(i < v){
        muestraArreglo(a, v, i + 1);
        printf("%d - ", a[i]);
    }
}
///-----------------------------------------------------------------------------------------------------------------------------
///5. Determinar en forma recursiva si un arreglo es capicúa.

int RecuCapicua (int A[], int v,int in, int fin){
int rta=1;
if(in < v){
if(A[in] != A[fin]){
    rta=0;
}else{
rta= RecuCapicua(A, v, in ++, fin--)
}
}
return rta;
}

///------------------------------------------------------------------------------------------------------------------------------
///6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int SumaArregloRecur(int A[], int v, int i){
int rta=0;
if(i == v){
    rta=0;
}else{
rta= A[i] + SumaArregloRecur(A,v,i++);
}
return rta;
}

///---------------------------------------------------------------------------------------------------------------------------------
///7. Buscar el menor elemento de un arreglo en forma recursiva.
int MenorNumArregloRecur(int A[], int v, int i){
int rta;
if(i < v){
   rta= MenorNumArregloRecur(A, v, i++);
   if(A[i] =< rta){
    rta= A[i];
   }
}
return rta
}

///-----------------------------------------------------------------------------------------------------------------------------------------
///Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
int MenorNumArchiRecur (char NombreArchi,int r){
int rta;
int rta2=0;
FILE* Archi= fopen(NombreArchi, "rb");
if(Archi){
if(ftell(Archi)== 0){
        fread(rta, sizeof(int),1,Archi);
}else{
    fseek(Archi,sizeof(int)*(-1 *r),2);
    fread(rta2, sizeof(int),1,Archi);
    if(rta2< rta){
        rta= rta2;
    }}
   fclose(archi);
}
return rta;
}

///----------------------------------------------------------------------------------------------------------------------------------------------------
///9. Invertir los elementos de un archivo de números enteros de forma recursiva.
///(si no te sale, primero proba con invertir los elementos de un arreglo de int)

int InversElemArchiRecu (char nombreArchi,int ini,int fin);
FILE* Archi= fopen(nombreArchi, "ab");
int Aux;
int Aux2;
if(Archi){
        if(ini!= fin){
                fseek(Archi,sizeof(int)* ini,0);
            fread(Aux,sizeof(int),1, Archi);
            fseek(Archi, sizeof(int)*-1 *fin,2);
            fread(Aux2, sizeof(int),1,Archi);

            fseek(Archi,sizeof(int)* ini,0);
            fwrite(Aux2,sizeof(int),1,Archi);
            fseek(Archi, sizeof(int)*-1 *fin,2);
            fwrite(Aux,sizeof(int),1,Archi);

            InversElemArchiRecu(char nombreArchi,ini++,fin++);
        }
    fclose(Archi);
}

///--------------------------------------------------------------------------------------------------------------------------
///10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
void MostrArchiRecur (char nombreArchi, int i){
FILE* Archi = fopen(nombreArchi, "rb");
if(Archi){



    fclose(Archi);
}
}

