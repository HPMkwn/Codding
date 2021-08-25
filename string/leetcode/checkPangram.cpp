#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) {
    set<char> s;

    for(int i=0;i<sentence.length();i++){
        s.insert(sentence[i]);
        if(s.size()==26)return true;
    }

    return false;
}

int main() { return 0; }