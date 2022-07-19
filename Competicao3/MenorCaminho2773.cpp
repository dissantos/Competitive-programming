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
    double Xi, Yi, Xf, Yf, V, Xl, Yl, Xr, Yr;

    double largura, distanciaCima, distanciaBaixo, tempo;

    while (cin >> Xi >> Yi >> Xf >> Yf >> V)
    {
        cin >> Xl >> Yl >> Xr >> Yr;
        largura = Xr - Xl;
        distanciaCima = sqrt((Xl - Xi) * (Xl - Xi) + (Yr - Yi) * (Yr - Yi)) + largura + sqrt((Xf - Xr) * (Xf - Xr) + (Yr - Yf) * (Yr - Yf));
        distanciaBaixo = sqrt((Xl - Xi) * (Xl - Xi) + (Yi - Yl) * (Yi - Yl)) + largura + sqrt((Xf - Xr) * (Xf - Xr) + (Yf - Yl) * (Yf - Yl));

        if (distanciaCima < distanciaBaixo)
        {
            tempo = distanciaCima / V;
        }
        else
        {
            tempo = distanciaBaixo / V;
        }

        cout.precision(1);

        cout << fixed << tempo << endl;
    }

    return 0;
}