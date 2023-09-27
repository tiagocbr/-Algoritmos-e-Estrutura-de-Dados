#include "pilha.h"
struct pilha
{
	int topo;
	int *itens[TAM_PILHA];
};

PILHA *pilha_criar()
{
	PILHA *p;
	p = (PILHA *)malloc(sizeof(PILHA));
	assert(p != NULL);
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

bool pilha_empilhar(PILHA *p, int *x)
{
	if (!pilha_cheia(p))
	{
		p->topo++;
		p->itens[p->topo] = x;
		return true;
	}
	return false;
}

int *pilha_desempilhar(PILHA *p)
{
	if (!pilha_vazia(p))
	{
		p->topo--;
		return p->itens[p->topo + 1];
	}
	return NULL;
}

int *pilha_topo(PILHA *p)
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
		free(p->itens[p->topo]);
		p->topo--;
	}
}

void pilha_apagar(PILHA **p)
{
	esvaziar(*p);
	free(*p);
}
