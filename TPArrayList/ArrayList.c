#include "ArrayList.h"


int ingresarNotas(celda adl[],int dim)
{
    int nota;
    char alumno[20];
    char materia [30];
    char salir='s';
    while(salir == 's' && validos<dim)
    {
        printf("\n ingrese la materia: ");
        fflush(stdin);
        scanf("%s",&materia);
        printf("\n ingrese el alumno: ");
        fflush(stdin);
        scanf("%s",&alumno);
        printf("\n ingrese la nota: ");
        scanf("%d", nota);
        validos= alta(adl,alumno, nota,materia,validos);
        printf("Desea continuar?");
        salir=getch(salir);
    }
    return validos;
}

int alta(celda adl[],char alumno[],int nota, char materia[],int validos)
{
    nodoAlum* Aux= crearNodoAlum(nota,alumno);
    int pos= buscarPosMateria(adl,materia,validos)
             if(pos== -1)
    {
        validos= agregarMateria(adl,materia,validos);
        pos= validos-1;

    }
    adl[pos].lista = agregarPpio(adl[pos].lista, Aux);
    return validos;
}

nodoAlum* crearNodoAlum(int nota,char alumno[])
{
    nodoAlum nuevoNodo = (nodoAlum*) malloc(sizeof(nodoAlum));
    strcyp(nuevoNodo->Alumno.alumno, alumno);
    nuevoNodo->Alumno.nota= nota;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

int buscarPosMateria(celda adl[],char materia[],int validos)
{
    int rta= -1;
    int i=0;
    while(rta== -1 && i<validos)
    {
        if(strcmp(adl[i].materia, materia)==0)
        {
            rta=i
        }
        else
        {
            i++;
        }
    }
    return rta;
}

int agregarMateria (celda adl[],char materia[],int validos)
{
    stcpy(adl[validos].materia,materia);
    adl[validos].lista= inicLista();
    validos++;
    return validos;
}



///------------------------------------------------------------------------------------------------------------------------
///
