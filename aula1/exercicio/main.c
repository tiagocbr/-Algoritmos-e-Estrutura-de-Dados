#include <stdio.h>
#include "tad.h"

int main()
{
    banco_t *b = criar(10);
    incluir("ana", "rua", b);
    incluir("tiago", "santos", b);
    incluir("asd", "fjd", b);
    excluir("asd", b);
    char *res = find("asd", b);
    if (res == NULL)
    {
        printf("Nao encontrado\n");
        destruir(b);
        return 0;
    }
    printf("%s\n", res);
    destruir(b);
}