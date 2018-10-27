#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Libs/TempoExecucao.h"

void TempoExecucao_MedirTempo()
{
    clock_t tempo;
  	tempo = clock();

    // código de teste
  	//for(int i = 0; i < 1000000001; ++i){}
  	//fim
    printf("\n==================================================\n\n");
  	printf(">>>>>>>>>> Tempo de Execução:%f <<<<<<<<<<\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    printf("\n==================================================\n");
}
