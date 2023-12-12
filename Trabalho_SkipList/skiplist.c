#include "skiplist.h"

typedef struct palavra_ pl;
typedef struct node_ node;
#define max_level 12

struct palavra_{
    char palavra[55] ;
    char definicao[145] ;
};

struct node_{
    pl* item;
    node* next;
    node* down;
    int level;
};



struct skiplist_{
    node* upleft;
    int level;
};

sl* create_sl(){

    sl* skiplist=(sl*)malloc(sizeof(sl));

    node* no = (node*)malloc(sizeof(node));
    no->item=NULL;
    no->next=NULL;
    no->down=NULL;
    no->level=0;

    skiplist->upleft=no;
    skiplist->level=0;
    return skiplist;
};

bool search_sl(sl* skiplist,char* palavra,bool imprime){
    node* sentinela=skiplist->upleft;
    while(sentinela->level>=0){

        while(sentinela->next!=NULL && strcmp(sentinela->next->item->palavra,palavra)<0){
            sentinela=sentinela->next;
        }

        if(sentinela->level==0)break;
        sentinela=sentinela->down;

    }

    if(sentinela->next==NULL || strcmp(sentinela->next->item->palavra,palavra)!=0) return false;

    if(imprime){
        printf("%s %s", sentinela->next->item->palavra,sentinela->next->item->definicao);
        putchar('\n');
    }

    return true;

}

bool inserir_sl(sl* skiplist,char* palavra,char* definicao){

    if(search_sl(skiplist,palavra,false))return false;

    node* sentinela = skiplist->upleft;
    node* updates[max_level+1]; 
    
    int node_level=0;
    float r = (float)rand() / RAND_MAX;
    while (r < 0.5 && node_level < max_level) {
        node_level++;
        r = (float)rand() / RAND_MAX;
    }

    //Guardando os nós updates
    while(sentinela->level>=0){

         while(sentinela->next!=NULL && strcmp(sentinela->next->item->palavra,palavra)<0){
            sentinela=sentinela->next;
        }

        updates[sentinela->level]=sentinela;
        if(sentinela->level==0)break;
        sentinela=sentinela->down;
    }

    //Inserindo o novo nó nos niveis ja existentes

    int current_level=0;

    pl* new_palavra=(pl*)malloc(sizeof(pl));
    strcpy(new_palavra->palavra,palavra);
    strcpy(new_palavra->definicao,definicao);

    while(current_level<=skiplist->level && current_level<=node_level){

        node* new_node=(node*)malloc(sizeof(node));
        new_node->item=new_palavra;
        new_node->level=current_level;
        new_node->next=updates[current_level]->next;
        updates[current_level]->next=new_node;

        if(current_level==0)
            new_node->down=NULL;
        else
            new_node->down=updates[current_level-1]->next;

        current_level++;
    }

    //Criando novos níveis, se necessário

    for(int i=skiplist->level+1;i<=node_level;i++){
        node* new_node=(node*)malloc(sizeof(node));
        new_node->item=new_palavra;
        new_node->level=i;
        new_node->next=NULL;
        new_node->down=updates[i-1]->next;

        node* new_upleft=(node*)malloc(sizeof(node));
        new_upleft->item = NULL;
        new_upleft->next = new_node;
        new_upleft->down = skiplist->upleft;
        new_upleft->level = i;
        skiplist->upleft=new_upleft;
        updates[i]=new_upleft;
    }
    if(node_level>skiplist->level){
        skiplist->level=node_level;
    }
    return true;
}

bool remove_sl(sl* skiplist,char* palavra){
    if(!search_sl(skiplist,palavra,false)) return false;

    node* sentinela=skiplist->upleft;
    node* updates[max_level+1];

    // Guardando os nós update para remover depois
    while(sentinela->level>=0){

         while(sentinela->next!=NULL && strcmp(sentinela->next->item->palavra,palavra)<0){
            sentinela=sentinela->next;
        }

        updates[sentinela->level]=sentinela;
        if(sentinela->level==0)break;
        sentinela=sentinela->down;
    }

    // Removendo os nós de cada nível

    int current_level=0;

    pl* palavra_remover;

    while(current_level<=skiplist->level){

        if(updates[current_level]->next!=NULL && strcmp(updates[current_level]->next->item->palavra,palavra)==0){
            node* rem = updates[current_level]->next;
            palavra_remover=rem->item;
            updates[current_level]->next = rem->next;
            free(rem);
        }

        current_level++;
    }
    free(palavra_remover);

    // Removendo os níveis que ficaram vazios

    while(skiplist->level>0 && skiplist->upleft->next==NULL){
        node* rem=skiplist->upleft;
        skiplist->upleft=skiplist->upleft->down;
        skiplist->level--;
        free(rem);
    }

    return true;
}

bool update_sl(sl* skiplist,char* palavra,char* new_def){
    if(!search_sl(skiplist,palavra,false)) return false;

    node* sentinela=skiplist->upleft;

    // Achando a palavra pra dar update
    while(sentinela->level>=0){

        while(sentinela->next!=NULL && strcmp(sentinela->next->item->palavra,palavra)<0){
            sentinela=sentinela->next;
        }
        if(sentinela->next!=NULL && strcmp(sentinela->next->item->palavra,palavra)==0){
            strcpy(sentinela->next->item->definicao,new_def);
            return true;
        }
        if(sentinela->level==0)break;
        sentinela=sentinela->down;
    }
    return false;
}

bool imprime_sl(sl* skiplist,char c){

    node* sentinela=skiplist->upleft;
    while(sentinela->level>=0){

        while(sentinela->next!=NULL && sentinela->next->item->palavra[0]<c){
            sentinela=sentinela->next;
        }

        if(sentinela->level==0)break;
        sentinela=sentinela->down;

    }

    

    if(sentinela->next==NULL || sentinela->next->item->palavra[0]!=c) return false;

    while(sentinela->next!=NULL && sentinela->next->item->palavra[0]==c){
            sentinela=sentinela->next;
            printf("%s %s",sentinela->item->palavra,sentinela->item->definicao);
            putchar('\n');
            
        }

    return true;

}

void apaga_sl(sl** skiplist){

    node* sentinela=(*skiplist)->upleft;
    while(sentinela->level>0)sentinela=sentinela->down;
    sentinela=sentinela->next;
    while(sentinela!=NULL){
        node* rem=sentinela;
        sentinela=sentinela->next;
        remove_sl(*skiplist,rem->item->palavra);
    }
    free((*skiplist)->upleft);
    free(*skiplist);
}

int tamanho(sl* skiplist){
    return skiplist->level;
}

