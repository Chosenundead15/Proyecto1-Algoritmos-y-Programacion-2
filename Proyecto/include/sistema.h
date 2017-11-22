#ifndef SISTEMA_H
#define SISTEMA_H

typedef struct materias {
    int codigo;
    char nombre[31];
    char descripcion[101];
    char semestre[5];
    int creditos;
    struct materias *sig;
} materias;

typedef struct cursos {
    int codigo;
    int materia;
    int ano;
    int lapso;
    struct cursos *sig;
} cursos;

typedef struct cursando {
    int codigo;
    int nota;
    struct cursando *sig;
} cursando;

typedef struct personas {
    long int cedula;
    char nombre[32];
    char apellido[32];
    char nacimiento[11];
    char direccion[32];
    cursando *curso;
    struct personas *sig;
} personas;

typedef struct sistema {
    materias * Materias;
    cursos * Cursos;
    personas *Personas;
} sistema;

#ifdef _WIN32
#define CLEAR system("cls")
#define PAUSE system("pause")
#else
#define CLEAR system("clear")
#define PAUSE getchar(); printf("pulse enter para continuar\n")
#endif

#endif
