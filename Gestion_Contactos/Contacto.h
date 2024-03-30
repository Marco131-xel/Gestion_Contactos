#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>
#include <vector>
#include "Grupo.h"

using namespace std;

struct Contacto {
    string nombre;
    string apellido;
    int telefono;
    Grupo* grupo;
    vector<string> fields;
    Contacto(string nombre, string apellido, int telefono, Grupo* grupo);
};

#endif // CONTACTO_H
