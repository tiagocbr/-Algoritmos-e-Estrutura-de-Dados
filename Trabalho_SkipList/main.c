#include "skiplist.h"


int main(){
    char op[20];
    sl* skiplist = create_sl();
    while(scanf("%s", op)!=EOF){

        if(strcmp(op,"insercao")==0){
            char str1[55],str2[145];
            scanf("%s", str1);
            scanf(" %[^\n]%*c", str2);

            bool ok = inserir_sl(skiplist,str1,str2);
            if(!ok)printf("OPERACAO INVALIDA\n");
            continue;
        }

        if(strcmp(op,"alteracao")==0){
            char str1[55],str2[145];
            scanf("%s", str1);
            scanf(" %[^\n]%*c", str2);

            bool ok = update_sl(skiplist,str1,str2);
            if(!ok)printf("OPERACAO INVALIDA\n");
            continue;
        }

        if(strcmp(op,"remocao")==0){
            char str1[55];
            scanf("%s", str1);
            bool ok = remove_sl(skiplist,str1);
            if(!ok)printf("OPERACAO INVALIDA\n");
            continue;
        }

        if(strcmp(op,"busca")==0){
            char str1[55];
            scanf("%s", str1);
            bool ok = search_sl(skiplist,str1,true);
            if(!ok)printf("OPERACAO INVALIDA\n");
            continue;
        }

        if(strcmp(op,"impressao")==0){
            char c;
            scanf(" %c",&c);
            bool ok = imprime_sl(skiplist,c);
            if(!ok)printf("NAO HA PALAVRAS INICIADAS POR %c\n",c);
            continue;
        }

        if(strcmp(op,"tamanho")==0){
            printf("%d\n",tamanho(skiplist));
        }

    }

    apaga_sl(&skiplist);
}