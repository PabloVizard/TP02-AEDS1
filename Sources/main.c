#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/Matriz.h"

int main(){

  //Algoritmo para medir o tempo de execução do programa
  clock_t tempo;
  tempo = clock();

  /*
  Matriz para guardar a distância das cidades.
  A variável que define seu tamanho foi declarada no arquivo Matriz.h
  */

  //Vetores para armazenar as matrículas
  int mat1[4] = {0,0,0,0}, mat2[4] = {0,0,0,0}, mat3[4] = {0,0,0,0};
  //Variável para armazenar o ponto de partida e volta do Caixeiro Viajante.
  int pontoPartida;

  //Nela, está setada a função para calcular a soma das matrículas dos participantes.
  pontoPartida = Permutacao_SomaMatricula(mat1, mat2, mat3);
  printf("Número de cidades: ");
  scanf("%d", &NumeroCidades);
  int MatrizCidades[NumeroCidades][NumeroCidades];
  //Definindo o ponto de partida pelo resto de divisão da soma pelo número de cidades.

  pontoPartida = (pontoPartida%NumeroCidades);
  printf("Ponto de partida: %d\n", pontoPartida+1);
  //Iniciando e imprimindo a matriz
  Matriz_Iniciar(NumeroCidades, MatrizCidades);

  Matriz_Imprimir(MatrizCidades);

  //Definindo a permutação.
  Permutacao_Iniciar(NumeroCidades, pontoPartida, MatrizCidades);
	//TempoExecucao_MedirTempo();

  printf("\n==================================================\n\n");
  printf(">>>>>>>>>> Tempo de Execução:%f <<<<<<<<<<\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
  printf("\n==================================================\n");

  return 0;
}
