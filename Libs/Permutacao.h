#ifndef PERMUTACAO_H
#define PERMUTACAO_H
int NumeroCidades;

void Permutacao_Iniciar(int NumeroCidades, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades]);
void Permutacao_Troca(int vetor[], int i, int j);
void Permutacao_Permuta(int vetor[], int inf, int sup, int pPartida, int MatrizCidades[NumeroCidades][NumeroCidades]);
int Permutacao_SomaMatricula(int *mat1, int *mat2, int *mat3);
#endif
