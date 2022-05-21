#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    int valor;
    int alunoAnterior;
    int alunoProximo;
};

vector<Aluno> alunos;


int main() {
    int n, i, j, prox = 1, eliminado, valor, tam, vencedor;
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
            aluno.alunoAnterior = i - 1;
            aluno.alunoProximo = i + 1;
            if(i == 0) {
                aluno.alunoAnterior = n-1;
            } else if ( i == n-1) {
                aluno.alunoProximo = 0;
            }
            alunos.push_back(aluno);
        }
        inicial = true;
        prox = 1;
        if (n > 1) {
            do {
                if(inicial) {
                    valor = alunos[prox-1].valor;
                    if(valor%2 == 0) {
                        prox = n-1;
                    }
                    inicial = false;
                }
                if (valor%2 == 1) {
                    for(i = 0, j = prox; i  < valor - 1; i++) {
                        j = alunos[j].alunoProximo;
                    }
                    eliminado = j;
                } else {
                    for(i = 0, j = prox; i  < valor - 1; i++) {
                        j = alunos[j].alunoAnterior;
                    }
                    eliminado = j;
                
                }

                n--;
                valor = alunos[eliminado].valor;
                if (valor%2 == 0) {
                    prox = alunos[eliminado].alunoAnterior;
                } else {
                    prox = alunos[eliminado].alunoProximo;
                }
                alunos[alunos[eliminado].alunoProximo].alunoAnterior = alunos[eliminado].alunoAnterior;
                alunos[alunos[eliminado].alunoAnterior].alunoProximo = alunos[eliminado].alunoProximo;
                
            } while(alunos[eliminado].alunoAnterior != alunos[eliminado].alunoProximo);
            vencedor = alunos[eliminado].alunoAnterior;
        } else {
            vencedor = 0;
        }

        cout << "Vencedor(a): " << alunos[vencedor].nome << endl;
    }
    return 0;
}