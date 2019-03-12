#include <stdlib.h>
#include<stdio.h>

int factorial(int);

int main()
{
  int n;
  long f;

  printf("Ingrese el entero\n"); //Se obtendra el valor al que se le encontrara el factorial
  scanf("%d", &n);

  if (n < 0)
    printf("Los enteros negativos no estan permitidos.\n"); //Debido a que el factorial de un numero negativo no esta determinado
  else
  {
    f = factorial(n); //Manda a llamar al subproceso factorial mandando como argumento el valor ingresado
    printf("El factorial de %d es =  %ld\n", n, f); //Se muestra la respuesta hasta el final de la recursividad de todo el programa
  }

  return 0;
}

int factorial(int n)
{
  if (n == 0)
    return 1; //El factorial de 0 siempre sera 1 paso
  else
    return(n * factorial(n-1)); //Proceso de calculo del factorial.
}
