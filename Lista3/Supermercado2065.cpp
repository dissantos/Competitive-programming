#include <bits/stdc++.h>
using namespace std;

struct Funcionario {
    int process_time;
    bool available;
    int wait_time;
};

Funcionario funcionarios[10000];
int tempoTotal;

int nextFunc(int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(funcionarios[i].available)
            return i;
    }
    return -1;
}

int testAvailable(int n) {
    int i;
    int pos = -1;
    for(i = 0; i < n; i++) {
        if(funcionarios[i].wait_time == tempoTotal) {
            funcionarios[i].available = true;
            funcionarios[i].wait_time = 0;
            if(pos == -1) {
                pos = i;
            }
        }
    }

    return pos;
}

void limparFila(int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(!funcionarios[i].available) {
            if(tempoTotal < funcionarios[i].wait_time) {
                tempoTotal = funcionarios[i].wait_time;
                funcionarios[i].wait_time = 0;
                funcionarios[i].available = true;
            }
        }
    }

}

int main() {
    int N, M, i, value, cliente, nextFuncionario;

    cin >> N >> M;


    for(i = 0; i < N; i++) {
        cin >> value;
        funcionarios[i].process_time = value;
        funcionarios[i].available = true;
    }
    tempoTotal = 0;
    for(i = 0; i < M; i++) {
        cin >> cliente;
        nextFuncionario = nextFunc(N);
        while(nextFuncionario == -1) {
            tempoTotal++;
            nextFuncionario = testAvailable(N);
        }
        funcionarios[nextFuncionario].available = false;
        funcionarios[nextFuncionario].wait_time = tempoTotal + (funcionarios[nextFuncionario].process_time*cliente);
    }

    limparFila(N);
    cout << tempoTotal << endl;


    return 0;
}