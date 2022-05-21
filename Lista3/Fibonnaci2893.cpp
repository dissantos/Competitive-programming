#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define resto 1000007

using namespace std;


unsigned long long int memoization[20000]; 
unsigned long long int k;

unsigned long long int fib(int pos_inicial, int pos_final) {
    unsigned long long int sum = 0;
    if (memoization[pos_final] != -1) {
        return memoization[pos_final];
    } else  {
        for(int i = pos_inicial; i < pos_final; i++)  {
            sum += memoization[i];
        }
        memoization[pos_final] = sum%resto;
        return memoization[pos_final]; 
    }
}
int main() {
    int t;
    
    int n;
    unsigned long long int sum;
    cin >> t;
    while(t) {
        t--;
        sum = 0;
        cin >> k >> n;  
        for(int i = 0; i < n; i++) {
            if(i < k) {
                memoization[i] = i;
                sum += i;
            }
            else 
                memoization[i] = -1;
        }
        memoization[k] = sum;
        if(memoization[n-1] != -1) {
            cout << memoization[n-1] << endl;
        } else {
            for(int i = k+1; i  < n; i++) {
                fib(i-k, i);
            }
            cout << memoization[n-1] << endl;
        }
    }
}