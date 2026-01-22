#include "Grafo.h"

Grafo* criarGrafo(int n) {
    Grafo* g = new Grafo;
    g->n = n;
    g->adj = new No*[n];

    for (int i = 0; i < n; i++)
        g->adj[i] = nullptr;

    return g;
}

void adicionarAresta(Grafo* g, int u, int v) {
    No* a = new No{v, g->adj[u]};
    g->adj[u] = a;

    No* b = new No{u, g->adj[v]};
    g->adj[v] = b;
}

int* coloracaoDDefectiva(Grafo* g, int d, int& totalCores) {
    int* cor = new int[g->n];
    for (int i = 0; i < g->n; i++)
        cor[i] = -1;

    totalCores = 0;

    for (int u = 0; u < g->n; u++) {
        bool pintou = false;

        for (int c = 0; c < totalCores; c++) {
            int conflitos = 0;
            No* p = g->adj[u];

            while (p) {
                if (cor[p->v] == c)
                    conflitos++;
                p = p->prox;
            }

            if (conflitos <= d) {
                cor[u] = c;
                pintou = true;
                break;
            }
        }

        if (!pintou) {
            cor[u] = totalCores;
            totalCores++;
        }
    }

    return cor;
}