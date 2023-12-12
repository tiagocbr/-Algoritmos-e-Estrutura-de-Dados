#ifndef _avl_H
#define _avl_H

#include "item.h"

//Usaremos a estrutura de dados AVL para fazer o set
typedef struct no_ NO;
typedef struct avl_ AVL;

//Cria uma avl vazia,alocando memória dinamicamente
//O(1)
AVL *avl_cria();

//Apaga a avl junto com todos os nós,liberando espaço na memória
//O(n)
void avl_apagar(AVL *A);

//Imprime todos os elementos da AVL em ordem crescente
//O(n)
void avl_imprimir(AVL *A);

//Realiza uma busca para achar um nó com uma chave específica
//Complexidade O(logN)
bool avl_busca(AVL *A, elem chave);

//Insere um elemento na AVL preservando sua estrutura balanceada, se necessário fazendo rotações
//Se o nó ja existir na AVL,não acontece nada
//Complexidade O(logN)
void avl_inserir(AVL *A, elem chave);

//Remove um elemento na AVL preservando sua estrutura balanceada, se necessário fazendo rotações
//Se o nó a ser removido nao existir,a função retorna falso
//Complexidade O(logN)
bool avl_remover(AVL *A, elem chave);

//Percorre a AVL inteira colocando seus elementos sequenciamente do menor para o maior no array vetor
//Note que o vetor resultante é um array ordenado com os elementos da AVL(essa propriedade será usada para auxiliar na função set_interseção)
//Essa função é utilizada para auxiliar na realização das operações de União e Inteseção do SET
//Complexidade O(n)
void avl_para_vetor(AVL *arvore,ITEM** vetor);

//Retorna o número de elementos da AVL
//O(1)
int avl_tamanho(AVL* arvore);

#endif