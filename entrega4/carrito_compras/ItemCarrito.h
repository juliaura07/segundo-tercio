#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"

class ItemCarrito
{
private:
    Producto *producto;
    int cantidad;

public:
    // Constructor
    ItemCarrito(Producto *prod, int cant);

    // Getters
    Producto *getProducto() const;
    int getCantidad() const;
    double getSubtotal() const;

    // Setters
    void setCantidad(int nuevaCantidad);

    // Métodos
    void aumentarCantidad(int cant);
    void mostrarItem() const;
};

#endif