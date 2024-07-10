#include <stdio.h>
#include <stdlib.h>
#include "solucaodinamica.h"

unsigned long int resolucao(long int *tabuleiro, unsigned long int n, int i, ValorCalculado *pontosArmazenados){
     
     if (i >= n) {
          return 0;
     }

     if (pontosArmazenados[i].calculado == true) {
          return pontosArmazenados[i].valor;
     }

     unsigned long int valor1 = resolucao(tabuleiro, n, i + 1, pontosArmazenados);
     unsigned long int valor2 = tabuleiro[i] + resolucao(tabuleiro, n, i + 2, pontosArmazenados);

     pontosArmazenados[i].valor = max(valor1, valor2);
     pontosArmazenados[i].calculado = true;

     return pontosArmazenados[i].valor;
}

unsigned long int solucaodinamica(long int *tabuleiro, unsigned long int n){
     
     ValorCalculado *pontosArmazenados = (ValorCalculado *)malloc((n) * sizeof(ValorCalculado));
     
     for (int i = 0; i < n; i++) {
          pontosArmazenados[i].valor = 0;
          pontosArmazenados[i].calculado = false;
     }

     unsigned long int resultado = resolucao(tabuleiro, n, 0, pontosArmazenados);

     free(pontosArmazenados);

     return resultado;
}