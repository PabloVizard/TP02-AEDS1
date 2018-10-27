#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "../Libs/Matriz.h"



void Matriz_Iniciar(int NumeroCidades, int MatrizCidades[NumeroCidades][NumeroCidades])
{
  int i, j;

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
void Matriz_Imprimir(int MatrizCidades[NumeroCidades][NumeroCidades]){
  int i, j;
  for(i = 0; i < NumeroCidades; i ++){
    for(j = 0; j < NumeroCidades; j++){
      printf("%.2d ", MatrizCidades[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
//oid Matriz_Random()
//{

//}
