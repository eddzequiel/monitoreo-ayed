#include <iostream>
#include <stdlib.h>
#define N 100

using namespace std;

void primo(int n, int tabla[N]);

int tabla[N];

int main(void)
{
    int n;

    cout << "\nIngrese la cantidad de elementos a evaluar... ";
    cin >> n;

    primo(n, tabla);

    for (int i = 1; i < n; i++)
        cout << tabla[i] << "\t";

    cout << endl;
}

void primo(int n, int tabla[N])
{
    int i, j, nprimos = 1;

    for (i = 2; i <= n; i++)
    {
        j = 1;

        while ((j < nprimos) && (i % tabla[j] != 0))
            j++;

        if (j == nprimos)
        {
            tabla[nprimos] = i;
            nprimos++;
        }
    }
}