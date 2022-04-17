#include <bits/stdc++.h>
using namespace std;

bool compareAssinaturas(string original, string atual) {
    int i;
    int cont = 0;
    for (i = 0; i < original.size(); i++) {
        if(original[i] != atual[i]) {
            cont++;
        }

        if (cont == 2) {
            return false;
        }
    }
    return true;
}

int main() {
    unordered_map<string, string> map_alunos;
    string aluno, assinatura;
    int n,m, cont = 0;
    while(true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        while (n--) {
            cin >> aluno; 
            cin >> assinatura;
            map_alunos[aluno] = assinatura;
        }
        cin >> m;
        cont = 0;
        while (m--) {
            cin >> aluno;
            cin >> assinatura;
            if(!compareAssinaturas(assinatura, map_alunos[aluno])) {
                cont++;
            }
        }
        cout << cont << endl;
    }
    return 0;
}