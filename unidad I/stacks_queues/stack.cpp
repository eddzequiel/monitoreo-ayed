/*
    Nota: este ejemplo específico de stack/pila
    es sin la implementación de punteros.

    Sirve únicamente para observar el 
    comportamiento de la pila.
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 5

using namespace std;

struct tpila
{
    int arreglo[N];
    int cima;
};

int main(void)
{
    struct tpila pila;
    int elem, n, i;

    pila.cima = -1;

    cout << "\nIngrese la cantidad de elementos a apilar... ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (pila.cima == n)
        {
            cout << "\nLa pila está llena" << endl;
        }
        else
        {
            cout << "\nIngrese el elemento " << i + 1 << "... ";
            cin >> elem;

            pila.cima++;
            pila.arreglo[pila.cima] = elem;
        }
    }

    cout << "\nIngrese la cantidad de elementos a desapilar... ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (pila.cima == -1)
        {
            cout << "\nLa pila está vacía" << endl;
        }
        else
        {
            elem = pila.arreglo[pila.cima];
            pila.cima--;
            cout << "\nSe ha removido un elemento (" << elem << ")." << endl;
        }
    }
}