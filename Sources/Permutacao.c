#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Permutacao.h"

void Permutacao_Iniciar(int NumeroCidades, int pPartida,int MatrizCidades[NumeroCidades][NumeroCidades])
{
	int i, cont = 0, menorcaminho = 2147483647;
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
	int caminhoMenor[NumeroCidades];
  Permutacao_Permuta(v, 0, tam_v - 1, pPartida, MatrizCidades, &menorcaminho, NumeroCidades, caminhoMenor);
	printf("\n====================================================================\n");
	printf("Caminho com a menor distancia = ");
	printf("%d ", pPartida+1);
	for(i = 0; i < NumeroCidades-1; i++)
	{
		printf("%d ", caminhoMenor[i]+1);
	}
	printf("%d", pPartida+1);
	printf("\n====================================================================");

	printf("\n====================================================================\n");
	printf("Menor Distancia = %d", menorcaminho);
	printf("\n====================================================================\n");
}

void Permutacao_Troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void Permutacao_Permuta(int vetor[], int inf, int sup, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades], int *menor, int NumeroCidades, int *caminhoMenor)
{
	int soma = 0, i = 0;
	if(inf == sup)
	{
		soma+=MatrizCidades[pPartida][vetor[0]];
		soma+=MatrizCidades[vetor[sup]][pPartida];
		printf("%d ", pPartida+1);

		for(i = 0; i <= sup; i++){
			if(i>0){
	  		soma +=MatrizCidades[vetor[i-1]][vetor[i]];
			}
			printf("%d ", vetor[i]+1);
		}
		if(*menor>soma){
			*menor = soma;
			for(i = 0; i < NumeroCidades; i++)
			{
				caminhoMenor[i] = vetor[i];
			}
		}
		//printf("\n");

		printf("%d -Distancia %d\n", pPartida+1, soma);

	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{
			Permutacao_Troca(vetor, inf, i);
			Permutacao_Permuta(vetor, inf + 1, sup, pPartida, MatrizCidades, menor, NumeroCidades, caminhoMenor);
			Permutacao_Troca(vetor, inf, i); // backtracking
		}
	}

}
int Permutacao_SomaMatricula(int *mat1, int *mat2, int *mat3, int matricula1, int matricula2, int matricula3){
	int i=0, soma=0;

  while(matricula1>0){
    mat1[i] = matricula1%10;
    i++;
    matricula1=matricula1/10;
  }
  i=0;

  while(matricula2>0){
    mat2[i] = matricula2%10;
    i++;
    matricula2=matricula2/10;
  }
  i=0;

  while(matricula3>0){
    mat3[i] = matricula3%10;
    i++;
    matricula3=matricula3/10;
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
