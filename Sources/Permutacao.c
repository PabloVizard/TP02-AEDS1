#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Permutacao.h"

void Permutacao_Iniciar(int NumeroCidades)
{
	int i, cont = 0;
	int v[NumeroCidades];
	for(i = 0; i < NumeroCidades; i++)
	{
		v[i] = cont;
		cont ++;
	}
	int tam_v = sizeof(v) / sizeof(int);
  Permutacao_Permuta(v, 0, tam_v - 1);

}

void Permutacao_Troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void Permutacao_Permuta(int vetor[], int inf, int sup)
{
	if(inf == sup)
	{
		for(int i = 0; i <= sup; i++)
			printf("%d ", vetor[i]);
		printf("\n");
	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{
			Permutacao_Troca(vetor, inf, i);
			Permutacao_Permuta(vetor, inf + 1, sup);
			Permutacao_Troca(vetor, inf, i); // backtracking
		}
	}
}
int Permutacao_SomaMatricula(){
	int mat1[4] = {0,0,0,0}, mat2[4] = {0,0,0,0}, mat3[4] = {0,0,0,0};
  int i=0, soma=0, matricula;

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

	return soma;
}
