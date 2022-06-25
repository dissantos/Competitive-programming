#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


int main() {
    string risada, risada_sem_consoante;
    int tam;
    risada_sem_consoante = "";

    cin >> risada;

    for(int i = 0; i < risada.size(); i++) {
        if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
            risada_sem_consoante += risada[i];
        }
    }

    tam = risada_sem_consoante.size();

    for(int i = 0; i < tam/2; i++) {
        if(risada_sem_consoante[i] != risada_sem_consoante[tam - 1 - i]) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}