/*
Aqui foi criada toda a estruturação do arquivo para ser aplicado em forma de função
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/Permutacao.h"
#include "../Libs/Matriz.h"
#include "../Libs/Arquivo.h"

void arquivo(int* mat1, int* mat2, int* mat3){
  char nomeArquivo[50];
  int i, j, partidaInicial;
  FILE *arq;
  printf("Entre com o nome do arquivo que você deseja ler: \n");
  scanf("%s", nomeArquivo);
  arq = fopen(nomeArquivo, "r"); //Abertura do arquivo
    if(arq == NULL){
      printf("O arquivo digitado não foi encontrado.\n");
    }
    else{
      //Entrando com as matrículas:
      partidaInicial = Permutacao_SomaMatricula(mat1, mat2, mat3);
      fscanf(arq, "%d", &NumeroCidades);
      printf("\n==================================================\n");
      printf("Quantidade de Cidades %d", NumeroCidades);
      printf("\n==================================================\n");

      int MatrizCidades[NumeroCidades][NumeroCidades];

      partidaInicial = (partidaInicial%NumeroCidades);

      for(i=0; i<NumeroCidades-1; i++){
        for(j=0; j<NumeroCidades-1; j++){
          if(i == j){
            MatrizCidades[i][j] = 0;
          }
          else{
            fscanf(arq, "%d", &MatrizCidades[i][j]);
          }
        }
      }
    }
}
