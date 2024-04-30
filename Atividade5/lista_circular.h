typedef struct No
{
    char valor;
    struct No* proximo_no;
} No;

No *no(char valor, No *proximo_no);

void inserir_no(No* H, char valor);

void imprimir_lista(No* H, No* end);

void remover_no(No* H, char valor, No* end);

void liberar_lista(No* H, No* end);