#include <bits/stdc++.h>
using namespace std;



int main() {
    int comprimento, test = 1, n, i, x1, x2, aux;
    while(true) {
        cin >> comprimento >> n ;


        if(comprimento == 0 && n == 0) {
            break;
        }

        vector<pair<int,int>> intervalo(n);
        vector<int> intervalo_arr(2*n);

        i = 0;
        while(i < n) {
            cin >> x1 >> x2;
            intervalo[i] = {x1, x2};
            i++;
        }

        sort(intervalo.begin(), intervalo.end());
        for (i = 0; i < n; i++) {
            intervalo_arr[2*i] = intervalo[i].first;
            intervalo_arr[2*i + 1] = intervalo[i].second;
        }

        cout << "Teste " << test << endl;
        for (i = 0; i < 2*n; i++) {
            if(i == 0) {
                cout << intervalo_arr[i] << " ";
            } else if (i == 1) {
                aux = intervalo_arr[i];
            } else if (i%2 == 0) {
                if (intervalo_arr[i] > aux) {
                    cout << aux << endl;
                    cout << intervalo_arr[i] << " ";
                }
            } else {
                if (aux < intervalo_arr[i]) {
                    aux = intervalo_arr[i];
                }
            }
        }
        cout << aux << endl << endl;

        test++;
    }
    return 0;
}