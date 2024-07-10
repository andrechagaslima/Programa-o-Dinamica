#include <stdio.h>
#include "forcabruta.h"

unsigned long int solucao(unsigned long int *tabuleiro, unsigned long int n, int i){
     
     if(i >= n){
          return 0;
     }

     int valor1 = solucao(tabuleiro, n, i+1);
     int valor2 = tabuleiro[i] + solucao(tabuleiro, n, i+2);

     return max(valor1, valor2);
}

unsigned long int forcabruta(unsigned long int *tabuleiro, unsigned long int n){

     unsigned long int resultado = solucao(tabuleiro, n, 0);

     return resultado;
}