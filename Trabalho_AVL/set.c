#include "set.h"

//O set basicamente é uma avl
struct set_{
    AVL* avl;
};

//As funções set_pertence,set_inserir,set_remover e set_imprimir utilizam diretamente as funções de busca,inserção,remoção e impressão da AVL

SET *set_criar(void){
    AVL* avl = avl_cria();
    SET* set = (SET*)malloc(sizeof(SET));
    set->avl = avl;
    return set;
}

bool set_pertence(SET *A, elem elemento){
    return avl_busca(A->avl,elemento);
}

bool set_inserir (SET *s, elem elemento){
    avl_inserir(s->avl,elemento);
}

bool set_remover(SET *s, elem elemento){
    avl_remover(s->avl,elemento);
}

void set_apagar(SET **s){
    avl_apagar((*s)->avl);
    free(*s);
}

void set_imprimir(SET *s){
    avl_imprimir(s->avl);
}

//A função set_união guarda em dois arrays os elementos de cada SET,utilizando a função avl_para_vetor
//Após isso,percorre-se cada vetor adicionando seus elementos no novo SET C e retorna o set C
SET *set_uniao(SET *A, SET *B){
    SET* C=set_criar();
    int size_a=avl_tamanho(A->avl);
    int size_b=avl_tamanho(B->avl);
    ITEM** lista1 = (ITEM**)malloc(sizeof(ITEM*)*(size_a));
    ITEM** lista2 = (ITEM**)malloc(sizeof(ITEM*)*(size_b));
    avl_para_vetor(A->avl,lista1);
    avl_para_vetor(B->avl,lista2);
    //inserir todos os elementos das listas 1 e 2 no set C e retornar o set C
    for(int i=0;i<size_a;i++){
        avl_inserir(C->avl,item_get_chave(lista1[i]));
    }
    for(int i=0;i<size_b;i++){
        avl_inserir(C->avl,item_get_chave(lista2[i]));
    }

    free(lista1);
    free(lista2);
    return C;
}


//A função set_interseção guarda em dois arrays os elementos de cada SET,utilizando a função avl_para_vetor
//Note que a função avl_para_vetor já retorna o array ordenado com os elementos de cada SET
//Utilizaremos da ordenação para encontrar a interseção mais facilmente
SET *set_interseccao(SET *A, SET *B){
    SET* C=set_criar();
    int size_a=avl_tamanho(A->avl);
    int size_b=avl_tamanho(B->avl);
    ITEM** lista1 = (ITEM**)malloc(sizeof(ITEM*)*(size_a));
    ITEM** lista2 = (ITEM**)malloc(sizeof(ITEM*)*(size_b));
    avl_para_vetor(A->avl,lista1);
    avl_para_vetor(B->avl,lista2);
    
    //Lista que guardará a interseção
    ITEM** lista3 = (ITEM**)malloc(sizeof(ITEM*)*(size_b > size_a ? size_a : size_b)); //o tamanho da interseção é no maximo o mínimo entre size_a e size_b
    
    //Algoritmo para encontrar a interseção em O(n)
    //i atua como um ponteiro na lista 1 
    //j atua como um ponteiro na lista 2
    int i=0,j=0,sz=0;
    while(i<size_a && j<size_b){
        //Se o elemento está em ambas as listas 1 e 2,então ele deve ser adicionado na lista 3
        if(item_get_chave(lista1[i])==item_get_chave(lista2[j])){
            lista3[sz]=lista1[i];
            sz++;i++;j++;continue;
        }
        //Se o elemento i da lista 1 for menor que o elemento j da lista 2,então deve-se ir pro próximo elemento da lista 1
        if(item_get_chave(lista1[i])<item_get_chave(lista2[j])){
            i++;continue;
        }

        //Se o elemento j da lista 2 for menor que o elemento i da lista 1,então deve-se ir para o próximo elemento da lista 2
        if(item_get_chave(lista1[i])>item_get_chave(lista2[j])){
            j++;continue;
        }
    }

    //Inserir todos os elementos da interseção no set C
    for(int i=0;i<sz;i++){
        avl_inserir(C->avl,item_get_chave(lista3[i]));
    }

    free(lista1);
    free(lista2);
    free(lista3);
    
    return C;
}