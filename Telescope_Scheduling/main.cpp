#include <iostream>

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

void orderByPriory(int stars[][3], int n)
{
    int aux[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            //if (stars[j][1] > stars[j + 1][1])
            if (stars[j][2] < stars[j + 1][2])
            {
                copyCad(aux, stars, j, j);
                copyCad(stars, stars, j, j + 1);
                copyCad(stars, aux, j + 1, j);
            }
        }
    }
}

void orderByInput(int stars[][3], int n, int s, int f)
{
    int aux[n][3];
    for (int i = s; i < f; i++)
    {
        for (int j = s; j < f - 1; j++)
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

void orderFinal(int stars[][3], int n, int priStars[], int tamPriory)
{
    int aux = 0;
    for (int i = 0; i < tamPriory; i++)
    {
        orderByInput(stars, n, aux, priStars[i] + 1);
        aux = priStars[i] + 1;
    }
}

int contPriory(int stars[][3], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (stars[i][2] != stars[i + 1][2])
            res++;
    }
    return res;
}

void posStars(int stars[][3], int n, int priStars[])
{
    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        if (stars[i][2] != stars[i + 1][2])
        {
            priStars[aux] = i;
            aux++;
        }
    }
}

int tamCad(int matrix[][3], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (matrix[i][2] != 0)
            res++;
    return res;
}

int prosess(int stars[][3], int n, int index)
{
    int res = 0;
    int cont = 0;
    int sol[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            sol[i][j] = 0;
    }
    copyCad(sol, stars, 0, 0);
    int tamSol = tamCad(sol, n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tamSol; j++)
        {
            if (stars[i][0] > sol[j][1])
            {
                if (sol[j + 1][0] == 0)
                {
                    copyCad(sol, stars, j + 1, i);
                    cont++;
                    break;
                }
                else if (stars[i][1] < sol[j + 1][0])
                {
                    for (int k = j + 1; k < tamCad(sol, n); k++)
                    {
                        copyCad(sol, sol, k + 1, k);
                    }
                    copyCad(sol, stars, j + 1, i);
                    cont++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i <= cont; i++)
        res += sol[i][2];
    return res;
}

/*
int prosess(int stars[][3], int n, int index)
{
    int res = stars[index][2];
    for (int i = index; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stars[i][1] < stars[j][0])
            {
                res += stars[j][2];
                i = j - 1;
                break;
            }
            if (j == n - 1)
                i = n;
        }
    }
    return res;
}
*/

int main(void)
{
    int n;
    cin >> n;
    int stars[n][3];

    for (int i = 0; i < n; i++)
    {
        cin >> stars[i][0] >> stars[i][1] >> stars[i][2];
    }

    orderByPriory(stars, n);

    int tamPriory = contPriory(stars, n);
    int priStars[tamPriory];
    posStars(stars, n, priStars);
    orderFinal(stars, n, priStars, tamPriory);

    cout << prosess(stars, n, tamPriory);

    /*
    orderByPriory(stars, n);    
    int sol[n];

    for (int i = 0; i < n; i++)
    {
        sol[i] = prosess(stars, n, i);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (sol[i] > res)
            res = sol[i];
    }
    cout << res;
*/
    return 0;
}
