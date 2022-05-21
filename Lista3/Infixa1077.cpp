#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ID 100

using namespace std;

struct token {
    int tag;
    char simbolo;
};

token tokenAtual;
int pos;

string expressao;

void expression();

void advance() {
    tokenAtual.simbolo = expressao[pos];
    pos++;

    if(tokenAtual.simbolo == '+' || tokenAtual.simbolo == '-' || tokenAtual.simbolo == '*' || tokenAtual.simbolo == '/' || tokenAtual.simbolo == '^' || tokenAtual.simbolo == '(' || tokenAtual.simbolo == ')')  {
        tokenAtual.tag = tokenAtual.simbolo;
    } else {
        tokenAtual.tag = ID;
    }
}

void eat(int tag)  {
    if (tokenAtual.tag == tag){
        advance();
    } else {
        cout << "erro: " << tokenAtual.simbolo << endl;
    }
}

void potOp() {
    //cout << "potOp: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case '^':
            eat('^');
            break;
        default:
            break;
    }
}

void mulOp() {
    //cout << "mulOp: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case '*':
            eat('*');
            break;
        case '/':
            eat('/');
            break;
        default:
            break;
    }
}

void addOp() {
    //cout << "addOp: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case '+':
            eat('+');
            break;
        case '-':
            eat('-');
            break;
        default:
            break;
    }
}

void pot() {
    //cout << "pot: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case ID:
            cout << tokenAtual.simbolo;
            eat(ID);
            break;
        case '(':
            eat('('); 
            expression();
            eat(')');
            break;
        default:
            break;
    }
}

void b() {
    //cout << "b: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    switch(tokenAtual.tag) {
        case '^':
            potOp();
            pot();
            cout << op.simbolo;
            b();
            break;
        default:
            break;
    }
}

void factor() {
    //cout << "factor: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            pot();
            b();
            break;
        default:
            break;
    }
}

void z() {
    //cout << "z: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    switch(tokenAtual.tag) {
        case '*':
        case '/':
            mulOp();
            factor();
            cout << op.simbolo;
            z();
            break;
        default:
            break;
    }
}

void term() {
    //cout << "term: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            factor();
            z();
            break;
        default:
            break;
    }
}

void a() {
    //cout << "a: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    switch(tokenAtual.tag) {
        case '+':
        case '-':
            addOp();
            term();
            cout << op.simbolo;
            a();
            break;
        default:
            break; 
    }
}

void expression() {
    //cout << "expression: " << tokenAtual.simbolo << endl;
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            term();
            a();
            break;
        default:
            break;
    }
}


int main() {
    int n;

    cin >> n;

    while(n) {
        n--;

        cin >> expressao;
        pos = 0;
        advance();

        expression();
        cout << endl;

        
    }

    return 0;
}