#include <iostream>
#include "grafo.h"

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    Grafo* g = criaGrafo(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adicionaAresta(g, u, v);
    }

    coloracaoGulosa(g);
    return 0;
}