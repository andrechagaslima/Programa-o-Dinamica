#include <stdio.h>
#include "forcabruta.h"

long int solucao(long int *tabuleiro, long int n, int i){
     
     if(i >= n){
          return 0;
     }

     long int valor1 = solucao(tabuleiro, n, i+1);
     long int valor2 = tabuleiro[i] + solucao(tabuleiro, n, i+2);

     return max(valor1, valor2);
}

long int forcabruta(long int *tabuleiro, long int n){

     long int resultado = solucao(tabuleiro, n, 0);

     return resultado;
}