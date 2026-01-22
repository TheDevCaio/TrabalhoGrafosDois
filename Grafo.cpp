#include <iostream>
#include "grafo.h"

using namespace std;

No* criaNo(int v) {
    No* novo = new No;
    novo->vertice = v;
    novo->prox = NULL;
    return novo;
}

Grafo* criaGrafo(int V) {
    Grafo* g = new Grafo;
    g->V = V;
    g->adj = new No*[V + 1];

    for (int i = 1; i <= V; i++)
        g->adj[i] = NULL;

    return g;
}

void adicionaAresta(Grafo* g, int u, int v) {
    No* n1 = criaNo(v);
    n1->prox = g->adj[u];
    g->adj[u] = n1;

    No* n2 = criaNo(u);
    n2->prox = g->adj[v];
    g->adj[v] = n2;
}

void coloracaoGulosa(Grafo* g) {
    int* cor = new int[g->V + 1];
    bool* usado = new bool[g->V + 1];

    for (int i = 1; i <= g->V; i++)
        cor[i] = -1;

    cor[1] = 0;

    for (int u = 2; u <= g->V; u++) {
        for (int i = 0; i <= g->V; i++)
            usado[i] = false;

        No* temp = g->adj[u];
        while (temp != NULL) {
            int v = temp->vertice;
            if (cor[v] != -1)
                usado[cor[v]] = true;
            temp = temp->prox;
        }

        int c;
        for (c = 0; c <= g->V; c++)
            if (!usado[c]) break;

        cor[u] = c;
    }

    int maxCor = 0;
    cout << "Resultado da coloracao:\n";
    for (int i = 1; i <= g->V; i++) {
        cout << "Vertice " << i << " -> cor " << cor[i] << endl;
        if (cor[i] > maxCor) maxCor = cor[i];
    }
    cout << "Total de cores usadas: " << maxCor + 1 << endl;

    delete[] cor;
    delete[] usado;
}
