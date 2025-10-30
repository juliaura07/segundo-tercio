#ifndef USUARIO_H
#define USUARIO_H

#include "CarritoCompras.h"
#include <string>
#include <vector>

struct Compra
{
    std::vector<ItemCarrito> items;
    double total;
    std::string fecha;

    Compra(const std::vector<ItemCarrito> &items, double total, const std::string &fecha)
        : items(items), total(total), fecha(fecha) {}
};

class Usuario
{
private:
    std::string nombre;
    std::string email;
    CarritoCompras carrito;
    std::vector<Compra> historialCompras;

public:
    // Constructor
    Usuario(const std::string &nombre, const std::string &email);

    // Getters
    std::string getNombre() const;
    std::string getEmail() const;
    CarritoCompras &getCarrito();

    // Métodos de compra
    bool realizarCompra();
    void mostrarHistorial() const;
    int cantidadCompras() const;
};

#endif