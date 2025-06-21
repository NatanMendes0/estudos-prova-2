/**
 * 4. Faça uma função que receba duas pilhas, P_Positivo e P_Negativo, e leia um conjunto
 * de 50 valores inteiros. Armazene os valores positivos (incluindo zero) na pilha P_Positivo
 * e os valores negativos na pilha P_Negativo. Ao final, imprima todos os elementos de cada
 * uma das pilhas.
 */

#include <stdio.h>
#include <stdlib.h>

// criar a estrutura do nó da pilha
typedef struct Node
{
    int data;
    struct Node *next; // ponteiro para o próximo elemento
} Node;

// estrutura da pilha (descritor)
typedef struct
{
    Node *top; // apontar para o elemento no topo da pilha
} Stack;

// criar uma pilhas vazia
Stack *init()
{

    // alocando a pilha positiva na memoria
    Stack *s = (Stack *)malloc(sizeof(Stack));

    // passar o descritor como null
    s->top = NULL;

    //retornar a pilha
    return s;
}

// verificar se a pilha estiver vazia
int is_empty(Stack *s)
{
    return s->top == NULL;
}

// adicionar um elemento no topo da pilha
void push(Stack *s, int data)
{

    // alocar um novo novo na memoria
    Node *new_node = (Node *)malloc(sizeof(Node));

    // atribuit dado no novo nodo
    new_node->data = data;

    // alocar novo nodo
    new_node->next = s->top;

    // novo nodo vai para o topo da lista
    s->top = new_node;

    printf("Elemento %d inserido na pilha. \n", data);
}

// organizar pilhas com o valor passado pela função
void organizarPilhas(Stack *positivos, Stack *negativos, int data)
{
    if (data >= 0)
    {
        push(positivos, data);
    }
    else
    {
        push(negativos, data);
    }
}

// Função para imprimir todos os elementos de uma pilha
void print_stack(const char *nome, Stack *s)
{
    printf("%s: ", nome);
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// função principal
int main(){

    // iniciar as pilhas
    Stack *P_Positiva = init();
    Stack *P_Negativa = init();

    // Conjunto de 50 valores inteiros (positivos, negativos e zero)
    int valores[50] = {
        10, -5, 0, 23, -17, 8, -2, 15, -9, 4,
        -11, 7, 0, -3, 19, -20, 6, -8, 2, -1,
        13, -6, 0, 21, -14, 5, -7, 12, -4, 3,
        -10, 9, 0, -12, 18, -15, 11, -13, 1, -16,
        14, -18, 16, -19, 17, -21, 20, -22, 22, -23};

    // laço de repetição para organizar as pilhas
    int i;
    for (i = 0; i < (sizeof(valores) / sizeof(valores[0])); i++){
        organizarPilhas(P_Positiva, P_Negativa, valores[i]);
        printf("Organizado.\n\n");
    }

    //mostrando os elementos das pilhas
    print_stack("P_Positiva", P_Positiva);
    print_stack("P_Negativa", P_Negativa);

    // liberando as pilhas
    free(P_Positiva);
    free(P_Negativa);

    return 0;
}