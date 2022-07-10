/*
 * ALunos: Diego Santos
 * Silvia Fonseca
 */
#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

bool insere_bola(int bola, vector<int>& hastes) {
    for(int i = 0; i < hastes.size(); i++) {
        if( hastes[i] != 0 ) {
            if(ceil((double)sqrt(hastes[i] + bola)) == floor((double)sqrt(hastes[i] + bola))) {
                hastes[i] = bola;
                return true;
            }
        }
    }
    
    for(int i = 0; i < hastes.size(); i++) {
        if( hastes[i] == 0 ) {
            hastes[i] = bola;
            return true;
        }
    }
    
    return false;
}

int main()
{
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        vector<int> hastes(n);
        
        int bola = 1;
        
        while(insere_bola(bola, hastes)) {
            bola++;
        }
        
        cout << bola-1 << endl;
    }
}