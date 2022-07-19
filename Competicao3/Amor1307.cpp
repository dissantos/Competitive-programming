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

int gcd(int n1, int n2)
{
    // cout << n1 << " " << n2 << endl;
    if (!n2)
    {
        return n1;
    }
    return gcd(n2, n1 % n2);
}

int main()
{
    string S1, S2;
    int N, i = 1;
    cin >> N;

    while (i <= N)
    {
        cin >> S1;
        cin >> S2;

        int n1 = stoi(S1, nullptr, 2);
        int n2 = stoi(S2, nullptr, 2);

        if (n2 > n1)
        {
            int aux = n1;
            n1 = n2;
            n2 = aux;
        }
        // cout << n1 << " " << n2 << endl;
        // cout << gcd(n1, n2) << endl;
        cout << "Pair #" << i << ": ";
        if (n1 == n2)
        {
            cout << "All you need is love!" << endl;
        }
        else if (gcd(n1, n2) > 1)
        {

            cout << "All you need is love!" << endl;
        }
        else
        {
            cout << "Love is not all you need!" << endl;
        }
        i++;
    }
    return 0;
}