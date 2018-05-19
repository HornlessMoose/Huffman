#include <stdio.h>
#include <stdlib.h>
#include "topologicalSort.h"
#define tam 8

int main(void) {

	Grafo* grafo = criarGrafo(tam);


/*	//com ciclos
	adicionarAresta(grafo, 0, 4);
	adicionarAresta(grafo, 4, 5);
	adicionarAresta(grafo, 5, 0);
	adicionarAresta(grafo, 6, 2);
	adicionarAresta(grafo, 2, 3);
	adicionarAresta(grafo, 3, 6);
*/


	//sem ciclos
	adicionarAresta(grafo, 0, 1);
	adicionarAresta(grafo, 0, 2);
	adicionarAresta(grafo, 0, 3);
	adicionarAresta(grafo, 0, 4);
	adicionarAresta(grafo, 1, 5);
	adicionarAresta(grafo, 1, 2);
	adicionarAresta(grafo, 2, 4);
	adicionarAresta(grafo, 3, 7);
	adicionarAresta(grafo, 4, 6);
	adicionarAresta(grafo, 6, 7);






	//topologicalSortDFS(grafo, tam);
	topologicalSortKahn(grafo, tam);

	getchar();


	return EXIT_SUCCESS;
}
