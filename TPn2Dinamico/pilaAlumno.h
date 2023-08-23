#ifndef PILAALUMNO_H_INCLUDED
#define PILAALUMNO_H_INCLUDED

#include <malloc.h>
#include "alumno.h"

typedef struct
{
    stAlumno * a;
    int v;
    int dim;
}pilaAlumno;

void inicPilaAlumno(pilaAlumno * p);
void apilarAlumno(pilaAlumno *p, stAlumno Alumno);
stAlumno Desapilar(pilaAlumno *p);
stAlumno TopeAlumno(pilaAlumno *p);
int PilaAlumnoVacia (pilaAlumno *p);

#endif // PILAALUMNO_H_INCLUDED
