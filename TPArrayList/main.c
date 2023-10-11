#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "ArrayList.h"
#include "registroMateria.h"
int cargarArreglo(char nombreArchivo[],celda adl[],int dim)



    int main()
    {
        celda adl[100];
        int v=0;

        v = cargarArreglo(nombreArchivo, adl,100);

        return 0;
    }
    int cargarArreglo(char nombreArchivo[],celda adl[],int dim)
    {
        FILE* Archi = fopen(nombreArchivo, "rb");
        char materia[20];
        stAlumno alumno;
        int v=0;
        stMateria registro;
        if(Archi)
        {
            while(v < dim && fread(&registro, sizeof(stMateria),1,Archi) > 0){
                strcpy(materia, registro.materia);
                alumno = getAlumno(registro);
                v = alta(adl,v,materia, alumno);
            }


            fclose(Archi);
        }
        return v;
    }


stAlumno getAlumno(stMateria materia){
stAlumno Alumno;
strcpy(Alumno.nombreAlumno, materia.nombreAlumno)
strcpy(Alumno.apellidoAlumno, materia.apellidoAlumno)
Alumno.nota= materia.nota;
}
