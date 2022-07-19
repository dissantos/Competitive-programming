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
    double a;
    double area, area1, area2, area3;

    while (cin >> a)
    {
        area = a * a;
        // Formulas baseadas em: https://www.obaricentrodamente.com/2022/04/como-calcular-a-area-envolvendo-um-quadrado-e-dois-arcos-de-circunferencia-parte-1.html
        area3 = 4 * (area * (1 - sqrt(3) / 4 - M_PI / 6));
        area1 = 2 * area * (M_PI / 2 - 1) - (area - area3);
        area2 = area - area1 - area3;

        cout.precision(3);
        cout << fixed << area1 << " " << area2 << " " << area3 << endl;
    }

    return 0;
}