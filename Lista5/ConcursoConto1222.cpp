#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


int main() {
    string palavra;
    int numPalavras, limiteCaracterLinha, limiteLinhaPagina;
    while(cin >> numPalavras >> limiteLinhaPagina >> limiteCaracterLinha){
        int qtdeCaracters= 0, linhas = 1, paginas = 1;
        for(int i = 0; i < numPalavras; i++) {
            cin >> palavra;
            //cout << palavra << endl;
            if(i != 0) {
                if(palavra.size() + 1 + qtdeCaracters > limiteCaracterLinha) {
                    if(linhas + 1 > limiteLinhaPagina) {
                        paginas++;
                        linhas = 0;
                    }
                    linhas++;
                    qtdeCaracters = 0;
                }
            } else {
                if(palavra.size() + qtdeCaracters > limiteCaracterLinha) {
                    if(linhas + 1 > limiteLinhaPagina) {
                        paginas++;
                        linhas = 0;
                    }
                    linhas++;
                    qtdeCaracters = 0;
                }
            }
            qtdeCaracters += palavra.size();
            if(i != 0 && qtdeCaracters < limiteCaracterLinha && qtdeCaracters != palavra.size()) {
                qtdeCaracters++;
            }
            //cout << qtdeCaracters << " " << linhas << " " << paginas << endl;
        }

        cout << paginas << endl;        
    }

    return 0;
}