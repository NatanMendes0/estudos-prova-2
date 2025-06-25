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

// * push() => considerando que a função push já está criada
// * pilha_vazia() => considerando que há uma função de verificar uma pilha vazia
// * pop() => considerando que há uma função de remover e retornar o primeiro elemento da pilha

#include <stdio.h>
#include <stdlib.h>

//descritor da fila 
typedef struct fila {
    struct pilha *P1; // pilha para guardar o começo da fila
    struct pilha *P2; // Pilha para guardar o fim da fila
} Fila;

//enfileirar -> inserir elementos na pilha P1
void enqueue(Fila *f, int valor){
    //adicionar um novo valor na pilha de entrada p1
    push(f->P1, valor); 
}

//desenfileirar -> remover e retornar o elemento do "ínicio" da fila
int dequeue(Fila *f){
    //se a pilha de saida (P2) estiver vazia, precisamos transferir os elementos da pilha de entrada (P1) pra ela
    if(pilha_vazia(f->P2)){ 
        while (!pilha_vazia(f->P1)){
            //remove do topo de P1 e insere no topo de P2. isso inverte a ordem dos elementos
            push(f->P2, pop(f->P1));
        }
    }

    //se P2 ainda estiver vaza, significa que a fila inteira está vazia
    if(pilha_vazia(f->P2)){
        //fila vazia
        return -1;
    }

    //a pilha de saída P2 agora tem o elemento mais antigo no topo, resta removê-lo e retorná-lo.
    return pop(f->P2);
}