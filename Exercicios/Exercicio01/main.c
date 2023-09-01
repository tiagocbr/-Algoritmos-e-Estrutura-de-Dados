#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main()
{
    PONTO *p, *p2;
    CIRCULO *r;
    float x, y, z;
    scanf("%f %f", &x, &y);
    p = ponto_criar(x, y);
    scanf("%f %f %f", &x, &y, &z);
    p2 = ponto_criar(x, y);
    r = circulo_criar(p2, z);

    /*
    Função que foi solicitada no enunciado do exercicio,preferi fazer no circulo.c pois já tinha os dois arquivos
    importados nele(o ponto.h e o circulo.h).Sendo assim tem menos dependencias para compilar/rodar o programa.
    */
    float dist = distancia(p, r);
    if (dist < z)
    {
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
        return 0;
    }
    if (dist > z)
    {
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
        return 0;
    }
    if (dist == z)
    {
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
        return 0;
    }
}