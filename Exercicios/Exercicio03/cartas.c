#include <stdio.h>
#include "item.h"
#include "fila.h"

void cartas(int n){
    FILA *f = fila_criar();
    for(int i=1;i<=n;i++){
        ITEM *it = item_criar(i);
        fila_inserir(f,it);
    }
    int x;
    printf("Discarded cards: ");
    while(fila_tamanho(f)>1){
        x = item_get_chave(fila_frente(f));
        fila_remover(f);
        ITEM* it=fila_remover(f);
        fila_inserir(f,it);
        if(fila_tamanho(f)==1){
            printf("%d",x);
        }
        else
        printf("%d, ",x);
    }
    x = item_get_chave(fila_frente(f));
    printf("\nRemaining card: %d\n",x);
    fila_apagar(&f);
}