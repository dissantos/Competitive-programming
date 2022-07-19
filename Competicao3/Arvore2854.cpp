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

int familias, num_pessoas, num_ligacoes;

void dfs(vector<vector<int>> &grafo, vector<int> &vertices_visitados, int vertice)
{
    if (vertices_visitados[vertice] == 0)
    {
        vertices_visitados[vertice] = 1;
        for (int i = 0; i < num_pessoas; i++)
        {
            if (grafo[vertice][i])
            {
                dfs(grafo, vertices_visitados, i);
            }
        }
    }
    return;
}

int main()
{
    map<string, int> pessoas;
    string pessoa1, pessoa2, ligacao;
    int pessoa_atual = 1;

    cin >> num_pessoas >> num_ligacoes;
    vector<int> vertices_visitados(num_pessoas);
    vector<vector<int>> grafo(num_pessoas, vector<int>(num_pessoas));

    for (int i = 0; i < num_ligacoes; i++)
    {
        cin >> pessoa1 >> ligacao >> pessoa2;
        if (pessoas[pessoa1] == 0)
        {
            pessoas[pessoa1] = pessoa_atual;
            pessoa_atual++;
        }

        if (pessoas[pessoa2] == 0)
        {
            pessoas[pessoa2] = pessoa_atual;
            pessoa_atual++;
        }

        grafo[pessoas[pessoa1] - 1][pessoas[pessoa2] - 1] = 1;
        grafo[pessoas[pessoa2] - 1][pessoas[pessoa1] - 1] = 1;
    }

    familias = 0;

    for (int i = 0; i < num_pessoas; i++)
    {
        if (vertices_visitados[i] == 0)
        {
            dfs(grafo, vertices_visitados, i);
            familias++;
        }
    }

    cout << familias << endl;
    return 0;
}