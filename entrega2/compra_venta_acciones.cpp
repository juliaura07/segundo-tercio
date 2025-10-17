#include <iostream>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int minPrice = INT_MAX;
        int maxProfit = 0;

        // Recorrer cada precio
        for (int price : prices)
        {
            // Actualizar el precio mínimo encontrado hasta ahora
            if (price < minPrice)
            {
                minPrice = price;
            }
            // Calcular ganancia si vendemos hoy
            else if (price - minPrice > maxProfit)
            {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};

// Función para imprimir el vector
void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}

// Función para analizar en detalle el proceso
void analyzeProfit(vector<int> &prices)
{
    if (prices.empty())
    {
        cout << "Array vacío, ganancia = 0" << endl;
        return;
    }

    int minPrice = INT_MAX;
    int maxProfit = 0;
    int buyDay = 0, sellDay = 0;
    int currentMinDay = 0;

    cout << "\nAnálisis día por día:" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < prices.size(); i++)
    {
        cout << "Día " << i + 1 << " (precio = " << prices[i] << "): ";

        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
            currentMinDay = i;
            cout << "Nuevo precio mínimo encontrado" << endl;
        }
        else
        {
            int profit = prices[i] - minPrice;
            cout << "Ganancia si vendemos hoy = " << profit;

            if (profit > maxProfit)
            {
                maxProfit = profit;
                buyDay = currentMinDay;
                sellDay = i;
                cout << " (¡Nueva ganancia máxima!)";
            }
            cout << endl;
        }
    }

    cout << "\n====================" << endl;
    if (maxProfit > 0)
    {
        cout << "Mejor estrategia:" << endl;
        cout << "  Comprar en día " << buyDay + 1 << " a precio " << prices[buyDay] << endl;
        cout << "  Vender en día " << sellDay + 1 << " a precio " << prices[sellDay] << endl;
        cout << "  Ganancia máxima = " << maxProfit << endl;
    }
    else
    {
        cout << "No hay oportunidad de ganancia (precios siempre bajando)" << endl;
        cout << "Ganancia máxima = 0" << endl;
    }
}

int main()
{
    Solution sol;

    cout << "=== CALCULADORA DE GANANCIA MÁXIMA EN ACCIONES ===" << endl;
    cout << "\nOpciones:" << endl;
    cout << "1. Ingresar precios manualmente" << endl;
    cout << "2. Usar Ejemplo 1: [7,1,5,3,6,4]" << endl;
    cout << "3. Usar Ejemplo 2: [7,6,4,3,1]" << endl;
    cout << "\nSeleccione una opción: ";

    int option;
    cin >> option;

    vector<int> prices;

    switch (option)
    {
    case 1:
    {
        cout << "\nIngrese la cantidad de días: ";
        int n;
        cin >> n;

        if (n < 1 || n > 100000)
        {
            cout << "Error: cantidad de días debe estar entre 1 y 100000" << endl;
            return 1;
        }

        cout << "Ingrese los precios separados por espacios: ";
        for (int i = 0; i < n; i++)
        {
            int price;
            cin >> price;

            if (price < 0 || price > 10000)
            {
                cout << "Error: precio debe estar entre 0 y 10000" << endl;
                return 1;
            }

            prices.push_back(price);
        }
        break;
    }
    case 2:
        prices = {7, 1, 5, 3, 6, 4};
        break;
    case 3:
        prices = {7, 6, 4, 3, 1};
        break;
    default:
        cout << "Opción inválida" << endl;
        return 1;
    }

    // Mostrar entrada
    cout << "\nPrecios: ";
    printVector(prices);
    cout << endl;

    // Calcular ganancia máxima
    int result = sol.maxProfit(prices);

    // Mostrar resultado simple
    cout << "\nGanancia máxima: " << result << endl;

    // Análisis detallado
    cout << "\n¿Desea ver el análisis detallado? (1=Sí, 0=No): ";
    int showAnalysis;
    cin >> showAnalysis;

    if (showAnalysis == 1)
    {
        analyzeProfit(prices);
    }

    return 0;
}