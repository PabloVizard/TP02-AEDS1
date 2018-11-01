#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include "../Libs/Permutacao.h"
#include "../Libs/Matriz.h"
#include "../Libs/Menu.h"
#define GET_MS(ini, fim)  ((fim.tv_sec * 1000000 + fim.tv_usec) \
      - (ini.tv_sec * 1000000 + ini.tv_usec))

int main(){
  //Vetores para armazenar as matrículas
  int mat1[4] = {0,0,0,0}, mat2[4] = {0,0,0,0}, mat3[4] = {0,0,0,0};
  //Variaveis para armazenar o numero das matriculas
  int matricula1, matricula2, matricula3;
  //Variável para armazenar o ponto de partida e volta do Caixeiro Viajante.
  int pontoPartida;
  //Variáveis auxiliares para a interrupção dos whiles.
  int modoAuxiliar = 1;
  int intConfirma = 0;

  printf("====================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                          |\n");
  printf("====================================================================\n");
  printf("\n");

  //Variavel para saber em qual modo entrar
  int modo;
  //variavel de confirmação
  char confirma;

  while(modoAuxiliar != 0)
  {
    Menu_Entradas();
    scanf("%d", &modo);

    if(modo == 1)
    {
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

      //Algoritmo para medir o tempo de execução do programa interativo


      struct timeval inicio, fim;

      gettimeofday(&inicio, NULL);

      printf("\n====================================================================\n");
      printf("Quantidade de Cidades %d", NumeroCidades);
      printf("\n====================================================================\n");

      // Matriz Cidades
      int MatrizCidades[NumeroCidades][NumeroCidades];

      //Definindo o ponto de partida pelo resto de divisão da soma pelo número de cidades.
      pontoPartida = (pontoPartida%NumeroCidades);
      printf("\n====================================================================\n");
      printf("Cidade Inicial %d", pontoPartida);
      printf("\n====================================================================\n");
      //Iniciando a matriz
      Matriz_Iniciar(NumeroCidades, MatrizCidades);
      printf("\n");
      //Definindo a permutação.
      Permutacao_Iniciar(NumeroCidades, pontoPartida, MatrizCidades);
      //imprimindo a matriz
      Matriz_Imprimir(MatrizCidades);

      gettimeofday(&fim, NULL);

      printf("\n====================================================================\n");
      printf("          #######--> Tempo de Execução: %.4f s <--#######", (float)GET_MS(inicio, fim)/1000000);
      printf("\n====================================================================\n");


    }

    else if(modo == 2)
    {
      char nomeArquivo[50];
      int i, j, partidaInicial;
      FILE *arq;
      printf("Entre com o nome do arquivo que você deseja ler: \n");
      scanf("%s", nomeArquivo);

      //Algoritmo para medir o tempo de execução do programa por arquivo
      struct timeval inicio, fim;
      gettimeofday(&inicio, NULL);

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

          fscanf(arq, "%d", &NumeroCidades);
          printf("\n====================================================================\n");
          printf("Quantidade de Cidades %d", NumeroCidades);
          printf("\n====================================================================\n");

          //Definindo o ponto de partida pelo resto de divisão da soma pelo número de cidades.
          partidaInicial = Permutacao_SomaMatricula(mat1, mat2, mat3, matricula1, matricula2, matricula3);
          partidaInicial = (partidaInicial%NumeroCidades);

          // Matriz Cidades
          int MatrizCidades[NumeroCidades][NumeroCidades];

          printf("\n====================================================================\n");
          printf("Cidade Inicial %d", partidaInicial);
          printf("\n====================================================================\n");

          // Lendo a matriz do arquivo
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

        gettimeofday(&fim, NULL);
        printf("\n====================================================================\n");
        printf("          #######--> Tempo de Execução: %.5f s <--#######", (float)GET_MS(inicio, fim)/1000000);
        printf("\n====================================================================\n");

    }
    else if(modo == 0)
    {
        Menu_Confirmacao();
        scanf(" %c", &confirma);
        printf("\n");

        //Transformando o char confirma em int
        confirma = toupper(confirma);
        intConfirma = confirma -64;

        if(intConfirma == 19) // "S" em numeros inteiros é o numero 19
        {
          Menu_Saida();
          modoAuxiliar = 0;
        }
      }
    }

  return 0;
}
