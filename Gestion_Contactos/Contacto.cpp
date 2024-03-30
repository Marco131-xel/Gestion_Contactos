#include "Contacto.h"
using namespace std;

Contacto::Contacto(string nombre, string apellido, int telefono, Grupo* grupo) :
        nombre(nombre), apellido(apellido), telefono(telefono), grupo(grupo) {}
