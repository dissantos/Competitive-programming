#include <bits/stdc++.h>
using namespace std;


int main() {
    int m, test = 1, tot, value;
    char op;
    while(true) {
        cin >> m;

        if(m == 0) {
            break;
        }
        cin >> tot;
        m--;
        while(m > 0) {
            cin >> op;
            cin >> value;
            if (op == '-') {
                value = (-1)*value;
            }

            tot += value;
            m--;
        }
        cout << "Teste " << test << endl;
        cout << tot << endl << endl;
        test++;
    }
    return 0;
}