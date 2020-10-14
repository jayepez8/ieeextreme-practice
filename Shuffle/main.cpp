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
    int **values=createMatrix(n);
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
    printMatrix(values, n);
    int resFinal = 0;
    int k=0;
        for(int i=k;i<n;i++){
        bool van=false;
            for(int j=0;j<n;j++){
                if(values[i][j]==1){
                    temp[j]=1;
                    van=true;
                    k=i;
                    i=k;
                }                  
            }
    }
    //cout<<resFinal<<endl;
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

int *createVector(int n){
    int *vector = new int [n];
    for(int i=0;i<n;i++)
        vector[i]=0;
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

