#include <iostream>
#include "TablaHash.h"
#include "Utilidades.h"

using namespace std;
// Funcion para la terminal
void terminal(TablaHash& tablaHash){
    string input;
    cout<<"Terminal M4"<<endl;
    while(true){
        cout<<">";
        getline(cin, input);
        // Parsear el comando
        Comando cmd = parseComando(input);
        // Ejecutar el comando
        if(cmd.nombre == "ADD" && cmd.accion == "NEW-GROUP"){
            nuevoGrupo(cmd, tablaHash);
        } else if(cmd.nombre == "quit" || cmd.nombre == "QUIT"){
            cout<<"Saliendo..."<<endl;
            break;
        } else {
            cout<<"Comando desconocido: "<<cmd.nombre<<endl;
        }
    }
}

// Funcion para el menu
void menu(TablaHash& tabla) {
    int opcion, telefono, indice;
    string nombre, apellido, nombreGrupo;
    Contacto* encontrado;
    Grupo* grupoEncontrado;

    do {
        cout << "\n\t *MENU*" << endl;
        cout << "1. Insertar contacto" << endl;
        cout << "2. Buscar contacto" << endl;
        cout << "3. Buscar contacto por indice" << endl;
        cout << "4. Terminal" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del contacto: ";
                cin >> nombre;
                cout << "Ingrese el apellido del contacto: ";
                cin >> apellido;
                cout << "Ingrese el telefono del contacto: ";
                cin >> telefono;
                cout << "Ingrese el nombre del grupo del contacto (opcional, presione enter para omitir): ";
                cin.ignore(); // Ignorar el salto de línea pendiente en el búfer
                getline(cin, nombreGrupo); // Leer la entrada completa (incluyendo espacios) para el nombre del grupo
                if (!nombreGrupo.empty()) {
                    grupoEncontrado = tabla.obtenerGrupo(nombreGrupo);
                    if (grupoEncontrado == nullptr) {
                        cout << "El grupo especificado no existe." << endl;
                        break;
                    }
                } else {
                    grupoEncontrado = nullptr;
                }
                tabla.agregarContacto(nombre, apellido, telefono, grupoEncontrado);
                cout << "Contacto insertado correctamente." << endl;
                break;
            case 2:
                cout << "Ingrese el nombre del contacto a buscar: ";
                cin >> nombre;
                encontrado = tabla.buscarContacto(nombre);
                if (encontrado != nullptr) {
                    cout<<"Nombre: "<<encontrado->nombre<<endl;
                    cout<<"Apellido: "<<encontrado->apellido<<endl;
                    cout << "Telefono: "<< encontrado->telefono << endl;
                    if(encontrado->grupo != nullptr){
                        cout << "Grupo: " << encontrado->grupo->nombre << endl;
                    } else {
                        cout<<"Grupo: No asignado"<<endl;
                    }
                } else {
                    cout << "Contacto no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese el indice del contacto a buscar: ";
                cin >> indice;
                encontrado = tabla.buscarContactoPorIndice(indice);
                if (encontrado != nullptr) {
                    cout << "Nombre del contacto en el indice " << indice << ": " << encontrado->nombre << endl;
                    cout << "Grupo: " << encontrado->grupo->nombre << endl;
                }
                break;
            case 4:
                cout<<""<<endl;
                terminal(tabla);
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida, por favor intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);
}

int main(){
    TablaHash tabla;
    menu(tabla);
    return 0;
}
