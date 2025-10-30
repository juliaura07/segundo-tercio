#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include "ItemCarrito.h"
#include <vector>

class CarritoCompras
{
private:
    std::vector<ItemCarrito> items;

public:
    // Constructor
    CarritoCompras();

    // Métodos principales
    bool agregarProducto(Producto *producto, int cantidad);
    bool eliminarProducto(const std::string &nombreProducto);
    double calcularTotal() const;
    void vaciarCarrito();

    // Métodos de visualización
    void mostrarCarrito() const;
    bool estaVacio() const;

    // Getters
    const std::vector<ItemCarrito> &getItems() const;
};

#endif