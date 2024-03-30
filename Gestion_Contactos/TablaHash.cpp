#include "TablaHash.h"
#include <iostream>

using namespace std;

TablaHash::TablaHash() : tabla(tamanioTabla) {}

TablaHash::~TablaHash() {
    for (auto& lista : tabla) {
        for (auto& contacto : lista) {
            delete contacto;
        }
    }
    for (auto& grupo : grupos) {
        delete grupo;
    }
}

void TablaHash::agregarContacto(string nombre,string apellido, int telefono, Grupo* grupo) {
    int indice = hashFuncion(nombre);
    tabla[indice].push_back(new Contacto(nombre, apellido, telefono, grupo));
    cout << "Llave: " << indice << " Contacto: " << nombre << endl;
}

Contacto* TablaHash::buscarContacto(string nombre) {
    int indice = hashFuncion(nombre);
    for (Contacto* contacto : tabla[indice]) {
        if (contacto->nombre == nombre) {
            return contacto;
        }
    }
    return nullptr; // Contacto no encontrado
}

Contacto* TablaHash::buscarContactoPorIndice(int indice) {
    if (indice < 0 || indice >= tamanioTabla) {
        cout << "Llave Invalida" << endl;
        return nullptr;
    }
    if (!tabla[indice].empty()) {
        Contacto* contacto = tabla[indice].front();
        cout << "Contacto encontrado en el indice " << indice << ": " << contacto->nombre << endl;
        return contacto;
    } else {
        cout << "Llave Invalida" << endl;
        return nullptr;
    }
}

void TablaHash::agregarGrupo(string nombre) {
    grupos.push_back(new Grupo(nombre));
}

Grupo* TablaHash::obtenerGrupo(string nombre) {
    for (Grupo* grupo : grupos) {
        if (grupo->nombre == nombre) {
            return grupo;
        }
    }
    return nullptr; // Grupo no encontrado
}

int TablaHash::hashFuncion(string clave) {
    int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash % tamanioTabla;
}
