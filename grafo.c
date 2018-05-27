#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

no* criarNo(int vertice){
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->vertice = vertice;
    novoNo->proximo = NULL;
    return novoNo;
}


Grafo* criarGrafo(int numVertices){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;

    grafo->adjLista = (no**)malloc(numVertices * sizeof(no));
    grafo->visitado = (short*) malloc(numVertices * sizeof(short));


    int i;
    for (i = 0; i < numVertices; i++){
        grafo->adjLista[i] = NULL;
        grafo->visitado[i] = 0;

    }

    return grafo;
}


void adicionarAresta(Grafo* grafo, int ori, int dest){

    no* novoNo = criarNo(dest);
    no* temp;

    if(grafo->adjLista[ori] == NULL || dest < grafo->adjLista[ori]->vertice){
      novoNo->proximo = grafo->adjLista[ori];
      grafo->adjLista[ori] = novoNo;
    }

    else{
      temp = grafo->adjLista[ori];

      while(temp->proximo != NULL){
        if(temp->proximo->vertice < dest)
          temp = temp->proximo;
        else break;
      }

      novoNo->proximo = temp->proximo;
      temp->proximo = novoNo;

    }

}

