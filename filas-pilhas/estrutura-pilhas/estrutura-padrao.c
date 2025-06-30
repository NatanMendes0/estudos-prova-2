#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha (Descritor)
typedef struct
{
    Node* top; // Ponteiro para o elemento do topo
} stack;
