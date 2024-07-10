#ifndef SOLUCAODINAMICA_H
#define SOLUCAODINAMICA_H
#include <stdbool.h>
#include "utilidades.h"

typedef struct ValorCalculado {    
    unsigned long int valor;       
    bool calculado;                
} ValorCalculado;

unsigned long int resolucao(unsigned long int *tabuleiro, unsigned long int n, int i, ValorCalculado *pontosArmazenados);

unsigned long int solucaodinamica(unsigned long int *tabuleiro, unsigned long int n);

#endif