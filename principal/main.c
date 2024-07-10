#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>
#include "leitura.h"
#include "forcabruta.h"
#include "solucaodinamica.h"

int main(int argc, char *argv[]) {
    
     char *estrategia = NULL;
     char *inputFile = NULL;
     char *outputFile = "saida.txt";
     struct rusage start, end; //Usados para calcular o tempo (getrusage)
     struct timeval inicio, fim; //Usados para calcular o tempo (gettimeofday)
     unsigned long int resultado = 0;

     //Recebe a estratégia e o nome do arquivo de entrada
     estrategia = argv[1];
     inputFile = argv[2];

     verificacaoArquivoEntrada(argv, inputFile, estrategia);

     // Abrir o arquivo de entrada
     FILE *arquivo = fopen(inputFile, "r");
     testaAberturaArquivo(arquivo, inputFile);

     // Abrir o arquivo de saída
     FILE *arquivoSaida = fopen(outputFile, "w");
     testaAberturaArquivo(arquivoSaida, outputFile);

     unsigned long int n;
     //Leitura do tamanho do array
     fscanf(arquivo, "%lu", &n);

     unsigned long int *tabuleiro = (unsigned long int *)malloc(n * sizeof(unsigned long int));

     leituraTabuleiro(arquivo, n, tabuleiro);

     getrusage(RUSAGE_SELF, &start);
     gettimeofday(&inicio, NULL);

     if(estrategia[0] == 'A') {
          resultado = forcabruta(tabuleiro, n);
     } else if (estrategia[0] == 'D') {
          resultado = solucaodinamica(tabuleiro, n);
     }

     gettimeofday(&fim, NULL);
     getrusage(RUSAGE_SELF, &end);

     //Cálculos de tempo
     double tempoUsuario = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
     double tempoNoSistema = (end.ru_stime.tv_sec - start.ru_stime.tv_sec) 
          + 1e-6 * (end.ru_stime.tv_usec - start.ru_stime.tv_usec);

     imprimirSaidas(arquivoSaida, resultado, tempoUsuario, tempoNoSistema);
     
     //Finalizações
     free(tabuleiro);
     fclose(arquivo);
     fclose(arquivoSaida);

     return 0;

}