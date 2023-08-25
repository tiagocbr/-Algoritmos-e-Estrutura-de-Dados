#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

banco_t *criar(int tamanho)
{
    if (tamanho <= 0)
        return NULL;
    banco_t *b = (banco_t *)malloc(sizeof(banco_t));

    if (b == NULL)
        return NULL;

    b->size = tamanho;
    b->lista = (pessoa_t *)malloc(sizeof(pessoa_t) * tamanho);
    b->pointer = 0;
    if (b->lista == NULL)
    {
        free(b);
        return NULL;
    }

    return b;
}

void incluir(char *nome, char *end, banco_t *b)
{
    if (nome == NULL || end == NULL || b->pointer >= b->size)
        return;

    pessoa_t p;
    p.nome = nome;
    p.end = end;
    b->lista[b->pointer] = p;
    b->pointer++;
}

int compara(char *a, char *b)
{
    if (strlen(a) != strlen(b))
    {
        return 0;
    }
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

void excluir(char *nome, banco_t *b)
{
    if (b == NULL || nome == NULL)
        return;
    for (int i = 0; i < b->pointer; i++)
    {
        if (compara(b->lista[i].nome, nome))
        {
            for (int j = i; j < b->pointer - 1; j++)
            {
                b->lista[j].nome = b->lista[j + 1].nome;
                b->lista[j].end = b->lista[j + 1].end;
            }
            b->pointer--;
            return;
        }
    }
}

char *find(char *nome, banco_t *b)
{
    if (b == NULL || nome == NULL)
        return NULL;

    for (int i = 0; i < b->pointer; i++)
    {
        if (compara(b->lista[i].nome, nome))
        {
            return b->lista[i].end;
        }
    }

    return NULL;
}

void destruir(banco_t *b)
{
    if (b == NULL)
        return;
    if (b->lista != NULL)
    {
        free(b->lista);
        free(b);
        return;
    }
    free(b);
}