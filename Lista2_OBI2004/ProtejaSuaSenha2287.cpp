#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;

int verifyPass(int n, int pos, int digit, int value, vector<map<char, vector<int>>> options, vector<vector<char>> passwords) {
    if(pos == n) {
        return value;
    }
    vector<int> opt;
    opt = options[pos].at(passwords[pos][digit]);

    if(value == opt[0]) {
        return verifyPass(n, pos+1, digit, value, options, passwords);
    } else if(value == opt[1]) {
        return verifyPass(n,pos+1, digit, value, options, passwords);
    } else {
        return -1;
    }
    return 0;
}

int main() {
    int n, test = 0, option1, option2, i, j, k, digit;
    char letter;
    while(true) {
        vector<vector<char>> passwords;
        vector<map<char, vector<int>>> options;
        cin >> n;
        if(n == 0) {
            break;
        }
        k = 0;
        while(k < n) {
            map<char, vector<int>> opt;
            vector<char> pass;
            cin >> option1;
            cin >> option2;
            opt.insert({'A', {option1, option2}});

            cin >> option1;
            cin >> option2;
            opt.insert({'B', {option1, option2}});

            cin >> option1;
            cin >> option2;
            opt.insert({'C', {option1, option2}});

            cin >> option1;
            cin >> option2;
            opt.insert({'D', {option1, option2}});

            cin >> option1;
            cin >> option2;

            opt.insert({'E', {option1, option2}});
            
            j = 0;
            while(j < 6){
                cin >> letter;
                pass.push_back(letter);
                j++;
            }
            k++;
            passwords.push_back(pass);
            options.push_back(opt);
        }
        vector<int> opt;
        test++;
        if(test > 1)
            printf("\n");
        printf("Teste %d\n",test);
        for(i = 0; i < 6; i++) {
            opt = options[0].at(passwords[0][i]);
            option1 =  verifyPass(n, 1, i, opt[0], options, passwords);
            option2 = verifyPass(n, 1, i, opt[1], options, passwords);
            if(option1 == -1) {
                cout << option2;
            } else {
                cout << option1;
            }
            cout << " ";
        }
        printf("\n");
    }
    if(test > 0)
        printf("\n");
    return 0;
}