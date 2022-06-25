#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


int main() {
    string frase, error;
    string maiorPalavra;
    int maior = 0;
    getline(cin,frase);
    while(frase != "0"){
        istringstream line(frase);
        int tamanhoPalavra[100] = {0};
        int numDePalavra = 0,i;
        string token;

        while(getline(line, token, ' ')){
            for(i = 0; token[i] != '\0'; i++){
                tamanhoPalavra[numDePalavra]++;
            }
            if(tamanhoPalavra[numDePalavra] >= maior){
                maior = tamanhoPalavra[numDePalavra];
                maiorPalavra = token;
            }
            numDePalavra++;
        }
        cout << tamanhoPalavra[0];
        for(i = 1 ; i < numDePalavra; i++){
            cout << "-" << tamanhoPalavra[i];
        }
        cout << endl;
        getline(cin,frase);
    }
    cout << endl << "The biggest word: " << maiorPalavra << endl;

    return 0;
}