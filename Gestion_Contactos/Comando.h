#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <vector>
using namespace std;

struct Comando {
    string nombre;
    string accion;
    string grupo;
    vector<string> fields;
};

#endif // COMANDO_H
