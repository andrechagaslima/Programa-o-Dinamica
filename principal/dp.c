#include <stdio.h>
#include <stdlib.h>
#include "dp.h"

int maxDP(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

unsigned long int solutionDP(unsigned long int *vet, int n, int i, ArrayAuxiliar *dp){
    if (i >= n) {
        return 0;
    }

    if (dp[i].calculado != false) {
        return dp[i].valor;
    }

    unsigned long int valor1 = solutionDP(vet, n, i + 1, dp);
    unsigned long int valor2 = vet[i] + solutionDP(vet, n, i + 2, dp);

     dp[i].valor = maxDP(valor1, valor2);
     dp[i].calculado = true;
    return dp[i].valor;
}

unsigned long int dynamic(unsigned long int *vet, int n){
    ArrayAuxiliar *dp = (ArrayAuxiliar *)malloc((n) * sizeof(ArrayAuxiliar));
    for (int i = 0; i < n; i++) {
        dp[i].calculado = false;
    }

    unsigned long int result = solutionDP(vet, n, 0, dp);

    free(dp);

    return result;
}