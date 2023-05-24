#include <stdio.h>
#include <stdlib.h>


void cargaMatrizRand(int fil, int col, int m[fil][col]);
float PromMatriz(int fil, int col, int m[fil][col]);
int SumaMatriz(int fil, int col, int m[fil][col]);
int BuscMatriz(int fil, int col, int m[fil][col],int Dato);
int PalMatriz(char m[][20], int dim );
void MostPalMatriz(char m[][20],int validos );
void OrdArgPalAlf(char m[][20],int validos,int dim);
int BuscaAlfPalMatriz(char m[][20],int validos, char p[]);
int DeterminMatriz(int m[2][2]);


int main()
{

    return 0;
}


void cargaMatrizRand(int fil, int col, int m[fil][col])
{
    int j;
    for(int i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            m[i][j]= rand();
        }
    }
}

int SumaMatriz(int fil, int col, int m[fil][col])
{
    int j;
    int suma;
    suma=0;
    for(int i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            suma= suma + m[i][j];
        }
    }
    return suma;
}


float PromMatriz(int fil, int col, int m[fil][col])
{
    int j;
    int suma, p;
    float promedio;
    suma=0;
    p=0;
    promedio=0;
    for(int i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            suma= suma + m[i][j];
            p++;
        }
    }
    promedio= suma / p;
    return promedio;
}

///--------------------------------------------------------------------
///Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
///La función recibe la matriz y el dato a buscar.

int BuscMatriz(int fil, int col, int m[fil][col],int  Dato)
{
    int j, flag;
    flag=0;
    for(int i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            if(m[i][j] == Dato)
            {
                flag=1;


            }
        }
    }
    return flag;
}
///------------------------------------------------------------------

///Hacer una función que cargue un arreglo de palabras (strings).
///La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero).

int PalMatriz(char m[][20], int dim )
{
    int i;
    char opcion=0;


    while (i<dim && opcion!= 27)
    {

        system("cls");
        printf("\n Ingrese un nombre:  ");
        fflush(stdin);
        gets(m[i]);
        i++;

        printf("ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
    }
    return i;
}



///---------------------------------------------------
///Hacer una función que muestre un arreglo de palabras.
void MostPalMatriz(char m[][20],int validos )
{
    int i;

    for(i=0; i<validos; i++)
    {
        printf("\n Nombre: %s", m[i]);
    }
}

///-------------------------------------------------------------

///Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
///La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario -1

int BuscaPalMatriz(char m[][20],int validos, char p[])
{
    int i, ubi,j;
    ubi= -1;
    j=0;
    i=0;
    int flag=-1;
    int flagJ=1;
    while(i<validos&& flag == -1)
    {
        while(p[j]!='/0' && flagJ ==1 )
        {
            if(m[i][j]== p[j])
            {
                j++;
            }
            else
            {
                flagJ =0;
            }
        }

        if(flagJ == 1)
        {
            flag = 1;
            ubi= i;
        }
        else
        {
            i++;
        }

    }
    return ubi;

}

///--------------------------------------------------------------------------

///Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente.
///La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario -1

int BuscaAlfPalMatriz(char m[][20],int validos, char p[])
{
    int i, ubi,j;
    ubi= -1;
    j=0;
    i=validos/2;
    int flag=-1;
    int flagJ=1;

    if(m[i][j]<= p[j]){
    while(i<validos&& flag == -1)
    {
        while(p[j]!='/0' && flagJ ==1 )
        {
            if(m[i][j]== p[j])
            {
                j++;
            }
            else
            {
                flagJ =0;
            }
        }

        if(flagJ == 1)
        {
            flag = 1;
            ubi= i;
        }
        else
        {
            i++;
        }

    }
    }else{
    while(i<0&& flag == -1)
    {
        while(p[j]!='/0' && flagJ ==1 )
        {
            if(m[i][j]== p[j])
            {
                j++;
            }
            else
            {
                flagJ =0;
            }
        }

        if(flagJ == 1)
        {
            flag = 1;
            ubi= i;
        }
        else
        {
            i--;
        }

    }

    }
    return ubi;
}


///------------------------------------------------------------------------
///Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético.
///(Por selección o inserción, el que más te guste).

void OrdArgPalAlf(char m[][20],int validos,int dim){
char aux[dim];
int i=0;
int j=0;
while(i<validos){
        if(m[i][j]> m[i+1][j]){
        strcat(aux[0], m[i]);
        strcat(m[i], m[i+1]);
        strcat(m[i+1], aux[0]);
        i++;
        }else{
        i++;}
}
}

///-----------------------------------------------------------------------

///Hacer una función que retorne el determinante de una matriz de 2x2.

int DeterminMatriz(int m[2][2]){
int result=0;

result= m[1][1]* m[2][2] - m[1][2]* m[2][1];
return result;
}

///-----------------------------------------------------------------------
///Función que verifique si una matriz de 2x2 tiene inversa.

void ElecMatriz(){
char strCand[5][20];
strcpy(strCand[0], "Distrito");
strcpy(strCand[1], "Candidato A");
strcpy(strCand[2], "Candidato B");
strcpy(strCand[3], "Candidato C");
strcpy(strCand[4], "Candidato D");
int Dist1[5]={1, 194,48,206,45};
int Dist2[5]={2, 180,20,320,16};
int Dist3[5]={3, 221,90,140,20};
int Dist4[5]={4, 432,51,821,14};
int Dist5[5]={5, 820,61,946,18};

int SumaCndA=0;
int SumaCndB=0;
int SumaCndC=0;
int SumaCndD=0;
SumaCndA= Dist1[1] + Dist2[1] + Dist3[1]+ Dist4[1] + Dist5[1] ;
SumaCndB= Dist1[2] + Dist2[2] + Dist3[2]+ Dist4[2] + Dist5[2] ;
SumaCndC= Dist1[3] + Dist2[3] + Dist3[3]+ Dist4[3] + Dist5[3] ;
SumaCndD= Dist1[4] + Dist2[4] + Dist3[4]+ Dist4[4] + Dist5[4] ;
int TotalVot=0;
TotalVot= SumaCndA + SumaCndB + SumaCndC + SumaCndD;
int PorcCndA=0;
int PorcCndB=0;
int PorcCndC=0;
int PorcCndD=0;

PorcCndA= SumaCndA *100 / TotalVot;
PorcCndB= SumaCndB *100 / TotalVot;
PorcCndC= SumaCndC *100 / TotalVot;
PorcCndD= SumaCndD *100 / TotalVot;

printf("| %s  %s  %s  %s  %s |\n", strCand[0], strCand[1], strCand[2],strCand[3], strCand[4]);
printf("| %d  %d  %d  %d  %d |\n", Dist1[0], Dist1[1], Dist1[2],Dist1[3], Dist1[4]);
printf("| %d  %d  %d  %d  %d |\n", Dist2[0], Dist2[1], Dist2[2],Dist2[3], Dist2[4]);
printf("| %d  %d  %d  %d  %d |\n", Dist3[0], Dist3[1], Dist3[2],Dist3[3], Dist3[4]);
printf("| %d  %d  %d  %d  %d |\n", Dist4[0], Dist4[1], Dist4[2],Dist4[3], Dist4[4]);
printf("| %d  %d  %d  %d  %d |\n", Dist5[0], Dist5[1], Dist5[2],Dist5[3], Dist5[4]);
printf("\n");
printf("La cantidad total de votos es de %d\n", TotalVot);
printf("Porcentajes: %d %| %d %| %d %| %d %|", PorcCndA, PorcCndB, PorcCndC, PorcCndD);

char Ganador[20];
strcpy(Ganador, "No Hay");
if (PorcCndA >= 50){
    strcpy(Ganador, strCand[1]);
}else{
if(PorcCndB >= 50){
        strcpy(Ganador, strCand[2]);
}else{
    if(PorcCndC >= 50){
    strcpy(Ganador, strCand[3]);
}else{
if(PorcCndD >= 50){
    strcpy(Ganador, strCand[4]);
}
}
}
}

printf("El ganador por el 50% es.... %s", Ganador);
}

