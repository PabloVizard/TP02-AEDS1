#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/TempoExecucao.h"
#include "../Libs/Matriz.h"

int main(){

  printf("Digite o número de cidades: ");
  scanf("%d", &NumeroCidades);

  int MatrizCidades[NumeroCidades][NumeroCidades];

  Matriz_Iniciar(NumeroCidades, MatrizCidades);
  Matriz_Imprimir(MatrizCidades);

  Permutacao_Iniciar(NumeroCidades);
  TempoExecucao_MedirTempo();

  return 0;
}
