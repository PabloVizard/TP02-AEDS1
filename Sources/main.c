#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/Permutacao.h"
#include "../Libs/Matriz.h"
#include "../Libs/Menu.h"

int main(){
  //Vetores para armazenar as matrículas
  int mat1[4] = {0,0,0,0}, mat2[4] = {0,0,0,0}, mat3[4] = {0,0,0,0};
  //Variaveis para armazenar o numero das matriculas
  int matricula1, matricula2, matricula3;
  //Variável para armazenar o ponto de partida e volta do Caixeiro Viajante.
  int pontoPartida;
  //Variáveis auxiliares para a interrupção dos whiles.
  int operadorAuxiliar = 1, modoAuxiliar = 1;
  int intConfirma = 0;

  printf("====================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                          |\n");
  printf("====================================================================\n");
  printf("\n");
  int modo;
  char confirma;

  while(modoAuxiliar != 0)
  {
    Menu_Entradas();
    scanf("%d", &modo);

    if(modo == 1)
    {
      //Algoritmo para medir o tempo de execução do programa interativo
      clock_t tempo;
      tempo = clock();

      //Receber os numeros de matricula
      printf("Matrícula do primeiro integrante: ");
      scanf("%d", &matricula1);

      printf("Matrícula do segundo integrante: ");
      scanf("%d", &matricula2);

      printf("Matrícula do terceiro integrante: ");
      scanf("%d", &matricula3);
      //Nela, está setada a função para calcular a soma das matrículas dos participantes.
      pontoPartida = Permutacao_SomaMatricula(mat1, mat2, mat3, matricula1, matricula2, matricula3);

      printf("Numero de cidades: ");
      scanf("%d", &NumeroCidades);
      printf("\n====================================================================\n");
      printf("Quantidade de Cidades %d", NumeroCidades);
      printf("\n====================================================================\n");

      int MatrizCidades[NumeroCidades][NumeroCidades];

      //Definindo o ponto de partida pelo resto de divisão da soma pelo número de cidades.
      pontoPartida = (pontoPartida%NumeroCidades);
      printf("\n====================================================================\n");
      printf("Cidade Inicial %d", pontoPartida+1);
      printf("\n====================================================================\n");
      //Iniciando a matriz
      Matriz_Iniciar(NumeroCidades, MatrizCidades);
      printf("\n");
      //Definindo a permutação.
      Permutacao_Iniciar(NumeroCidades, pontoPartida, MatrizCidades);
      //imprimindo a matriz
      Matriz_Imprimir(MatrizCidades);

      printf("\n====================================================================\n");
      printf("          >>>>>>>>>> Tempo de Execução:%f <<<<<<<<<<",(clock() - tempo) / (double)CLOCKS_PER_SEC);
      printf("\n====================================================================\n\n");


    }

    else if(modo == 2)
    {
      //Algoritmo para medir o tempo de execução do programa por arquivo
      clock_t tempo2;
      tempo2 = clock();

      char nomeArquivo[50];
      int i, j, partidaInicial;
      FILE *arq;
      printf("Entre com o nome do arquivo que você deseja ler: \n");
      scanf("%s", nomeArquivo);
      arq = fopen(nomeArquivo, "r"); //Abertura do arquivo
        if(arq == NULL){
          printf("O arquivo digitado não foi encontrado.\n");
        }
        else{
          //Entrando com as matrículas:
          fscanf(arq, "%d", &matricula1);
          fscanf(arq, "%d", &matricula2);
          fscanf(arq, "%d", &matricula3);

          printf("\n====================================================================\n");
          printf("Matricula 01 = %d\n", matricula1);
          printf("Matricula 02 = %d\n", matricula2);
          printf("Matricula 03 = %d", matricula3);
          printf("\n====================================================================\n");

          partidaInicial = Permutacao_SomaMatricula(mat1, mat2, mat3, matricula1, matricula2, matricula3);

          fscanf(arq, "%d", &NumeroCidades);
          printf("\n====================================================================\n");
          printf("Quantidade de Cidades %d", NumeroCidades);
          printf("\n====================================================================\n");

          int MatrizCidades[NumeroCidades][NumeroCidades];

          partidaInicial = (partidaInicial%NumeroCidades);

          printf("\n====================================================================\n");
          printf("Cidade Inicial %d", partidaInicial+1);
          printf("\n====================================================================\n");

          for(i=0; i<NumeroCidades; i++){
            for(j=0; j<NumeroCidades; j++){
              if(i == j){
                MatrizCidades[i][j] = 0;
              }
              else{
                fscanf(arq, "%d", &MatrizCidades[i][j]);
              }
            }
          }
          //Definindo a permutação.
          Permutacao_Iniciar(NumeroCidades, partidaInicial, MatrizCidades);
          //imprimindo a matriz
          Matriz_Imprimir(MatrizCidades);
        }

        printf("\n====================================================================\n");
        printf("          >>>>>>>>>> Tempo de Execução:%f <<<<<<<<<<",(clock() - tempo2) / (double)CLOCKS_PER_SEC);
        printf("\n====================================================================\n");

    }
    else if(modo == 0)
    {
        Menu_Confirmacao();
        scanf(" %c", &confirma);
        printf("\n");
        confirma = toupper(confirma);
        intConfirma = confirma -64;
        if(intConfirma == 19)
        {
          Menu_Saida();
          modoAuxiliar = 0;
        }
      }
    }

  return 0;
}
