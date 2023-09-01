#include "pilha.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha
{
	int topo;
	ITEM *itens[TAM_PILHA];
	// int *itens;
};

PILHA *pilha_criar()
{
	PILHA *p;
	p = (PILHA *)malloc(sizeof(PILHA));
	assert(p != NULL);
	// p->itens = (ITEM *)malloc(sizeof(ITEM) * TAM_PILHA);
	p->topo = -1;
	return p;
}

bool pilha_vazia(PILHA *p)
{
	assert(p != NULL);

	if (p->topo == -1)
		return true;
	else
		return false;
}

bool pilha_cheia(PILHA *p)
{
	assert(p != NULL);

	if (p->topo == TAM_PILHA - 1)
		return true;
	else
		return false;
}

bool pilha_empilhar(PILHA *p, ITEM *x)
{
	if (!pilha_cheia(p))
	{
		p->topo++;
		p->itens[p->topo] = x;
		return true;
	}
	return false;
}

ITEM *pilha_desempilhar(PILHA *p)
{
	if (!pilha_vazia(p))
	{
		p->topo--;
		return p->itens[p->topo + 1];
	}
	return NULL;
}

ITEM *pilha_topo(PILHA *p)
{
	if (!pilha_vazia(p))
	{
		return p->itens[p->topo];
	}
	return NULL;
}

void esvaziar(PILHA *p)
{
	assert(p != NULL);
	while (p->topo != -1)
	{
		item_apagar(&p->itens[p->topo]);
		p->topo--;
	}
}

void pilha_apagar(PILHA **p)
{
	esvaziar(*p);
	free(*p);
}
