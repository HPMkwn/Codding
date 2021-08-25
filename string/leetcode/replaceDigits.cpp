#include <bits/stdc++.h>
using namespace std;

string replaceDigits(string s) {

    for(int i=1;i<s.size();i+=2){
        if(s[i]>47 && s[i]<58){
            s[i] = s[i-1] + int(s[i]);
        }
    }

    return s;
}
int main() { return 0; }