#include "avl.h"


//O nó da AVL armazenará um item,ponteiros para os nós filhos esquerdo e direito, a altura e fator de balanceamento do nó(que serão usados na inserção/remoção para fazer as rotações)
struct no_ {
	ITEM *valor;
	NO *esq, *dir;
	int altura, FB;
};

//a avl guardará um ponteiro para o nó raiz e o tamanho da arvore(size)
struct avl_ {
	NO *raiz;
    int size;
};

//cria uma avl vazia com tamanho 0 e a raiz apontando para NULL
AVL *avl_cria() {
    AVL* arvore=(AVL*)malloc(sizeof(AVL));
    arvore->raiz=NULL;
    arvore->size=0;
    return arvore;
}

//apaga um nó e todos os seus subsequentes na árvore,liberando a memória do nó e do item que tem dentro do nó
void no_apagar(NO *A) {
    if(A==NULL)return;
    no_apagar(A->esq);
    no_apagar(A->dir);
    item_apagar(&(A->valor));
    free(A);
}

//aloca espaço na memória para um nó e para o item que tem dentro dele,o valor desse nó é passado como parametro,e inicialmente tem altura 1
NO* no_criar(elem valor) {
    NO* no=(NO*)malloc(sizeof(NO));
    ITEM* item=item_criar( valor);
    no->valor=item;
    no->esq=NULL;
    no->dir=NULL;
    no->FB=0;
    no->altura=1;
    return no;
}

//apaga a AVL inteira,liberando o espaço na memoria
void avl_apagar(AVL *A) {
    no_apagar(A->raiz);
    free(A);
}

//imprime todos os nós subsequentes ao no A da AVL,em ordem crescente
void imprimir_em_ordem(NO *A) {
    if(A==NULL)return;
    imprimir_em_ordem(A->esq);
    printf("%d, ",item_get_chave(A->valor));
    imprimir_em_ordem(A->dir);
    
}

//imprime a AVL inteira,em ordem crescente
void avl_imprimir(AVL *A) {
    imprimir_em_ordem(A->raiz);
    printf("\n");
}

//retorna a altura do no A com base na altura dos seus filhos,essa função é usada para atualizar as alturas e os Fatores de balanceamento quando um nó é inserido/removido ou quando é feita uma rotação
int altura_no(NO* A) {
    if(A==NULL)return 0;
    int h1= (A->esq)==NULL ? 0: A->esq->altura;
    int h2= (A->dir)==NULL ? 0: A->dir->altura;
    if(h1<h2)h1=h2;
    return h1+1;
}

//Realiza uma busca na sub-árvore do no A da AVL, utilizando sua estrutura para diminuir a complexidade da busca
bool busca_no(NO* A,elem chave) {
    if(A==NULL)return false;
    if(chave==item_get_chave(A->valor))return true;
    if(chave<item_get_chave(A->valor))return busca_no(A->esq,chave);
    else return busca_no(A->dir,chave);
    
}

//Realiza uma busca a partir do nó raiz da AVL
bool avl_busca(AVL *A, elem chave) {
    return busca_no(A->raiz,chave);
}

//Rotação esquerda,direita e direita-esquerda.Utilizadas para modificar a estrutura da AVL após inserções/remoções de maneira a manter sua estrutura balanceada
//Após a rotação é necessario atualizar as alturas e fator de balanceamento dos nós envolvidos
NO *rotacao_EE(NO *desb){
    NO *aux;
    aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;

    desb->altura=altura_no(desb);
    aux->altura=altura_no(aux);
    aux->FB=altura_no(aux->esq)-altura_no(aux->dir);
    desb->FB=altura_no(desb->esq)-altura_no(desb->dir);
    return aux;
}

NO *rotacao_DD(NO* desb){
    NO* aux;
    aux=desb->esq;
    desb->esq =  aux->dir;
    aux->dir= desb;
    
    desb->altura=altura_no(desb);
    aux->altura=altura_no(aux);
    aux->FB=altura_no(aux->esq)-altura_no(aux->dir);
    desb->FB=altura_no(desb->esq)-altura_no(desb->dir);
    return aux;
}

NO *rotacao_ED(NO* desb){
    desb->esq=rotacao_EE(desb->esq);              
    return (rotacao_DD(desb));
}

NO* rotacao_DE(NO* desb){
    desb->dir=rotacao_DD(desb->dir);
    return(rotacao_EE(desb));
}

//Função para inserir um nó na sub-árvore do nó A ,preservando sua estrutura e forma
NO* inserir_no(NO *A, elem chave, bool *inserido){
    //Se chegarmos no nó NULL significa que é aqui que o novo nó deve ser inserido
    if(A==NULL){
        NO* novo=no_criar(chave);
        *inserido=true;
        return novo;
    }
    
    //Se a chave for menor que o valor do nó,o novo nó deve ser inserido na esquerda,caso contrario direita
    if(chave<item_get_chave(A->valor))A->esq=inserir_no(A->esq,chave,inserido);
    else if(chave>item_get_chave(A->valor))A->dir=inserir_no(A->dir,chave,inserido);
    else *inserido=false;

    //Após a inserção é necessario atualizar a altura do nó e seu fator de balanceamento
    A->altura=altura_no(A);
    A->FB=altura_no(A->esq) - altura_no(A->dir);

    if(A->FB>1){
        if(A->esq->FB<0)A=rotacao_ED(A); //Caso em que o nó A está com FB=2 e o filho possui FB = -1
        else A=rotacao_DD(A);  //Caso em que o nó A tem FB=2 e o filho tem FB>=0
    }
    if(A->FB<-1){
        if(A->dir->FB>0)A=rotacao_DE(A); //Caso em que o nó A está com FB=-2 e o filho possui FB=1
        else A=rotacao_EE(A);  //Caso em que o nó A possui FB=-2 e o filho possui FB<=0
    }
    return A;
}

//Função para inserir um nó na AVL,utiliza a função inserir_no partindo da raiz
void avl_inserir(AVL *A, elem chave) {
    bool inserido = false;
    A->raiz=inserir_no(A->raiz,chave,&inserido);
    if(inserido)A->size++;
}

//Função que retorna o nó com maior valor na sub-arvore do nó A,essa função é utilizada para auxiliar na função de remoção
NO* maior_valor(NO* A){
    if(A->dir==NULL)return A;
    return maior_valor(A->dir);
}

//Função para remover um nó na sub-árvore do nó A ,preservando sua estrutura e forma
NO* no_remover(NO* A,elem chave,bool *removido){
    //Se chegar em um nó nulo,significa que o elemento a ser removido na árvore nao existe
    if(A==NULL)return NULL;

    //Caso o nó A seja o elemento a ser removido
    if(chave==item_get_chave(A->valor)){
        *removido = true;
        if(A->esq==NULL){
            if(A->dir==NULL){ //Caso em que o nó a ser removido é uma folha
                item_apagar(&(A->valor));
                free(A);
                return NULL;
            }
            else{ //Caso em que o nó a ser removido so tem o filho direito
                item_apagar(&(A->valor));
                A->valor=item_criar(item_get_chave(A->dir->valor));
                A->dir = no_remover(A->dir,item_get_chave(A->dir->valor),removido);
            }
        }
        else{
            if(A->dir==NULL){ //Caso em que o  nó a ser removido so tem o filho esquerdo
                item_apagar(&(A->valor));
                A->valor=item_criar(item_get_chave(A->esq->valor));
                A->esq = no_remover(A->esq,item_get_chave(A->esq->valor),removido);
            }
            else{  //Caso em que o nó a ser removido tem filhos esquerdo e direito 

                //O nó B é o maior nó da sub-árvore da esquerda, o Valor do nó A assumirá o valor do nó B, que será removido depois;
                NO* B = maior_valor(A->esq); 
                item_apagar(&(A->valor));
                A->valor= item_criar(item_get_chave(B->valor)); 
                A->esq = no_remover(A->esq,item_get_chave(B->valor),removido); 

            }
        }
    
    }

    //Se a chave for menor do que o valor do nó A,significa que devemos procurar o nó na sub-árvore da esquerda,caso contrario procuraremos na árvore direita
    else if(chave<item_get_chave(A->valor))A->esq = no_remover(A->esq,chave,removido);
    else if(chave>item_get_chave(A->valor))A->dir = no_remover(A->dir,chave,removido);


    //Após a remoção atualiza-se a altura e o fator de balanceamento do nó A,e faz-se as rotações necessárias,analogamente a inserção
    A->altura=altura_no(A);
    A->FB=altura_no(A->esq) - altura_no(A->dir);
    if(A->FB>1){
        if(A->esq->FB<0)A=rotacao_ED(A);
        else A=rotacao_DD(A);
    }
    if(A->FB<-1){
        if(A->dir->FB>0)A=rotacao_DE(A);
        else A=rotacao_EE(A);
    }

    return A;
}

//Função para remover um nó da AVL, utiliza a função no_remover na raiz da AVL
bool avl_remover(AVL *A, elem chave){
    bool removido = false;
    A->raiz=no_remover(A->raiz,chave,&removido);
    if(removido)A->size--;
}

//Percorre toda a subárvore de um Nó,colocando seus elementos em um vetor
void preencher_vetor(NO *raiz, ITEM **vetor, int *indice) {
    if (raiz != NULL) {
        preencher_vetor(raiz->esq, vetor, indice);
        vetor[*indice] = raiz->valor;
        (*indice)++;
        preencher_vetor(raiz->dir, vetor, indice);
    }
}

//Coloca todos os elemtos da AVL em um vetor,utiliza a função preencher_vetor na raiz da AVL
void avl_para_vetor(AVL *arvore,ITEM** vetor) {
    int indice = 0;
    preencher_vetor(arvore->raiz, vetor, &indice);
}

//retorna o número de elementos da AVL
int avl_tamanho(AVL* arvore){
    return arvore->size;
}
