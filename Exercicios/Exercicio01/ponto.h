#ifndef PONTO_H
#define PONTO_H
#include <stdbool.h>

// Definindo a struct ponto_ como um par ordenado (x,y);
typedef struct ponto_
{
    float x, y;
} PONTO;

PONTO *ponto_criar(float x, float y);
void ponto_apagar(PONTO *p);
bool ponto_set(PONTO *p, float x, float y);

/*
Pode ser necessário definir outras operações para o TAD.
Se for o caso, faça e justifique!
*/
#endif
