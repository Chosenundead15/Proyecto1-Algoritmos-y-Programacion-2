#ifndef PERSONAS_H
#define PERSONAS_H

#include "sistema.h"

void AgregarPersona(sistema *sis);

void ModificarPersona(sistema *sis);

void ConsultarPersona(sistema *sis);

void EliminarPersona(sistema *sis);

int ExistePersona(sistema *sis, int ced);

personas* PersonasObtener(sistema* sis, long int ced);

void ImprimirPersona(personas *p);

cursando* NotasObtener(cursando *curs, int cod);

#endif
