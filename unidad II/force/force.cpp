#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#define TAM 5000

using namespace std;

void fuerzabruta(char cad[TAM], char subcad[TAM], int lcad, int lsubcad);

int main(void)
{
    int lcad, lsubcad;
    char cad[TAM], subcad[TAM];
    float inicio, fin, tiempo;

    cout << "\nBúsqueda de un patrón de cadena dentro de un texto" << endl;

    cout << "\nIngrese el texto de la cadena" << endl;
    gets(cad);
    cout << "\nIngrese el texto de la subcadena" << endl;
    gets(subcad);

    lcad = strlen(cad);
    lsubcad = strlen(subcad);

    cout << "\nLa longitud de la cadena \"cad\" es: " << lcad;
    cout << "\nLa longitud de la subcadena \"subcad\" es: " << lsubcad;

    inicio = clock();

    fuerzabruta(cad, subcad, lcad, lsubcad);

    fin = clock();
    tiempo = fin - inicio;

    cout << "\nEl tiempo de ejecución de fuerzabruta() es: " << (double)tiempo / ((double)CLOCKS_PER_SEC) << " ms";
}

void fuerzabruta(char cad[TAM], char subcad[TAM], int lcad, int lsubcad)
{
    int i, j, k, flag = 0;

    for (i = 0; i <= lcad - lsubcad; i++)
    {
        j = 0;
        k = i;

        while ((subcad[j] == cad[k]) && (j <= lsubcad))
        {
            j++;
            k++;
        }

        if (j > lsubcad - 1)
        {
            cout << "\nEl patrón de cadena fue encontrado en la posición " << i + 1 << endl;
            flag = 1;
        }
        else
            flag = 0;
    }

    if (flag == 0)
    {
        cout << "\nPatrón de cadena no encontrado" << endl;
    }
}