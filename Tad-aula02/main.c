#include <stdio.h>
#include "conj.h"

int main()
{
    conj_t *A, *B, *C;

    A = criar();
    B = criar();
    C = criar();

    inserir(10, A);
    printf("%d\n", membro(10, A));

    remover(10, A);
    printf("%d\n", membro(10, A));

    inserir(3, A);
    inserir(7, A);
    inserir(5, B);
    inserir(7, B);

    imprimir(A);
    imprimir(B);

    printf("Uniao\n");
    uniao(A, B, C);
    imprimir(C);

    printf("intersecao\n");
    intersecao(A, B, C);
    imprimir(C);

    printf("diferenca\n");
    diferenca(A, B, C);
    imprimir(C);

    liberar(C);
    liberar(B);
    liberar(A);
}