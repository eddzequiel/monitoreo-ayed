#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

///Declaracion de la estructura
typedef struct registro
{
    int elemento;
    struct registro *nodoSiguiente;
} nodo;

///Declaracion de las funciones a implementar
nodo *nuevonodo (int info);
void agregarALista (nodo **primerNodo, int dato);
void imprimirLista(nodo *primerNodo);
void borrarDeLista(nodo **primerNodo, int dato);

///Proceso principal
int main(int argc, char** argv)
{
    nodo *primerNodo;
    int x;
    printf("¡Es momento de agregar valores a la lista!\n\n");
    primerNodo=NULL;
    do
    {
        printf("Ingrese el dato a agregar (-1= Terminar): \n");
        scanf("%d",&x);
        if (x!=-1)
            agregarALista(&primerNodo,x);
    } while(x!=-1);

    imprimirLista(primerNodo);

    do
    {
        printf("Ingrese el dato a borrar (-1= Terminar): \n");
        scanf("%d",&x);
        if(x!=-1)
            borrarDeLista(&primerNodo,x);
    } while(x!=-1);

    imprimirLista(primerNodo);

    return 0;
}

///Funcion que crea un nodo
void agregarALista(nodo **primerNodo, int dato)
{
    nodo *nuevo;
    nuevo=nuevonodo(dato);
    if (*primerNodo==NULL)
        *primerNodo=nuevo;
    else
    {
        nuevo->nodoSiguiente=*primerNodo;
        *primerNodo=nuevo;
    }
    return;
}

nodo *nuevonodo (int info)
{
    nodo *n;
    n=(nodo*)malloc(sizeof(nodo));
    n->nodoSiguiente=NULL;
    n->elemento=info;
    return n;
}

///Funcion que borra los nodos
void borrarDeLista(nodo **primerNodo, int dato)
{
    nodo *nodoAnterior, *nodoActual;
    int encontrado=0;
    nodoAnterior=NULL;
    nodoActual=*primerNodo;

    while((nodoActual!=NULL) && (!encontrado))
    {
        encontrado=(nodoActual->elemento==dato);
        if (!encontrado)
        {
            nodoAnterior=nodoActual;
            nodoActual=nodoActual->nodoSiguiente;
        }
    }

    if(nodoActual!=NULL)
        if(nodoActual==*primerNodo)
            *primerNodo=nodoActual->nodoSiguiente;
        else
            nodoAnterior->nodoSiguiente=nodoActual->nodoSiguiente;

    free(nodoActual);

    return;
}

///Funcion que imprime los nodos
void imprimirLista (nodo *primerNodo)
{
    printf("\n\n");

    printf("La lista actual es:");
    while(primerNodo!=NULL)
    {
        printf("\t%d", primerNodo->elemento);
        primerNodo=(primerNodo->nodoSiguiente);
    }
    printf("\n\n");

    return;
}

