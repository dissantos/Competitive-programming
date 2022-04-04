#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string evenPlayer;
    string oddPlayer;
    int n, i, evenMove, oddMove, tests = 1;
    while(true) {
        vector<string> winner;
        i = 0;
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> evenPlayer;
        cin >> oddPlayer;
        while(i < n) {
            cin >> evenMove;
            cin >> oddMove;
            if((evenMove+oddMove)%2 == 0){
                winner.push_back(evenPlayer);
            } else {
                winner.push_back(oddPlayer);
            }
            i++;
        }

        cout << "Teste ";
        cout << tests << endl;
        for(i = 0; i < n; i++) {
            cout << winner[i] << endl;
        }
        cout << endl;
        tests++;
    }
    return 0;
}