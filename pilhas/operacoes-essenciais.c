#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct Node
{
    int data;
    struct Node* next; // ponteiro para o próximo elemento da pilha
} Node;

// Estrutura da pilha (Descritor)
typedef struct
{
    Node* top; // Ponteiro para o elemento do topo
} Stack;

// Criar uma pilha vazia
Stack* init() {
    
    //alocamos a pilha na memoria
    Stack* s = (Stack*) malloc(sizeof(Stack));

    // Passamos o descritor como NULL
    s->top = NULL;

    // Retornamos a pilha
    return s;
}

// retornar verdadeiro se a pilha estiver vazia
int is_empty(Stack* s){
    return s-> top == NULL;
}

// adicionar um elemento no topo da linha 
void push(Stack* s, int data){
    
    // alocar novo nodo na memória
    Node* new_node = (Node*) malloc(sizeof(Node));

    // atribuir dado no novo nodo
    new_node->data = data;

    // alocar novo nodo 
    new_node->next = s->top;

    // novo nodo vai para o topo da lista
    s->top = new_node;

    printf("Elemento %d inserido na pilha. \n", data);
}

// remover o elemento do topo da pilha e retorná-lo
int pop(Stack* s){
    
    // verificar se a lista está vazia
    if (is_empty(s)){
        printf("Erro: Pilha está vazia (Stack Underflow). \n");
        return -1; // retornar um valor de erro
    }
    
    //atribuir uma variavel temporária para o topo da lista
    Node* temp = s->top;

    // atribuir o elemento deletado numa var
    int popped_data = temp->next;

    // Atualiza o topo da pilha para o próximo elemento, removendo o elemento atual do topo
    s->top = s->top->next;

    // liberar variavel temp
    free(temp);

    return popped_data;
}


// retornar o valor do topo sem removê-lo
int top(Stack* s){
   
    // verificar se a pilha está vazia primeiro
    if (is_empty(s)){
        printf("Pilha está vazia.\n");
        return -1;
    }

    // retornar o topo
    return s->top->data;
}
