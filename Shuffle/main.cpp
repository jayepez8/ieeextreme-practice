#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

void printMatrix(int **, int);
int **createMatrix(int);
int *createVector(int);

int main(int argc, char const *argv[])
{
    int n;
    char aux;
    cin >> n >> ws;
    int **values = createMatrix(n);
    int *temp = createVector(n);

    for (int i = 0; i < n; i++)
    {
        values[i][i] = 0;
        string line;
        getline(cin, line);
        istringstream iss(line);
        int number;
        while (iss >> number)
        {
            values[i][number] = 0;
        }
    }
    int pos = 0;
    int cont = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i][j] == 0)
                cont++;
            else
                pos = j;
        }
        if (cont == n - 1)
        {
            for (int j = 0; j < n; j++)
                values[j][pos] = 0;

            if (temp[pos] == 0)
            {
                temp[pos] = 1;
            }
            i = 0;
            cont = 0;
        }
        else
        {
            cont = 0;
        }
    }
    cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[j][i] == 0)
                cont++;
            else
                pos = j;
        }
        if (cont == n - 1)
        {
            for (int j = 0; j < n; j++)
                values[pos][j] = 0;

            if (temp[i] == 0)
            {
                temp[i] = 1;
            }
            i = 0;
            cont = 0;
        }
        else
        {
            cont = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[j][i] == 0)
                cont++;
        }
        if (cont == n && temp[i] == 0)
        {
            res++;
        }

        cont = 0;
    }
    cout << res << endl;
    return 0;
}

int **createMatrix(int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 1;
        }
    }
    return matrix;
}

int *createVector(int n)
{
    int *vector = new int[n];
    for (int i = 0; i < n; i++)
        vector[i] = 0;
    return vector;
}

void printMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}