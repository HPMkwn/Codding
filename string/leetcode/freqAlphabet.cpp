#include <bits/stdc++.h>
using namespace std;

string freqAlphabets(string s) {

    string str="";
    for(int i=0;i<s.size();){
        if(i+2 < s.size() && s[i+2]!='#'){
            str += s[i] + 48;
            i++;
        }else{
            
            str += (s[i]-48)*10 + s[i+1] + 48;
            i += 3;
        }
    }
    return str;
}
int main() { return 0; }