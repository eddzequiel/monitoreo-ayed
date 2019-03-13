#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

///Declaracion de la estructura
typedef struct registro
{
    int elem;
    struct registro *sig;
} nodo;

///Declaracion de las funciones a implementar
nodo *nuevonodo (int info);
void agregar (nodo **primero, int dato);
void imprimir(nodo *primero);
void borrar(nodo **primero, int dato);

///Proceso principal
int main(int argc, char** argv)
{
    int x;
    nodo *primero;
    primero=NULL;
    printf("Es momento de agregar valores a la lista :\n\n");
    do
    {
        printf("Ingrese el dato a agregar (-1= Terminar): \n");
        scanf("%d",&x);
        if (x!=-1)
            agregar(&primero,x);
    } while(x!=-1);

    imprimir(primero);

    do
    {
        printf("Ingrese el dato a borrar (-1= Terminar): \n");
        scanf("%d",&x);
        if(x!=-1)
            borrar(&primero,x);
    } while(x!=-1);

    imprimir(primero);

    return 0;
}

///Funcion que crea un nodo
void agregar(nodo **primero, int dato)
{
    nodo *nuevo;
    nuevo=nuevonodo(dato);
    if (*primero==NULL)
        *primero=nuevo;
    else
    {
        nuevo->sig=*primero;
        *primero=nuevo;
    }
    return;
}

nodo *nuevonodo (int info)
{
    nodo *n;
    n=(nodo*)malloc(sizeof(nodo));
    n->sig=NULL;
    n->elem=info;
    return n;
}

///Funcion que borra los nodos
void borrar(nodo **primero, int dato)
{
    nodo *anterior, *actual;
    int encontrado=0;
    anterior=NULL;
    actual=*primero;

    while((actual!=NULL) && (!encontrado))
    {
        encontrado=(actual->elem=dato);
        if (!encontrado)
        {
            anterior=actual;
            actual=actual->sig;
        }
    }
    if(actual!=NULL)
        if(actual==*primero)
            *primero=actual->sig;
        else
            anterior->sig=actual->sig;

    free(actual);

    return;
}

///Funcion que imprime los nodos
void imprimir (nodo *primero)
{
    printf("\n\n");

    printf("La lista actual es:");
    while(primero!=NULL)
    {
        printf("\t%d", primero->elem);
        primero=(primero->sig);
    }
    printf("\n\n");

    return;
}

