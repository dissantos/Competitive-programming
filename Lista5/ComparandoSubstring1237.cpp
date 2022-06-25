#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    string sentenca1, sentenca2;

    while (getline(cin, sentenca1))
    {
        getline(cin, sentenca2);
        int maiorTamanho = 0;

        for (int i = 0; i < sentenca1.size(); i++)
        {
            for (int j = 0; j < sentenca2.size(); j++)
            {
                if (sentenca1[i] == sentenca2[j])
                {
                    int pos_substr1 = i;
                    int pos_substr2 = j;
                    int tamanho = 0;
                    while (sentenca1[pos_substr1] == sentenca2[pos_substr2])
                    {
                        tamanho++;
                        pos_substr1++;
                        pos_substr2++;
                        if (pos_substr1 == sentenca1.size() || pos_substr2 == sentenca2.size())
                        {
                            break;
                        }
                    }

                    if (tamanho > maiorTamanho)
                    {
                        maiorTamanho = tamanho;
                    }
                }
            }
        }

        cout << maiorTamanho << endl;
    }

    return 0;
}