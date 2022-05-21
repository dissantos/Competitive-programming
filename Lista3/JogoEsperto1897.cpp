#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;

struct operacao {
    char op;
    int qtd_op;
    int valor;
};

queue<operacao> fila_op;

int m;
map<int, int> valores_encontrados;

void addFila(operacao aux) {
    if(!valores_encontrados[aux.valor]){
        valores_encontrados[aux.valor] = aux.qtd_op;
        aux.qtd_op++;
        aux.op = '+';  // + 7
        fila_op.push(aux);
        aux.op = '-';  // - 7
        fila_op.push(aux);
        aux.op = '\\'; // /2
        fila_op.push(aux);
        aux.op = '/';  // /3
        fila_op.push(aux);
        aux.op = '*';  // *2
        fila_op.push(aux);
        aux.op = 'x';  // *3
        fila_op.push(aux);
    }
}

bool realizaOp(operacao n) {
    switch (n.op)
    {
    case '+':
        n.valor += 7;
        addFila(n);
        return (n.valor) == m;
        break;
    case '-':
        n.valor -= 7;
        addFila(n);
        return (n.valor) == m;
        break;
    case '\\':
        n.valor /= 2;
        addFila(n);
        return (n.valor) == m;
        break;
    case '/':
        n.valor /= 3;
        addFila(n);
        return (n.valor) == m;
        break;
    case '*':
        n.valor *= 2;
        addFila(n);
        return (n.valor) == m;
        break;
    case 'x':
        n.valor *= 3;
        addFila(n);
        return (n.valor) == m;
        break;
    default:
        break;
    }

    return false;
}



void testaOp() {
    operacao op_atual;
    while(fila_op.size() > 0) {
        op_atual = fila_op.front();
        fila_op.pop();
        if(realizaOp(op_atual)) {
            cout << op_atual.qtd_op << endl;
            return;
        }
    }
}



int main() {
    int n;
    cin >> n >> m;
    operacao aux;
    aux.valor = n;
    aux.qtd_op = 0;
    if(n == m) {
        cout << "0" << endl;
    }
    addFila(aux);


    testaOp();

    return 0;
}