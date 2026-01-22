#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> grafo(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vector<int> cor(n, -1);
    int cores = 0;

    for (int i = 0; i < n; i++) {
        bool pintou = false;

        for (int c = 0; c < cores; c++) {
            int conflitos = 0;

            for (int viz : grafo[i]) {
                if (cor[viz] == c)
                    conflitos++;
            }

            if (conflitos <= d) {
                cor[i] = c;
                pintou = true;
                break;
            }
        }

        if (!pintou) {
            cor[i] = cores;
            cores++;
        }
    }

    cout << "Resultado da coloracao:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertice " << i + 1 << " -> cor " << cor[i] << "\n";
    }

    cout << "Total de cores usadas: " << cores << endl;

    return 0;
}