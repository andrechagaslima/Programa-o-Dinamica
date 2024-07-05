#include "bruteForce.h"
#include <stdio.h>

     int max(int a, int b){
     if(a > b){
          return a;
     } else {
          return b;
     }
     }

     unsigned long int bruteForce(unsigned long int *vet, unsigned long int n, int i){
     if(i >= n){
          return 0;
     }

     int valor1 = bruteForce(vet, n, i+1);
     int valor2 = vet[i] + bruteForce(vet, n, i+2);

     return max(valor1, valor2);
     }

     // int bruteForce(int *vet, int n){
     //     if(n == 0){
     //         return 0;
     //     }
     //     if(n == 1){
     //         return vet[0];
     //     } else {
     //         int maior = 0;

     //         for(int i = 0; i < n; i++){
     //             int* vetCut = (int*)malloc((n - 2) * sizeof(int));
     //             int k = 0;

     //             for (int j = 0; j < n; j++) {
     //                 if (j != i && j != i-1 && j != i+1){
     //                     vetCut[k] = vet[j];
     //                     k++;
     //                 }
     //             }

     //             maior = max(maior, vet[i] + bruteForce(vetCut, k));

     //             free(vetCut);
     //         }

     //         return maior;
     //     }
     // }