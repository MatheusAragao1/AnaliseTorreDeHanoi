#include <stdio.h>
 
void torreDeHanoiComPrint(int numDisk, char pinoInicial, char pinoDestino, char pinoAuxiliar, int * seq, FILE* arq)
{
    (*seq)++;

    if (numDisk == 1)
    {
        fprintf(arq, "\nMover disco 1 do pino %c para o pino %c", pinoInicial, pinoDestino);
        printf("\nMover disco 1 do pino %c para o pino %c", pinoInicial, pinoDestino);
        return;
    }

    torreDeHanoiComPrint(numDisk - 1, pinoInicial, pinoAuxiliar, pinoDestino, seq, arq);

    fprintf(arq,"\n Mover disco %d do pino %c para o pino %c", numDisk, pinoInicial, pinoDestino );
    printf("\n Mover disco %d do pino %c para o pino %c", numDisk, pinoInicial, pinoDestino);

    torreDeHanoiComPrint(numDisk - 1, pinoAuxiliar, pinoDestino, pinoInicial, seq, arq);
}

void torreDeHanoi(int numDisk, char pinoInicial, char pinoDestino, char pinoAuxiliar)
{
    if (numDisk == 1)
    {
        return;
    }

    torreDeHanoi(numDisk - 1, pinoInicial, pinoAuxiliar, pinoDestino);

    torreDeHanoi(numDisk - 1, pinoAuxiliar, pinoDestino, pinoInicial);
}

int main()
{
    int seq = 0;
    int ns = 10;

    FILE* novoArq = fopen("comparacoesRecursiva.txt", "w");

    while(ns >= 3){
      printf("\nA sequencia de movimentos com N = %d é:\n",ns);
      fprintf(novoArq, "\nA sequencia de movimentos com N = %d é:\n",ns);
      torreDeHanoiComPrint(ns, 'A', 'C', 'B', &seq, novoArq);
      fprintf(novoArq,"\nA sequencia de passos na torre de hanoi com N = %d é: %d\n",ns,seq );
      printf("\nA sequencia de passos na torre de hanoi é com N = %d  é: %d",ns,seq);
      printf("\n");
      seq = 0;
      ns--;
    }

    fclose(novoArq);
    return 0;
}