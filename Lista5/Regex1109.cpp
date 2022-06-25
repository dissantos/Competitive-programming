#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    string str_regex, expr;
    int N;

    while (cin >> str_regex)
    {
        str_regex.erase(remove(str_regex.begin(), str_regex.end(), '.'), str_regex.end());
        regex pattern(str_regex);
        cin >> N;
        getline(cin, expr);
        for (int i = 0; i < N; i++)
        {
            getline(cin, expr);

            if (regex_match(expr, pattern))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }

        cout << endl;
    }
    return 0;
}