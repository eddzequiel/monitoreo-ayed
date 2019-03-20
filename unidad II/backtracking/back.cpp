#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Constantes para el tamaño del tablero
#define n 8
#define TAM n *n

using namespace std;

// Prototipo de función
void mover(int tablero[][n], int marca, int posx, int posy);

// Posiciones
const int ejex[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int ejey[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// bandera para verificar que se completó
int flag;

int main(void)
{
    int tablero[n][n];
    // contadores para los bucles
    int i, j, marca = 2;

    // Inicializamos el tablero
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            tablero[i][j] = 0;
    }

    // Poner la primera marca
    tablero[0][0] = 1;

    // Se llama la función para aplicar backtracking
    mover(tablero, marca, 0, 0);

    // Si se pudo llenar el tablero, se imprime
    if (flag)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout << tablero[i][j] << "\t";

            cout << endl;
        }
    }
    else // sino...
        cout << "\nNo se encontró solución..." << endl;
}

void mover(int tablero[][n], int marca, int posx, int posy)
{
    // declaramos variables para hacer los movimientos
    int x, y, d;
    flag = 0;
    d = 0; // variable de desplazamiento

    do
    {
        // se asigna la posición actual
        x = posx + ejex[d];
        y = posy + ejey[d];

        if ((x >= 0 && x < n) && (y >= 0 && y < n)) // se validan los límites
        {
            if (tablero[x][y] == 0) // se verifica si está vacía
            {
                tablero[x][y] = marca; // asigna el valor para la casilla

                if (marca < TAM) // validamos que la marca sea correcta
                {
                    mover(tablero, marca + 1, x, y); // seguimos moviendo

                    if (!flag)
                        tablero[x][y] = 0; // se vacía para corregir el error
                }
                else
                    flag = 1; // listo
            }
        }
        d++;
    } while (!flag && d < 8);
}