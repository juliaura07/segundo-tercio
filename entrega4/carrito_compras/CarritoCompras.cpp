#include "CarritoCompras.h"
#include <iostream>

CarritoCompras::CarritoCompras() {}

bool CarritoCompras::agregarProducto(Producto *producto, int cantidad)
{
    if (cantidad <= 0)
    {
        std::cout << "X La cantidad debe ser mayor a 0" << std::endl;
        return false;
    }

    if (producto->getStock() < cantidad)
    {
        std::cout << "X Stock insuficiente. Disponible: "
                  << producto->getStock() << std::endl;
        return false;
    }

    // Buscar si el producto ya existe en el carrito
    for (auto &item : items)
    {
        if (item.getProducto()->getNombre() == producto->getNombre())
        {
            int nuevaCantidad = item.getCantidad() + cantidad;
            if (producto->getStock() < nuevaCantidad)
            {
                std::cout << "X Stock insuficiente para agregar más unidades" << std::endl;
                return false;
            }
            item.aumentarCantidad(cantidad);
            std::cout << ":) Producto actualizado en el carrito" << std::endl;
            return true;
        }
    }

    // Si no existe, agregar nuevo item
    items.push_back(ItemCarrito(producto, cantidad));
    std::cout << ":) Producto agregado al carrito" << std::endl;
    return true;
}

bool CarritoCompras::eliminarProducto(const std::string &nombreProducto)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getProducto()->getNombre() == nombreProducto)
        {
            items.erase(it);
            std::cout << ":) Producto eliminado del carrito" << std::endl;
            return true;
        }
    }
    std::cout << "X Producto no encontrado en el carrito" << std::endl;
    return false;
}

double CarritoCompras::calcularTotal() const
{
    double total = 0.0;
    for (const auto &item : items)
    {
        total += item.getSubtotal();
    }
    return total;
}

void CarritoCompras::vaciarCarrito()
{
    items.clear();
}

void CarritoCompras::mostrarCarrito() const
{
    if (items.empty())
    {
        std::cout << " El carrito está vacío" << std::endl;
        return;
    }

    std::cout << "\n ---- CARRITO DE COMPRAS ----" << std::endl;
    for (const auto &item : items)
    {
        item.mostrarItem();
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "TOTAL: $" << calcularTotal() << std::endl;
}

bool CarritoCompras::estaVacio() const
{
    return items.empty();
}

const std::vector<ItemCarrito> &CarritoCompras::getItems() const
{
    return items;
}