#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Matriz.h"



void Matriz_Iniciar(int NumeroCidades, int MatrizCidades[NumeroCidades][NumeroCidades])
{
  int i, j;

  srand(time(NULL)); //Utilizamos esse comando para podermos usar numeros aleatorios para a distancia entre as cidades

  //Percorrer a matriz adicionando um numero aleatorio quando i for diferente de j e adicionar 0 quando i for igual a j
  for(i = 0; i < NumeroCidades; i++)
  {
    for(j = 0; j < NumeroCidades; j++)
    {
      if (i!=j)
      {
        MatrizCidades[i][j] = (rand()%99)+1;
      }
      else
      {
        MatrizCidades[i][j] = 0;
      }
    }
  }
}

void Matriz_Imprimir(int MatrizCidades[NumeroCidades][NumeroCidades]){
  int i, j;

  //Printar a matriz completa
  printf("\n====================================================================\n");
  printf("Matriz Cidades");
  printf("\n====================================================================\n\n");
  for(i = 0; i < NumeroCidades; i ++){
    for(j = 0; j < NumeroCidades; j++){
      printf("% .2d ", MatrizCidades[i][j]);
    }
    printf("\n");
  }
}
