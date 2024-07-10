#include <stdio.h>
#include <stdlib.h>
#include "solucaodinamica.h"

long int resolucao(long int *tabuleiro, long int n, int i, ValorCalculado *pontosArmazenados){
     
     if (i >= n) {
          return 0;
     }

     if (pontosArmazenados[i].calculado == true) {
          return pontosArmazenados[i].valor;
     }

     long int valor1 = resolucao(tabuleiro, n, i + 1, pontosArmazenados);
     long int valor2 = tabuleiro[i] + resolucao(tabuleiro, n, i + 2, pontosArmazenados);

     pontosArmazenados[i].valor = max(valor1, valor2);
     pontosArmazenados[i].calculado = true;

     return pontosArmazenados[i].valor;
}

long int solucaodinamica(long int *tabuleiro, long int n){
     
     ValorCalculado *pontosArmazenados = (ValorCalculado *)malloc((n) * sizeof(ValorCalculado));
     
     for (int i = 0; i < n; i++) {
          pontosArmazenados[i].valor = 0;
          pontosArmazenados[i].calculado = false;
     }

     long int resultado = resolucao(tabuleiro, n, 0, pontosArmazenados);

     free(pontosArmazenados);

     return resultado;
}