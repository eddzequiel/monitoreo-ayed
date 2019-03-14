#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    struct nodo *izqPtr;
    struct nodo *derPtr;
};

typedef struct nodo arbol;
typedef arbol *arbolPtr;

// prototipos
void insnodo(arbolPtr *, int);
void preorden(arbolPtr);
void inorden(arbolPtr);
void postorden(arbolPtr);

int main(void)
{
    int elem;
    arbolPtr raizPtr = NULL;

    cout << "\nElementos originales" << endl;

    for (int i = 0; i < 7; i++)
    {
        elem = rand() % 15;
        cout << elem << endl;
        insnodo(&raizPtr, elem);
    }

    cout << "\nLos elementos con el recorrido en preorden son: ";
    preorden(raizPtr);
    cout << "\nLos elementos con el recorrido en inorden son: ";
    inorden(raizPtr);
    cout << "\nLos elementos con el recorrido en postorden son: ";
    postorden(raizPtr);
    cout << endl;
}

void insnodo(arbolPtr *nodoPtr, int valor)
{
    if (*nodoPtr == NULL)
    {
        *nodoPtr = (arbol *)malloc(sizeof(arbol));
        if (*nodoPtr != NULL)
        {
            (*nodoPtr)->dato = valor;
            (*nodoPtr)->izqPtr = NULL;
            (*nodoPtr)->derPtr = NULL;
        }
        else
            cout << "\nElemento no insertado, error de memoria";
    }
    else
    {
        if (valor < (*nodoPtr)->dato)
            insnodo(&((*nodoPtr)->izqPtr), valor);
        else if (valor > (*nodoPtr)->dato)
            insnodo(&((*nodoPtr)->derPtr), valor);
        else
            cout << "\nValor duplicado, descartado\n";
    }
}

void preorden(arbolPtr nodoPtr)
{
    if (nodoPtr != NULL)
    {
        cout << "\t" << nodoPtr->dato;
        preorden(nodoPtr->izqPtr);
        preorden(nodoPtr->derPtr);
    }
}

void inorden(arbolPtr nodoPtr)
{
    if (nodoPtr != NULL)
    {
        inorden(nodoPtr->izqPtr);
        cout << "\t" << nodoPtr->dato;
        inorden(nodoPtr->derPtr);
    }
}

void postorden(arbolPtr nodoPtr)
{
    if (nodoPtr != NULL)
    {
        postorden(nodoPtr->izqPtr);
        postorden(nodoPtr->derPtr);
        cout << "\t" << nodoPtr->dato;
    }
}