/**
 * 1. Desenhe uma árvore de pesquisa binária inserindo os 
 * seguintes elementos: 15, 10, 13, 20, 14, 
 * 7, 11, 25, 3, 19, 22, 6, 9, 21, 2, 12,
 * 24, 27, 8, 23.
*/

#include <stdlib.h>
#include <stdio.h>

//Registro do nodo de uma ABP
struct nodo{
	int chave;
	struct nodo *pai;
	struct nodo *dir;
	struct nodo *esq;
};

//Registro do descritor da ABP
struct arvore{
	struct nodo* raiz;
};

//Função que inicializa a ABP
struct arvore *inicializa_arvore(){
	struct arvore* temp = (struct arvore*)malloc(sizeof(struct arvore));
	temp->raiz = NULL;
	return temp;
}

//Função que insere um novo nodo na ABP
void insert(struct arvore* T, int chave){
	struct nodo* novo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
	novo_nodo->chave = chave;
	novo_nodo->pai = NULL;
	novo_nodo->esq = NULL;
	novo_nodo->dir = NULL;

	struct nodo* pai = NULL;
	struct nodo* aux = T->raiz;

	while(aux != NULL){
		pai = aux;
		if(novo_nodo->chave < aux->chave){
			aux = aux->esq;
		}else{
			aux = aux->dir;
		}
	}

	novo_nodo->pai = pai;

	if(pai == NULL){
		T->raiz = novo_nodo;
		printf("Inserindo %d como raiz da árvore.\n\n", novo_nodo->chave);
	}else if(novo_nodo->chave < pai->chave){
		pai->esq = novo_nodo;
		printf("Inserindo %d como filho à esquerda de %d.\n\n", novo_nodo->chave, pai->chave);
	}else{
		pai->dir = novo_nodo;
		printf("Inserindo %d como filho à direita de %d.\n\n", novo_nodo->chave, pai->chave);
	}
}

//função principal
int main(){

    //criar um ponteiro da abp
    struct arvore *tree;

    //inicializar a arvore
    tree = inicializa_arvore();

	//inserir valores
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

	//liberar a abp
	free(tree);
}