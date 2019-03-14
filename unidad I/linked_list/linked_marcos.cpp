#include <iostream>

using namespace std;

typedef struct registro
{
    int elem;
    struct registro *sig;
} nodo;

nodo *nuevonodo(int elemento);
void agregar(nodo **primero, int dato);
void borrar(nodo **primero, int dato);
void imprimir(nodo *primero);

int main()
{
    int elemento;
    nodo *primero;
    primero = NULL;

    cout << "\t\t Elementos de la lista enlazada...." << endl;

    do
    {
        cout << "Introduzca el elemento de la lista (-1 = fin)" << endl;
        cin >> elemento;

        if (elemento != -1)
        {
            agregar(&primero, elemento);
        }

    } while (elemento != -1);

    imprimir(primero);

    do
    {
        cout << "Introduzca el elemento a borrar -1=fin" << endl;
        cin >> elemento;

        if (elemento != -1)
        {
            borrar(&primero, elemento);
        }

    } while (elemento != -1);

    imprimir(primero);

    return 0;
}

nodo *nuevonodo(int elemento)
{
    nodo *n;
    n = (nodo *)malloc(sizeof(nodo));
    n->sig = NULL;
    n->elem = elemento;
    return n;
}

void agregar(nodo **primero, int elemento)
{
    nodo *nuevo;
    nuevo = nuevonodo(elemento);

    if (*primero == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        nuevo->sig = *primero;
        *primero = nuevo;
    }
}

void imprimir(nodo *primero)
{
    cout << "Los elementos de la lista son" << endl;
    while (primero != NULL)
    {
        cout << "\n\t" << primero->elem << "\t";
        primero = primero->sig;
    }

    return;
}

void borrar(nodo **primero, int x)
{
    nodo *anterior, *actual;
    int encontrado = 0;

    anterior = NULL;
    actual = *primero;

    while ((actual != NULL) && (!encontrado))
    {

        encontrado = (actual->elem == x);
        if (!encontrado)
        {
            anterior = actual;
            actual = actual->sig;
        }
    }
    if (actual != NULL)
    {
        if (actual == *primero)
        {
            *primero = actual->sig;
        }
    }
    else
    {
        anterior->sig = actual->sig;
    }

    free(actual);
    return;
}