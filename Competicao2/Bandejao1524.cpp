/*
 * ALunos: Diego Santos
 * Silvia Fonseca
 */
#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    int N, K, pos_anterior, pos_atual, soma;

    while (cin >> N >> K)
    {
        vector<int> distancias(N - 1);
        soma = 0;
        pos_anterior = 0;

        for (int i = 0; i < N - 1; i++)
        {
            cin >> pos_atual;
            distancias[i] = pos_atual - pos_anterior;
            pos_anterior = pos_atual;
        }

        sort(distancias.begin(), distancias.end());

        for (int i = 0; i < N - K; i++)
        {
            soma += distancias[i];
        }

        cout << soma << endl;
    }

    return 0;
}