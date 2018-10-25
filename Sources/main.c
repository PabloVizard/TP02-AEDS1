#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void permuta(int vetor[], int inf, int sup);

void medirTempo();

int main() {

  int v[] = {1, 2, 3, 4, 5};
	int tam_v = sizeof(v) / sizeof(int);

  permuta(v, 0, tam_v - 1);

  medirTempo();
  return 0;
}

void medirTempo()
{
    clock_t tempo;
  	tempo = clock();

    // código de teste
  	//for(int i = 0; i < 1000000001; ++i){}
  	//fim
  	printf("Tempo:%f\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}

void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup)
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
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup);
			troca(vetor, inf, i); // backtracking
		}
	}
}
