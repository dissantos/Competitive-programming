#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;

struct dragao {
    unsigned long long int multa;
    unsigned long long int dias;
    float pd;

    bool operator<(const dragao & b) const {
        return b.pd > pd;
    }
};
priority_queue<dragao> fila;



bool comp(dragao a, dragao b) {
    return a.pd < b.pd;
}

int main() {
    unsigned long long int multa, dias;
    dragao aux, atual;
    bool inicio = true;
    int i = 0;
    unsigned long long int multaTotal = 0, multaAcumulada = 0;

    while(cin >> dias >> multa) {
        aux.dias = dias;
        aux.multa = multa;
        aux.pd = (float)multa / (float) dias;
        if(inicio) {
            inicio = false;
            atual = aux;
        } else {
            multaAcumulada += aux.multa;
            fila.push(aux);
            if(i == atual.dias) {
                i = 0;
                atual = fila.top();
                multaAcumulada -= atual.multa;
                fila.pop();
            }
            multaTotal += multaAcumulada;
        }
        i++;
    }

    while(fila.size() > 0) {
        atual.dias -= i;
        multaTotal += atual.dias*multaAcumulada;
        i = 0;
        atual = fila.top();
        multaAcumulada -= atual.multa;
        fila.pop();
    }
    multaTotal += atual.dias*multaAcumulada;

    cout << multaTotal << endl;

    return 0;
}