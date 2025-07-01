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

// receber duas filas ordenadas e criar uma terceira com todos os valores ordenados
Queue* orderNewQueue(Queue* q1, Queue* q2){
    Queue* merged = (Queue*)malloc(sizeof(Queue));
    initQueue(merged);
    Node *n1 = q1->front;
    Node *n2 = q2->front;

    while (n1 != NULL && n2 != NULL) {
        if (n1->data <= n2->data) {
            enqueue(merged, n1->data);
            n1 = n1->next;
        } else {
            enqueue(merged, n2->data);
            n2 = n2->next;
        }
    }
    while (n1 != NULL) {
        enqueue(merged, n1->data);
        n1 = n1->next;
    }
    while (n2 != NULL) {
        enqueue(merged, n2->data);
        n2 = n2->next;
    }
    return merged;
}

// imprimir a fila
void showQueue(Queue* q){
    Node* current = q->front;
    printf("[");
    while (current != NULL){
        printf("%d", current->data);
        if(current->next != NULL){
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n\n");
}

// destruir a fila
void finalize(Queue*q){
    Node *first, *temp;
    first = q->front;
    while(first != NULL){
        temp = first->next;
        free(first);
        first = temp;
    }
    free(q);
}

// função principal
int main (){
    // declarar duas filas e alocar seus espaços na memória
    Queue *f1, *f2;
    f1 = (Queue*)malloc(sizeof(Queue));
    f2 = (Queue*)malloc(sizeof(Queue));

    // iniciar as filas
    initQueue(f1);
    initQueue(f2);

    // preencher filas com números aleatórios ordenados
    int i, j;
    int val = rand() % 10;
    for (i = 0; i < 10; i++) {
        val += rand() % 10 + 1; // garante ordem crescente
        enqueue(f1, val);
    }
    val = rand() % 10;
    for (j = 0; j < 10; j++) {
        val += rand() % 10 + 1;
        enqueue(f2, val);
    }

    // verificar se foi possível criar as filas
    if(isEmpty(f1) || isEmpty(f2)){
        printf("Não foi possível criar as filas");
        return -1;
    }

    // mostrar as filas antes de mesclar
    printf("Fila 1:\n");
    showQueue(f1);    
    printf("Fila 2:\n");
    showQueue(f2);

    // chamar função que cria uma fila com o valores de f1 e f2
    Queue* merged = orderNewQueue(f1, f2);
    printf("Fila mesclada:\n");
    showQueue(merged);
    
    // destruir filas
    finalize(f1);
    finalize(f2);
    finalize(merged);

    return 0;
}