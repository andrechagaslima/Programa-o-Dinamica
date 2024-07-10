#ifndef SOLUCAODINAMICA_H
#define SOLUCAODINAMICA_H
#include <stdbool.h>
#include "utilidades.h"

typedef struct ValorCalculado {    
     long int valor;       
     bool calculado;                
} ValorCalculado;

long int resolucao(long int *tabuleiro, long int n, int i, ValorCalculado *pontosArmazenados);

long int solucaodinamica(long int *tabuleiro, long int n);

#endif