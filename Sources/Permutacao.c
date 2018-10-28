#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Permutacao.h"

void Permutacao_Iniciar(int NumeroCidades, int pPartida,int MatrizCidades[NumeroCidades][NumeroCidades])
{
	int i, cont = 0;
	int v[NumeroCidades-1];
	for(i = 0; i < NumeroCidades-1; i++)
	{
		if(i ==pPartida){
			cont ++;
		}
			v[i] = cont;
			cont ++;

	}
	int tam_v = sizeof(v) / sizeof(int);
  Permutacao_Permuta(v, 0, tam_v - 1, pPartida, MatrizCidades);

}

void Permutacao_Troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void Permutacao_Permuta(int vetor[], int inf, int sup, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades])
{	int soma = 0, i = 0;
	if(inf == sup)
	{ soma+=MatrizCidades[pPartida][vetor[0]];
		soma+=MatrizCidades[vetor[sup]][pPartida];
		for(i = 0; i <= sup; i++){
			if(i>0){
	  		soma +=MatrizCidades[vetor[i-1]][vetor[i]];
			}
			printf("%d ", vetor[i]);
		}
		printf("\n");
		printf("soma = %d\n", soma);
	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{
			Permutacao_Troca(vetor, inf, i);
			Permutacao_Permuta(vetor, inf + 1, sup, pPartida, MatrizCidades);
			Permutacao_Troca(vetor, inf, i); // backtracking
		}
	}
}
int Permutacao_SomaMatricula(int *mat1, int *mat2, int *mat3){
  int i=0, soma=0, matricula;

  printf("Matrícula do primeiro integrante: ");
  scanf("%d", &matricula);

  while(matricula>0){
    mat1[i] = matricula%10;
    i++;
    matricula=matricula/10;
  }
  i=0;

  printf("Matrícula do segundo integrante: ");
  scanf("%d", &matricula);

  while(matricula>0){
    mat2[i] = matricula%10;
    i++;
    matricula=matricula/10;
  }
  i=0;

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
  }

  for(i = 3; i>=0; i--){
    soma+=mat2[i];
  }

  for(i = 3; i>=0; i--){
    soma+=mat3[i];
  }

	return soma;
}
