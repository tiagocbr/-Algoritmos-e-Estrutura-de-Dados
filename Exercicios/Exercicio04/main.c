#include "lista.h"

int main(){
    int n;scanf("%d",&n);
    LISTA *lista=lista_criar();
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        lista_inserir(lista,item_criar(x));
    }
    lista_imprimir(lista);
    lista_apagar(&lista);
}