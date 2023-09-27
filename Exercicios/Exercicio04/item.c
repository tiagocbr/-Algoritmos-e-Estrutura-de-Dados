#include "item.h"

struct item_{
    int valor;
};


ITEM *item_criar(int chave){
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
void item_imprimir(ITEM *item){
    printf("%d",item->valor);
}
int item_get_chave(ITEM *item){
    return item->valor;
}
bool item_set_chave(ITEM *item, int chave){
    if(item!=NULL){
        item->valor=chave;
        return true;
    }
    return false;
}