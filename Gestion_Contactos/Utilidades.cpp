#include "Utilidades.h"
#include <iostream>
#include <cctype>
using namespace std;

Comando parseComando(string input) {
    Comando cmd;
    string temp;

    // Encontrar el nombre del comando
    size_t pos = input.find(' ');
    if (pos != string::npos) {
        cmd.nombre = input.substr(0, pos);
        input.erase(0, pos + 1);
    } else {
        cmd.nombre = input;
        return cmd; // Comando sin argumentos
    }

    // Encontrar la accion
    pos = input.find(' ');
    if (pos != string::npos) {
        cmd.accion = input.substr(0, pos);
        input.erase(0, pos + 1);
    } else {
        cmd.accion = input;
        return cmd; // Comando con solo nombre y accion
    }

    // Encontrar el nombre del grupo
    pos = input.find(' ');
    if (pos != string::npos) {
        cmd.grupo = input.substr(0, pos);
        input.erase(0, pos + 1);
    } else {
        cmd.grupo = input;
        return cmd; // Comando con solo nombre, accion y grupo
    }

    // Parsear los campos
    pos = input.find('(');
    if (pos != string::npos) {
        input.erase(0, pos + 1);
        while ((pos = input.find(',')) != string::npos) {
            temp = input.substr(0, pos);
            // Limpiar espacios en blanco y caracteres no alfanumericos
            size_t i = 0;
            while (i < temp.size()) {
                if (isspace(temp[i]) || !isalnum(temp[i]))
                    temp.erase(i, 1);
                else
                    ++i;
            }
            cmd.fields.push_back(temp);
            input.erase(0, pos + 1);
        }
        // Limpiar el ultimo campo
        temp = input.substr(0, input.find(')'));
        size_t i = 0;
        while (i < temp.size()) {
            if (isspace(temp[i]) || !isalnum(temp[i]))
                temp.erase(i, 1);
            else
                ++i;
        }
        cmd.fields.push_back(temp);
    }

    return cmd;
}

// Comando para agregar un nuevo grupo
void nuevoGrupo(const Comando& cmd, TablaHash& tablaHash){
    // Verificar si se proporcionaron campos
    if (cmd.fields.empty()){
        cout << "No se han proporcionado campos para agregar." << endl;
        return;
    }

    // Agregar el nuevo grupo a la tabla hash
    tablaHash.agregarGrupo(cmd.grupo);

    // Extraer el nombre, apellido y telefono del primer campo
    string nombre = cmd.fields[0];
    string apellido = cmd.fields.size() > 1 ? cmd.fields[1] : "";
    int telefono = cmd.fields.size() > 2 ? stoi(cmd.fields[2]) : 0;

    // Mostrar los campos del nuevo grupo
    cout <<">"<< "Nuevo grupo agregado: " << cmd.grupo << " con los siguientes campos:" << endl;
    cout <<" "<< "Nombre: " << nombre << ", Apellido: " << apellido << ", Telefono: " << telefono << endl;

    // Agregar el contacto a la tabla hash
    tablaHash.agregarContacto(nombre, apellido, telefono, tablaHash.obtenerGrupo(cmd.grupo));
}