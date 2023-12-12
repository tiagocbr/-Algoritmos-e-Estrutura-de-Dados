#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct skiplist_ sl;

sl* create_sl();
bool search_sl(sl* skiplist,char* palavra,bool imprime);
bool inserir_sl(sl* skiplist,char* palavra,char* definicao);
bool update_sl(sl* skiplist,char* palavra,char* new_def);
bool remove_sl(sl* skiplist,char* palavra);
bool imprime_sl(sl* skiplist,char c);
void apaga_sl(sl** skiplist);
int tamanho(sl* skiplist);