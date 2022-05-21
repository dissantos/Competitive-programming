#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<int> ram(100);
    stack<int> valoresPilha;
    string comando, valor;
    int n, valor1, valor2, resultado;

    cin >> n;
    while(n) {
        n--;

        cin >> comando;
        if(comando.find("push_R") != string::npos) {
            valor = comando;
            valor.erase(valor.begin(), valor.begin() + strlen("push_R"));
            valoresPilha.push(ram[stoi(valor)]);
        } else if(comando.find("push_") != string::npos) {
            valor = comando;
            valor.erase(valor.begin(), valor.begin() + strlen("push_"));
            valoresPilha.push(stoi(valor));
        } else if(comando.find("pop_R") != string::npos) {
            valor = comando;
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            valor.erase(valor.begin(), valor.begin() + strlen("pop_R"));
            ram[stoi(valor)] = valor1;
        } else if (comando.find("add") != string::npos) {
            valor2 = valoresPilha.top();
            valoresPilha.pop();
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            resultado = valor1 + valor2;
            valoresPilha.push(resultado);
        
        } else if (comando.find("sub") != string::npos) {
            valor2 = valoresPilha.top();
            valoresPilha.pop();
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            resultado = valor1 - valor2;
            valoresPilha.push(resultado);
        
        } else if (comando.find("mul") != string::npos) {
            valor2 = valoresPilha.top();
            valoresPilha.pop();
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            resultado = valor1 * valor2;
            valoresPilha.push(resultado);
        
        } else if (comando.find("div") != string::npos) {
            valor2 = valoresPilha.top();
            valoresPilha.pop();
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            resultado = valor1 / valor2;
            valoresPilha.push(resultado);
        } else {
            valor1 = valoresPilha.top();
            valoresPilha.pop();
            cout << valor1 << endl;
        }
        
    }

    return 0;
}