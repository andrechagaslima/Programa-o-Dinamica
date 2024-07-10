#ifndef DP_H
#define DP_H
#include <stdbool.h>

typedef struct ArrayAuxiliar {
    unsigned long int valor;
    bool calculado;
} ArrayAuxiliar;

int maxDP(int a, int b);

unsigned long int solutionDP(unsigned long int *vet, int n, int i, ArrayAuxiliar *dp);

unsigned long int dynamic(unsigned long int *vet, int n);

#endif