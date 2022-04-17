#include <bits/stdc++.h>
using namespace std;


int main() {
    queue<int> cards;  
    int n,i, card;
    cin >> n;
    while(n) {
        for(i = 1; i <= n; i++) {
            cards.push(i);
        }

        cout << "Discarded cards:";
        while(cards.size() > 2) {
            cout << " " << cards.front() << ',';
            cards.pop();
            card = cards.front();
            cards.pop();
            cards.push(card);
        }
        if(cards.size() > 1) {
            cout << " " << cards.front() ;
            cards.pop();
            card = cards.front();
            cards.pop();
            cards.push(card);
        }
        cout << endl << "Remaining card: " << cards.front() << endl;
        cards.pop();


        cin >> n;
    }
    return 0;
}