// TODO: continuar atividade
/**
 * 7. Mostre como uma fila pode ser implementada utilizando duas pilhas. 
 * Suponha que o descritor da fila é implementado dessa forma:
 * struct fila{ 
 *      struct pilha *P1;
 *      struct pilha *P2;
 * };
 * Implemente apenas as funções dequeue e enqueue. Leve em conta que as
 * funções de manipulação das pilhas já estão implementadas.
*/

// Supondo que já existem as funções:
// Struct nodo{int info; struct nodo *prox}; => estrutura do nodo da fila
// // void enfileira(struct fila *f, int valor); => para adicionar um valor à fila
// // int desenfileira(struct fila *f); => para remover e retornar o valor da fila
// int fila_vazia(struct fila *f); => para verificar se a fila está vazia

#include <stdio.h>
#include <stdlib.h>

//descritor da fila 
struct fila {
    struct pilha *P1; // pilha para guardar o começo da fila
    struct pilha *P2; // Pilha para guardar o fim da fila
};

