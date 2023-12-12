#include "item.h"

// O item guarda as informações de cada nó da AVL, que no caso será um tipo de dado elem (pode ser inteiro,char,float,é so mudar a definicao no item.h)
struct item_ {
    elem valor;
};

ITEM *item_criar(elem chave){
    ITEM* it=(ITEM*)malloc(sizeof(ITEM));
    it->valor=chave;
    return it;
}

bool item_apagar(ITEM **item){
    if(item!=NULL){
        free(*item);
        return true;
    }
    return false;
};

elem item_get_chave(ITEM *item){
    return item->valor;
}

bool item_set_chave(ITEM *item, elem chave){
    if(item!=NULL){
        item->valor=chave;
        return true;
    }
    return false;
}