#include <stdio.h>
#include <stdlib.h>
#include "solucaodinamica.h"

long int resolucao(long int *tabuleiro, long int n, int i, ValorCalculado *pontosArmazenados){
     
     //Se ultrapassar o tamanho da sequência
     if (i >= n) {
          return 0;
     }

     //Verifica se a pontuação já foi calculada
     if (pontosArmazenados[i].calculado == true) {
          return pontosArmazenados[i].valor;
     }

     //Chamada recursiva que explora todos os elementos 
     long int valor1 = resolucao(tabuleiro, n, i + 1, pontosArmazenados);
     //Chamada recursiva que explora as possibilidades de pontuação
     long int valor2 = tabuleiro[i] + resolucao(tabuleiro, n, i + 2, pontosArmazenados);

     //Armazena a pontuação máxima calculada
     pontosArmazenados[i].valor = max(valor1, valor2);
     pontosArmazenados[i].calculado = true;

     return pontosArmazenados[i].valor;
}

long int solucaodinamica(long int *tabuleiro, long int n){
     
     ValorCalculado *pontosArmazenados = (ValorCalculado *)malloc((n) * sizeof(ValorCalculado));
     
     //Inicializa o armazenamento de pontuação
     for (int i = 0; i < n; i++) {
          pontosArmazenados[i].valor = 0;
          pontosArmazenados[i].calculado = false;
     }

     //Chama a função a partir do primeiro elemento da sequência
     long int resultado = resolucao(tabuleiro, n, 0, pontosArmazenados);

     free(pontosArmazenados);

     return resultado;
}