cmake_minimum_required(VERSION 3.27)
project(Gestion_Contactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestion_Contactos main.cpp
        TablaHash.h
        TablaHash.cpp
        Contacto.cpp
        Grupo.cpp
        Comando.h
        Utilidades.h
        Utilidades.cpp)
