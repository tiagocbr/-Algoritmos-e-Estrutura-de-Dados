typedef struct
{
    int *lista;
} conj_t;

conj_t *criar();
void uniao(conj_t *A, conj_t *B, conj_t *C);
void intersecao(conj_t *A, conj_t *B, conj_t *C);
void diferenca(conj_t *A, conj_t *B, conj_t *C);
int membro(int x, conj_t *A);
void inserir(int x, conj_t *A);
void remover(int x, conj_t *A);
void liberar(conj_t *A);
void imprimir(conj_t *A);
