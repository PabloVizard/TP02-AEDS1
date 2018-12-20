#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Menu.h"

void Menu_Entradas(){
  printf("====================================================================\n");
  printf("|                                                                  |\n");
  printf("|                   Deseja usar qual modo?                         |\n");
  printf("|                                                                  |\n");
  printf("====================================================================\n");

  printf("\n");

  printf("  1. Desejo usar o modo interativo.\n");
  printf("  2. Desejo usar o modo arquivo.\n");
  printf("  0. Desejo sair.\n");

  printf("\n");

  printf("====================================================================\n");

  printf("Modo escolhido: ");
}

void Menu_Confirmacao(){
  printf("====================================================================\n");
  printf("\n");
  printf("Você deseja realmente parar a execução do programa?\n");
  printf("[S/n]: ");
}
void Menu_Saida(){
  printf("====================================================================\n");
  printf("\n");
  printf("Trabalho feito por:\n\n -> Arthur De Bellis - 03503\n -> Saulo Miranda Silva - 03475\n -> Pablo Ferreira - 03480\n");
  printf("\n");
  printf("====================================================================\n");
}
void Menu_Arquivo(){
  printf("====================================================================\n");
  printf("                        MODO ARQUIVO\n");
  printf("====================================================================\n");
  printf("\n");
  printf("Entre com o nome do arquivo que deseja ler: ");
}
