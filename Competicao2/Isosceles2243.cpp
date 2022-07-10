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
    int N, altura;
    cin >> N;
    vector<int> alturas(N);
    for (int i = 0; i < N; i++)
    {
        cin >> altura;
        alturas[i] = altura;
    }

    alturas[0] = 1;
    alturas[N - 1] = 1;

    for (int i = 1; i < N - 1; i++)
    {
        if (alturas[i] >= alturas[i - 1] + 1)
        {
            alturas[i] = alturas[i - 1] + 1;
        }
    }

    for (int i = N - 2; i > 0; i--)
    {
        if (alturas[i] >= alturas[i + 1] + 1)
        {
            alturas[i] = alturas[i + 1] + 1;
        }
    }

    sort(alturas.begin(), alturas.end());

    cout << alturas[N - 1] << endl;

    return 0;
}