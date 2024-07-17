#include <stdio.h>
#include "forcabruta.h"

long int solucao(long int *tabuleiro, long int n, int i){
     
     //Se ultrapassar o tamanho da sequência
     if(i >= n){
          return 0;
     }

     //Chamada recursiva que explora todos os elementos 
     long int valor1 = solucao(tabuleiro, n, i+1);
     //Chamada recursiva que explora as possibilidades de pontuação
     long int valor2 = tabuleiro[i] + solucao(tabuleiro, n, i+2);

     return max(valor1, valor2);
}

long int forcabruta(long int *tabuleiro, long int n){

     //Chama a função a partir do primeiro elemento da sequência
     long int resultado = solucao(tabuleiro, n, 0);

     return resultado;
}