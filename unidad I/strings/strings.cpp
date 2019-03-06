#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
    char cad1[15], cad2[5], cad3[30], cad4[50], espacio[2] = " ";
    char num1[10] = "99.99";
    char *p;

    cout << "\nIngrese la cadena cad1: " << endl;
    cin >> cad1;
    cout << "\nIngrese la cadena cad2: " << endl;
    cin >> cad2;
    cout << "\nIngrese la cadena cad3: " << endl;
    cin >> cad3;

    cout << "\nLa longitud de cad1 es: " << strlen(cad1) << endl;
    cout << "\nLa longitud de cad2 es: " << strlen(cad2) << endl;
    cout << "\nLa longitud de cad3 es: " << strlen(cad3) << endl;

    strcpy(cad4, cad1);
    strcat(cad4, espacio);
    strcat(cad4, cad2);
    strcat(cad4, espacio);
    strcat(cad4, cad3);
    strcat(cad4, espacio);

    cout << "\nEl contenido de la cadena 4 es: " << cad4 << endl;

    if (strcmp(cad1, cad3) > 0)
    {
        cout << "\nLa cadena cad1 es mayor que la cad3" << endl;
    }
    else if (strcmp(cad1, cad3) < 0)
    {
        cout << "\nLa cadena cad1 es menor que cad3" << endl;
    }
    else
        cout << "\nLa cadena cad1 es igual a cad3" << endl;

    p = strstr(cad4, cad3);

    if (p)
    {
        cout << "\nLa subcadena " << cad3 << " se encontró en la cad4." << endl;
    }
    else
        cout << "\nLa subcadena " << cad3 << " se no encontró en la cad4." << endl;

    cout << "\nLa cadena de num1 es: " << num1 << endl;
    cout << "\nLa cadena num1 convertida a entero es " << atoi(num1) << endl;
    cout << "\nLa cadena num1 convertida a flotante es " << atof(num1) << endl;

    getchar();
}