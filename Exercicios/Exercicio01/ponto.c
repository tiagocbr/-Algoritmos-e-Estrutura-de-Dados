#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

PONTO *ponto_criar(float x, float y)
{
    PONTO *p = (PONTO *)malloc(sizeof(PONTO));
    if (p == NULL)
        return NULL;
    p->x = x;
    p->y = y;
    return p;
}

void ponto_apagar(PONTO *p)
{
    if (p == NULL)
        return;
    free(p);
    p = NULL;
}
bool ponto_set(PONTO *p, float x, float y)
{
    if (p == NULL)
        return false;

    p->x = x;
    p->y = y;
    return true;
}