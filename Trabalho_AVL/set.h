#ifndef _SET_H
#define _SET_H

  #include "avl.h" 
  #include "item.h"
 
 typedef struct set_ SET;

  //Cria um set vazio, alocando memória dinamicamente para toda a sua estrutura interna
  //O(1)
  SET *set_criar(void);

  //Faz uma busca por um elemento dentro do SET
  //Se o SET conter o elemento retorna true,caso contrário retorna false
  //Essa função tem complexidade O(logN)
  bool set_pertence(SET *A, int elemento);

  //Insere um elemento no SET
  //Se o elemento já existir,o SET continua o mesmo(não armazena elementos repetidos)
  //Complexidede O(logN)
  bool set_inserir (SET *s, int elemento);

  //Remove um elemento do set,se existir
  //Complexidade O(logN)  
  bool set_remover(SET *s, int elemento);

  //Apaga o set junto com todos os elementos dentro dele
  //Complexidade O(n);
  void set_apagar(SET **s);

  //Imprime todos os elementos do SET em ordem crescente
  //O(n)
  void set_imprimir(SET *s);

  //Retorna um SET que representa a união do SET A e B;
  //Complexidade O(nlogn)
  SET *set_uniao(SET *A, SET *B);

  //Retorna um SET que representa a interseção do SET A e B;
  //Complexidade O(nlogn)
  SET *set_interseccao(SET *A, SET *B);
  
#endif