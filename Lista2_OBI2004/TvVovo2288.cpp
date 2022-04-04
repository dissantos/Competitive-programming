#include <bits/stdc++.h>
using namespace std;

int matriz[1000][1000];
int aux[1000][1000];


int main() {
    int m,n, i,j, value, x, y, auxX, auxY, test = 1;
    while(true) {
        cin >> m;
        cin >> n;

        if(m == 0 && n == 0) {
            break;
        }

        for(i=0; i < m; i++) {
            for(j=0; j < n; j++) {
                cin >> value;
                matriz[i][j] = value;
            }
        }
        x = 0;
        y = 0;
        while(true) {
            cin >> auxX;
            cin >> auxY;
            x += auxX;
            y -= auxY;
            if(auxX == 0 && auxY == 0) {
                if(x >= 0) {
                    if(x%n == 0) {
                        x = n;
                    } else {
                        x %= n;
                    }
                }

                if(y >= 0) { 
                    if(y%m == 0) {
                        y = m;
                    } else {
                        y %= m;
                    }
                }
                cout << "Teste " << test << endl;
                test++;
                for(i = 0; i < m; i++) {
                    for (j = 0; j < n; j++) {
                        if( x >= 0 && y >= 0) {
                            if(i - y < 0) {
                                auxY = y - m;
                            } else {
                                auxY = y;
                            }
                            if(j - x < 0) {
                                auxX = x - n;
                            } else {
                                auxX = x;
                            }
                            value = matriz[i-auxY][j - auxX];
                            aux[i][j] = value;
                        }
                        if( x < 0 && y >= 0) {
                            if(i - y < 0) {
                                auxY = y - m;
                            } else {
                                auxY = y;
                            }
                            
                            aux[i][j] = matriz[i - auxY][(j - x) % n];
                        }
                        if( x >= 0 && y < 0) {
                            if(j - x < 0) {
                                auxX = x - n;
                            } else {
                                auxX = x;
                            }
                            aux[i][j] = matriz[(i - y)%m][j - auxX];
                        }
                        if( x < 0 && y < 0) {
                            
                            aux[i][j] = matriz[(i - y)%m][(j - x)%n];
                        }

                        if (j < n-1) cout << aux[i][j] << " ";
                        else cout << aux[i][j] << endl;
                    }
                }
                break;
            }            
        }
        cout << endl;

    }
    return 0;
}