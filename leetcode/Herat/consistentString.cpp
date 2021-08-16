#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {

    bool s[26]={false};
    for(int i=0;i<allowed.size();i++){
        s[allowed[i]-97] = true;
    }

    int total = words.size();

    for(int i=0;i<words.size();i++){
        for(char ch : words[i]){
            if(!s[ch-97]){total--;break;}
        }
    }

    return total;
}

int main() { return 0; }