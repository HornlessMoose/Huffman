#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* criarPilha(){
	pilha* novaPilha = malloc(sizeof(pilha));
	novaPilha->topo = NULL;
	return novaPilha;
}

void colocarPilha(pilha *pilha, int vertice){
	no *novoNo = malloc(sizeof(no));
	novoNo->vertice = vertice;
	novoNo->proximo = pilha->topo;
	pilha->topo = novoNo;
}

int retirarPilha(pilha *pilha){
	if(!pilhaVazia(pilha)){
		int result = pilha->topo->vertice;
		no *removido = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		free(removido);

		return result;
	}

	return -1;
}

int pilhaVazia(pilha *pilha){
	return (pilha->topo == NULL);
}

void printPilha(pilha* pilha){
	while(!pilhaVazia(pilha)){
		printf("%d\n",retirarPilha(pilha));
	}
}

