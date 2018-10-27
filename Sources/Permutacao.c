#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Permutacao.h"

void Permutacao_Iniciar()
{
	int v[] = {1, 2, 3, 4};
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
