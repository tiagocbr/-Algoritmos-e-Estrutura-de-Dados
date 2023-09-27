#include "pilha.h"
int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int* visitados=(int*)malloc(sizeof(int)*((n*m)+1));
    for(int i=0;i<=n*m;i++){
        visitados[i]=0;
    }

    PILHA *adj = pilha_criar();

    int **matr=(int**)malloc(sizeof(int*)*(n+2));
    for(int i=0;i<n+2;i++){
        matr[i]=(int*)malloc(sizeof(int)*(m+2));
    }
    for(int j=0;j<=m+1;j++){
        matr[0][j]=-1;
        matr[n+1][j]=-1;
    }
    for(int i=0;i<=n+1;i++){
        matr[i][0]=-1;
        matr[i][m+1]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&matr[i][j]);
        }
    }
    int i=1;int j=1;
    int *x=(int*)malloc(sizeof(int));
    *x=1;
    pilha_empilhar(adj,x);
    int* atual;
    int ok=1;
    while(!pilha_vazia(adj)){
        atual = pilha_topo(adj);
        if(visitados[*atual]==1){pilha_desempilhar(adj);continue;}
        visitados[*atual]=1;
        i=(*atual - 1)/m + 1;
        j=(*atual-1)%m + 1;
        //printf("%d %d\n",i,j);
        int* des=pilha_desempilhar(adj);
        printf("(%d, %d)\n",i-1,j-1);
         if(matr[i][j]==2){
            ok=0;
            break;
        }
        if(matr[i+1][j]==1 || matr[i+1][j]==2){ // baixo
            int* dest=(int *)malloc(sizeof(int));
            *dest=m*(i)+j;
            if(visitados[*dest]==0){
                //printf("baixo\n");
                pilha_empilhar(adj,dest);
            }
            else free(dest);
        }

        if(matr[i][j-1]==1 || matr[i][j-1]==2){ //esquerda
            int* dest=(int *)malloc(sizeof(int));
            *dest=m*(i-1)+j-1;
            if(visitados[*dest]==0){
                //printf("esq\n");
                pilha_empilhar(adj,dest);
            }
            else free(dest);
        }

        if(matr[i-1][j]==1 || matr[i-1][j]==2){ //cima
            int* dest=(int *)malloc(sizeof(int));
            *dest=m*(i-2)+j;

            if(dest>=0){
                if(visitados[*dest]==0){
                    //printf("cima\n");
                    pilha_empilhar(adj,dest);

                }
                else free(dest);
            }else free(dest);

        }

        if(matr[i][j+1]==1 || matr[i][j+1]==2 ){  //direita
            int* dest=(int *)malloc(sizeof(int));
            *dest=m*(i-1)+j+1;
            if(visitados[*dest]==0){
                //printf("direita\n");
                pilha_empilhar(adj,dest);
            }else free(dest);
        }
    }
    if(ok){
        printf("Saída não encontrada.\n");
    }

    pilha_apagar(&adj);
    free(visitados);
}