#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_
#include "fila.h"
#include "pilha.h"

void topologicalSortDFS(Grafo* grafo, int tam);

void dfs(Grafo* grafo, int ori, pilha* pilha);

void topologicalSortKahn(Grafo* grafo, int tam);

#endif /* TOPOLOGICALSORT_H_ */
