#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/TempoExecucao.h"
#include "../Libs/Matriz.h"

int main(){
  /*
  Matriz para guardar a distância das cidades.
  A variável que define seu tamanho foi declarada no arquivo Matriz.h
  */
  int MatrizCidades[NumeroCidades][NumeroCidades];
  //Vetores para armazenar as matrículas
  int mat1[4] = {0,0,0,0}, mat2[4] = {0,0,0,0}, mat3[4] = {0,0,0,0};
  //Variável para armazenar o ponto de partida e volta do Caixeiro Viajante.
  int pontoPartida;
  
  //Nela, está setada a função para calcular a soma das matrículas dos participantes.
  pontoPartida = Permutacao_SomaMatricula(mat1, mat2, mat3);
  printf("Número de cidades: ");
  scanf("%d", &NumeroCidades);

  //Definindo o ponto de partida pelo resto de divisão da soma pelo número de cidades.
  pontoPartida = pontoPartida%NumeroCidades;

  //Iniciando e imprimindo a matriz
  Matriz_Iniciar(NumeroCidades, MatrizCidades);
  Matriz_Imprimir(MatrizCidades);

  //Definindo a permutação.
  Permutacao_Iniciar(NumeroCidades);
  TempoExecucao_MedirTempo();

  return 0;
}
