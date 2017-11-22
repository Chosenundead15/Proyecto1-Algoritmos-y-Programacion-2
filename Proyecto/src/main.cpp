#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"
#include "materia.h"
#include "cursos.h"
#include "personas.h"
#include "archivo.h"

void DecidirMantenimiento(int caso, sistema *sis);
void MenuMantenimiento(sistema *sis);

void MenuRegistro();

int main() {
    sistema *Sistema = new sistema;
    Sistema->Materias = NULL;
    Sistema->Cursos = NULL;
    Sistema->Personas = NULL;
    LeerArchivo(Sistema);
    int op = -1;
    PAUSE;
    CLEAR;
    while ( op != 0 ) {
        printf (" \n\n\t\t Mini Proyecto I \t\t\n\n ");
        printf ("\t1. -	Mantenimiento\n");
        printf ("\t2. -	Registro de estudiantes en cursos\n");
        printf ("\t3. -	Consultas\n");
        printf ("\t0. Salir\n\n");
        printf ("\tIndique su opcion (0-3)\t->> ");
        scanf ("%d", &op);

        CLEAR;
        printf("\n       Opcion %i\n\n",op);
        switch (op){
        case 1:
            MenuMantenimiento(Sistema);
            break;
        case 2:
            printf ("Registro de estudiantes en cursos");
            MenuRegistro();
            break;
            /*case 3:
            printf("Consultas Especiales");
            MenuConsultas();
            break;*/
        };
        printf("\n\n\t");
        if (op) PAUSE;
        CLEAR;
    }
    
    return 0;
}

void DecidirMantenimiento(int caso, sistema *sis) {
/*Esta funcion decide a que se le va hacer mantenimiento y como de acuerdo a la funcion que la llamo usando el parametro caso*/
    int op;
    op = -1;
    while ( op != 0 ) {
        printf ( "1. Agregar\n");
        printf ( "2. Modificar\n");
        printf ( "3. Consultar\n");
        printf ( "4. Eliminar\n");
        scanf ("%d", &op);

        /*TRABAJAR*/
        switch ( op ) {
        case 1:
            printf(" Agregar \n");			/*TRABAJAR*/
            if ( caso == 1 ) AgregarMateria(sis);
            if ( caso == 2 ) AgregarCurso(sis);
            if ( caso == 3 ) AgregarPersona(sis);
            break;
        case 2:
            printf(" Modificar \n");				/*TRABAJAR*/
            if ( caso == 1 ) ModificarMateria(sis);
            if ( caso == 2 ) ModificarCurso(sis);
            if ( caso == 3 ) ModificarPersona(sis);
            break;
        case 3:
            printf(" Consultar \n");			/*TRABAJAR*/
            if ( caso == 1 ) ConsultarMateria(sis);
            if ( caso == 2 ) ConsultarCurso(sis);
            if ( caso == 3 ) ConsultarPersona(sis);
            break;
        case 4:
            printf(" Eliminar \n");	    /*TRABAJAR*/
            if ( caso == 1 ) EliminarMateria(sis);
            if ( caso == 2 ) EliminarCurso(sis);
            if ( caso == 3 ) EliminarPersona(sis);
            break;
        }
    }
}

void MenuMantenimiento(sistema *sis) {
    printf(" - Mantenimiento - ");
    int op;
    op = -1;
    while ( op != 0 ) {
        printf (" A que desea hacer mantenimiento?\n");
        printf ( "1. Materias\n");
        printf ( "2. Cursos\n");
        printf ( "3. Personas\n");
        scanf ("%d", &op);

        CLEAR;

        printf("\n       Opcion %i\n\n", op);
        switch ( op ) {
        case 1:
            printf(" Mantenimiento de Materias \n");
            DecidirMantenimiento(op, sis); /*se usa la variable op para tener uniformidad en el comportamiento de la funcion con el case*/
            break;
        case 2:
            printf(" Manteinimiento de Cursos \n");
            DecidirMantenimiento(op, sis);
            break;
        case 3:
            printf(" Matenimiento de Personas \n");
            DecidirMantenimiento(op, sis);
            break;
        }
    }
}

void MenuRegistro() {
    /*Una persona solo se puede inscribir una vez en cada curso.
      Una persona solo se puede inscribir una vez en cada curso.
      Se puede modificar la nota en un curso y alumnos dados*/
    int op;   /* Primero preguntar en que curso desea modificar al estudiante*/
    op = -1;
    while ( op != 0 ) {
        printf (" 1. Agregar estudiante\n ");
        printf ( "2. Modificar estudiante\n");
        printf ( "3. Eliminar estudiante\n");
        scanf ("%d", &op);
        CLEAR;
        printf("\n       Opcion %i\n\n",op);
    }
    switch ( op ){
    case 1:
        printf(" Agregar\n ");			/*TRABAJAR*/
        break;
    case 2:
        printf(" Modificar\n ");				/*TRABAJAR*/
        break;
    case 3:
        printf(" Eliminar\n ");	    /*TRABAJAR*/
        break;
    }
}
