#ifndef FILA_H_
#define FILA_H_
#include "grafo.h"

typedef struct fila{
  no* cabeca;
}fila;

fila* criarFila();

void enfileirar(fila* fila, int ori);

int desenfileirar(fila* fila);

int filaVazia(fila* fila);

void printFila(fila* resposta);






#endif /* FILA_H_ */
