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
	}else if(novo_nodo->chave < pai->chave){
		pai->esq = novo_nodo;
	}else{
		pai->dir = novo_nodo;
	}
}

//Função de busca em uma ABP
struct nodo* search(struct nodo* nodo, int chave){

    if(nodo == NULL || chave == nodo->chave){
        return nodo;
    }
    if(chave < nodo->chave){
        return search(nodo->esq, chave);
    }
    return search(nodo->dir, chave);


}

//Função que encontra o menor valor da ABP
struct nodo* minimum(struct nodo* nodo){
    while(nodo->esq != NULL){
        nodo = nodo->esq;
    }
    return nodo;
}

//Função que encontra o maior valor da ABP
struct nodo* maximum(struct nodo* nodo){
    while(nodo->dir != NULL){
        nodo = nodo->dir;
    }
    return nodo;
}

//Função que encontrar o nodo sucessor de outro
struct nodo* sucessor(struct nodo* nodo){

    if(nodo->dir != NULL){
        return minimum(nodo->dir);
    }

    struct nodo *pai = nodo->pai;

    while(pai != NULL && nodo == pai->dir){
        nodo = pai;
        pai = pai->pai;
    }

    return pai;
}

//Função que encontrar o nodo predecessor de outro
struct nodo* predecessor(struct nodo* nodo){

    if(nodo->esq != NULL){
        return maximum(nodo->esq);
    }

    struct nodo *pai = nodo->pai;

    while(pai != NULL && nodo == pai->esq){
        nodo = pai;
        pai = pai->pai;
    }

    return pai;
}

//Função que percorre a ABP em ordem
void em_ordem(struct nodo* nodo){
	if(nodo != NULL){
		em_ordem(nodo->esq);
		printf("%d\n", nodo->chave);
		em_ordem(nodo->dir);
	}
}

//Função que percorre a ABP em pré-ordem
void pre_ordem(struct nodo* nodo){
	if(nodo != NULL){
		printf("%d\n", nodo->chave);
		pre_ordem(nodo->esq);
		pre_ordem(nodo->dir);
	}
}

//Função que percorre a ABP em pós-ordem
void pos_ordem(struct nodo* nodo){
	if(nodo != NULL){
		pos_ordem(nodo->esq);
		pos_ordem(nodo->dir);
		printf("%d\n", nodo->chave);
	}
}

//Função que substitui um nodo por outro
void replace(struct arvore* T, struct nodo* nodo1, struct nodo* nodo2){

	if(nodo1->pai == NULL){
		T->raiz = nodo2;
	}else if(nodo1 == nodo1->pai->esq){
		nodo1->pai->esq = nodo2;
	}else{
		nodo1->pai->dir = nodo2;
	}

	if(nodo2 != NULL){
		nodo2->pai = nodo1->pai;
	}

}

//Função que remove um nodo da ABP
void delete(struct arvore* T, struct nodo* nodo){
	if(nodo->esq == NULL){
		replace(T, nodo, nodo->dir);
	}else if(nodo->dir == NULL){
		replace(T, nodo, nodo->esq);
	}else{
		struct nodo* sucessor = minimum(nodo->dir);
		if(sucessor->pai!=nodo){
			replace(T, sucessor, sucessor->dir);
			sucessor->dir = nodo->dir;
			sucessor->dir->pai = sucessor;
		}
		replace(T, nodo, sucessor);
		sucessor->esq = nodo->esq;
		sucessor->esq->pai = sucessor;
	}
	free(nodo);
}

//Função que percorre os nodos em pós-ordem os excluindo
void finalize_pos_ordem(struct nodo* nodo){
    if(nodo != NULL){
        finalize_pos_ordem(nodo->esq);
        finalize_pos_ordem(nodo->dir);
        free(nodo);
    }

}

//Função que finaliza a ABP
void finalize(struct arvore* T){
    finalize_pos_ordem(T->raiz);
    free(T);
}

int main(){

    struct arvore *tree;
    tree = inicializa_arvore();
	insert(tree,4);
	insert(tree,2);
	insert(tree,6);
	insert(tree,1);
	insert(tree,3);
	insert(tree,5);
	insert(tree,7);

    em_ordem(tree->raiz);

	finalize(tree);

}