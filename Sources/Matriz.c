#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Matriz.h"



void Matriz_Iniciar(int NumeroCidades)
{
  int i, j, linha = NumeroCidades, coluna = NumeroCidades;
  int MatrizCidades[linha][coluna];

  srand(time(NULL)); //Utilizamos esse comando para podermos usar numeros aleatorios para a distancia entre as cidades

  for(i = 0; i < NumeroCidades; i++)
  {
    for(j = 0; j < NumeroCidades; j++)
    {
      if (i!=j)
      {
        MatrizCidades[i][j] = (rand()%99);
      }
      else
      {
        MatrizCidades[i][j] = 0;
      }
    }
  }
}
void Matriz_Imprimir(int **MatrizCidades, int NumeroCidades)
{
  int i, j, linha = NumeroCidades, coluna = NumeroCidades;

  for(i = 0; i < NumeroCidades; i ++)
  {
    printf("\n");
    for(j = 0; j < NumeroCidades; j++)
    {
      printf("%2d  ", MatrizCidades[i][j]);
    }
  }
}

//oid Matriz_Random()
//{

//}