#include <iostream>

using namespace std;


struct nodo {
	int dato;
	struct nodo * siguiente;
};


void pausa()
{
    getchar();
}


nodo *cabeza = NULL;


// Devolviendo el puntero al elemento
// cuyo dato es menor o igual al dato de entrada
struct nodo *nodoBase(int n) { //Busca la estructura en memoria
	if(cabeza == NULL) return cabeza;
	nodo *actual = cabeza;
	nodo *anterior = cabeza;
	while(actual) {
		if(actual->dato == n) return actual;
		if(actual->dato > n) return anterior;
		anterior = actual;
		actual = actual->siguiente;
	}
}


// Devolviendo el puntero al elemento
// cuyo dato es igual al dato de entrada
struct nodo *nodoBase2(int n) {
	if(cabeza == NULL) return cabeza;
	nodo *actual = cabeza;
	nodo *anterior = cabeza;
	while(actual) {
		if(actual->dato == n) return actual;
		anterior = actual;
		actual = actual->siguiente;
	}
	return actual;
}


void agregarNodo(int n) {
	nodo *nuevoNodo = new nodo;
	nuevoNodo->dato = n;
	nuevoNodo->siguiente = NULL;

	if(cabeza == NULL) {
		cabeza = nuevoNodo;
		return;
	}
	nodo *actual = cabeza;
	while(actual) {
		if(actual->siguiente == NULL) {
			actual->siguiente = nuevoNodo;
			return;
		}
		actual = actual->siguiente;
	}
}


void eliminarNodo(int n) {
	nodo *puntero = nodoBase(n);
	if(puntero == NULL) 
		cout << "No existe el nodo con el valor = " << n << 
endl;
	if(puntero == cabeza) {
		cabeza = puntero->siguiente;
		return;
	}
	nodo *actual = cabeza;
	nodo *anterior = cabeza;

	while(actual) {
		if(actual == puntero) {
			anterior->siguiente = actual->siguiente;
			return;
		}
		anterior = actual;
		actual = actual->siguiente;
	}
}


void imprimir() {
	struct nodo *list = cabeza;
	while(list) {
		cout << list->dato <<" ";
		list = list->siguiente;
	}
	cout << endl;
}


int main()
{
    cout<<"\n--------------------------------------------------\n";
	cout<<"-------------------Agregando nodo-------------------\n";
	cout<<"\n--------------------------------------------------\n";
	agregarNodo(10);
    imprimir();
    pausa();
    
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------------Agregando nodo-------------------\n";
	cout<<"\n--------------------------------------------------\n";
	agregarNodo(20);
	imprimir();
	pausa();
	
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------------Agregando nodo-------------------\n";
	cout<<"\n--------------------------------------------------\n";
	agregarNodo(30);
	imprimir();
	pausa();
	
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------------Agregando nodo-------------------\n";
	cout<<"\n--------------------------------------------------\n";
	agregarNodo(40);
	imprimir();
	pausa();
	
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------Eliminando nodo seleccionado-------------\n";
	cout<<"\n--------------------------------------------------\n";
	eliminarNodo(50);
	imprimir();
	pausa();
	
	return 0;
}
