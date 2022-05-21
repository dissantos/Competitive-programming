#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ID 100
#define ENDFILE 0

using namespace std;

struct token {
    int tag;
    char simbolo;
};

token tokenAtual;
int pos;
bool isError;

string expressao;
string posfix;

void expression();

void advance() {
    tokenAtual.simbolo = expressao[pos];
    pos++;

    if(tokenAtual.simbolo == '+' || tokenAtual.simbolo == '-' || tokenAtual.simbolo == '*' || tokenAtual.simbolo == '/' || tokenAtual.simbolo == '^' || tokenAtual.simbolo == '(' || tokenAtual.simbolo == ')'|| tokenAtual.simbolo == '<'|| tokenAtual.simbolo == '>'|| tokenAtual.simbolo == '='|| tokenAtual.simbolo == '#'|| tokenAtual.simbolo == '.'|| tokenAtual.simbolo == '|')  {
        tokenAtual.tag = tokenAtual.simbolo;
    } else if((tokenAtual.simbolo >= 'A' && tokenAtual.simbolo <= 'Z')||(tokenAtual.simbolo >= 'a' && tokenAtual.simbolo <= 'z') || (tokenAtual.simbolo >= '0' && tokenAtual.simbolo <= '9')){
        tokenAtual.tag = ID;
    } else if(pos <= expressao.size() && !isError){
        cout << "Lexical Error!" << endl;
        isError = true;
    } else {
        tokenAtual.tag = ENDFILE;
    }
}

void eat(int tag)  {
    if (tokenAtual.tag == tag){
        advance();
    } else if(!isError) {
        isError = true;
        cout << "Syntax Error!" << endl;
    }
}

void potOp() {
    //cout << "potOp: " << tokenAtual.simbolo << endl;
    if(!isError)
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
    if(!isError)
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
    if(!isError)
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

void relOp() {
    if(!isError)
    switch(tokenAtual.tag) {
        case '<':
            eat('<');
            break;
        case '>':
            eat('>');
            break;
        case '=':
            eat('=');
            break;
        case '#':
            eat('#');
            break;
        default:
            break;
    }
}

void andOp() {
    if(!isError)
    switch(tokenAtual.tag) {
        case '.':
            eat('.');
            break;
        default:
            break;
    }
}

void orOp() {
    if(!isError)
    switch(tokenAtual.tag) {
        case '|':
            eat('|');
            break;
        default:
            break;
    }
}

void pot() {
    //cout << "pot: " << tokenAtual.simbolo << endl;
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
            posfix += tokenAtual.simbolo;
            eat(ID);
            break;
        case '(':
            eat('('); 
            expression();
            eat(')');
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void b() {
    //cout << "b: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '^':
            potOp();
            pot();
            posfix += op.simbolo;
            b();
            break;
        default:
            break;
    }
}

void factor() {
    //cout << "factor: " << tokenAtual.simbolo << endl;
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            pot();
            b();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void z() {
    //cout << "z: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '*':
        case '/':
            mulOp();
            factor();
            posfix += op.simbolo;
            z();
            break;
        default:
            break;
    }
}

void term() {
    //cout << "term: " << tokenAtual.simbolo << endl;
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            factor();
            z();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void a() {
    //cout << "a: " << tokenAtual.simbolo << endl;
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '+':
        case '-':
            addOp();
            term();
            posfix += op.simbolo;
            a();
            break;
        default:
        
            break; 
    }
}

void simpleexpr() {
    //cout << "expression: " << tokenAtual.simbolo << endl;
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            term();
            a();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void l() {
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '<':
        case '>':
        case '=':
        case '#':
            op = tokenAtual;
            relOp();
            simpleexpr();
            posfix += op.simbolo;
            l();
            break;
        default:
            break;
    }
}

void relexpr() {
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            simpleexpr();
            l();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void c() {
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '.':
            op = tokenAtual;
            andOp();
            relexpr();
            posfix += op.simbolo;
            c();
            break;
        default:
            break;
    }
}

void andExpr() {
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            relexpr();
            c();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

void d() {
    token op = tokenAtual;
    if(!isError)
    switch(tokenAtual.tag) {
        case '|':
            orOp();
            andExpr();
            posfix += op.simbolo;
            d();
            break;
        default:
            break;
    }
}

void expression() {
    if(!isError)
    switch(tokenAtual.tag) {
        case ID:
        case '(':
            andExpr();
            d();
            break;
        default:
            isError = true;
            cout << "Syntax Error!" << endl;
            break;
    }
}

int main() {
    int n;

    while(cin >> expressao) {
        pos = 0;
        isError = false;
        posfix = "";

        while(pos != expressao.size()) {
            advance();
        }
        pos = 0;
        advance();

        if(!isError) {
            expression();
        }

        

        if(pos != expressao.size()+1 && !isError) {
            cout << "Syntax Error!" << endl;
        }else if(!isError) {
            cout << posfix << endl;
        }

        
    }

    return 0;
}