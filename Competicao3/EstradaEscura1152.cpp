/*
 * ALunos: Diego Santos
 * Pedro Santos
 * Silvia Fonseca
 */
#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int m, n;

struct ARESTA
{
    int origem;
    int destino;
    long long int peso;
};

bool cmp(ARESTA a, ARESTA b)
{
    return a.peso < b.peso;
}

int encontrarPai(int vertice, vector<int> &root)
{
    while (root[vertice] != vertice)
    {
        root[vertice] = root[root[vertice]];
        vertice = root[vertice];
    }

    return vertice;
}

void unirVertices(int origem, int destino, vector<int> &root)
{
    int paiOrigem = encontrarPai(origem, root);
    int paiDestino = encontrarPai(destino, root);
    root[paiOrigem] = root[paiDestino];
}

int kruskal(vector<ARESTA> graph, vector<int> &root, int pesoTotal)
{
    int origem, destino;

    for (int i = 0; i < n; i++)
    {
        origem = graph[i].origem;
        destino = graph[i].destino;
        if (encontrarPai(origem, root) != encontrarPai(destino, root))
        {
            pesoTotal -= graph[i].peso;
            unirVertices(origem, destino, root);
        }
    }
    return pesoTotal;
}

int main()
{
    cin >> m >> n;
    while (m != 0 || n != 0)
    {
        vector<int> root(m);
        vector<ARESTA> graph(n);
        long long int pesoTotal = 0;
        for (int i = 0; i < m; i++)
        {
            root[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            ARESTA aux;
            cin >> aux.origem >> aux.destino >> aux.peso;
            graph[i] = aux;
            pesoTotal += aux.peso;
        }

        sort(graph.begin(), graph.end(), cmp);
        long long int pesoEconomizado = kruskal(graph, root, pesoTotal);

        cout << pesoEconomizado << endl;

        cin >> m >> n;
    }

    return 0;
}