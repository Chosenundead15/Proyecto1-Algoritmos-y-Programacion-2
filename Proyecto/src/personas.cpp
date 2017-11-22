#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"

void AgregarPersona(sistema *sis) {
    int op = 1;
    int ced = 0;
    personas *aux = NULL;
    personas *aux2 = PersonasFinal(sis);

    while ( op ) {
        printf("Introduce la cedula del estuduiante\n");
        scanf("%d", &ced);
        if ( !ExistePersona(sis, ced) ) {
            aux = new personas;
            aux->cedula = ced;
            printf("Introduce el nombre del estuduiante\n");
            fgets(aux->nombre, 64, stdin);
            printf("Introduce el apellido del estudiante\n");
            fgets(aux->apellido, 64, stdin);
            printf("Introduce el ano de nacimiento\n");
            fgets(aux->nacimiento, 10, stdin);
            printf("Introduce la direccion del estuduiante\n");
            fgets(aux->direccion, 64, stdin);

            if ( aux2 ) {
                aux2->sig = aux;
            } else {
                sis->Personas = aux;
            }
        }

        printf("Desea agregar otra persona si=1 y no=0\n");
        scanf("%d", &op);
    }
}

int ExistePersona(sistema *sis, int ced) {
    personas *aux = sis->Personas;

    while ( aux ) {
        if ( aux->cedula != ced ) {
            aux = aux->sig;
        } else {
            printf("La cedula ya existe\n");
            return 1;
        }
    }

    return 0;
}

personas* PersonasObtener(sistema* sis, long int ced) {
    personas *aux = sis->Personas;
    while ( aux && aux->sig && aux->cedula != ced) {
        aux = aux->sig;
    }

    return aux;
}

cursando* NotasObtener(personas *per, int cod) {
    if ( per ) {
        cursando *aux = per->curso;

        while ( aux && aux->sig && aux->nota != cod) {
            aux = aux->sig;
        }
        return aux;
    } else {
        return NULL;
    }
}

void ConsultarPersona(sistema *sis) {
    int op = 1;
    while ( op ) {
        CLEAR;
        printf("introduzca la cedula de la materia que desea consultar\n");
        int input;
        scanf("%d", &input);
        personas *aux = sis->Personas;

        while ( aux ) {
            if ( aux->cedula != input ) {
                aux = aux->sig;
            } else {
                ImprimirPersona(aux);
                break;
            }
        }

        if ( !aux ) {
            printf("no existe persona con esa cedula\n");
        }
        printf("Desea consultar otra persona? si=1 y no=0\n");
        scanf("%d", &op);
    }
}

void ImprimirPersona(personas *p) {
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("nacimiento: %s\n", p->nacimiento);
    printf("direccion: %s\n", p->direccion);
}

void EliminarPersona(sistema *sis) {
    int op = 1;
    int input;
    personas *aux, *aux2;
    while ( op ) {
        aux = sis->Personas;
        printf("ponga la cedula de la persona a borrar\n");
        scanf("%d", &input);

        if ( aux->cedula == input ) {
            ImprimirPersona(aux);
            printf("Seguro  que desea eliminar a esa persona\n");
            scanf("%d", &input);

            if ( input ) {
                sis->Personas = aux->sig;
                delete aux;
            }
        } else {
            while ( aux->sig && aux->sig->cedula != input ) {
                aux = aux->sig;
            }
            
            if ( aux->sig ) {
                ImprimirPersona(aux->sig);
                printf("Seguro que desea borrar a la persona?\n");
                scanf("%d", &input);
                if( input ) {
                    aux2 = aux->sig;
                    aux->sig = aux->sig->sig;
                    delete aux2;
                }
            } else {
                printf("No existe persona con esa cedula\n");
            }
        }
    }
}

void ModificarPersona(sistema *sis) {
    personas *aux;
    int input = 1;
    
    while ( input ) {
        aux = sis->Personas;
        printf("introduzca la cedula de persona a modificar\n");
        scanf("%d", &input);
        
        while ( aux && aux->sig && aux->cedula != input ) {
            aux = aux->sig;
        }
        
        if ( aux->cedula != input ) {
            printf("no hay persona con esa cedula\n");
        } else {
            ImprimirPersona(aux);
            printf("\n\t Que desea modficar\n");
            printf("1) nombre\n");
            printf("2) apellido\n");
            printf("3) nacimiento\n");
            printf("4) direccion\n");
            
            scanf("%d", &input);
            
            switch ( input ) {
            case 1:
                printf("cual es el nuevo nombre que le desea poner\n");
                fgets(aux->nombre, 32, stdin);
                break;
            case 2:
                printf("cual es el nuevo apellido que le desea poner\n");
                fgets(aux->apellido, 32, stdin);
                break;
            case 3:
                printf("cual es la nueva fecha de nacimineto que le desea poner\n");
                fgets(aux->nacimiento, 10, stdin);
                break;
            case 4:
                printf("cual es la nueva direccion a colocar\n");
                fgets(aux->direccion, 32, stdin);
            }
        }
        
        printf("desea modificar otra persona si=1 no=0\n");
        scanf("%d", &input);
    }
}
