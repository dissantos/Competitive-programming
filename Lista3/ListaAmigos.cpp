#include <bits/stdc++.h>
using namespace std;


int main() {
    string listaAtual, listaNova, nome;
    getline(cin, listaAtual);
    getline(cin, listaNova);
    getline(cin, nome);
    
    if(nome.compare("nao")){
        int pos = listaAtual.find(nome);

        listaAtual.insert(pos, listaNova);
        if(pos+listaNova.size() < listaAtual.size() ){
            listaAtual.insert(pos+listaNova.size(), " ");
        }
    } else {
        listaAtual.append(" ");
        listaAtual.append(listaNova);
    }
    cout << listaAtual << endl;
    return 0;
}