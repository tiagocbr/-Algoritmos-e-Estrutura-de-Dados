#ifndef _PILHA_H
#define _PILHA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define TAM_PILHA 10000000

typedef struct pilha PILHA;

PILHA *pilha_criar(void);
void pilha_apagar(PILHA **pilha);
bool pilha_vazia(PILHA *pilha);
bool pilha_cheia(PILHA *pilha);
int pilha_tamanho(PILHA *pilha);
int *pilha_topo(PILHA *pilha);
bool pilha_empilhar(PILHA *pilha, int *item);
int *pilha_desempilhar(PILHA *pilha);
void pilha_print(PILHA *p);
bool balanceada(char *sequencia);

#endif