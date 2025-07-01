/**
 * 9. Escreva uma função que receba duas filas, cada uma contendo valores numéricos ordenados.
 * A função deve criar uma terceira fila encadeada, também ordenada, contendo todos os valores das
 * filas originais.
 */

#include <stdio.h>
#include <stdlib.h>

// implementar o nó de uma fila (node)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// implementar uma fila
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// inicializar uma fila
void initQueue (Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

// verificar se a fila está vazia
int isEmpty (Queue* q){
    return q->front == NULL;
}

// enfileirar um elemento de uma fila
void enqueue(Queue* q, int num){
    // 1º - alocar memoria para novo nó
    Node* new_node = (Node*)malloc(sizeof(Node));

    // 2º - verificar se a alocação foi bem-sucedida
    if (new_node == NULL){
        fprintf(stderr, "Falha ao alocar memoria\n\n");
        exit(EXIT_FAILURE);
    }

    // 3º - atribuir o valor ao novo nó
    new_node->data = num;
    new_node->next = NULL;

    // 4º - inserir o nodo na fila, temos que verificar se a fila está vazia. Se estiver:
        // -> Novo nó será o FRONT e o REAR;
        // -> Caso contrário, adiciona o novo nó ao final da fila.
    if  (isEmpty(q)){
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// desenfileirar um elemento
void dequeue(Queue* q){
    // 1º - criar um nodo temporário c/ o valor a ser removido e verificar se a fila está vazia
    Node* temp;
    if(q->front == NULL){
        printf("Erro: Fila vazia!\n\n");
    }

    // 2º - rmeover a cabeça da fila
    else {
        temp = q->front;
        q->front = temp->next;
        free(temp);
        
        // 3º - verificar se a frente da fila é nula, se sim, o fim da fila será atribuído como nulo
        if(q->front == NULL){
            q->rear=NULL;
        }
    }
}

/**
 * @brief 
 * Aqui vai a função que recebe as duas filas e retorna uma terceira fila que contem os valores de 
 * ambas ordenados 
 */