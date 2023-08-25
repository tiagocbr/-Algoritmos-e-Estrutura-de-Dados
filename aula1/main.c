#include <stdio.h>
#include "fracao.h"

int main()
{
    fracao_t *f1 = criar(1, 2), *f2 = criar(2, 3);
    fracao_t *f3 = somar(f1, f2);
    imprimir(f1);
    imprimir(f2);
    imprimir(f3);
    destruir(f1);
    destruir(f2);
    destruir(f3);
}