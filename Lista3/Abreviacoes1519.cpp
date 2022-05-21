#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;


map<string, int> count_words;

bool comp(string a, string b) {
    if(a.length() > 2 && b.length() > 2)
        return ((a.length() - 2)*count_words[a] > (b.length() - 2)*count_words[b]);
    else 
        return a.length() > 2;
}

int main() {
    string frase;
    string word;
    vector<string> words, order_words;
    set<string> set_words;
    map<char, string> dict_words;

    while(true) {
        words.clear();
        order_words.clear();
        count_words.clear();
        set_words.clear();
        dict_words.clear();

        getline(cin, frase);
        if(frase == ".") {
            break;
        }
        istringstream iss(frase);

        while(iss >> word) {
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++) {
            if(count_words.find(words[i]) == count_words.end()) {
                count_words[words[i]] = 1;
            } else {
                count_words[words[i]] += 1;
            }
        }

        order_words = words;
        sort(order_words.begin(), order_words.end(), comp);
        for(int i = 0; i < order_words.size(); i++) {
            if(order_words[i].length() > 2){
                if(dict_words.find(order_words[i][0]) == dict_words.end()) {
                    set_words.insert(order_words[i]);
                    dict_words[order_words[i][0]] = order_words[i];
                }
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            if(words[i].length() > 2) {
                if(set_words.find(words[i]) != set_words.end()) {
                    cout << words[i][0] << "." << " ";
                } else {
                    cout << words[i] << " ";
                }
            } else {
                cout << words[i] << " ";
            }
        }
        
        if(words[words.size() - 1].length() > 2) {
            if(set_words.find(words[words.size() - 1]) != set_words.end()) {
                cout << words[words.size() - 1][0] << "." << endl;
            } else {
                    cout << words[words.size() - 1] << endl;
            }
        } else {
            cout << words[words.size() - 1] << endl;
        }


        map<char, string>::iterator i;
        cout << dict_words.size() << endl;
        for( i = dict_words.begin(); i != dict_words.end(); i++) {
            cout << i->first << ". = " << i->second <<endl;
        }
    }

    return 0;
}