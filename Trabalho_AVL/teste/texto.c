#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NA 1000000
#define NB 1000000

void gerarNumerosAleatorios(int *numeros, int tamanho)
{
    for (int i = 0; i < tamanho; ++i)
    {
        numeros[i] = rand() % (10 * tamanho) + 1;
    }
}

void escreverArquivo(int *numeros, int tamanho, FILE *arquivo)
{

    for (int i = 0; i < tamanho; ++i)
    {
        fprintf(arquivo, "%d ", numeros[i]);
    }

    fclose(arquivo);
}

int main()
{
    srand(time(NULL));
    FILE *arquivo = fopen("arvores.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    fprintf(arquivo, "%d %d\n", NA, NB);
    int numeros[NA + NB];

    gerarNumerosAleatorios(numeros, NA + NB);

    escreverArquivo(numeros, NA + NB, arquivo);

    printf("Arquivo arvores.txt foi criado com os números aleatórios.\n");

    return 0;
}
