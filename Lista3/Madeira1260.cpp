#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, num_arvores;
    string arvore;
    map<string, float> arvores;


    cin >> n;
    getline(cin, arvore);
    getline(cin, arvore);
    while(n) {
        arvores.clear();
        num_arvores = 0;
        n--;
        while(true) {
            getline(cin, arvore);
            if(arvore == "") {
                break;
            } else {
                if(arvores.find(arvore) == arvores.end()) {
                    arvores[arvore] = 1;
                } else {
                    arvores[arvore] += 1;
                }
                num_arvores++;
            }
        }

        for(auto arvore = arvores.begin(); arvore != arvores.end(); arvore++) {
            cout << arvore->first << " " ;
            cout. precision(4);
            cout << fixed << (arvore->second/(float)num_arvores)*100 << endl;
        }
        if(n > 0) {
            cout << endl;
        }
    }
    return 0;
}