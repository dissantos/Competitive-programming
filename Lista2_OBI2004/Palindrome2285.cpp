#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

char palindrome[2002];
char aux[2002];
int dp[2002][2002] = { -1 };

bool testPalindrome(char * str, int pos_inicial, int pos_final) {
    if(dp[pos_inicial][pos_final-1] != -1) {
        return dp[pos_inicial][pos_final-1];
    } else if (testPalindrome(palindrome, pos_inicial + 1, pos_final - 1)) {
        dp[pos_inicial][pos_final - 1] = palindrome[pos_inicial] == palindrome [pos_final - 1];
    } else {
        dp[pos_inicial][pos_final - 1] = 0;
    }
    return dp[pos_inicial][pos_final - 1];
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

bool testBestPalindrome(char * palindrome, int pos_inicial, int pos_final, int n) {
    int tam = pos_final - pos_inicial + 1;
    int i, j;

    //cout << pos_inicial << " " << pos_final << endl;
    //cout << tam << endl;

    for (i = pos_inicial + 1; i <= pos_final; i++) {
        for (j = n-1; j >= i; j--) {
            //cout << i << "--" << j << endl;
            if(dp[i][j]) {
                if (tam < (j-i) + 1) {
                    return false;
                }
            }
        }
    }

    return true;
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

        for(i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = -1;
                if( i == j) {
                    dp[i][j] = 1;
                }
                if (j == i+1) {
                    dp[i][j] =  palindrome[i] == palindrome[j];
                }
            }
        }

        int aux, pos = 0, cont = 0;

        for (aux = 2; aux < n; aux++) {
            for ( i = 0; i < n - aux; i++) {
                testPalindrome(palindrome, i, (i+aux+1));
            }
        }
        aux = 0;
        /*
        for( i = 0; i < n; i++) {
            for (j = 0; j < n; j++){
                if(dp[i][j] == -1)
                    cout << dp[i][j] << " ";
                else
                    cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/

        vector<int> set_lenghts(n);

        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                if(i == 0) {
                    set_lenghts.push_back(1);
                    break;
                } else {
                    aux = 0;
                    for(k = i-1; k >= 0 ; k--) {
                        if (dp[k][j]) {
                            if (aux = 0)
                                aux = set_lenghts[k];
                            else if (aux > set_lenghts[k])

                            //TO DO
                        }
                    }
                }
            }
            cont++;
            i = pos;
            aux = pos+1;
            pos++;
        }

        test++;
        if(test > 1)
            printf("\n");
        printf("Teste %d\n",test);
        
        /*
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
        */
 
        printf("%d\n",cont);
    }
    if(test > 0)
        printf("\n");
    return 0;
}