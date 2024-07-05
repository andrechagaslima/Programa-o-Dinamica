#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "leitura.h"
#include "bruteForce.h"
#include <string.h>

int main(int argc, char *argv[]) {
    
   char *estrategia = NULL;
   char *inputFile = NULL;
   char *outputFile = "saida.txt";
   struct rusage start, end; //Usados para calcular o tempo (getrusage)
   struct timeval inicio, fim; //Usados para calcular o tempo (gettimeofday)

   estrategia = argv[1];
   inputFile = argv[2];

   verificacaoArquivoEntrada(argv, inputFile, estrategia);

   // Abrir o arquivo de entrada
   FILE *arquivo = fopen(inputFile, "r");
   testaAberturaArquivo(arquivo, inputFile);

   // Abrir o arquivo de saída
   FILE *arquivoSaida = fopen(outputFile, "w");
   testaAberturaArquivo(arquivoSaida, outputFile);

   int n;
   //Leitura do tamanho do array
   fscanf(arquivo, "%d", &n);

   unsigned long int *array = (unsigned long int *)malloc(n * sizeof(unsigned long int));

   leituraArray(arquivo, n, array);

   unsigned long int resultado = bruteForce(array, n, 0);

   double tempoUsuario = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
   double tempoNoSistema = (end.ru_stime.tv_sec - start.ru_stime.tv_sec) 
        + 1e-6 * (end.ru_stime.tv_usec - start.ru_stime.tv_usec);

   imprimirSaidas(arquivoSaida, resultado, tempoUsuario, tempoNoSistema);
   
   for (int i = 0; i < n; i++) {
      printf("%ld ", array[i]);
   }

   printf("\n%s\n", estrategia);
   printf("%s\n", inputFile);

}
   