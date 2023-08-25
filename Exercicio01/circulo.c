#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"
#include <math.h>

#define PI 3.14159265358979323846

CIRCULO *circulo_criar(PONTO *p, float raio)
{
    if (p == NULL)
        return NULL;
    if (raio < 0)
        return NULL;

    CIRCULO *c = (CIRCULO *)malloc(sizeof(CIRCULO));
    if (c == NULL)
        return NULL;

    c->centro = *p;
    c->raio = raio;
    return c;
}
void circulo_apagar(CIRCULO *circ)
{
    if (circ == NULL)
        return;
    free(circ);
    circ == NULL;
}
float circulo_area(CIRCULO *circ)
{
    if (circ == NULL)
        return -1;
    return PI * (circ->raio) * (circ->raio);
}

float distancia(PONTO *p, CIRCULO *r)
{
    if (p == NULL || r == NULL)
        return -1;

    return sqrt((r->centro.x - p->x) * (r->centro.x - p->x) + (r->centro.y - p->y) * (r->centro.y - p->y));
}