#include <bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k) {
    vector<string> tokens;
    stringstream check1(s);
    string intermediate;
    while (getline(check1, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }

    if(k>=tokens.size())return s;

    string str="";
    for(int i=0;i<k;i++){
        str += tokens[i] + " ";
    }

    return str.substr(0,str.size()-1);

}
int main() { return 0; }