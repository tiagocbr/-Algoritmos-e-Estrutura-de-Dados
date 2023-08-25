#include "fracao.h"
#include <stdio.h>
#include <stdlib.h>

fracao_t *criar(int num, int den)
{
    if (den == 0)
        return NULL;
    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
    if (f == NULL)
        return NULL;
    f->num = num;
    f->den = den;
    return f;
}

void imprimir(fracao_t *f)
{
    if (f == NULL)
        return;
    printf("%d / %d\n", f->num, f->den);
}

void destruir(fracao_t *f)
{
    if (f == NULL)
        return;
    free(f);
    f = NULL;
}

int mdc(int a, int b)
{
    return b == 0 ? a : mdc(b, a % b);
}

int mmc(int a, int b)
{
    return a * b / mdc(a, b);
}

fracao_t *somar(fracao_t *f1, fracao_t *f2)
{
    if (f1 == NULL || f2 == NULL)
        return NULL;
    fracao_t *res = (fracao_t *)malloc(sizeof(fracao_t));
    if (res == NULL)
        return NULL;
    res->den = mmc(f1->den, f2->den);
    res->num = ((f1->num) * (res->den) / (f1->den)) + ((f2->num) * (res->den) / (f2->den));
    return res;
}
