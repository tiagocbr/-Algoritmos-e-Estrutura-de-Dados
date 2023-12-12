#include "item.h"
#include "Pilha.h"

struct item_
{
    char valor;
};

ITEM *item_criar(char chave)
{
    ITEM *e = (ITEM *)malloc(sizeof(ITEM));
    assert(e != NULL);
    e->valor = chave;
    return e;
}

void item_imprimir(ITEM *item)
{
    char c = item->valor;
    putchar(c);
}
char item_get_chave(ITEM *item)
{
    return item->valor;
}
bool item_set_chave(ITEM *item, char chave)
{
    if (item == NULL)
        return false;
    item->valor = chave;
    return true;
}
bool item_apagar(ITEM **e)
{
    if (e != NULL)
        free(*e);
}
