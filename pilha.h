#ifndef PILHA_H_
#define PILHA_H_
#include "grafo.h"

typedef struct pilha{
	no* topo;
}pilha;

pilha* criarPilha();

void colocarPilha(pilha *pilha, int vertice);

int retirarPilha(pilha *pilha);

int pilhaVazia(pilha *pilha);

void printPilha(pilha* pilha);

#endif /* PILHA_H_ */
