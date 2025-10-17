#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;

        // Recorrer cada carácter de izquierda a derecha
        for (char c : columnTitle)
        {
            // Multiplicar resultado anterior por 26 (base 26)
            result = result * 26;

            // Sumar el valor de la letra actual (A=1, B=2, ..., Z=26)
            result += (c - 'A' + 1);
        }

        return result;
    }
};

// Función para validar la entrada
bool isValidColumnTitle(const string &s)
{
    if (s.empty() || s.length() > 7)
        return false;

    for (char c : s)
    {
        if (!isupper(c))
            return false;
    }
    return true;
}

// Función para mostrar el proceso paso a paso
void explainConversion(const string &columnTitle)
{
    cout << "\n=== Proceso de Conversión ===" << endl;
    cout << "Columna: " << columnTitle << endl;
    cout << "\nSistema base 26 (A=1, B=2, ..., Z=26):" << endl;
    cout << "------------------------------------" << endl;

    int result = 0;

    for (int i = 0; i < columnTitle.length(); i++)
    {
        char c = columnTitle[i];
        int value = c - 'A' + 1;

        cout << "Paso " << i + 1 << ": '" << c << "'" << endl;
        cout << "  Valor de '" << c << "' = " << value << endl;
        cout << "  Resultado anterior = " << result << endl;
        cout << "  Nuevo resultado = " << result << " × 26 + " << value;

        result = result * 26 + value;

        cout << " = " << result << endl
             << endl;
    }

    cout << "Resultado final: " << result << endl;
}

// Función para convertir número a título (inversa)
string numberToTitle(int n)
{
    string result = "";

    while (n > 0)
    {
        n--; // Ajuste para sistema base 26 (1-indexed)
        result = char('A' + n % 26) + result;
        n /= 26;
    }

    return result;
}

int main()
{
    Solution sol;

    cout << "=== CONVERTIDOR DE COLUMNAS DE EXCEL ===" << endl;
    cout << "\nOpciones:" << endl;
    cout << "1. Ingresar título de columna" << endl;
    cout << "2. Ejemplo 1: A → 1" << endl;
    cout << "3. Ejemplo 2: AB → 28" << endl;
    cout << "4. Ejemplo 3: ZY → 701" << endl;
    cout << "5. Probar varios ejemplos" << endl;
    cout << "\nSeleccione una opción: ";

    int option;
    cin >> option;

    string columnTitle;

    switch (option)
    {
    case 1:
    {
        cout << "\nIngrese el título de columna (letras mayúsculas, máx 7): ";
        cin >> columnTitle;

        // Convertir a mayúsculas por si acaso
        for (char &c : columnTitle)
        {
            c = toupper(c);
        }

        if (!isValidColumnTitle(columnTitle))
        {
            cout << "Error: Título inválido. Use solo letras mayúsculas (máx 7 caracteres)" << endl;
            return 1;
        }

        int result = sol.titleToNumber(columnTitle);
        cout << "\nColumna: " << columnTitle << endl;
        cout << "Número: " << result << endl;

        cout << "\n¿Ver proceso detallado? (1=Sí, 0=No): ";
        int showDetail;
        cin >> showDetail;

        if (showDetail == 1)
        {
            explainConversion(columnTitle);
        }
        break;
    }
    case 2:
        columnTitle = "A";
        cout << "\nColumna: " << columnTitle << endl;
        cout << "Número: " << sol.titleToNumber(columnTitle) << endl;
        explainConversion(columnTitle);
        break;

    case 3:
        columnTitle = "AB";
        cout << "\nColumna: " << columnTitle << endl;
        cout << "Número: " << sol.titleToNumber(columnTitle) << endl;
        explainConversion(columnTitle);
        break;

    case 4:
        columnTitle = "ZY";
        cout << "\nColumna: " << columnTitle << endl;
        cout << "Número: " << sol.titleToNumber(columnTitle) << endl;
        explainConversion(columnTitle);
        break;

    case 5:
    {
        cout << "\n=== TABLA DE CONVERSIÓN ===" << endl;
        cout << "Columna → Número" << endl;
        cout << "----------------" << endl;

        string examples[] = {"A", "B", "Z", "AA", "AB", "AZ", "BA", "ZZ", "AAA", "ZY", "FXSHRXW"};

        for (const string &ex : examples)
        {
            int num = sol.titleToNumber(ex);
            cout << ex << " → " << num;

            // Verificar conversión inversa
            string back = numberToTitle(num);
            if (back == ex)
            {
                cout << " ✓" << endl;
            }
            else
            {
                cout << " (verificación: " << back << ")" << endl;
            }
        }

        cout << "\n¿Convertir algún número a columna? (número, 0 para salir): ";
        int num;
        cin >> num;

        if (num > 0)
        {
            string col = numberToTitle(num);
            cout << "Número " << num << " → Columna " << col << endl;
        }
        break;
    }
    default:
        cout << "Opción inválida" << endl;
        return 1;
    }

    return 0;
}