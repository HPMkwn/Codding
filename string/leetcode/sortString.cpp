#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s) {
    // Vector of string to save tokens
    vector<string> tokens;
    stringstream check1(s);
    string intermediate;
    while (getline(check1, intermediate, ' ')) {
        tokens.push_back(intermediate);
        cout<<intermediate<<"\n";
    }

    // for (string token : tokens) cout << token << "\n";
    map<int,string> mp;
    for(string token : tokens){
        mp[int(token[token.length()-1])] = token.substr(0,token.length()-1);
    }

    map<int,string> ::iterator itr;

    string ret = "";
    for(itr = mp.begin();itr!=mp.end();itr++){
        ret += itr->second + " ";
    }

    // cout<<ret<<"\n";

    return ret.substr(0,ret.length()-1);
}

int main() {
    cout<<sortSentence("Hello2 world1")<<"\n";
     return 0; }