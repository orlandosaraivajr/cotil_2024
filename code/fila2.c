/*
 * Exemplo do uso de fila dinâmica com uso de structs e ponteiros.
 *
 * Prof. Me. Orlando Saraiva Jr
 */
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
struct Node {
    int data;
    struct Node* next;
};

// Definição da estrutura da fila
struct Fila {
    struct Node* front;
    struct Node* rear;
};

// Inicializa uma fila vazia
void inicializar(Fila* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

// Insere um elemento no fim da fila
void enqueue(Fila* Q, int d) {
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro: não foi possível alocar memória\n");
        exit(-1);
    }
    novoNode->data = d;
    novoNode->next = NULL;

    // Se a fila estiver vazia, o novo nó será tanto o início quanto o fim da fila
    if (Q->rear == NULL) {
        Q->front = novoNode;
        Q->rear = novoNode;
    } else {
        Q->rear->next = novoNode;
        Q->rear = novoNode;
    }
}

// Remove e retorna o elemento do início da fila
int dequeue(Fila* Q) {
    if (Q->front == NULL) {
        fprintf(stderr, "Erro: fila vazia\n");
        exit(-1);
    }

    struct Node* temp = Q->front;
    int retorno = temp->data;
    Q->front = Q->front->next;

    // Se a fila ficar vazia após a remoção, ajustar o ponteiro rear para NULL
    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    free(temp);
    return retorno;
}

// Imprime os elementos da fila
void imprime_fila(Fila* Q) {
    struct Node* temp = Q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Libera a memória alocada para a fila
void limpar_fila(Fila* Q) {
    while (Q->front != NULL) {
        dequeue(Q);
    }
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

    limpar_fila(&minhaFila);

    return 0;
}

