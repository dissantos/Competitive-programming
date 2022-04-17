#include <bits/stdc++.h>
using namespace std;


bool cmp(string a, string b) {
    return strcmp(a.c_str(),b.c_str()) == -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> pessoas;
    while(n--) {
        string pessoa;
        cin >> pessoa;
        pessoas.push_back(pessoa);
    }

    sort(pessoas.begin(), pessoas.end(), cmp);

    cout << pessoas[k-1] << endl;


    return 0;
}