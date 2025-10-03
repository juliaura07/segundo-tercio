#include <iostream>

using namespace std;

class Solution
{
public:
    // Solución sin convertir a string
    bool isPalindrome(int x)
    {
        // Los números negativos no son palíndromos
        // Los números que terminan en 0 no son palíndromos (excepto el 0)
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        // Revertimos la mitad del número
        int revertedHalf = 0;
        while (x > revertedHalf)
        {
            revertedHalf = revertedHalf * 10 + x % 10;
            x /= 10;
        }

        // Para números con cantidad par de dígitos: x == revertedHalf
        // Para números con cantidad impar de dígitos: x == revertedHalf/10
        return x == revertedHalf || x == revertedHalf / 10;
    }
};

// Función para probar la solución
int main()
{
    Solution sol;

    // Ejemplo 1
    int x1 = 121;
    cout << "Ejemplo 1: " << x1 << " es palindromo? "
         << (sol.isPalindrome(x1) ? "true" : "false") << endl;

    // Ejemplo 2
    int x2 = -121;
    cout << "Ejemplo 2: " << x2 << " es palindromo? "
         << (sol.isPalindrome(x2) ? "true" : "false") << endl;

    // Ejemplo 3
    int x3 = 10;
    cout << "Ejemplo 3: " << x3 << " es palindromo? "
         << (sol.isPalindrome(x3) ? "true" : "false") << endl;

    // Pruebas adicionales
    int x4 = 12321;
    cout << "Prueba adicional: " << x4 << " es palindromo? "
         << (sol.isPalindrome(x4) ? "true" : "false") << endl;

    return 0;
}