#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
    string arreglo[50];
    int i, notas[5];

    cout << "\nIngrese los 5 estudiantes:" << endl;

    for (i = 0; i < 5; i++)
    {
        /* 
            Al momento de ingresar data, sólo ingresa 1 nombre
            o cambia el cin de tal manera que lea toda la línea
        */
        cout << "\nNombre del estudiante #" << i + 1 << ": ";
        fflush(stdout);
        cin >> arreglo[i];
        fflush(stdin);
        cout << "Ingrese la nota de " << arreglo[i] << ": ";
        fflush(stdout);
        cin >> notas[i];
        fflush(stdin);
        fflush(stdout);
    }

    for (i = 0; i < 5; i++)
    {
        cout << "\n\nEl estudiante " << i + 1 << " es " << arreglo[i] << "." << endl;
        cout << "Su nota es de " << notas[i] << "." << endl;
    }

    getchar();
}