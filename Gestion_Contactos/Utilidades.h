#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include "Comando.h"
#include "TablaHash.h"
using namespace std;

Comando parseComando(string input);
void nuevoGrupo(const Comando& cmd, TablaHash& tablaHash);

#endif // UTILIDADES_H
