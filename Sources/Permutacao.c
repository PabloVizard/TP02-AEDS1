#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Permutacao.h"

void Permutacao_Iniciar(int NumeroCidades, int pPartida,int MatrizCidades[NumeroCidades][NumeroCidades])
{
	int i, cont = 0, menorcaminho = 2147483647; // variavel menorcaminho com o maior numero int para poder pegar o menorcaminho

	// Vetor com n-1 para não ter a cidade inicial
	int v[NumeroCidades-1];

	//vetor para armazenar o caminho com a menor distancia
	int caminhoMenor[NumeroCidades];

	// Gerar um vetor sem a cidade inicial
	for(i = 0; i < NumeroCidades-1; i++)
	{
		if(i == pPartida){
			cont ++;
		}
			v[i] = cont;
			cont ++;
	}

	int tam_v = sizeof(v) / sizeof(int);

	Permutacao_Permuta(v, 0, tam_v - 1, pPartida, MatrizCidades, &menorcaminho, NumeroCidades, caminhoMenor);
	printf("--------------------------------------------------------------------\n");
	printf("\n====================================================================\n");
	printf("Caminho com a menor distancia = ");
	printf("%d ", pPartida);

	for(i = 0; i < NumeroCidades-1; i++)
	{
		printf("%d ", caminhoMenor[i]);
	}
	printf("%d", pPartida);
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
		soma+=MatrizCidades[pPartida][vetor[0]]; //Somar a cidade inicial com a primeira cidade
		soma+=MatrizCidades[vetor[sup]][pPartida]; //Somar a ultima com a cidade inicial

		printf("--------------------------------------------------------------------\n");
		printf("%d ", pPartida);

		for(i = 0; i <= sup; i++){
			if(i>0){
	  		soma +=MatrizCidades[vetor[i-1]][vetor[i]]; //Somar os caminhos
			}
			printf("%d ", vetor[i]);
		}

		// compara o numero menor anterior com o atual
		if(*menor>soma){
			*menor = soma;
			for(i = 0; i < NumeroCidades; i++)
			{
				caminhoMenor[i] = vetor[i];
			}
		}

		printf("%d - Distancia = %d\n", pPartida, soma);

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

	//Pegar os numeros absolutos de cada matricula
  while(matricula1>0){
    mat1[i] = matricula1%10;
    i++;
    matricula1=matricula1/10;
  }
  i=0;

	//Pegar os numeros absolutos de cada matricula
  while(matricula2>0){
    mat2[i] = matricula2%10;
    i++;
    matricula2=matricula2/10;
  }
  i=0;

	//Pegar os numeros absolutos de cada matricula
  while(matricula3>0){
    mat3[i] = matricula3%10;
    i++;
    matricula3=matricula3/10;
  }
  i=0;

  //Somar os numeros da matricula que adiquirimos anteriormente
  for(i = 3; i>=0; i--){
    soma+=mat1[i];
  }

	//Somar os numeros da matricula que adiquirimos anteriormente
  for(i = 3; i>=0; i--){
    soma+=mat2[i];
  }

	//Somar os numeros da matricula que adiquirimos anteriormente
  for(i = 3; i>=0; i--){
    soma+=mat3[i];
  }

	return soma; //retornar a soma
}
