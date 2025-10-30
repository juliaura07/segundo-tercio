#include "Usuario.h"
#include <iostream>
#include <ctime>

Usuario::Usuario(const std::string &nombre, const std::string &email)
    : nombre(nombre), email(email) {}

std::string Usuario::getNombre() const
{
    return nombre;
}

std::string Usuario::getEmail() const
{
    return email;
}

CarritoCompras &Usuario::getCarrito()
{
    return carrito;
}

bool Usuario::realizarCompra()
{
    if (carrito.estaVacio())
    {
        std::cout << "X El carrito está vacío. No se puede realizar la compra." << std::endl;
        return false;
    }

    // Reducir el stock de los productos
    for (const auto &item : carrito.getItems())
    {
        if (!item.getProducto()->reducirStock(item.getCantidad()))
        {
            std::cout << "X Error al reducir stock del producto: "
                      << item.getProducto()->getNombre() << std::endl;
            return false;
        }
    }

    // Obtener fecha actual
    time_t now = time(0);
    char *dt = ctime(&now);
    std::string fecha(dt);
    fecha.pop_back(); // Eliminar el salto de línea

    // Guardar la compra en el historial
    double total = carrito.calcularTotal();
    historialCompras.push_back(Compra(carrito.getItems(), total, fecha));

    std::cout << "\n:) ¡Compra realizada exitosamente!" << std::endl;
    std::cout << "Total pagado: $" << total << std::endl;
    std::cout << "Fecha: " << fecha << "\n"
              << std::endl;

    // Vaciar el carrito
    carrito.vaciarCarrito();

    return true;
}

void Usuario::mostrarHistorial() const
{
    if (historialCompras.empty())
    {
        std::cout << " No tienes compras realizadas aún." << std::endl;
        return;
    }

    std::cout << "\n ---- HISTORIAL DE COMPRAS ----" << std::endl;
    std::cout << "Usuario: " << nombre << " (" << email << ")\n"
              << std::endl;

    for (size_t i = 0; i < historialCompras.size(); ++i)
    {
        const auto &compra = historialCompras[i];
        std::cout << "Compra #" << (i + 1) << " - " << compra.fecha << std::endl;
        std::cout << "Items:" << std::endl;

        for (const auto &item : compra.items)
        {
            std::cout << "  ";
            item.mostrarItem();
        }

        std::cout << "  Total: $" << compra.total << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }

    std::cout << "--------------------------------------\n"
              << std::endl;
}

int Usuario::cantidadCompras() const
{
    return historialCompras.size();
}