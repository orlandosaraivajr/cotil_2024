/*
 * Exemplo do uso de fila com uso de vetor.
 *
 * Prof. Me. Orlando Saraiva Jr
 */
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 6

struct Fila {
    int data[QUEUE_MAX];
    int inicio;
    int fim;
    int size;
};

void inicializar(Fila *Q) {
    Q->inicio = 0;
    Q->fim = 0;
    Q->size = 0;
}

void enqueue(Fila *Q, int d) {
    if (Q->size < QUEUE_MAX) {
        Q->data[Q->fim] = d;
        Q->fim = (Q->fim + 1) % QUEUE_MAX;
        Q->size++;
    } else {
        fprintf(stderr, "Erro: fila cheia\n");
    }
}

int dequeue(Fila *Q) {
    if (Q->size == 0) {
        fprintf(stderr, "Erro: fila vazia\n");
        exit(-1);
    } else {
        int retorno = Q->data[Q->inicio];
        Q->inicio = (Q->inicio + 1) % QUEUE_MAX;
        Q->size--;
        return retorno;
    }
}

void imprime_fila(Fila *Q) {
    int i;
    for (i = 0; i < Q->size; i++) {
        int idx = (Q->inicio + i) % QUEUE_MAX;
        printf("%d ", Q->data[idx]);
    }
    printf("\n");
}

int main() {
    Fila minhaFila;
    int valor;

    inicializar(&minhaFila);

    enqueue(&minhaFila, 3);
    imprime_fila(&minhaFila);
    enqueue(&minhaFila, 5);
    imprime_fila(&minhaFila);
    enqueue(&minhaFila, 1);
    imprime_fila(&minhaFila);

    valor = dequeue(&minhaFila);
    printf("Valor removido da fila:\t %d\n", valor);
    imprime_fila(&minhaFila);
    
    valor = dequeue(&minhaFila);
    printf("Valor removido da fila:\t %d\n", valor);
    imprime_fila(&minhaFila);
    
    valor = dequeue(&minhaFila);
    printf("Valor removido da fila:\t %d\n", valor);

    return 0;
}
