#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        if (numRows == 0)
            return triangle;

        // Primera fila siempre es [1]
        triangle.push_back({1});

        // Generar las filas restantes
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row;
            vector<int> prevRow = triangle[i - 1];

            // Primera posición siempre es 1
            row.push_back(1);

            // Calcular valores intermedios
            for (int j = 1; j < i; j++)
            {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }

            // Última posición siempre es 1
            row.push_back(1);

            triangle.push_back(row);
        }

        return triangle;
    }
};

// Función para imprimir el triángulo
void printTriangle(const vector<vector<int>> &triangle)
{
    cout << "[";
    for (int i = 0; i < triangle.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j];
            if (j < triangle[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < triangle.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sol;
    int numRows;

    cout << "Ingrese el número de filas del triángulo de Pascal: ";
    cin >> numRows;

    // Validar entrada
    if (numRows < 1 || numRows > 30)
    {
        cout << "Error: numRows debe estar entre 1 y 30" << endl;
        return 1;
    }

    // Generar el triángulo
    vector<vector<int>> result = sol.generate(numRows);

    // Imprimir resultado
    cout << "\nTriángulo de Pascal con " << numRows << " filas:" << endl;
    printTriangle(result);

    // Visualización alternativa (más legible)
    cout << "\nVisualización:" << endl;
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}