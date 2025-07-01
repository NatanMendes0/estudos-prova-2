/**
 * F, F_Impares e F_Pares. Ela
 * separa todos os valores presentes
 * em F, movendo os valores pares
 * para a fila F_Pares e os
 * valores ímpares para F_Impares.
 * O objetivo é organizar os
 * elementos de F conforme sua
 * paridade, esvaziando F no
 * processo e preenchendo as filas
 * de pares e ímpares adequadamente.
 */

#include <stdio.h>
#include <stdlib.h>

//implementação do nó de uma fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//implementação da fila
typedef struct {
    Node* front;
    Node* rear;
} Queue;

//função para inicializar a fila
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

//função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

//função para enfileirar um elemento
void enqueue(Queue* q, int value) {

    //alocar memória para o novo nó
    Node* newNode = (Node*)malloc(sizeof(Node));

    // verificar se a alocação foi bem-sucedida
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // atribuir o valor ao novo nó
    newNode->data = value;
    newNode->next = NULL;

    // se a fila estiver vazia, o novo nó será o front e o rear
    // caso contrário, adiciona o novo nó ao final da fila
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// funçao para desenfileirar um elemento
void dequeue(Queue* q) {
    Node *temp;
    if(q->front==NULL){
        printf("Erro: Fila Vazia\n\n"); // tentou remover algo de uma fila vazia
    } else {
        temp = q->front;
        q->front = temp->next;
        free(temp);
        if(q->front==NULL){
            q->rear=NULL;
        }
    }
}

// função para ordenar os valores da fila F em F_Pares e F_Impares
void ordenarFilas(Queue *q, Queue *q_impar, Queue *q_par){
    /**
     * @brief Essa parte deve:
     * - Checar se o valor atual do nodo avaliado é par ou impar;
     * - Inserir o valor do nodo num novo nodo da respectiva fila;
     * - Remover o nodo da fila original
     */
    while(!isEmpty(q)){
        if(q->front->data % 2 == 0){
            enqueue(q_par, q->front->data);
            dequeue(q);
        } else {
            enqueue(q_impar, q->front->data);
            dequeue(q);
        }
    }
}

// função de destruir filas
void finalize (Queue *q){
    Node *inicio, *temp;
    inicio = q->front;
    while(inicio != NULL) {
        temp = inicio->next;
        free(inicio);
        inicio = temp;
    }
    free(q);
}

// mostrar os valores de uma fila
void mostrarFila(Queue *q) {
    Node *current = q->front;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

//função principal
int main() {
    Queue *F, *F_Pares, *F_Impares;
    F = (Queue*)malloc(sizeof(Queue));
    F_Pares = (Queue*)malloc(sizeof(Queue));
    F_Impares = (Queue*)malloc(sizeof(Queue));
    initQueue(F);
    initQueue(F_Pares);
    initQueue(F_Impares);

    // exemplo de enfileiramento de valores na fila F
    int i;
    for (i = 0; i <= 20; i++) {
        enqueue(F, i);
    }

    // receber os valores de F e separá-los em F_Pares e F_Impares
    ordenarFilas(F, F_Impares, F_Pares);

    // mostrar as filas e seus valores
    printf("Imprimindo a fila de pares:\n\n");
    mostrarFila(F_Pares);

    printf("\n\nImprimindo a fila de impares:\n\n");
    mostrarFila(F_Impares);
    
    return 0;
}