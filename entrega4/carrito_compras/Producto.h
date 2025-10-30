#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto
{
private:
    std::string nombre;
    double precio;
    int stock;

public:
    Producto(const std::string &nombre, double precio, int stock);

    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    void setStock(int nuevoStock);

    bool reducirStock(int cantidad);
    void aumentarStock(int cantidad);
    void mostrarInfo() const;
};

#endif