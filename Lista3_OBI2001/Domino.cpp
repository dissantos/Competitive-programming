#include <bits/stdc++.h>
using namespace std;

bool visited[7];
int graph[7][7];

void dfs(int v) {
    int i;
    if (!visited[v]) {
        visited[v] = true;

        for(i = 0; i < 7; i++) {
            if(graph[v][i]) {
                dfs(i);
            }
        }
    } 
    
}

bool testConvex() {
    int i;
    for (i = 0; i < 7; i++) {
        if(!visited[i]) {
            dfs(i);
            break;
        }
    }
    for (i = 0; i < 7; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, test = 1, x, y, i,j, cont_oddPieces;
    while(true) {
        int oddPieces[7] = {0};
        cin >> n;

        if(n == 0) {
            break;
        }
        
        cont_oddPieces = 0;
        for (i = 0; i < 7; i++) {
            visited[i] = true; 
            for (j = 0; j < 7; j++){
                graph[i][j] = 0;
            }
        }
        i = 0;

        while (i < n) {
            cin >> x >> y;
            oddPieces[x] = 1 - oddPieces[x];
            oddPieces[y] = 1 - oddPieces[y];
            graph[x][y] = 1;
            graph[y][x] = 1;
            visited[x] = false;
            visited[y] = false;
            i++;
        } 
        
        cout << "Teste " << test << endl;
        for(i = 0; i < 7; i++) {
            if(oddPieces[i]) {
                cont_oddPieces++;
            }
        }
        if (cont_oddPieces > 2) {
            cout << "nao" << endl;
        } else if (testConvex()) {
            cout << "sim" << endl;
        } else {
            cout << "nao" << endl;
        }
        cout << endl;
        test++;
    }
    return 0;
}