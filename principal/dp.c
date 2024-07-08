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

unsigned long int solutionDP(unsigned long int *vet, int n, int i, unsigned long int *dp){
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    unsigned long int valor1 = solutionDP(vet, n, i + 1, dp);
    unsigned long int valor2 = vet[i] + solutionDP(vet, n, i + 2, dp);

    dp[i] = maxDP(valor1, valor2);

    return dp[i];
}

unsigned long int dynamic(unsigned long int *vet, int n){
    unsigned long int *dp = (unsigned long int *)malloc((n) * sizeof(unsigned long int));
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    unsigned long int result = solutionDP(vet, n, 0, dp);

    free(dp);

    return result;
}