#include <stdio.h>
#include <stdlib.h>
#include "conj.h"
#define N 100

conj_t *criar()
{
    conj_t *A = (conj_t *)malloc(sizeof(conj_t));
    if (A == NULL)
        return NULL;
    A->lista = (int *)malloc(sizeof(int) * N);
    if (A->lista == NULL)
    {
        free(A);
        return NULL;
    }
    for (int i = 0; i < N; i++)
    {
        A->lista[i] = 0;
    }
    return A;
}

void uniao(conj_t *A, conj_t *B, conj_t *C)
{
    if (A == NULL || B == NULL || C == NULL)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (A->lista[i] == 1 || B->lista[i] == 1)
        {
            C->lista[i] = 1;
        }
        else
            C->lista[i] = 0;
    }
}

void intersecao(conj_t *A, conj_t *B, conj_t *C)
{
    if (A == NULL || B == NULL || C == NULL)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (A->lista[i] == 1 && B->lista[i] == 1)
        {
            C->lista[i] = 1;
        }
        else
            C->lista[i] = 0;
    }
}
void diferenca(conj_t *A, conj_t *B, conj_t *C)
{
    if (A == NULL || B == NULL || C == NULL)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (A->lista[i] == 1)
        {
            if (B->lista[i] == 0)
                C->lista[i] = 1;
            else
                C->lista[i] = 0;
        }
        else
            C->lista[i] = 0;
    }
}
int membro(int x, conj_t *A)
{
    if (x >= N)
    {
        return 0;
    }
    if (A == NULL)
        return -1;
    return A->lista[x];
}
void inserir(int x, conj_t *A)
{
    if (x >= N)
    {
        return;
    }
    if (A == NULL)
        return;
    A->lista[x] = 1;
}
void remover(int x, conj_t *A)
{
    if (x >= N)
    {
        return;
    }
    if (A == NULL)
        return;
    A->lista[x] = 0;
}
void liberar(conj_t *A)
{
    if (A == NULL)
        return;
    if (A->lista != NULL)
    {
        free(A->lista);
    }
    free(A);
}
void imprimir(conj_t *A)
{
    if (A == NULL)
        return;

    for (int i = 0; i < N; i++)
    {
        if (A->lista[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
