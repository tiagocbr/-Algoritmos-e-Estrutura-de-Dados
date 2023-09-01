#include "Pilha.h"
#include "item.h"

bool balanceada(char *sequencia)
{
    PILHA *p = pilha_criar();
    for (int i = 0; sequencia[i] != '\0'; i++)
    {
        if (sequencia[i] == '(' || sequencia[i] == '[' || sequencia[i] == '{')
        {
            ITEM *x = item_criar(sequencia[i]);
            pilha_empilhar(p, x);
        }
        else
        {
            if (pilha_vazia(p))
            {
                pilha_apagar(&p);
                return false;
            }
            if ((sequencia[i] == ')' && item_get_chave(pilha_topo(p)) == '(') || (sequencia[i] == ']' && item_get_chave(pilha_topo(p)) == '[') || (sequencia[i] == '}' && item_get_chave(pilha_topo(p)) == '{'))
            {
                pilha_desempilhar(p);
            }
            else
            {
                return false;
                pilha_apagar(&p);
            }
        }
    }
    if (pilha_vazia(p))
    {
        pilha_apagar(&p);
        return true;
    }
    pilha_apagar(&p);
    return false;
}