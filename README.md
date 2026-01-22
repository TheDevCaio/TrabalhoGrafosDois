Este código foi compilado usando MSYS2 (UCRT64) no Windows.

❌ Não funciona direto no PowerShell
✅ Use o terminal MSYS2 UCRT64

1. Abrir o terminal

No Windows, procure por MSYS2

Abra MSYS2 UCRT64

2. Ir até a pasta do projeto

3. Compilar: g++ main.cpp Graph.cpp -o main

4. Executar: ./main

5. Exemplo de entrada:

5 6 1
1 2
1 3
2 3
2 4
3 5
4 5

Observações: 

Na primeira linha do exemplo de entrada:

5 → número de vértices

6 → número de arestas

1 → d = número máximo de conflitos permitidos por vértice

👉 Esse 1 é o que faz ser d-defectivo
