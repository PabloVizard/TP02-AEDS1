#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/TempoExecucao.h"
#include "../Libs/Matriz.h"

int main(){

  int NumeroCidades;
  printf("Digite o número de cidades: ");
  scanf("%d", &NumeroCidades);

  int MatrizCidades[NumeroCidades][NumeroCidades];

  Matriz_Iniciar(NumeroCidades);
  Matriz_Imprimir(**MatrizCidades, NumeroCidades);

  Permutacao_Iniciar();
  TempoExecucao_MedirTempo();

  return 0;
}
