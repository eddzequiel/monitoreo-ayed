#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 5

using namespace std;

struct tcola
{
    int array[N];
    int front, rear;
};

int main(void)
{
    struct tcola cola;
    int elem, n, i;

    cola.rear = elem = 0;

    cout << "\nIngrese la cantidad de elementos a encolar... ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (cola.rear == n)
        {
            cout << "\nLa cola está llena" << endl;
        }
        else
        {
            cout << "\nIngrese el elemento " << i + 1 << "... ";
            cin >> elem;

            cola.array[cola.rear] = elem;
            cola.rear++;
        }
    }

    cout << "\nIngrese la cantidad de elementos a desencolar... ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (cola.front >= cola.rear)
        {
            cout << "\nLa cola está vacía" << endl;
        }
        else
        {
            elem = cola.array[cola.front];
            cola.front++;
            cout << "\nSe ha removido un elemento (" << elem << ")." << endl;
        }
    }
}