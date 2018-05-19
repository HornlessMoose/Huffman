#include <stdio.h>
#include <stdlib.h>
#include "topologicalSort.h"
#include <locale.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2


void topologicalSortDFS(Grafo* grafo, int tam){
	setlocale(LC_ALL, "Portuguese");
	pilha *pilha = criarPilha();
	int i, tamF = 0;

	for(i = 0;i < tam; i++){
		if(grafo->visitado[i] == BRANCO){
			tamF++;
			dfs(grafo, i, pilha);
		}
		else if(grafo->visitado[i] == PRETO) tamF++;

	}

	//printf("%d ", tamF);
	if(tamF == tam){
		puts("Uma possível ordenação topologica é:");
		printPilha(pilha);
	}
	else
		puts("O grafo pussui ao menos um ciclo e a ordenação topologica não e possível");
}


void dfs(Grafo* grafo, int ori, pilha* pilha){
	grafo->visitado[ori] = CINZA;
	no* adjLista = grafo->adjLista[ori];

	while (adjLista != NULL) {
		if (grafo->visitado[adjLista->vertice] == BRANCO){

			dfs(grafo, adjLista->vertice,pilha);

		}
		else if(grafo->visitado[adjLista->vertice] == CINZA)
			return;
		adjLista = adjLista->proximo;
	}
	grafo->visitado[ori] = PRETO;

	colocarPilha(pilha,ori);
}


void topologicalSortKahn(Grafo* grafo, int tam){

	setlocale(LC_ALL, "Portuguese");


	int* indegree = calloc(tam,sizeof(int));
	int i, vertice, tamF = 0;
	fila* q = criarFila();
	fila* resposta = criarFila();
	no* adjLista;

	for(i = 0; i < tam; i++){
		adjLista = grafo->adjLista[i];
		while(adjLista != NULL){
			indegree[adjLista->vertice]++;
			adjLista = adjLista->proximo;
		}
	}

	for(i = 0 ; i < tam; i++)
		if(!indegree[i])enfileirar(q, i);

	while(!filaVazia(q)){
		vertice = desenfileirar(q);
		enfileirar(resposta, vertice);
		tamF++;

		adjLista = grafo->adjLista[vertice];

		while(adjLista != NULL){
			if(--indegree[adjLista->vertice] == 0){
				enfileirar(q, adjLista->vertice);
			}
			adjLista = adjLista->proximo;
		}
	}

	if(tamF == tam)printFila(resposta);
	else
		puts("O grafo pussui ao menos um ciclo e a ordenação topologica não e possível");

}
