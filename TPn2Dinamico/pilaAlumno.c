#include "pilaAlumno.h"

void inicPilaAlumno(pilaAlumno * p){

    p->v = 0; // (*p).v = 0
    p->dim = 50;
    p->a = (stAlumno *) malloc((p->dim)*sizeof(stAlumno));

}

void apilarAlumno(pilaAlumno *p, stAlumno Alumno){

if(p->v == p->dim){
p->a = (stAlumno*) realloc(p->a,sizeof(p->dim+50));
p->dim = p->dim +50;
}

p->a[p->v]= *Alumno;
    p->v++;
}

stAlumno Desapilar(pilaAlumno *p){

p->v--;

return p->a[p->v];
}

stAlumno TopeAlumno(pilaAlumno *p){

return p->a[p->v-1];
}

int PilaAlumnoVacia (pilaAlumno *p){
int flag=1;

if(p->v > 0){
    flag=0;
}
return flag;
}


