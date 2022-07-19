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

int encontrarPai(int vertice, vector<int> &root)
{
    while (root[vertice] != vertice)
    {
        root[vertice] = root[root[vertice]];
        vertice = root[vertice];
    }

    return vertice;
}

void unirBancos(int banco1, int banco2, vector<int> &root)
{
    int paiBanco1 = encontrarPai(banco1, root);
    int paiBanco2 = encontrarPai(banco2, root);
    root[paiBanco1] = root[paiBanco2];
}

int main()
{
    int n, k, banco1, banco2;
    string operacao;
    cin >> n >> k;
    vector<int> bancos(n + 1);

    for (int cod = 0; cod <= n; cod++)
    {
        bancos[cod] = cod;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> operacao >> banco1 >> banco2;
        if (operacao == "F")
        {
            unirBancos(banco1, banco2, bancos);
        }
        else
        {
            if (encontrarPai(banco1, bancos) != encontrarPai(banco2, bancos))
            {
                cout << "N" << endl;
            }
            else
            {
                cout << "S" << endl;
            }
        }
    }

    return 0;
}