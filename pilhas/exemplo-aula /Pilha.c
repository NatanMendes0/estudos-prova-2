#include <stdio.h>
#include <stdlib.h>

//Estrutura de um nodo da pilha
struct nodo{
	int info;
	struct nodo *prox;
};

//Descritor da pilha
struct pilha{
	struct nodo *topo;
};

//Função de inicialização da pilha
struct pilha *init(){
	struct pilha* temp = (struct pilha *)malloc(sizeof(struct pilha));
	temp->topo = NULL;
	return temp;
}

//Função de destruição da pilha
void finalize(struct pilha *desc){
	struct nodo *inicio, *temp;
	inicio = desc->topo;
	while(inicio != NULL){
		temp = inicio->prox;
		free(inicio);
		inicio = temp;
	}
	free(desc);
}

//função de inserção de um novo nodo na pilha
void push(struct pilha *desc, int info){
	
	struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));
	novo_nodo->info = info;
	novo_nodo->prox = desc->topo;
	desc->topo = novo_nodo;
	
}

//Função de remoção do nodo no topo da pilha
void pop(struct pilha *desc){
	struct nodo *temp;
	if(desc->topo == NULL){
		printf("Erro\n");
		return;
	}else{
		temp = desc->topo;
		desc->topo = temp->prox;
		free(temp);
	}
}

int main(){

	struct pilha *pilha;

	pilha = init();

	push(pilha, 5);
	push(pilha, 4);
	push(pilha, 3);
	push(pilha, 2);
	push(pilha, 1);


	struct nodo *temp = pilha->topo;

	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp = temp->prox;
	}


	finalize(pilha);


}
