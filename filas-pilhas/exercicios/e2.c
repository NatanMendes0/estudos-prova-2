/**
     2. Dada uma fila Q esteja inicialmente vazia, mostre como seu estado se modifica à
    medida que a sequência de operações a seguir é executada: 
    1 -enqueue(5, Q);
    2 - enqueue(4, Q);
    3 -dequeue(Q);
    4 - enqueue(9, Q);
    5 - dequeue(Q);
    6 -enqueue(10, Q);
    7 - enqueue(12, Q);
    8 - dequeue(Q);
    9 - dequeue(Q);
    10 - enqueue(2, Q);
    11 - dequeue(Q);
    12 - dequeue(Q); 
*/

/**
 * 1 - 5
 * 2 - 5, 4
 * 3 - 4
 * 4 - 4, 9 
 * 5 - 9 
 * 6 - 9, 10
 * 7 - 9, 10, 12
 * 8 - 10, 12
 * 9 - 12
 * 10 - 12, 2
 * 11 - 2
 * 12 - null
 */