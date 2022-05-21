#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define MAX 100001

using namespace std;

struct nota {
    unsigned long long int valor;
    bool operator<(const nota & b) const {
        return b.valor > valor;
    }
};


int n,b;
unsigned long long int treeMax[2*MAX];
unsigned long long int treeMin[2*MAX];
vector<nota> notas;
vector<nota> nota_aux;
priority_queue<nota> intervalo;

//Baseado na implementação do GeekForGeekies https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
void buildTrees() {
    int i;
    for(i = 0; i < n; i++) {
        treeMax[n+i] = notas[i].valor;
        treeMin[n+i] = notas[i].valor;
    }

    for(i = n-1; i > 0; --i) {
        treeMax[i] = max(treeMax[2*i] , treeMax[2*i+1]);
        treeMin[i] = min(treeMin[2*i] , treeMin[2*i+1]);
    }
}

unsigned long long int queryMax(int l, int r) {
    unsigned long long int maxValue = 0;
    unsigned long long int aux;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if((l & 1) > 0) {
            aux = treeMax[l++];
            if(maxValue < aux) maxValue = aux;
        }

         if((r & 1) > 0) {
            aux = treeMax[--r];
            if(maxValue < aux) maxValue = aux;
        }
    }

    return maxValue;
}

unsigned long long int queryMin(int l, int r) {
    unsigned long long int minValue = 101;
    unsigned long long int aux;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if((l & 1) > 0) {
            aux = treeMin[l++];
            if(minValue > aux) minValue = aux;
        }

         if((r & 1) > 0) {
            aux = treeMin[--r];
            if(minValue > aux) minValue = aux;
        }
    }

    return minValue;
}



bool cmp(nota a, nota b) {
    return a.valor < b.valor;
}



int main() {

    int i,j; 
    unsigned long long int v, soma, soma_aux, menor, maior;

    while(cin >> n >> b) {
        soma = 0;
        soma_aux = 0;
        notas.clear();
        for(i = 0; i < n; i++) {
            cin >> v;
            nota aux;
            aux.valor = v;
            notas.push_back(aux);
        }
        buildTrees();
        nota_aux = notas;
        menor = queryMax(0,b);
        maior = queryMin(0,b);
        for(i = 0; i < b; i++) {
            soma_aux += notas[i].valor;
        }
        soma = soma_aux - maior - menor;
        for (i = b; i < n; i++) {
            soma_aux += nota_aux[i].valor - nota_aux[i-b].valor;
            maior = queryMax(i-b+1,i+1);
            menor = queryMin(i-b+1,i+1);
            
            soma += soma_aux - maior - menor;
        }
        cout << soma << endl;
    }

    return 0;
}