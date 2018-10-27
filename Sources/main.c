#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/TempoExecucao.h"
#include "../Libs/Matriz.h"

int main(){
  int mat1[4] = {0,0,0,0}, mat2[4], mat3[4];
  int i=0, soma=0, tam=0, matricula;

  printf("Matrícula do primeiro integrante: ");
  scanf("%d", &matricula);

  while(matricula>0){
    mat1[i] = matricula%10;
    i++;
    matricula=matricula/10;
  }
  i=0;
  //matricula = 0;

  printf("Matrícula do segundo integrante: ");
  scanf("%d", &matricula);

  while(matricula>0){
    mat2[i] = matricula%10;
    i++;
    matricula=matricula/10;
  }
  i=0;
  //matricula = 0;

  printf("Matrícula do terceiro integrante: ");
  scanf("%d", &matricula);

  while(matricula>0){
    mat3[i] = matricula%10;
    i++;
    matricula=matricula/10;
  }
  i=0;
  //matricula = 0;

  for(i = 3; i>=0; i--){
    soma+=mat1[i];
    printf("%d", mat1[i]);
  }
  printf("\n");

  for(i = 3; i>=0; i--){
    soma+=mat2[i];
    printf("%d", mat2[i]);
  }
  printf("\n");

  for(i = 3; i>=0; i--){
    soma+=mat3[i];
    printf("%d", mat3[i]);
  }
  printf("\n");

  printf("Soma dos dígitos das matrículas: %d\n", soma);
  printf("Digite o número de cidades: ");
  scanf("%d", &NumeroCidades);

  int MatrizCidades[NumeroCidades][NumeroCidades];

  Matriz_Iniciar(NumeroCidades, MatrizCidades);
  Matriz_Imprimir(MatrizCidades);

  Permutacao_Iniciar(NumeroCidades);
  TempoExecucao_MedirTempo();

  return 0;
}
