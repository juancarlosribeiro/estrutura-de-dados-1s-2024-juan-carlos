#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

No *no(char valor, No *proximo_no)
{
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

// no inserir_no, sempre vai inserir no proximo indice
void inserir_no(No *H, char valor)
{
    if (H != NULL)
    {
        H->proximo_no = no(valor, H->proximo_no);
    }
}

void imprimir_lista(No *H, No *end)
{
    if (H != NULL)
    {
        if (H->proximo_no != end)
        {
            printf("%c\t", H->valor);
            imprimir_lista(H->proximo_no, end);
        }
        else
        {
            printf("%c\t", H->valor);
        }
    }
}

void remover_no(No *H, char valor, No *end)
{
    if (H->valor == valor)
    {
        No *no_removido = H->proximo_no;
        H->valor = H->proximo_no->valor;
        H->proximo_no = H->proximo_no->proximo_no;
        free(no_removido);
        return;
    }
    if (H != NULL)
    {
        if (H->proximo_no != end)
        {
            if (H->proximo_no->valor == valor)
            {
                No *no_removido = H->proximo_no;
                H->proximo_no = H->proximo_no->proximo_no;
                free(no_removido);
            }
            remover_no(H->proximo_no, valor, end);
        }
        else
        {
            if (H->proximo_no->valor == valor)
            {
                No *no_removido = H->proximo_no;
                H->proximo_no = H->proximo_no->proximo_no;
                free(no_removido);
            }
        }
    }
}

void liberar_lista(No *H, No *end)
{
    if (H != NULL)
    {
        if (H->proximo_no != end)
        {
            liberar_lista(H->proximo_no, end);
            free(H);
        }
        else {
            free(H);
        }
    }
}
