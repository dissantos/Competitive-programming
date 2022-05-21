#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, i;
    string nome, presente;
    map<string, set<string>> listaPresentes;
    


    cin >> n;
    while(n) {
        n--;
        cin >> nome;
        set<string> presentes;
        for(i = 0; i < 3; i++) {
            cin >> presente;
            presentes.insert(presente);
        }

        listaPresentes[nome] = presentes;
    }

    while(cin >> nome >> presente) {
        if (listaPresentes.find(nome) == listaPresentes.end()){
            cout << "Tente Novamente!" << endl;
        } else if(listaPresentes[nome].find(presente) == listaPresentes[nome].end()) {
            cout << "Tente Novamente!" << endl;
        } else {
            cout << "Uhul! Seu amigo secreto vai adorar o/" << endl;
        }
    }
    return 0;
}