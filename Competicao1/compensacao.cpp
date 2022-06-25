//ALEXANDRE LUIS RIBEIRO MARTINS
//DIEGO SANTOS GONCALVES
//Gabriel Arrighi Silva

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


int main() {
    int M,N;
    int hab_x, hab_y, val, val_total = 0, val_total_red = 0, cheques_hab;
    cin >> M >> N;
    vector<vector<int>> graph_hab(N, vector<int>(N));
    
    while(M--) {
        cin >> hab_x >> val >> hab_y;
        graph_hab[hab_x-1][hab_y-1] += val;
        graph_hab[hab_y-1][hab_x-1] -= val; 
    }
    
    for(int j = 0; j < N; j++) {
        cheques_hab = 0;
        for(int i = 0; i < N; i++) {
            if(graph_hab[i][j] > 0) val_total += graph_hab[i][j];
            cheques_hab += graph_hab[i][j];
        }
        if(cheques_hab > 0) val_total_red += cheques_hab;
    }
    
    if(val_total_red == val_total) {
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }
    cout << val_total_red << endl;
}