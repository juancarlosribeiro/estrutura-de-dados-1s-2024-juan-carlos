#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    No *n1 = no('A', NULL);
    n1->proximo_no = n1;

    inserir_no(n1, 'B');
    inserir_no(n1, 'C');
    inserir_no(n1, 'D');
    inserir_no(n1, 'D');
    inserir_no(n1, 'E');
    inserir_no(n1, 'F');
    
    printf("lista apos insercoes:\t");
    imprimir_lista(n1, n1);
    printf("\n");

    remover_no(n1, 'D', n1);
    printf("lista apos remover os D:\t");
    imprimir_lista(n1, n1);
    liberar_lista(n1, n1);
}