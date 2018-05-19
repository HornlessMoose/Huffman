#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct no{
    int vertice;
    struct no* proximo;
}no;

typedef struct Grafo{
    int numVertices;
    no** adjLista;
    short *visitado;

}Grafo;

no* criarNo(int vertice);

Grafo* criarGrafo(int vertices);

void adicionarAresta(Grafo* grafo, int ori, int dest);





#endif /* GRAFO_H_ */
