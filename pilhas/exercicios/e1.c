// 1. Dada uma pilha S esteja inicialmente vazia, mostre como seu estado se modifica à
// medida que a sequência de operações a seguir é executada: 
// push(5, S);
// push(4, S);
// pop(S);
// push(9, S);
// pop(S);
// push(10, S);
// push(12, S);
// pop(S);
// pop(S);
// push(2, S);
// pop(S);
// pop(S);

/**
 * 1 - 5
 * 2 - 5, 4
 * 3 - 5
 * 4 - 5, 9
 * 5 - 5
 * 6 - 5, 10
 * 7 - 5, 10, 12
 * 8 - 5, 10
 * 9 - 5
 * 10 - 5, 2
 * 11 - 5
 */