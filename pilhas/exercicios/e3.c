/**
    3. Dependendo do conjunto de operações selecionadas, uma fila dupla pode comportar-se como uma pilha ou como uma fila. 
    Isso é muito vantajoso em aplicações que precisam desses dois tipos de dados simultaneamente. 
    Que conjunto de operações devemos usar com uma fila dupla para que ela se comporte como: 
    a) Uma pilha? 
        - Devemos usar inserção e remoção pelo mesmo extremo (por exemplo, sempre pelo início ou sempre pelo fim).
    b) Uma fila?
        - Devemos usar inserção em um extremo (por exemplo, no fim) e remoção no outro extremo (por exemplo, no início).
*/

/*
    Explicação:
    => Fila Dupla (Deque):
    Uma fila dupla (ou deque, de "double-ended queue") é uma estrutura de dados que permite inserção e remoção de elementos 
    tanto no início quanto no fim da fila.

    a) Comportamento de Pilha
    Pilha segue o princípio LIFO (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido.
    Para simular uma pilha usando uma fila dupla, você deve inserir e remover sempre pelo mesmo extremo 
    (por exemplo, sempre pelo início ou sempre pelo fim).
    Exemplo: Se você sempre insere e remove pelo fim, o último elemento inserido será o primeiro a sair, igual a uma pilha.
    
    b) Comportamento de Fila
    Fila segue o princípio FIFO (First In, First Out), ou seja, o primeiro elemento inserido é o primeiro a ser removido.
    Para simular uma fila usando uma fila dupla, você deve inserir em um extremo e remover no outro.
    Exemplo: Inserir sempre no fim e remover sempre do início. Assim, o primeiro elemento inserido será o primeiro a sair, 
    igual a uma fila comum.
    
    ---------------------------

    => Resumindo
    Pilha com deque: Inserção e remoção pelo mesmo lado.
    Fila com deque: Inserção em um lado e remoção no outro.
    
    ---------------------------
    
    => Analogia:
    
    Pense em uma fila dupla como um corredor com portas nas duas extremidades:
    Se você só usa uma porta para entrar e sair, está usando como uma pilha.
    Se entra por uma porta e sai pela outra, está usando como uma fila.
*/