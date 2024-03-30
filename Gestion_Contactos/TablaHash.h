#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <vector>
#include <string>
#include "Grupo.h"
#include "Contacto.h"

using namespace std;

class TablaHash {
private:
    static const int tamanioTabla = 5; // Tamaño de la tabla hash
    vector<vector<Contacto*>> tabla;
    vector<Grupo*> grupos;

    int hashFuncion(string clave);

public:
    TablaHash();
    ~TablaHash();
    void agregarContacto(string nombre, string apellido, int telefono, Grupo* grupo);
    Contacto* buscarContacto(string nombre);
    Contacto* buscarContactoPorIndice(int indice);
    void agregarGrupo(string nombre);
    Grupo* obtenerGrupo(string nombre);
};

#endif // TABLAHASH_H
