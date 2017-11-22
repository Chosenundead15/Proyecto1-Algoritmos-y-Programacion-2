#ifndef MATERIA_H
#define MATERIA_H

#include "sistema.h"

int ExisteMateria(sistema *sis, int cod);

materias* MateriasFinal(sistema *sis);

void AgregarMateria(sistema *sis);

void ConsultarMateria(sistema *sis);

void ModificarMateria(sistema *sis);

void EliminarMateria(sistema *sis);

void ImprimirMateria(materias *m);

#endif
