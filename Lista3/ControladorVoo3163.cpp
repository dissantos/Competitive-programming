#include <bits/stdc++.h>
using namespace std;


int main() {
    char option, spacer = ' ';
    int pos, cont = 0, i;
    string aviao;
    vector<vector<string>> avioes(4);

    cin >> option;
    while(option != '0') {
        if(option == '-') {
            cin >> pos;
        } else if (option == 'A') {
            cin >> aviao;
            avioes[pos-1].push_back(aviao);
            cont++;
        }
        cin >> option;
    }
    while(cont > 0){
        if(cont == 1) spacer = '\n';
        if(avioes[0].size()) {
            cout << "A" << avioes[0][0] << spacer;
            avioes[0].erase(avioes[0].begin());
            cont--;
        }


        if(cont == 1) spacer = '\n';
        if(avioes[2].size()) {
            cout << "A" << avioes[2][0] << spacer;
            avioes[2].erase(avioes[2].begin());
            cont--;
        }

        if(cont == 1) spacer = '\n';
        if(avioes[1].size()) {
            cout << "A" << avioes[1][0] << spacer;
            avioes[1].erase(avioes[1].begin());
            cont--;
        }

        if(cont == 1) spacer = '\n';
        if(avioes[3].size()) {
            cout << "A" << avioes[3][0] << spacer;
            avioes[3].erase(avioes[3].begin());
            cont--;
        }
    }
    


    return 0;
}