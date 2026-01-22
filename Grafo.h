#ifndef GRAFO_H
#define GRAFO_H

struct No {
    int vertice;
    No* prox;
};

struct Grafo {
    int V;
    No** adj;
};

No* criaNo(int v);
Grafo* criaGrafo(int V);
void adicionaAresta(Grafo* g, int u, int v);
void coloracaoGulosa(Grafo* g);

#endif
