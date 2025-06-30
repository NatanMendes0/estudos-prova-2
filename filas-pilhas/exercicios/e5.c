/**
 * 5. Escreva uma função que receba duas pilhas e 
 * verifique se elas são iguais. O algoritmo deve 
 * retornar 1 se as duas pilhas forem iguais e 0 
 * caso contrário. Ao final da execução, as duas 
 * pilhas devem permanecer no mesmo estado em que 
 * estavam no início.
 */

#include <stdio.h>
#include <stdlib.h>

//criar a estrutura do nó da pilha
typedef struct Node {
    int data;
    struct Node *next; //apontar para o próximo elemento
} Node; //<- alias para a estrutura

//estrutura da pilha
typedef struct {
    Node *top; // apontar para o elemento no topo da pilha
} Stack;

//criar uma pilha vazia
Stack *init(){
    //alocando a pilha na memoria
    Stack *s = (Stack *)malloc(sizeof(Stack));

    //passar o descritor como null
    s->top = NULL;

    //retornar a pilha
    return s;
}

//verificar se a pilha está vazia
int is_empty(Stack *s){
    return s->top == NULL;
}

//adicionar um elemento no topo da pilha
void push(Stack *s, int data){
    
    //alocar um novo espaço na memória
    Node *new_node = (Node*)malloc(sizeof(Node));

    //atribuir o valor de data ao novo nodo
    new_node->data = data;

    //proximo elemento do novo nodo recebe o último elemento da lista
    new_node->next = s->top;

    //topo da lista recebe o novo nodo
    s->top = new_node;

    printf("Elemento %d inserido na pilha. \n", new_node->data);
}

//função que compara as pilhas
int verificarIguais(Stack *s1, Stack *s2){
    Node *p1 = s1->top;
    Node *p2 = s2->top;

    while (p1 != NULL && p2 != NULL) {
        printf("Comparando: p1->data = %d, p2->data = %d\n", p1->data, p2->data);
        if (p1->data != p2->data) {
            printf("\nPilhas com conteudo diferentes!\n");
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Se ambos chegaram ao fim, são iguais. Se só um chegou, tamanhos diferentes.
    if (p1 == NULL && p2 == NULL) {
        printf("\nPilhas com conteudo iguais!\n");
        return 1;
    } else {
        printf("\nPilhas com tamanhos diferentes!\n");
        return 0;
    }


}

int main(){

    //iniciar as pilhas
    Stack *p1 = init();
    Stack *p2 = init();

    // * TESTE 1: CINCO VALORES IGUAIS
    //adicionar 5 valores iguais nas pilhas
    int i;
    for (i = 0; i < 5; i++) {
        push(p1, i);
        push(p2, i);
    }
    
    //invocar a função de verificar as listas
    verificarIguais(p1, p2);

    // * TESTE 2: CINCO VALORES DIFERENTES
    // Esvaziar as pilhas antes do teste
    while (!is_empty(p1)) {
        Node *tmp = p1->top;
        p1->top = p1->top->next;
        free(tmp);
    }
    while (!is_empty(p2)) {
        Node *tmp = p2->top;
        p2->top = p2->top->next;
        free(tmp);
    }
    
    //adicionar 5 valores diferentes nas pilhas
    for (i = 0; i < 5; i++) {
        push(p1, i);
        push(p2, i+2);
    }
    
    //invocar a função de verificar as listas
    verificarIguais(p1, p2);

    // * TESTE 3: PILHAS DE TAMANHOS DIFERENTES
    // Esvaziar as pilhas antes do teste
    while (!is_empty(p1)) {
        Node *tmp = p1->top;
        p1->top = p1->top->next;
        free(tmp);
    }
    while (!is_empty(p2)) {
        Node *tmp = p2->top;
        p2->top = p2->top->next;
        free(tmp);
    }

    // Adicionar 10 valores em p1 e 15 valores em p2
    for (i = 0; i < 10; i++) {
        push(p1, i);
    }
    for (i = 9; i < 0; i--) {
        push(p2, i+1);
    }

    // Invocar a função de verificar as listas
    verificarIguais(p1, p2);

    //verificar se as listas não estão vazias
    is_empty(p1);
    is_empty(p2);

    //liberar todos os nós das pilhas antes de liberar as pilhas
    while (!is_empty(p1)) {
        Node *tmp = p1->top;
        p1->top = p1->top->next;
        free(tmp);
    }
    while (!is_empty(p2)) {
        Node *tmp = p2->top;
        p2->top = p2->top->next;
        free(tmp);
    }

    //liberar as pilhas
    free(p1);
    free(p2);

    return 0;
}