// 3. Aplique os algoritmos de percurso em-ordem, pré-ordem e pós-ordem,
// na árvore do exercício 1, e apresente os resultados.

// utilizando toda a base do exercicio 1:

#include <stdlib.h>
#include <stdio.h>

// Node of BST
struct node {
    int key;
    struct node *parent;
    struct node *right;
    struct node *left;
};

// Descriptor of the BST
struct tree {
    struct node* root;
};

// Function to initialize the BST
struct tree *initialize_tree() {
    struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
    temp->root = NULL;
    return temp;
}


// Function to insert a new node in the BST
void insert(struct tree* T, int key) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    struct node* parent = NULL;
    struct node* aux = T->root;
    
    while(aux != NULL) {
        parent = aux;
        if(new_node->key < aux->key) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    
    new_node->parent = parent;
    
    if(parent == NULL) {
        T->root = new_node;
        printf("Inserting %d as root of the tree.\n\n", new_node->key);
    } else if(new_node->key < parent->key) {
        parent->left = new_node;
        printf("Inserting %d as left child of %d.\n\n", new_node->key, parent->key);
    } else {
        parent->right = new_node;
        printf("Inserting %d as right child of %d.\n\n", new_node->key, parent->key);
    }
}

// Function to search for a node in the BST
struct node* search(struct node* node, int key){
    
    // check if node is a NULL value
    if (node == NULL) {
        printf("\nNodo percorrido: NULL\n");
        return NULL;
    }

    // show the node in the loop
    printf("\nNodo percorrido: %d\n", node->key);

    // check if the value of key is equal to the node's key
    if (key == node->key) {
        return node;
    }

    // if key value is < than the node value,
    // search in left branch of the tree  using recursion 
    if(key < node->key){
        return search(node->left, key);
    }

    // if key value is > than the node value,
    // search in right branch of the tree using recursion
    return search (node->right, key);
}

// Function that traverses the nodes in post-order and frees them
void finalize_post_order(struct node* node){
    if(node != NULL){
        finalize_post_order(node->left);
        finalize_post_order(node->right);
        free(node);
    }
}

// Function that finalizes the BST
void finalize(struct tree* T){
    finalize_post_order(T->root);
    free(T);
}

// Function in order -> print all the nodes, to the min for max value
void inOrder(struct node* node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d%c", node->key, 32); //node value + space (chr(32))
        inOrder(node->right);
    }
}

// Function pre-order -> print the node in order of access
void preOrder(struct node* node){
    if(node != NULL){
        printf("%d%c", node->key, 32); //node value + space (chr(32))
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Function post-order -> print dad node after his childrens
void postOrder(struct node* node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d%c", node->key, 32); //node value + space (chr(32))
    }
}

// main function
int main() {
    
    // create a pointer to the BST
    struct tree *tree;
    
    // initialize the tree
    tree = initialize_tree();
    
    // insert values
    insert(tree, 5);
    insert(tree, 10);
    insert(tree, 13);
    insert(tree, 20);
    insert(tree, 14);
    insert(tree, 7);
    insert(tree, 11);
    insert(tree, 25);
    insert(tree, 3);
    insert(tree, 19);
    insert(tree, 22);
    insert(tree, 6);
    insert(tree, 9);
    insert(tree, 21);
    insert(tree, 2);
    insert(tree, 12);
    insert(tree, 24);
    insert(tree, 27);
    insert(tree, 8);
    insert(tree, 23);

    // percurso em-ordem, pré-ordem e pós-ordem:

    // em ordem
    printf("Percorrendo arvore em ordem:\n");
    inOrder(tree->root);

    printf("\n\n");

    // em pré-ordem
    printf("Percorrendo arvore em pre-ordem:\n");
    preOrder(tree->root);

    printf("\n\n");

    // em pós-ordem
    printf("Percorrendo arvore em pos-ordem:\n");
    postOrder(tree->root);

    // free the BST
    finalize(tree);
}