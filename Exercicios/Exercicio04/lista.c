#include "lista.h"

    struct lista_{
        ITEM* lista[TAM_MAX];
        int topo;
    };

    int b_search(ITEM** arr,int valor,int tam){
        int ini=0;
        int fim=tam-1;
        int res=tam;
        while(ini<=fim){
            int meio=(ini+fim)/2;
            int atual=item_get_chave(arr[meio]);
            if(atual<valor)ini=meio+1;
            else{
                res=meio;
                fim=meio-1;
            }
        }
        return res;
    }

	LISTA *lista_criar(void){
        LISTA*lista=(LISTA*)malloc(sizeof(LISTA));
        lista->topo=-1;
    }
	bool lista_inserir(LISTA *lista, ITEM *item){
        if(lista==NULL || item==NULL || lista->topo==TAM_MAX-1)return false;
        int valor=item_get_chave(item);
        int pos=b_search(lista->lista,valor,lista->topo+1);
        lista->topo++;
        for(int i=lista->topo;i>pos;i--){
            lista->lista[i]=lista->lista[i-1];
        }
        lista->lista[pos]=item;
        return true;
    }
	ITEM *lista_remover(LISTA *lista, int chave){
        if(lista==NULL || lista->topo==-1)return NULL;
        int pos=b_search(lista->lista,chave,lista->topo+1);
        if(pos==lista->topo+1)return NULL;
        int ct=0;
        for(int i=pos;item_get_chave(lista->lista[i])!=chave;i++){
            ct++;
            item_apagar(&(lista->lista[i]));
        }
        lista->topo-=ct;
        for(int i=pos;i<=lista->topo;i++){
            lista->lista[i]=lista->lista[i+ct];
        }
        return lista->lista[pos];
    }
	void lista_apagar(LISTA **lista){
        for(int i=0;i<=(*lista)->topo;i++){
            item_apagar(&((*lista)->lista[i]));
        }
        free(*lista);
    }
	ITEM *lista_busca(LISTA *lista, int chave){
        int pos=b_search(lista->lista,chave,lista->topo+1);
        if(pos==lista->topo+1)return NULL;
        else return lista->lista[pos];
    }

	int lista_tamanho(LISTA *lista){
        return lista->topo+1;
    }
	bool lista_vazia(LISTA *lista){
        if(lista->topo==-1)return true;
        else return false;
    }
	bool lista_cheia(LISTA *lista){
        if(lista->topo==TAM_MAX-1)return true;
        else return false;
    }
	void lista_imprimir(LISTA *lista){
        for(int i=0;i<lista->topo;i++){
            printf("[%d]; ",item_get_chave(lista->lista[i]));
        }
        printf("[%d];",item_get_chave(lista->lista[lista->topo]));
    }