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

int buscaBinaria(vector<int> v, int consulta, int l, int d)
{
    int meio = (l + d) / 2;
    if (v[meio] == consulta)
    {
        return meio;
    }
    else if (l >= d)
    {
        return -1;
    }
    else if (v[meio] > consulta)
    {
        return buscaBinaria(v, consulta, l, meio - 1);
    }
    else
    {
        return buscaBinaria(v, consulta, meio + 1, d);
    }
}

int main()
{
    int numMarmores, numConsultas, consulta, caso = 1, posicao;

    cin >> numMarmores >> numConsultas;

    while (numMarmores != 0 && numConsultas != 0)
    {
        vector<int> marmores(numMarmores);

        for (int i = 0; i < numMarmores; i++)
        {
            cin >> marmores[i];
        }
        sort(marmores.begin(), marmores.end());
        cout << "CASE# " << caso << ":" << endl;
        for (int i = 0; i < numConsultas; i++)
        {
            cin >> consulta;
            bool encontrou = false;
            for (int j = 0; j < numMarmores; j++)
            {
                if (marmores[j] == consulta)
                {
                    encontrou = true;
                    cout << consulta << " found at " << (j + 1) << endl;
                    break;
                }
                else if (marmores[j] > consulta)
                {
                    break;
                }
            }
            if (!encontrou)
                cout << consulta << " not found" << endl;
        }
        caso++;
        cin >> numMarmores >> numConsultas;
    }

    return 0;
}