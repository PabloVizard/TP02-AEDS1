#ifndef PERMUTACAO_H
#define PERMUTACAO_H

int NumeroCidades;

void Permutacao_Iniciar(int NumeroCidades, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades]); // Função para iniciar a permutação
void Permutacao_Troca(int vetor[], int i, int j); // Função que troca os elementos da permutação
void Permutacao_Permuta(int vetor[], int inf, int sup, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades], int *menor, int NumeroCidades, int *caminhoMenor); // Função que realiza as permutações
int Permutacao_SomaMatricula(int *mat1, int *mat2, int *mat3, int matricula1, int matricula2, int matricula3); //Função que soma os numeros da matricula

#endif
