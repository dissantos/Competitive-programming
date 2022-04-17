#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    int valor;
};

vector<Aluno> alunos;

void printVector(int n) {
    int i;
    cout << "----------------" << endl;
    for(i = 0; i < n; i++) {
        cout << alunos[i].nome << endl;
    }
}

int main() {
    int n, i, prox = 1, eliminado, valor, tam;
    bool inicial;
    string nome;
    Aluno aluno;
    while (true) {
        cin >> n;
        if(n==0) {
            break;
        }

        alunos.clear();
        for(i = 0; i < n; i++) {
            cin >> nome;
            cin >> valor;
            aluno.nome = nome;
            aluno.valor = valor;
            alunos.push_back(aluno);
        }
        inicial = true;
        prox = 1;
        while(alunos.size() > 1) {
            printVector(n);
            if(inicial) {
                valor = alunos[prox-1].valor;
                inicial = false;
            }
            if (valor%2 == 1) {
                eliminado = prox + (valor%n) - 1;
            } else {

                eliminado = prox - ((valor)%n);
                if(valor%n == 0) {
                    eliminado = prox + 1;
                }
                if (eliminado < 0) eliminado += n;
                cout << valor << endl;
                cout << prox << endl;
                cout << eliminado << endl;
            }

            n--;
            valor = alunos[eliminado].valor;
            prox = eliminado;
            if (valor%2 == 0) {
                prox--;
                if(prox < 0) {
                    prox = n-1;
                }
            } else if(prox == n ) {
                if(valor%2 == 1) {
                    prox = 0;
                } else {
                    prox--;
                    
                }
            }
            alunos.erase(alunos.begin() + eliminado);
            

        }

        cout << "Vencedor(a): " << alunos[0].nome << endl;
    }
    return 0;
}