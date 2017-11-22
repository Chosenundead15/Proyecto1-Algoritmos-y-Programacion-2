#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cursos.h"

void AgregarCurso(sistema *sis) {
    int op = 1;
    int cod = 0;
    cursos *aux = NULL;
    cursos *aux2 = CursosFinal(sis);

    while ( op ) {
        printf("Introduzca el codigo de la materia\n");
        scanf("%d", &cod);
        if ( !ExisteCurso(sis, cod) ) {
            aux = new cursos;
            aux->codigo = cod;
            printf("Introduzca el ano\n");
            scanf("%d", &aux->ano);
            printf("Introduzca el Lapso\n");
            scanf("%d", &aux->lapso);

            if ( aux2 ) {
                aux2->sig = aux;
            } else {
                sis->Cursos = aux;
            }
        }

        printf("Desea agregar otra materia si = 1 y no = 0\n");
        scanf("%d", &op);
    }
}

int ExisteCurso(sistema *sis, int cod) {
    cursos *aux = sis->Cursos;

    while ( aux ) {
        if ( aux->codigo != cod ) {
            aux = aux->sig;
        } else {
            printf("El curso ya existe\n");
            return 1;
        }
    }
    return 0;
}

cursos* CursosFinal(sistema *sis) {
    cursos *aux = sis->Cursos;
    while ( aux && aux->sig ) {
        aux = aux->sig;
    }
    return aux;
}

void ConsultarCurso(sistema *sis) {
    int op = 1;
    while ( op ) {
        CLEAR;
        printf("Introduzca el codigo del curso que desea consultar\n");
        int input;
        scanf("%d", &input);
        cursos *aux = sis->Cursos;

        while ( aux && aux->codigo != input) {
            aux = aux->sig;
        }

        if ( !aux ) {
            printf("no existe curso con ese codigo\n");
        } else {
            ImprimirCurso(aux);
        }

        printf("Desea consiltar otra materia? si=1 no=0\n");
        scanf("%d", &op);
    }
}

void ImprimirCurso(cursos *c) {
    printf("Ano: %d\n", c->ano);
    printf("Codigo de marteria: %d\n", c->materia);
    printf("Lapso: %d\n", c->lapso);
}

void EliminarCurso(sistema *sis) {
    int op = 1;
    int input;
    cursos *aux, *aux2;
    while ( op ) {
        aux = sis->Cursos;
        printf("ponga el codigo del curso a eliminar\n");
        scanf("%d", &input);

        if ( aux->codigo == input ) {
            ImprimirCurso(aux);

            printf("Seguro que desea eliminar el curso\n");
            scanf("%d", &input);

            if ( input ) {
                sis->Cursos = aux->sig;
                delete aux;
            }
        } else {
            while ( aux->sig && aux->sig->codigo !=input ) {
                aux = aux->sig;
            }
            if ( aux->sig ) {
                ImprimirCurso(aux->sig);
                printf("Seguro que desea eliminar el curso\n");
                scanf("%d", &input);
                if ( input ) {
                    aux2 = aux->sig;
                    aux->sig = aux->sig->sig;
                    delete aux2;
                }
            } else {
                printf ("no existe curso con ese codigo\n");
            }
        }
    }
}

void ModificarCurso(sistema* sis) {
    int input = 1;
    cursos *aux;
    
    while ( input ) {
        aux = sis->Cursos;
        printf("introduzca el codigo del curso\n");
        scanf("%d", &input);
        
        while ( aux && aux->sig && aux->sig->codigo != input ) {
            aux = aux->sig;
        }
        
        if ( aux->codigo != input ) {
            printf("no hay curso con ese codigo\n");
        } else {
            ImprimirCurso(aux);
            printf("\n\t Que desea modificar\n");
            printf("1) ano\n");
            printf("2) lapso\n");
            
            scanf("%d", &input);
            
            switch ( input ) {
            case 1:
                printf("cual es el nuevo ano del curso\n");
                scanf("%d", &aux->ano);
                break;
            case 2:
                printf("cual es el nuevo lapso del curso\n");
                scanf("%d", &aux->lapso);
            }
        }
        
        printf("desea odificar otro curso\n");
        scanf("%d", &input);
    }
}
