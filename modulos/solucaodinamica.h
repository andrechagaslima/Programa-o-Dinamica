#ifndef SOLUCAODINAMICA_H
#define SOLUCAODINAMICA_H
#include <stdbool.h>
#include "utilidades.h"

typedef struct ValorCalculado {    
    unsigned long int valor;       
    bool calculado;                
} ValorCalculado;

unsigned long int resolucao(long int *tabuleiro, unsigned long int n, int i, ValorCalculado *pontosArmazenados);

unsigned long int solucaodinamica(long int *tabuleiro, unsigned long int n);

#endif