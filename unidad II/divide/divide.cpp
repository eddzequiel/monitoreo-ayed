#include <iostream>

using namespace std;

int potencia(int base, int exponente);

int main(void)
{
    int base, exponente;
    long int resultado;

    cout << "\nResultado de elevar un número a determinada potencia";
    cout << "\nIngrese la base... ";
    cin >> base;

    cout << "Ingrese el exponente... ";
    cin >> exponente;

    resultado = potencia(base, exponente);

    cout << "\nEl resultado de elevar la base " << base << " al exponente " << exponente << " es " << resultado;
}

int potencia(int base, int exponente)
{
    switch (exponente)
    {
    case 0:
        return 1;
        break;
    case 1:
        return base;
        break;
    case 2:
        return (base * base);
        break;
    default:

        int resultado = base;

        for (int i = 0; i < exponente - 1; i++)
        {
            resultado = resultado * base;
        }
        return resultado;
    }
}