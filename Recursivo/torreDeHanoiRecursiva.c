#include <stdio.h>
#include <sys/resource.h>

void torreDeHanoiRecursivaComPrint(int numDisk, char pinoInicial, char pinoDestino, char pinoAuxiliar, int *seq, FILE *arq)
{
    (*seq)++;

    if (numDisk == 1)
    {
        fprintf(arq, "\nMover disco 1 do pino %c para o pino %c", pinoInicial, pinoDestino);
        printf("\nMover disco 1 do pino %c para o pino %c", pinoInicial, pinoDestino);
        return;
    }

    torreDeHanoiRecursivaComPrint(numDisk - 1, pinoInicial, pinoAuxiliar, pinoDestino, seq, arq);

    fprintf(arq, "\n Mover disco %d do pino %c para o pino %c", numDisk, pinoInicial, pinoDestino);
    printf("\n Mover disco %d do pino %c para o pino %c", numDisk, pinoInicial, pinoDestino);

    torreDeHanoiRecursivaComPrint(numDisk - 1, pinoAuxiliar, pinoDestino, pinoInicial, seq, arq);
}

void torreDeHanoiRecursiva(int numDisk, char pinoInicial, char pinoDestino, char pinoAuxiliar)
{
    if (numDisk == 1)
    {
        return;
    }

    torreDeHanoiRecursiva(numDisk - 1, pinoInicial, pinoAuxiliar, pinoDestino);

    torreDeHanoiRecursiva(numDisk - 1, pinoAuxiliar, pinoDestino, pinoInicial);
}

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
    long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
    struct rusage ptempo;

    getrusage(0, &ptempo);

    seg_CPU = ptempo.ru_utime.tv_sec;
    mseg_CPU = ptempo.ru_utime.tv_usec;
    seg_sistema = ptempo.ru_stime.tv_sec;
    mseg_sistema = ptempo.ru_stime.tv_usec;

    *seg_CPU_total = (seg_CPU + 0.000001 * mseg_CPU);
    *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}

int main()
{
    int seq = 0;
    int ns;
    double s_CPU_final;
    double s_CPU_inicial;
    double s_total_inicial;
    double s_total_final;
    int operacao;

    printf("Digite o valor da proxima operação: 1 - Gerar arquivo com comparação de movimentos | 2 - Gerar arquivo com comparação de tempo de processamento\n");

    scanf("%d", &operacao);
    while (operacao == 1 || operacao == 2)
    {
        if (operacao == 1)
        {
            ns = 10;
            FILE *novoArq = fopen("comparacoesRecursivaMovimentos.txt", "w");
            while (ns >= 3)
            {
                printf("\nA sequencia de movimentos com N = %d é:\n", ns);
                fprintf(novoArq, "\nA sequencia de movimentos com N = %d é:\n", ns);
                torreDeHanoiRecursivaComPrint(ns, 'A', 'C', 'B', &seq, novoArq);
                fprintf(novoArq, "\nA sequencia de passos na torre de hanoi com N = %d é: %d\n", ns, seq);
                printf("\nA sequencia de passos na torre de hanoi é com N = %d  é: %d", ns, seq);
                printf("\n");
                seq = 0;
                ns--;
            }
            fclose(novoArq);
            ns = 10;
        }
        else
        {
            FILE *novoArq2 = fopen("comparacoesRecursivaTempoProcessamento.txt", "w");
            ns = 30;
            while (ns >= 3)
            {
                printf("aqui");
                Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

                torreDeHanoiRecursiva(ns, 'A', 'C', 'B');

                Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

                printf("\nTempo de CPU total para N = %d é %f\n",ns, s_CPU_final - s_CPU_inicial);
                fprintf(novoArq2,"\nTempo de CPU total para N = %d é %f\n",ns, s_CPU_final - s_CPU_inicial);
                ns--;
            }
            fclose(novoArq2);
            ns = 30;
        }
        printf("Digite o valor da proxima operação: 1 - Gerar arquivo com comparação de movimentos | 2 - Gerar arquivo com comparação de tempo de processamento\n");
        scanf("%d", &operacao);
        seq = 0;
    }

    return 0;
}