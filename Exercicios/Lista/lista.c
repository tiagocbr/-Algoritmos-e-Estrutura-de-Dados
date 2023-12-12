#include "lista.h"

    typedef struct node_ NO;

    struct node_{
        ITEM* valor;
        NO* next;
        NO* prev;
    };

    struct lista_{
        NO* ini;
        NO* fim;
    };

	LISTA *lista_criar(void){
        LISTA*lista=(LISTA*)malloc(sizeof(LISTA));
        lista->ini=NULL;
        lista->fim=NULL;
    }
	bool lista_inserir(LISTA *lista, ITEM *item){
        if(lista==NULL || item==NULL)return false;
        NO* no=(NO*)malloc(sizeof(NO));
        no->valor=item;
        no->next=NULL;
        no->prev=lista->fim;
        lista->fim=no;
        if(lista->ini==NULL){
            lista->ini=no;
        }
        else{
            (no->prev)->next=no;
        }
        return true;

    }
        
	ITEM *lista_remover(LISTA *lista, int chave){
        NO* aux=lista->fim;
        lista->fim=(lista->fim)->prev;
        (lista->fim)->next=NULL;
        free(aux);
    }
	bool lista_apagar(LISTA **lista){
        if(lista==NULL)return false;
        while((*lista)->ini!=NULL){
            NO* aux=(*lista)->ini;
            (*lista)->ini=aux->next;
            free(aux);
        }
        free(*lista);
        return true;

    }

	bool lista_vazia(LISTA *lista){
        if(lista->ini==NULL)return true;
        else return false;
    }

	void lista_imprimir(LISTA *lista){
        NO* aux=lista->ini;
        while(aux!=NULL){
            printf("[%d]; ",item_get_chave(aux->valor));
            aux=aux->next;
        }
        putchar('\n');   
    }
    bool lista_inverter(LISTA **lista){
        if(lista==NULL)return false;
        NO* aux=(*lista)->ini;
        (*lista)->ini=(*lista)->fim;
        (*lista)->fim=aux;
        while(aux!=NULL){
            NO* temp=aux->next;
            aux->next=aux->prev;
            aux->prev=temp;
            aux=temp;
        }
        return true; 
    }