#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define TAM 9

using namespace std;

int main(void)
{
    int candidatos[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};
    int solucion[TAM];
    int valorEntregado, totalCompra, vuelto, i;

    cout << "\nDinero con el que paga: ";
    cin >> valorEntregado;

    cout << "\nTotal de la compra: ";
    cin >> totalCompra;

    vuelto = valorEntregado - totalCompra;

    if (vuelto <= 0)
        cout << "\nNo hay vuelto" << endl;

    for (i = 0; i < TAM; i++)
        solucion[i] = 0;

    for (i = 0; i < TAM; i++)
        while (vuelto >= candidatos[i])
        {
            solucion[i]++;
            vuelto -= candidatos[i];
        }

    cout << "\nSe le regresa... " << endl;

    for (i = 0; i < TAM; i++)
        if (solucion[i])
            cout << endl
                 << solucion[i] << " billetes/monedas de " << candidatos[i] << endl;
}