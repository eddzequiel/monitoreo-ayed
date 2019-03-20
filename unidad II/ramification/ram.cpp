#include <iostream>
#include <stdlib.h>

#define N 8

using namespace std;

void inicio();
bool colocarReina(int tablero[N][N], int fila, int columna);
bool comprobar(int tablero[N][N], int columna);
void imprimir(int tablero[N][N]);

int main(void)
{
    inicio();
}

void inicio()
{
    int tablero[N][N] = {0};

    if (comprobar(tablero, 0) == false)
        cout << "\nNo se encontró la solución" << endl;
    else
        imprimir(tablero);
}

bool colocarReina(int tablero[N][N], int fila, int columna)
{
    int i, j;

    // si se mueve hacia la derecha
    for (i = 0; i < columna; i++)
        if (tablero[fila][i])
            return false;

    // si se mueve en diagonal ascendente
    for (i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j])
            return false;

    // si se mueve en diagonal descendente
    for (i = fila, j = columna; i < N && j >= 0; i++, j--)
        if (tablero[i][j])
            return false;

    // sino
    return true;
}

bool comprobar(int tablero[N][N], int columna)
{
    if (columna >= N) // las 8 reinas fueron ubicadas
        return true;

    for (int i = 0; i < N; i++)
    {
        if (colocarReina(tablero, i, columna))
        {
            tablero[i][columna] = 1; // se coloca la reina

            if (comprobar(tablero, columna + 1) == true)
                return true; // se siguen ubicando las reinas
            else
                tablero[i][columna] = 0; // se hace el backtracking
        }
    }

    return false;
}

void imprimir(int tablero[N][N])
{
    cout << "\nResultado de la matriz de solución de las 8 reinas\n"
         << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}