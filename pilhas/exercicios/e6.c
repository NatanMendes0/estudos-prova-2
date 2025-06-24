/**
 * 6.  Mostre como uma pilha pode ser implementada utilizando duas filas. 
 * Suponha que odescritor da pilha é implementado dessa forma:
 * struct pilha{struct fila *F1;struct fila *F2;};
 * Implemente apenas as funções pop e push. Leve em conta que as funções
 * de manipulação das filas já estão implementadas.
 */

// Supondo que já existem as funções:
// void enfileira(struct fila *f, int valor); -> // para adicionar um valor à fila
// int desenfileira(struct fila *f); -> // para remover e retornar o valor da fila
// int fila_vazia(struct fila *f); -> // para verificar se a fila está vazia

struct pilha {
    struct fila *F1;
    struct fila *F2;
};

void push(struct pilha *p, int valor) {
    enfileira(p->F2, valor);
    while (!fila_vazia(p->F1)) {
        enfileira(p->F2, desenfileira(p->F1));
    }
    // Troca F1 e F2
    struct fila *temp = p->F1;
    p->F1 = p->F2;
    p->F2 = temp;
}

int pop(struct pilha *p) {
    if (fila_vazia(p->F1)) {
        // Pilha vazia
        return -1; // ou outro valor de erro
    }
    return desenfileira(p->F1);
}

//* EXPLICAÇÃO:
/**
 * O código implementa uma pilha (estrutura LIFO) usando duas 
 * filas (estruturas FIFO). A struct pilha possui dois ponteiros para 
 * filas, F1 e F2. As funções principais são push (empilhar) e pop 
 * (desempilhar).

* Na função push, o valor é enfileirado em F2. Depois, todos os elementos 
* de F1 são transferidos para F2, garantindo que o valor recém-inserido 
* fique na frente. Em seguida, F1 e F2 trocam de lugar: F1 passa a conter os
* elementos na ordem correta da pilha, e F2 fica vazia para o próximo uso.

* A função pop remove e retorna o elemento do topo da pilha, que está no 
* início da fila F1. Se F1 estiver vazia, retorna -1 para indicar erro 
* (pilha vazia).

* Dessa forma, a operação pop é eficiente (O(1)), enquanto push é O(n), 
* pois precisa reorganizar os elementos. Essa é uma abordagem clássica 
* para simular pilhas usando apenas operações de fila.
*/