#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "archivo.h"
#include "materia.h"
#include "cursos.h"
#include "personas.h"

static void LeerMaterias(sistema *sis);
void LeerCursos(sistema *sis);
static void LeerPersonas(sistema *sis);
static void LeerNotas(sistema *sis);

static void SalvarMaterias(sistema *sis);
static void SalvarCursos(sistema *sis);
static void SalvarPersonas(sistema *sis);
static void SalvarNotas(sistema *sis);

void LeerArchivo(sistema *sis) {
    LeerMaterias(sis);
    LeerCursos(sis);
    LeerPersonas(sis);
    LeerNotas(sis);
}

static void LeerMaterias(sistema *sis) {
    materias *mat = NULL;
    materias *mat2 = NULL;
    char read[128];

    FILE *archivo = fopen("Materias.txt", "r");
    if ( archivo == NULL ) {
        printf("No hay archivo de materias\n");
        return;
    }

    while ( fgets(read, 3, archivo) )  {
        mat = new materias;
        fgets(read, 128, archivo);
        sscanf(read, "%d", &mat->codigo);
        fgets(mat->nombre, 128, archivo);
        fgets(mat->descripcion, 128, archivo);
        fgets(mat->semestre, 128, archivo);
        fgets(read, 128, archivo);
        sscanf(read, "%d", &mat->creditos);
        mat2 = MateriasFinal(sis);
        if ( mat2 ) {
            mat2->sig = mat;
        } else {
            sis->Materias = mat;
        }
        mat = NULL;
    }

    fclose(archivo);
    printf("lectura de materias completada\n");
}

void LeerCursos(sistema *sis) {
    cursos *cur = NULL;
    cursos *cur2 = NULL;
    char read[128];
    FILE *archivo = fopen("Cursos.txt", "r");
    if ( archivo == NULL ) {
        printf("No hay archivo de cursos\n");
        return;
    }

    while ( fgets(read, 3, archivo) )  {
        cur = (cursos*)malloc(sizeof(cursos));
        cur->sig = NULL;
        fgets(read, 128, archivo);
        printf("%s", read);
        sscanf(read, "%d", &cur->codigo);
        printf("%s", read);
        fgets(read, 128, archivo);
        sscanf(read,"%d", &cur->materia);
        printf("%s", read);
        fgets(read, 128, archivo);
        sscanf(read, "%d", &cur->ano);
        printf("%s", read);
        fgets(read, 128, archivo);
        sscanf(read, "%d", &cur->lapso);
        cur2 = CursosFinal(sis);
        if ( cur2 ) {
            cur2->sig = cur;
        } else {
            sis->Cursos = cur;
        }
        cur = NULL;
    }

    fclose(archivo);
    printf("lectura de cursos completada\n");
}

static void LeerPersonas(sistema *sis) {
    personas *per = NULL;
    personas *per2 = NULL;
    char read[128];
    FILE *archivo = fopen("Alumnos.txt", "r");
    if ( archivo == NULL ) {
        printf("No hay archivo de alumnos\n");
        return;
    }

    while ( fgets(read, 3, archivo) )  {
        per = new personas;
        fgets(read, 128, archivo);
        sscanf(read, "%ld", &per->cedula);
        fgets(per->nombre, 34, archivo);
        fgets(per->apellido, 34, archivo);
        fgets(per->nacimiento, 11, archivo);
        fgets(per->direccion, 34, archivo);
        per2 = PersonasFinal(sis);
        if ( per2 ) {
            per2->sig = per;
        } else {
            sis->Personas = per;
        }
        per = NULL;
    }

    fclose(archivo);
    printf("lectura de personas completada\n");
}

static void LeerNotas(sistema *sis) {
    cursando *curs = NULL;
    cursando *curs2 = NULL;
    personas *aux;
    char read[16];
    if ( sis->Personas ) {
        aux = sis->Personas;
    } else {
        printf("no hay personas inscritas para registra notas\n");
        return;
    }

    FILE *archivo = fopen("Notas.txt", "r");
    if ( !archivo ) {
        printf("no hay archivo de notas\n");
        return;
    }

    while ( fgets(read, 10, archivo) ) {
        if ( !strcmp( read, "\n") ) {
            curs = new cursando;
            sscanf(read, "%d", &curs->codigo);
            fgets(read, 10, archivo);
            sscanf(read, "%d", &curs->nota);
            curs2 = NotasFinal(sis);
            if ( curs2 ) {
                curs2->sig = curs;
            } else {
                aux->curso = curs;
            }
        } else if ( aux->sig ) {
            aux = aux->sig;
        }
    }

    fclose(archivo);
    printf("lectura de notas completada\n");
}

void SalvarArchivo(sistema *sis) {
    SalvarMaterias(sis);
    SalvarCursos(sis);
    SalvarPersonas(sis);
    SalvarNotas(sis);
}

static void SalvarMaterias(sistema *sis) {
    FILE *archivo = fopen("Materias.txt", "w");
    materias *aux = sis->Materias;

    while ( aux ) {
        fprintf(archivo, "\n");
        fprintf(archivo, "%d", aux->codigo);
        fprintf(archivo, "%s", aux->nombre);
        fprintf(archivo, "%s", aux->descripcion);
        fprintf(archivo, "%s", aux->semestre);
        fprintf(archivo, "%d", aux->creditos);
        aux = aux->sig;
    }

    fclose(archivo);
}

static void SalvarCursos(sistema *sis) {
    FILE *archivo = fopen("Cursos.txt", "w");
    cursos *aux = sis->Cursos;

    while ( aux ) {
        fprintf(archivo, "\n");
        fprintf(archivo, "%d", aux->codigo);
        fprintf(archivo, "%d", aux->materia);
        fprintf(archivo, "%d", aux->ano);
        fprintf(archivo, "%d", aux->lapso);
        aux = aux->sig;
    }

    fclose(archivo);
}

static void SalvarPersonas(sistema *sis) {
    FILE *archivo = fopen("Alumnos.txt", "w");
    personas *aux = sis->Personas;

    while ( aux ) {
        fprintf(archivo, "\n");
        fprintf(archivo, "%ld", aux->cedula);
        fprintf(archivo, "%s", aux->nombre);
        fprintf(archivo, "%s", aux->apellido);
        fprintf(archivo, "%s", aux->nacimiento);
        fprintf(archivo, "%s", aux->direccion);
        aux = aux->sig;
    }

    fclose(archivo);
}

static void SalvarNotas(sistema *sis) {
    FILE *archivo = fopen("Notas.txt", "w");
    personas *aux1 = sis->Personas;
    cursando *aux2 = NULL;

    while ( aux1 ) {
        aux2 = aux1->curso;
        while ( aux2 ) {
            fprintf(archivo, "%d", aux2->codigo);
            fprintf(archivo, "%d", aux2->nota);
            fprintf(archivo, "\n");
            aux2 = aux2->sig;
        }

        aux1 = aux1->sig;
    }

    fclose(archivo);
}
