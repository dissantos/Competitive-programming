#include <bits/stdc++.h>
using namespace std;



int main() {
    string txtAtual;
    string txtVerdadeiro;
    string aux;
    int i;
    bool mudancaInicial = true;
    char comandoAtual=' ';

    while(cin >> txtAtual) {
        for(i = 0; i < txtAtual.length(); i++) {
            if(mudancaInicial) {
                if(txtAtual[i] != '[' && txtAtual[i] != ']') {
                    txtVerdadeiro.push_back(txtAtual[i]);
                } else if(txtAtual[i] == '[') {
                    comandoAtual = '[';
                    mudancaInicial = false;
                }
            } else {
                if(txtAtual[i] != '[' && txtAtual[i] != ']') {
                    aux.push_back(txtAtual[i]);
                } else {
                    if(comandoAtual == '[') {
                        txtVerdadeiro.insert(0, aux);
                    } else {
                        txtVerdadeiro.append(aux);
                    }
                    comandoAtual = txtAtual[i];
                    aux = "";
                }
            }
        }
        if(comandoAtual == '[') {
            txtVerdadeiro.insert(0, aux);
        } else {
            txtVerdadeiro.append(aux);
        }

        cout << txtVerdadeiro << endl;
        txtVerdadeiro = "";
        aux = "";
        comandoAtual = ' ';
        mudancaInicial = true;
    }

    return 0;
}