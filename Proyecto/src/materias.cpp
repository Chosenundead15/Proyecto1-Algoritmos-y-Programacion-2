#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"

void AgregarMateria(sistema *sis) {
    int op = 1;
    int cod = 0;
    materias *aux = NULL;
    materias *aux2 = MateriasFinal(sis);

    while ( op ) {
        printf("Introduce el codigo de la materia\n");
        scanf("%d", &cod);
        if ( !ExisteMateria(sis, cod) ) {
            aux = new materias;
            aux->codigo = cod;
            printf("Introduce el nombre de la materia (maximo 30 caracteres)\n");
            scanf("%s", aux->nombre);
            printf("Introduce una descripcion de la materia(maximo 100 caracteres)\n");
            scanf("%s", aux->descripcion);
            printf("Introduce el semestre al que pertenece\n");
            scanf("%s", aux->semestre);
            printf("Introduce los creditos que vale\n");
            scanf("%d", &aux->creditos);

            if ( aux2 ) {
                aux2->sig = aux;
            } else {
                sis->Materias = aux;
            }
        }

        printf("Desea agregar otra materia si = 1 y no = 0\n");
        scanf("%d", &op);
    }
}

int ExisteMateria(sistema *sis, int cod) {
    materias *aux = sis->Materias;

    while ( aux && aux->codigo != cod ) {
        if ( aux->codigo != cod ) {
            aux = aux->sig;
        } else {
            printf("La materia ya existe\n");
			return 1;
        }
    }

    return 0;
}

materias* MateriasFinal(sistema* sis) {
    materias *aux = sis->Materias;
    while ( aux && aux->sig ) {
        aux = aux->sig;
    }

    return aux;
}

void ConsultarMateria(sistema *sis) {
    int op = 1;
    while ( op ) {
        CLEAR;
        printf("introduzca el codigo de la materia que desea consultar\n");
        int input;
        scanf("%d", &input);
        materias *aux = sis->Materias;

        while ( aux && aux->codigo != input) {
            aux = aux->sig;
        }

        if ( !aux ) {
            printf("no existe materia con ese codigo\n");
        } else {
            ImprimirMateria(aux);
        }

        printf("Desea consultar otra materia? si = 1 no = 0\n");
        scanf("%d", &op);
    }
}

void ImprimirMateria(materias *m) {
    printf("Nombre: %s\n", m->nombre);
    printf("Descripcion: %s\n", m->descripcion);
    printf("Semestre: %s\n", m->semestre);
    printf("Creditos: %d\n", m->creditos);
}

void EliminarMateria(sistema *sis) {
    int op = 1;
    int input;
    materias *aux, *aux2;
    while ( op ) {
        aux = sis->Materias;
        printf("ponga el codigo de la materia a eliminar\n");
        scanf("%d", &input);

        if ( aux->codigo == input ) {
            ImprimirMateria(aux);
            printf("Seguro que desea eliminar la materia?\n");
            scanf("%d", &input);

            if ( input ) {
                sis->Materias = aux->sig;
                delete aux;
            }

        } else {

            while ( aux->sig && aux->sig->codigo != input ) {
                aux = aux->sig;
            }

            if ( aux->sig ) {
                ImprimirMateria(aux->sig);
                printf("Seguro que desea elminar la materia?\n");
                scanf("%d", &input);
                if ( input ) {
                    aux2 = aux->sig;
                    aux->sig = aux->sig->sig;
                    delete aux2;
                }
            } else {
                printf("No existe Materia con ese codigo\n");
            }
        }
    }
}

void ModificarMateria(sistema* sis) {
    int error = 1;
    int input = 1;
    materias *aux;
    char str[256];
    
    while ( input ) {
        aux = sis->Materias;
        printf("introduzca el codigo de la materia a modificar\n");
        scanf("%d", &input);
        
        while ( aux && aux->sig && aux->codigo != input ) {
            aux = aux->sig;
        }
        
        if ( aux->codigo != input ) {
            printf("no hay materia con ese codigo\n");
        } else {
            ImprimirMateria(aux);
            printf("\n\t Que desea modificar\n");
            printf("1) nombre\n");
            printf("2) descripcion\n");
            printf("3) semestre\n");
            printf("4) creditos\n");
            
            scanf("%d", &input);
            
            switch ( input ) {
            case 1:
                printf("cual es el nuevo nombre que le desea poner\n");
                
                while ( error ) {
                    scanf("%s", str);
                    if ( strlen(str) > 30 ) {
                        error = 1;
                        printf("el nombre es muy largo intentelo  de nuevo \n");
                    } else {
                        error = 0;
                        strcpy(aux->nombre, str);
                    }
                }
                break;
                
            case 2:
                printf("cual es la nueva descripcion que desea poner\n");
                
                while ( error ) {
                    scanf("%s", str);
                    if ( strlen(str) > 100 ) {
                        error = 1;
                        printf("la desripcion es muy largo intentelo de nuevo\n");
                    } else {
                        error = 0;
                        strcpy(aux->descripcion, str);
                    }
                }
                break;
                
            case 3:
                printf("cual es el nuevo semestre de la materia\n");
                scanf("%s", aux->semestre);
                break;
            case 4:
                printf("cuales son las nuevas unidades de creditos que cuesta\n");
                scanf("%d", &aux->creditos);
                break;
            }
        }
        
        printf("desea modificar otra materia si=1 no=0\n");
        scanf("%d", &input);
    }
}
