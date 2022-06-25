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
    int N, receita, lucroTotal, lucroDia, lucroAux, custoPorDia;
    ;

    while (cin >> N)
    {
        lucroAux = 0;
        lucroTotal = 0;
        if (N == 0)
        {
            cout << 0 << endl;
            continue;
        }
        cin >> custoPorDia;
        for (int i = 0; i < N; i++)
        {
            cin >> receita;
            lucroDia = receita - custoPorDia;
            lucroTotal += lucroDia;

            if (lucroAux < lucroTotal)
            {
                lucroAux = lucroTotal;
            }
            else if (lucroTotal < 0)
            {
                lucroTotal = 0;
            }
        }

        cout << lucroAux << endl;
    }
    return 0;
}