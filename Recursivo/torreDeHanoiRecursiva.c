#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void printarLinhasDePino(int camada, int pino[], FILE *arq)
{
    switch (pino[camada])
    {
    case 0:
        printf("          |          ");
        fprintf(arq, "          |          ");
        break;
    case 1:
        printf("         *|*         ");
        fprintf(arq, "         *|*         ");
        break;
    case 2:
        printf("        **|**        ");
        fprintf(arq, "        **|**        ");
        break;
    case 3:
        printf("       ***|***       ");
        fprintf(arq, "       ***|***       ");
        break;
    case 4:
        printf("      ****|****      ");
        fprintf(arq, "      ****|****      ");
        break;
    case 5:
        printf("     *****|*****    ");
        fprintf(arq, "     *****|*****    ");
        break;
    case 6:
        printf("    ******|******    ");
        fprintf(arq, "    ******|******    ");
        break;
    case 7:
        printf("   *******|*******   ");
        fprintf(arq, "   *******|*******   ");
        break;
    case 8:
        printf("  ********|********  ");
        fprintf(arq, "  ********|********  ");
        break;
    default:
        printf(" ------------------- ");
        fprintf(arq, " ------------------- ");
        break;
    }
}

void printarPinos(int pinoOrigem[], int pinoDestino[], int pinoAuxiliar[], FILE *arq)
{
    int k;
    for (k = 0; k < 9; k++)
    {
        printarLinhasDePino(k, pinoOrigem, arq);
        printarLinhasDePino(k, pinoDestino, arq);
        printarLinhasDePino(k, pinoAuxiliar, arq);
        printf("\n");
        fprintf(arq, "\n");
    }
}

void moverDiscos(int pinoOrigem[], int pinoDestino[])
{
    int i, j;
    int temp;

    for (i = 0; i < 9; i++)
    {
        if (pinoOrigem[i] != 0)
        {
            temp = pinoOrigem[i];
            pinoOrigem[i] = 0;
            break;
        }
    }

    for (j = 0; j < 9; j++)
    {
        if (pinoDestino[j] != 0)
        {
            pinoDestino[j - 1] = temp;
            break;
        }
    }
}

void torreDeHanoiIterativa_metodo_xxx(int numDisk, int printar, int *seq, FILE *arq)
{
    //https://www.irjet.net/archives/V8/i3/IRJET-V8I352.pdf
    int k, tot;
    int de, para;
    int even;
    if (numDisk % 2 == 0) {
        even = 1; //é par
    }
    else even = 0;
    tot=2^numDisk-1;
    for (k = 1; k < tot; k++){
        if (even == 0) {
            if (k % 3 == 1) {
                //movimentolegal(A, C, *direcao);
            }
            if (k % 3 == 2) {
                //movimentolegal(A, B, *direcao);
            }
            if (k % 3 == 0) {
                //movimentolegal(B, C, *direcao);
            }

        } else if (even == 1) {
            if (k % 3 == 1) {
                //movimentolegal(A, B, *direcao);
            }
            if (k % 3 == 2) {
                //movimentolegal(A, C, *direcao);
            }
            if (k % 3 == 0) {
                //movimentolegal(C, B, *direcao);
            }
        }
        printf("\n Mover disco de pino %d para o pino %d", de, para);
        fprintf(arq, "\n Mover disco de pino %d para o pino %d", de, para);
        (*seq)++;
    }
}

void torreDeHanoiIterativa_metodo_Bit_a_Bit(int numDisk, int printar, int *seq, FILE *arq)
{
    //https://daemoniolabs.wordpress.com/2012/05/16/solucao-iterativa-para-o-problema-da-torre-de-hanoi/

    int k;
    int de, para;

    if (printar == 1) {
        for (k = 1; k < (1 << numDisk); k++) {  // " k < (1 << n)" equivale à 2^n-1
            /* obtem haste origem */
            de = (k & (k - 1)) % 3;

            /* obtem haste destino */
            para = ((k | (k - 1)) + 1) % 3;

            /* descreve o movimento */
            printf(      "\n Mover disco de pino %d para o pino %d", de, para);
            fprintf(arq, "\n Mover disco de pino %d para o pino %d", de, para);
            (*seq)++;
        }
    } else {
        for (k = 1; k < (1 << numDisk); k++) {  // " k < (1 << n)" equivale à 2^n-1
            /* obtem haste origem */
            de = (k & (k - 1)) % 3;

            /* obtem haste destino */
            para = ((k | (k - 1)) + 1) % 3;
            (*seq)++;
        }
    }

}

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

void torreDeHanoiComArrayPinosGraficamente(int n, int pinoOrigem[], int pinoDestino[], int pinoAuxliar[], int print1[], int print2[], int print3[], FILE *arq)
{
    if (n > 0)
    {
        torreDeHanoiComArrayPinosGraficamente(n - 1, pinoOrigem, pinoAuxliar, pinoDestino, print1, print2, print3, arq);
        printarPinos(print1, print2, print3, arq);
        moverDiscos(pinoOrigem, pinoDestino);
        torreDeHanoiComArrayPinosGraficamente(n - 1, pinoAuxliar, pinoDestino, pinoOrigem, print1, print2, print3, arq);
    }
}

int main()
{
    int seq = 0;
    int ns;
    double s_CPU_final;
    double s_CPU_inicial;
    double s_total_inicial;
    double s_total_final;
    int operacao, metodo;

    printf("Digite o valor da proxima operação: \n"
           "1 - Gerar arquivo com comparação de movimentos | \n"
           "2 - Gerar arquivo com comparação de tempo de processamento | \n"
           "3 - Gerar arquivo com movimentos do disco entre os pinos |\n"
           "4 - Sair\n");

    scanf("%d", &operacao);

    while (operacao == 1 || operacao == 2 || operacao == 3)
    {
        printf("1 - Método Recursivo: \n"
               "2 - Método Iterativo bit a bit | \n"
               "3 - Método Iterativo xxxxxxxxx | \n"
               "4 - Abortar\n");
        scanf("%d", &metodo);

        if (operacao == 1) {
            if (metodo == 1) {
                ns = 10;
                FILE *novoArq = fopen("comparacoesRecursivaMovimentos.txt", "w");
                while (ns >= 3) {
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
            if (metodo == 2) {
                ns = 10;
                FILE *novoArq = fopen("comparacoesIterativoBaBMovimentos.txt", "w");
                while (ns >= 3) {
                    printf("\nA sequencia de movimentos com N = %d é:\n", ns);
                    fprintf(novoArq, "\nA sequencia de movimentos com N = %d é:\n", ns);
                    torreDeHanoiIterativa_metodo_Bit_a_Bit(ns, 1, &seq, novoArq);
                    fprintf(novoArq, "\nA sequencia de passos na torre de hanoi com N = %d é: %d\n", ns, seq);
                    printf("\nA sequencia de passos na torre de hanoi é com N = %d  é: %d", ns, seq);
                    printf("\n");
                    seq = 0;
                    ns--;
                }
                fclose(novoArq);
                ns = 10;
            }
            if (metodo == 3) {
                ns = 10;
                FILE *novoArq = fopen("comparacoesIterativoxxxMovimentos.txt", "w");
                while (ns >= 3) {
                    printf("\nA sequencia de movimentos com N = %d é:\n", ns);
                    fprintf(novoArq, "\nA sequencia de movimentos com N = %d é:\n", ns);
                    torreDeHanoiIterativa_metodo_xxx(ns, 1, &seq, novoArq);
                    fprintf(novoArq, "\nA sequencia de passos na torre de hanoi com N = %d é: %d\n", ns, seq);
                    printf("\nA sequencia de passos na torre de hanoi é com N = %d  é: %d", ns, seq);
                    printf("\n");
                    seq = 0;
                    ns--;
                }
                fclose(novoArq);
                ns = 10;
            }

        }
        else if (operacao == 3)
        {
            int n;
            printf("Digite um valor para N (7 <= N >= 3): ");
            scanf("%d", &n);
            int pinoOrigem[9] = {0, 0, 0, 0, 0, 0, 0, 0, 9};
            int pinoDestino[9] = {0, 0, 0, 0, 0, 0, 0, 0, 9};
            int pinoAuxiliar[9] = {0, 0, 0, 0, 0, 0, 0, 0, 9};
            int i;
            int j = 1;

            if (n > 8 || n < 2)
            {
                printf("Entre um N entre 8 e 2\n");
                exit(0);
            }
            FILE *novoArq3 = fopen("comparacoesRecursivaDinamicaPinos.txt", "w");
            fprintf(novoArq3, "Sequencia visual dos discos e pinos para N = %d\n\n", n);
            for (i = 8 - n; i < 8; i++)
            {
                pinoOrigem[i] = j;
                j++;
            }

            torreDeHanoiComArrayPinosGraficamente(n, pinoOrigem, pinoDestino, pinoAuxiliar, pinoOrigem, pinoDestino, pinoAuxiliar, novoArq3);
            printarPinos(pinoOrigem, pinoDestino, pinoAuxiliar, novoArq3);
            fclose(novoArq3);
        }
        else if (operacao == 2)
        {
            if (metodo == 1) {
                FILE *novoArq2 = fopen("comparacoesRecursivaTempoProcessamento.txt", "w");
                ns = 30;
                while (ns >= 3) {
                    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

                    torreDeHanoiRecursiva(ns, 'A', 'C', 'B');

                    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

                    printf("\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    fprintf(novoArq2, "\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    ns--;
                }
                fclose(novoArq2);
                ns = 30;
            }
            if (metodo == 2) {
                FILE *novoArq2 = fopen("comparacoesIterativaBaBTempoProcessamento.txt", "w");
                ns = 30;
                while (ns >= 3) {
                    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

                    torreDeHanoiIterativa_metodo_Bit_a_Bit(ns, 0, &seq, novoArq2);

                    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

                    printf("\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    fprintf(novoArq2, "\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    ns--;
                }
                fclose(novoArq2);
                ns = 30;
            }
            if (metodo == 3) {
                FILE *novoArq2 = fopen("comparacoesIterativaxxxTempoProcessamento.txt", "w");
                ns = 30;
                while (ns >= 3) {
                    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

                    torreDeHanoiIterativa_metodo_xxx(ns, 0, &seq, novoArq2);

                    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

                    printf("\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    fprintf(novoArq2, "\nTempo de CPU total para N = %d é %f\n", ns, s_CPU_final - s_CPU_inicial);
                    ns--;
                }
                fclose(novoArq2);
                ns = 30;
            }
        }
        printf(" \n \n");
        printf("Digite o valor da proxima operação: \n"
               "1 - Gerar arquivo com comparação de movimentos | \n"
               "2 - Gerar arquivo com comparação de tempo de processamento | \n"
               "3 - Gerar arquivo com movimentos do disco entre os pinos |\n"
               "4 - Sair\n");

        scanf("%d", &operacao);
        seq = 0;
    }

    return 0;
}