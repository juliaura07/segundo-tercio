#include "Usuario.h"
#include <iostream>
#include <vector>

using namespace std;

void mostrarMenu()
{
    cout << "\n--------------------------------------" << endl;
    cout << "   SISTEMA DE CARRITO DE COMPRAS   " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Ver catálogo de productos" << endl;
    cout << "2. Agregar producto al carrito" << endl;
    cout << "3. Ver carrito" << endl;
    cout << "4. Eliminar producto del carrito" << endl;
    cout << "5. Realizar compra" << endl;
    cout << "6. Ver historial de compras" << endl;
    cout << "7. Salir" << endl;
    cout << "Selecciona una opción: ";
}

void mostrarCatalogo(const vector<Producto> &catalogo)
{
    cout << "\n ---- CATÁLOGO DE PRODUCTOS ----" << endl;
    for (size_t i = 0; i < catalogo.size(); ++i)
    {
        cout << (i + 1) << ". ";
        catalogo[i].mostrarInfo();
    }
    cout << "-----------------------------------\n"
         << endl;
}

int main()
{
    // Crear catálogo de productos
    vector<Producto> catalogo = {
        Producto("Laptop", 1200000, 10),
        Producto("Mouse", 25000, 50),
        Producto("Teclado", 75000, 30),
        Producto("Monitor", 3000000, 15),
        Producto("Auriculares", 50000, 40),
        Producto("Webcam", 80000, 20)};

    // Crear usuario
    string nombre, email;
    cout << "Bienvenido al Sistema de Carrito de Compras" << endl;
    cout << "Ingresa tu nombre: ";
    getline(cin, nombre);
    cout << "Ingresa tu email: ";
    getline(cin, email);

    Usuario usuario(nombre, email);
    cout << "\n¡Hola " << nombre << "! Tu cuenta ha sido creada.\n"
         << endl;

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            mostrarCatalogo(catalogo);
            break;
        }

        case 2:
        {
            mostrarCatalogo(catalogo);
            int numProducto, cantidad;
            cout << "Selecciona el número del producto: ";
            cin >> numProducto;

            if (numProducto < 1 || numProducto > static_cast<int>(catalogo.size()))
            {
                cout << "X Producto inválido" << endl;
                break;
            }

            cout << "Ingresa la cantidad: ";
            cin >> cantidad;

            usuario.getCarrito().agregarProducto(&catalogo[numProducto - 1], cantidad);
            break;
        }

        case 3:
        {
            usuario.getCarrito().mostrarCarrito();
            break;
        }

        case 4:
        {
            if (usuario.getCarrito().estaVacio())
            {
                cout << " El carrito está vacío" << endl;
                break;
            }

            usuario.getCarrito().mostrarCarrito();
            string nombreProducto;
            cout << "Ingresa el nombre del producto a eliminar: ";
            getline(cin, nombreProducto);
            usuario.getCarrito().eliminarProducto(nombreProducto);
            break;
        }

        case 5:
        {
            usuario.getCarrito().mostrarCarrito();
            if (!usuario.getCarrito().estaVacio())
            {
                char confirmar;
                cout << "¿Confirmar compra? (s/n): ";
                cin >> confirmar;

                if (confirmar == 's' || confirmar == 'S')
                {
                    usuario.realizarCompra();
                }
                else
                {
                    cout << "Compra cancelada." << endl;
                }
            }
            break;
        }

        case 6:
        {
            usuario.mostrarHistorial();
            break;
        }

        case 7:
        {
            cout << "\n¡Gracias por usar nuestro sistema! Hasta pronto." << endl;
            break;
        }

        default:
        {
            cout << "X Opción inválida. Intenta de nuevo." << endl;
            break;
        }
        }

    } while (opcion != 7);

    return 0;
}