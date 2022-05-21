#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;

bool testCombination(char proteinA, char proteinB) {
    //cout << proteinA << proteinB << endl;
    switch(proteinA) {
        case 'B':
            return proteinB == 'S';
        case 'S':
            return proteinB == 'B';
        case 'C':
            return proteinB == 'F';
        case 'F':
            return proteinB == 'C';
        default:
            break;
    }

    return false;
}

void printStack(stack<char> pilha) {
    while(pilha.size() != 0) {
        cout << pilha.top();
        pilha.pop();
    }
    cout << endl;
}

int main() {
    string fita;
    char proteina;
    int i;
    bool encontrouCombinacao;
    int combinacoes;

    while(cin >> fita) {
        combinacoes = 0;
        stack<char> pilha;
        for(i = 0; i < fita.size(); i++) {
            pilha.push(fita[i]);
        }
        
        do {
            encontrouCombinacao = false;
            proteina = pilha.top();
            pilha.pop();
            stack<char> aux;
            while(pilha.size() > 0) {
                if(testCombination(proteina, pilha.top())) {
                    encontrouCombinacao = true;
                    pilha.pop();
                    if(pilha.size() > 1) {
                        proteina = pilha.top();
                        pilha.pop();
                    } else if(pilha.size() == 1) {
                        aux.push(pilha.top());
                        pilha.pop();
                    }
                    combinacoes++;
                } else {
                    aux.push(proteina);
                    proteina = pilha.top();
                    pilha.pop();
                    if(pilha.size() == 0) {
                        aux.push(proteina);
                    } 

                }
            }
            pilha = aux;
            //printStack(pilha);
            
        }while(encontrouCombinacao && pilha.size());
        cout << combinacoes << endl;
    }
    return 0;
}