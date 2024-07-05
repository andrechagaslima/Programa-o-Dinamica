#include <stdio.h>
#include <stdlib.h>
#include "dp.h"

int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

unsigned long int solution(unsigned long int *vet, int n, int i, unsigned long int *dp){
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    unsigned long int valor1 = solution(vet, n, i + 1, dp);
    unsigned long int valor2 = vet[i] + solution(vet, n, i + 2, dp);

    dp[i] = max(valor1, valor2);

    return dp[i];
}

unsigned long int dynamic(unsigned long int *vet, int n){
    unsigned long int *dp = (unsigned long int *)malloc((n + 1) * sizeof(unsigned long int));
    for (int i = 0; i < n + 1; i++) {
        dp[i] = -1;
    }

    unsigned long int result = solution(vet, n, 0, dp);

    free(dp);

    return result;
}