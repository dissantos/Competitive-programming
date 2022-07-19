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

struct PAIS_MEDALHAS
{
    string nomePais;
    int medalhasOuro;
    int medalhasPratas;
    int medalhasBronze;
};

bool comp(PAIS_MEDALHAS a, PAIS_MEDALHAS b)
{
    return ((a.medalhasOuro > b.medalhasOuro) ||
            (a.medalhasOuro == b.medalhasOuro && a.medalhasPratas > b.medalhasPratas) ||
            (a.medalhasOuro == b.medalhasOuro && a.medalhasPratas == b.medalhasPratas && a.medalhasBronze > b.medalhasBronze) ||
            (a.medalhasOuro == b.medalhasOuro && a.medalhasPratas == b.medalhasPratas && a.medalhasBronze == b.medalhasBronze && a.nomePais < b.nomePais));
}

int main()
{
    int N;
    cin >> N;
    vector<PAIS_MEDALHAS> quadroMedalhas(N);
    for (int i = 0; i < N; i++)
    {
        PAIS_MEDALHAS aux;
        cin >> aux.nomePais >> aux.medalhasOuro >> aux.medalhasPratas >> aux.medalhasBronze;
        quadroMedalhas[i] = aux;
    }
    sort(quadroMedalhas.begin(), quadroMedalhas.end(), comp);

    for (int i = 0; i < N; i++)
    {
        cout << quadroMedalhas[i].nomePais << " " << quadroMedalhas[i].medalhasOuro << " " << quadroMedalhas[i].medalhasPratas << " " << quadroMedalhas[i].medalhasBronze << endl;
    }
    return 0;
}