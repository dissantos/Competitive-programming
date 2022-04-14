#include <bits/stdc++.h>
using namespace std;


int main() {
    int x1, x2, y1, y2, x, y, test = 1, n, count;
    while(true) {
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) {
            break;
        }

        cin >> n;
        count = 0;
        while(n > 0) {
            cin >> x >> y;
            if( x1 <= x && x <= x2 && y1 >= y &&  y >= y2) {
                count ++;
            }
            n--;
        }
        cout << "Teste " << test << endl;
        cout << count << endl;
        test++;
    }
    return 0;
}