#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void medirTempo();

int main() {

  int numeroCidades;

  medirTempo();
  return 0;
}

void medirTempo()
{
    clock_t tempo;
  	tempo = clock();

    // código de teste
  	for(int i = 0; i < 1000000001; ++i){}
  	//fim
  	printf("Tempo:%f\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}
