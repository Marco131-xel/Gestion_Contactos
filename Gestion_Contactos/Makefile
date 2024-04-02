# Nombre del ejecutable
TARGET = Gestion

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Archivos fuente
SRCS = Comando.h Contacto.cpp Contacto.h Grupo.cpp Grupo.h main.cpp TablaHash.cpp TablaHash.h Utilidades.cpp Utilidades.h

# Regla principal: compilar el programa
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET)

# Regla para eliminar los archivos temporales generados durante la compilación
.PHONY: clean