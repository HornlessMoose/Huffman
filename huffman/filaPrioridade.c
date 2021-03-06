#include <stdio.h>
#include <stdlib.h>
#include "HuffmanArvore.h"
#include "filaPrioridade.h"

HuffmanArvore* criarNo(void* byte,int frequencia){
	HuffmanArvore* novoNo = (HuffmanArvore*) malloc(sizeof(HuffmanArvore));

	novoNo->byteArvore = malloc(sizeof(Byte));
	novoNo->frequencia = frequencia;

	novoNo->esquerda = novoNo->direita = novoNo->proximo = NULL;


	*(Byte*)novoNo->byteArvore = *(Byte*)byte;

	return novoNo;

}

filaPrioridade* criarFila(){
	filaPrioridade* novaFila = (filaPrioridade*) malloc(sizeof(filaPrioridade));

	novaFila->cabeca = NULL;

	return novaFila;
}



void construirFila(filaPrioridade* fila, int* frequencia){
	int i;
	for(i = 0; i < 256; i++)
		if(frequencia[i])
			enfileirar(fila, criarNo(&i, frequencia[i]));


}

int filaVazia(filaPrioridade* fila){
    return (fila->cabeca == NULL);

}

void enfileirar(filaPrioridade* fila, HuffmanArvore* novoNo){


	if(filaVazia(fila) || fila->cabeca->frequencia >= novoNo->frequencia){
		novoNo->proximo = fila->cabeca;
		fila->cabeca = novoNo;
	}
	else{
		HuffmanArvore* temp = fila->cabeca;
		while(temp->proximo != NULL && temp->proximo->frequencia < novoNo->frequencia){
			temp = temp->proximo;
		}
		novoNo->proximo = temp->proximo;
		temp->proximo = novoNo;

	}
}

HuffmanArvore* desenfileirar(filaPrioridade* fila){
	if(!filaVazia(fila)){
		HuffmanArvore* No = fila->cabeca;
		fila->cabeca = fila->cabeca->proximo;
		No->proximo = NULL;
		return No;
	}
	return NULL;
}

HuffmanArvore* construirArvore(filaPrioridade* fila){
	HuffmanArvore* novoNo = criarArvoreVazia();
	Byte byte = '*';

	while(fila->cabeca->proximo != NULL){
		novoNo = criarNo(&byte, 0);

		novoNo->esquerda = desenfileirar(fila);
		novoNo->direita = desenfileirar(fila);

		novoNo->frequencia = novoNo->esquerda->frequencia + novoNo->direita->frequencia;

		enfileirar(fila, novoNo);
	}

	return fila->cabeca;
}
