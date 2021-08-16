#include <bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {

    int total=0,count=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            total++;
        }else {
            total--;
        }

        if(total==0)count++;
    }

    return count;
}

int main() { return 0; }