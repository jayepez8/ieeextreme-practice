#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    n = n + 1;
    m = m + 1;
    int matrix[n][m];
    int p[n + 1];
    int b[n + 1];
    p[0] = 0;
    b[0] = 0;
    for (int i = 1; i < n; i++)
        cin >> p[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        matrix[0][i] = 0;
        if (i < n)
            matrix[i][0] = 0;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 1; j <= m - 1; ++j)
        {
            if (j - p[i] < 0)
                matrix[i][j] = matrix[i - 1][j];
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - p[i]] + b[i]);
        }
    }
    cout << endl;
    int may = -1, V = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
            if (matrix[i][j] > may)
            {
                may = matrix[i][j];
                V = matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "El mayor beneficio es: " << V << endl;
}