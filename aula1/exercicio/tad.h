typedef struct
{
    char *nome, *end;
} pessoa_t;

typedef struct
{
    pessoa_t *lista;
    int size;
    int pointer;
} banco_t;

banco_t *criar(int tamanho);
void incluir(char *nome, char *end, banco_t *b);
void excluir(char *nome, banco_t *b);
char *find(char *nome, banco_t *b);
void destruir(banco_t *b);
