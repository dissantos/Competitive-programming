#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

char palindrome[2002];
char aux[2002];
bool testPalindrome(char * str, int pos_inicial, int pos_final) {
    strncpy(aux, str+pos_inicial, pos_final - pos_inicial);
    int tam = pos_final - pos_inicial;
    if(tam == 1) {
        return true;
    }
    for(int i = 0; i < (tam)/2; i++)
        if(aux[i] != aux[tam - i - 1]) {
            return false;
        }
    return true;
}


bool permuteArray(int n, int tam) {
    int i;
    bool permuta[n-1] = { false };
    bool dontFound;
    int lim_inf;
    for(i = 0; i < tam; i++) {
        permuta[i] = true;
    }
    while(true) {
        if(!prev_permutation(permuta, permuta + (n-1))) {
            break;
        }
        lim_inf = 0;
        dontFound = false;
        for(i = 0; i < n-1; i++) {
            if(permuta[i]) {
                if(!testPalindrome(palindrome, lim_inf, (i+1))){
                    dontFound = true;
                    break;
                }
                lim_inf = i+1;
                continue;
            }
        }
        if(!dontFound) {
            if (testPalindrome(palindrome, lim_inf, n)) {
                return true;
            }
        }
        
    }
    return false;
}

int main() {
    int n, test = 0, k, i, j, tam;
    bool foundMin;
    char letter;
    while(true) {
        cin >> n;
        if(n == 0) {
            break;
        }
        k = 0;
        
        while(k < n) {
            cin >> letter;
            palindrome[k] = letter;
            k++;
        }
        test++;
        if(test > 1)
            printf("\n");
        printf("Teste %d\n",test);
        tam = 1;
        foundMin = false;
        if(!testPalindrome(palindrome, 0, n)) {
            do {
                tam++;
                if(permuteArray(n, tam-1)) {
                    foundMin = true;
                }
            } while(!foundMin && tam < n);
        } 
        printf("%d\n",tam);
    }
    if(test > 0)
        printf("\n");
    return 0;
}