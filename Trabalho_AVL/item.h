#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>
	#include <stdlib.h>
	#include <stdio.h>
    
	//o ITEM guardará as informações de cada nó da AVL,que será um tipo de dado elem (nesse caso inteiro)
    typedef int elem;
	typedef struct item_ ITEM;

	//a função item_criar cria um item alocando espaço dinamicamente na memoria e retornando o ponteiro pra o item
	ITEM *item_criar(elem chave);

	//apaga o item e libera a memoria 
	bool item_apagar(ITEM **item);

	//retorna a chave do ITEM(nesse caso um inteiro)
	elem item_get_chave(ITEM *item);

	//Muda a chave do item para uma nova chave
	bool item_set_chave(ITEM *item, elem chave);

#endif
