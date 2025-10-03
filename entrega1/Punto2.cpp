#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Callback functions para cada operación aritmética
double suma(double a, double b)
{
    return a + b;
}

double resta(double a, double b)
{
    return a - b;
}

double multiplicacion(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    if (b == 0)
    {
        cout << "Error: División por cero no permitida" << endl;
        exit(1);
    }
    return a / b;
}

// Función que valida si una cadena es un número válido
bool esNumeroValido(const string &str)
{
    if (str.empty())
        return false;

    char *end;
    strtod(str.c_str(), &end);

    // Si end apunta al final de la cadena, es un número válido
    return *end == '\0';
}

// Función que ejecuta la operación usando un callback
void ejecutarOperacion(double (*callback)(double, double), double num1, double num2)
{
    double resultado = callback(num1, num2);
    cout << "El resultado de la operacion es: " << resultado << endl;
}

// Función para mostrar el uso correcto del programa
void mostrarUso(const string &nombrePrograma)
{
    cout << "Ha ingresado valores inadecuados para el programa:" << endl;
    cout << "USO: " << nombrePrograma << " <num1> <operador> <num2>" << endl;
    cout << "Operadores validos: +, -, *, x, /" << endl;
    cout << "Ejemplo: " << nombrePrograma << " 2 + 5" << endl;
}

int main(int argc, char *argv[])
{
    // Validar que se reciban exactamente 3 argumentos
    if (argc != 4)
    {
        mostrarUso(argv[0]);
        return 1;
    }

    string arg1 = argv[1];
    string operador = argv[2];
    string arg2 = argv[3];

    // Validar que los operandos sean números válidos
    if (!esNumeroValido(arg1) || !esNumeroValido(arg2))
    {
        mostrarUso(argv[0]);
        return 1;
    }

    // Convertir los argumentos a números decimales usando strtod
    double num1 = strtod(arg1.c_str(), NULL);
    double num2 = strtod(arg2.c_str(), NULL);

    // Puntero a función para la operación seleccionada
    double (*operacion)(double, double) = NULL;

    // Seleccionar la operación según el operador ingresado
    if (operador == "+")
    {
        operacion = suma;
    }
    else if (operador == "-")
    {
        operacion = resta;
    }
    else if (operador == "*" || operador == "x")
    {
        operacion = multiplicacion;
    }
    else if (operador == "/")
    {
        operacion = division;
    }
    else
    {
        cout << "Error: Operador no valido '" << operador << "'" << endl;
        mostrarUso(argv[0]);
        return 1;
    }

    // Ejecutar la operación usando el callback
    ejecutarOperacion(operacion, num1, num2);

    return 0;
}