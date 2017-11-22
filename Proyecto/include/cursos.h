#ifndef CURSOS_H
#define CURSOS_H

#include "sistema.h"

void AgregarCurso(sistema *sis);

void ModificarCurso(sistema *sis);

void ConsultarCurso(sistema *sis);

void EliminarCurso(sistema *sis);

cursos* CursosObtener(sistema *sis, int cod);

void ImprimirCurso(cursos *c);

int ExisteCurso(sistema *sis, int cod);

#endif
