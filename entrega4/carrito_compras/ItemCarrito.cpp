#include "ItemCarrito.h"
#include <iostream>

ItemCarrito::ItemCarrito(Producto *prod, int cant)
    : producto(prod), cantidad(cant) {}

Producto *ItemCarrito::getProducto() const
{
    return producto;
}

int ItemCarrito::getCantidad() const
{
    return cantidad;
}

double ItemCarrito::getSubtotal() const
{
    return producto->getPrecio() * cantidad;
}

void ItemCarrito::setCantidad(int nuevaCantidad)
{
    cantidad = nuevaCantidad;
}

void ItemCarrito::aumentarCantidad(int cant)
{
    cantidad += cant;
}

void ItemCarrito::mostrarItem() const
{
    std::cout << cantidad << "x " << producto->getNombre()
              << " - $" << producto->getPrecio()
              << " c/u = $" << getSubtotal() << std::endl;
}