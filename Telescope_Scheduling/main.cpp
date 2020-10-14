#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(int stars[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << stars[i][j] << " ";
        cout << endl;
    }
}

void copyCad(int a[][3], int b[][3], int p1, int p2)
{
    for (int i = 0; i < 3; i++)
    {
        a[p1][i] = b[p2][i];
    }
}

void orderByEntry(int stars[][3], int n)
{
    int aux[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (stars[j][0] > stars[j + 1][0])
            {
                copyCad(aux, stars, j, j);
                copyCad(stars, stars, j, j + 1);
                copyCad(stars, aux, j + 1, j);
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    int stars[n][3];

    for (int i = 0; i < n; i++)
    {
        cin >> stars[i][0] >> stars[i][1] >> stars[i][2];
    }

    orderByEntry(stars, n);
    int res = stars[0][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stars[i][1] < stars[j][0])
            {
                res += stars[i][2];
                i = j;
            }
        }
    }
    cout << res;

    return 0;
}
