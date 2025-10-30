CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Nombre del ejecutable
TARGET = carrito_compras

# Archivos fuente y objetos
SOURCES = main.cpp Producto.cpp ItemCarrito.cpp CarritoCompras.cpp Usuario.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo " Compilación exitosa! Ejecuta con: ./$(TARGET)"

# Compilar archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo " Archivos limpiados"

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Regla para ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make         - Compila el proyecto"
	@echo "  make run     - Compila y ejecuta el programa"
	@echo "  make clean   - Elimina archivos compilados"
	@echo "  make help    - Muestra esta ayuda"

.PHONY: all clean run help
```

---

## **Archivo 11: .gitignore**
```
# Archivos compilados
*.o
*.exe
carrito_compras

# Archivos de Visual Studio Code
.vscode/

# Archivos del sistema
.DS_Store
Thumbs.db

# Archivos temporales
*.tmp
*.swp
*~

# Carpetas de build
build/
bin/
obj/