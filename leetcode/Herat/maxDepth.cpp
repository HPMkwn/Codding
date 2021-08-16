#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    
    int balance=0,count=0;;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')balance++;
        else if(s[i]==')')balance--;

        if(balance>count){
            count = balance;
        }
    }

    return count;
}

int main() { return 0; }