#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


int main() {
    string senha;

    while(getline(cin, senha)) {
        bool caracterIncorreto = false, temMaiscula = false, temMinuscula = false, temNumero = false;
        if(senha.size() < 6 || senha.size() > 32) {
            cout << "Senha invalida." << endl;
            continue;
        }

        for(int i = 0; i < senha.size() ; i++) {
            if(senha[i] >= 'a' && senha[i] <= 'z') {
                temMinuscula = true;
            } else if(senha[i] >= 'A' && senha[i] <= 'Z') {
                temMaiscula = true;
            } else if(senha[i] >= '0' && senha[i] <= '9') {
                temNumero = true;
            } else {
                caracterIncorreto = true;
                break;
            }
        }

        if(!caracterIncorreto && temMaiscula && temMinuscula && temNumero) {
            cout << "Senha valida." << endl;
        } else {
            cout << "senha invalida." << endl;
        }


    }
    return 0;
}