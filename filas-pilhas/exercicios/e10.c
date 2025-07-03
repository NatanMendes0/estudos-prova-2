// 10. Faça um algoritmo que cadastre em uma pilha vários números.
// Posteriormente, o algoritmo deve gerar duas filas, a primeira com
// os números pares e a segunda com os números ímpares que estavam
// na pilha. A saída o programa deve apresentar a pilha digitada e
// as filas geradas. Caso alguma das filas seja vazia, deve-se mostrar
// uma mensagem.

#include <stdlib.h>
#include <stdio.h>

// * FUNCTIONS FOR QUEUES:
// implement the node of a queue
typedef struct queue_node {
    int data;
    struct queue_node* next;
} QueueNode;

// implement a queue
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// initialize a queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// enqueue an element into the queue
void enqueue(Queue* q, int num) {
    // allocate memory for new node
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));

    // check if allocation was successful
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory\n\n");
        exit(EXIT_FAILURE);
    }

    // assign value to the new node
    new_node->data = num;
    new_node->next = NULL;

    // insert the node into the queue
    if (isQueueEmpty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// dequeue an element from the queue
void dequeue(Queue* q) {
    QueueNode* temp;
    if (q->front == NULL) {
        printf("Error: Queue is empty!\n\n");
    } else {
        temp = q->front;
        q->front = temp->next;
        free(temp);

        // if the queue becomes empty, set rear to NULL
        if (q->front == NULL) {
            q->rear = NULL;
        }
    }
}

// print the queue
void showQueue(Queue* q){
    QueueNode* current = q->front;
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

// destroy the queue
void finalizeQueue(Queue* q){
    QueueNode *first, *temp;
    first = q->front;
    while(first != NULL){
        temp = first->next;
        free(first);
        first = temp;
    }
    free(q);
}

// * FUNCTIONS FOR STACKS: 
// node from a stack
typedef struct node
{
    int info;
    struct node* next;
} Node;

// stack descritor
typedef struct stack
{
    struct node *top;
} Stack;

// init a stack
Stack* init(){
    //alloc in memory
    Stack* temp = (Stack* )malloc(sizeof(struct stack));
    temp->top = NULL;
    return temp;
}

// destruct a stack
void finalize(Stack* desc){
    Node *beg, *temp;
    beg = desc->top;

    // run into the stack and free their nodes
    while(beg != NULL){
        temp = beg->next;
        free(beg);
        beg = temp;
    }

    //delete desc
    free(desc);
}

// insert a new node in the stack
void push(Stack *desc, int info){

    // alloc new node in memory
    Node *new_node = (Node *)malloc(sizeof(Node *));

    //new node receives their new value and goes to the top
    new_node->info = info;
    new_node->next = desc->top;
    desc->top = new_node;
}

// check if stack is empty
int isEmpty(Stack *s){
    return s->top == NULL;
}

// remove the top node in the stack
void pop(Stack *desc){
    Node *temp;

    // check if the stack is not empty and remove their nodes. 
    // If the stack is already empty, returns a messagem for user
    if (!isEmpty(desc)) {
        temp = desc->top;
        desc->top = temp->next;
        free(temp);
    } else {
        printf("Erro: Sua pilha ja esta vazia!\n\n");
        return;
    }
}

// show stack values
void showStack(Stack *s){
    //run into stack nodes and show their values
    Node *curr = s->top;
    printf("[");
    while(curr != NULL){
        printf("%d%c", curr->info, 32);
        
        // add the "," in the printf
        if (curr->next != NULL) {
            printf(",%c", 32);
        }

        curr = curr->next;
    }
    printf("]\n\n");
}

// organize the stack into two queues with their values (odd -> q1 and even -> q2)
// Struct to hold two queues
typedef struct {
    Queue* odd;
    Queue* even;
} QueuesPair;

// organize the stack into two queues with their values (odd -> odd, even -> even)
QueuesPair organizeEvenOdd(Stack *s) {
    // alloc and init queues
    Queue *q1 = (Queue*)malloc(sizeof(Queue));
    Queue *q2 = (Queue*)malloc(sizeof(Queue));
    initQueue(q1);
    initQueue(q2);

    // run into stack and organize the queues based on even or odd
    Node *temp = s->top;
    while (temp != NULL) {
        if (temp->info % 2 == 0) {
            enqueue(q2, temp->info); // even
        } else {
            enqueue(q1, temp->info); // odd
        }
        temp = temp->next;
    }

    QueuesPair result;
    result.odd = q1;
    result.even = q2;
    return result;
}

// main function
int main(){
    
    Stack *s;
    s = init();

    int i;
    for(i = 0; i < 15; i++){
        push(s, i);
    }

    // show the initial stack
    printf("Pilha inicial:\n");
    showStack(s);

    // call the function that separates stack data into two Queues (even or odd) and show their values
    QueuesPair queues = organizeEvenOdd(s);
    
    printf("\n");
    printf("Fila de valores pares:\n");
    showQueue(queues.even);
    
    printf("\n");
    printf("Fila de valores ímpares:\n");
    showQueue(queues.odd);
    
    // check if queues are empty
    if (isQueueEmpty(queues.even)) {
        printf("A fila de valores pares está vazia.\n\n");
    }
    if (isQueueEmpty(queues.odd)) {
        printf("A fila de valores ímpares está vazia.\n\n");
    }

    // free queues and stacks
    finalizeQueue(queues.even);
    finalizeQueue(queues.odd);
    finalize(s);
}