#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string s) {

        for(int i=0;i<s.length();i++){
            if(s[i]<97)
                s[i] += 32;
        }

        return s;
}

int main() { return 0; }