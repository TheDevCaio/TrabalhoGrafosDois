#ifndef GRAFO_H
#define GRAFO_H

struct No {
    int v;
    No* prox;
};

struct Grafo {
    int n;
    No** adj;
};

Grafo* criarGrafo(int n);
void adicionarAresta(Grafo* g, int u, int v);
int* coloracaoDDefectiva(Grafo* g, int d, int& totalCores);

#endif