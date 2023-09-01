#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

// definindo circulo com as coordenadas do centro e o raio
typedef struct circulo_
{
    PONTO centro;
    float raio;
} CIRCULO;

CIRCULO *circulo_criar(PONTO *p, float raio);
void circulo_apagar(CIRCULO *circ);
float circulo_area(CIRCULO *circ);

/*
Função que foi solicitada no enunciado do exercicio,preferi fazer no circulo.c pois já tinha os dois arquivos
importados nele(o ponto.h e o circulo.h).Sendo assim tem menos dependencias para compilar/rodar o programa.
*/
float distancia(PONTO *p, CIRCULO *r);

/*
Pode ser necessário definir outras operações para o TAD.
Se for o caso, faça e justifique!
*/
#endif
