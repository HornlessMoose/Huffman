#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <locale.h>

fila* criarFila(){
  fila* novaFila = (fila*) malloc(sizeof(fila));
  novaFila->cabeca = NULL;
  return novaFila;
}

void enfileirar(fila* fila, int vertice){
  no* novoNo = (no*) malloc(sizeof(no));
  novoNo->vertice = vertice;
  novoNo->proximo = NULL;

  if(fila->cabeca == NULL){
    novoNo->proximo = fila->cabeca;
    fila->cabeca = novoNo;
  }

  else{
    no* temp = fila->cabeca;
    while(temp->proximo != NULL) {
      temp = temp->proximo;
    }
    novoNo->proximo = temp->proximo;
    temp->proximo = novoNo;

  }

}

int desenfileirar(fila* fila){
  no* novoNo = fila->cabeca;
  fila->cabeca = fila->cabeca->proximo;
  novoNo->proximo = NULL;
  return novoNo->vertice;

}

int filaVazia(fila* fila){
	return (fila->cabeca == NULL);
}

void printFila(fila* fila){


	while(!filaVazia(fila)){
		printf("%d\n", fila->cabeca->vertice);
		fila->cabeca = fila->cabeca->proximo;
	}


}


