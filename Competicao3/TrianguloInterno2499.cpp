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

int main()
{
    long long int area, m_pontos, n_pontos;
    long long int c1, c2, c3;

    cin >> area >> n_pontos >> m_pontos;
    while (area || n_pontos || m_pontos)
    {
        cin >> c1 >> c2 >> c3;
        if (c2 > c3)
        {
            long long int aux = c2;
            c2 = c3;
            c3 = aux;
        }

        // Area = Base * Altura/2
        // Base do triangulo interno = (B/(m+1))(c3-c2)
        long long int base = (c3 - c2);

        // Altura do triangulo interno = (A/(n+1))c1
        long long int altura = c1;

        // area do triangulo interno = (base * altura * B * A)/2 = base*altura*area
        long long int area_triangulo_interno = base * altura * area / ((m_pontos + 1) * (n_pontos + 1));

        cout << area_triangulo_interno << endl;

        cin >> area >> n_pontos >> m_pontos;
    }
    return 0;
}