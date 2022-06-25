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

int fibonacci(int elemento)
{
    int f1 = 1, f2 = 1, soma, i;
    for (i = 0; i < elemento; i++)
    {
        soma = f1 + f2;
        f1 = f2;
        f2 = soma;
    }

    return f2;
}

int main()
{
    int t, quilometros, i, milhas;

    cin >> t;

    while (t > 0)
    {
        t--;
        cin >> quilometros;
        milhas = 0;

        for (i = 22; i >= 0; i--)
        {
            if (fibonacci(i) <= quilometros)
            {
                quilometros -= fibonacci(i);
                if (i - 1 >= 0)
                {
                    milhas += fibonacci(i - 1);
                }
            }
            if (quilometros == 0)
            {
                break;
            }
        }
        cout << milhas << endl;
    }
    return 0;
}