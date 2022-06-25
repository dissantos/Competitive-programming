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
    int soldados, i, j, vitorias = 0;
    long long int habilidade;
    cin >> soldados;
    vector<long long int> nlog(soldados), quad(soldados);

    for (int i = 0; i < soldados; i++)
    {
        cin >> habilidade;
        quad[i] = habilidade;
    }

    for (int i = 0; i < soldados; i++)
    {
        cin >> habilidade;
        nlog[i] = habilidade;
    }

    sort(quad.begin(), quad.end());
    sort(nlog.begin(), nlog.end());

    j = soldados - 1;
    for (i = soldados - 1; i >= 0 && j >= 0; i--)
    {
        do
        {
            if (nlog[i] > quad[j])
            {
                vitorias++;
                j--;
                break;
            }
            else
            {
                j--;
            }

        } while (j >= 0);
    }

    cout << vitorias << endl;
    return 0;
}