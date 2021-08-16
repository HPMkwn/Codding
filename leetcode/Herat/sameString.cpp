#include <bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

    string str1="",str2="";
    for(string str:word1){
        str1 += str;
    }
    for(string str:word2){
        str2 += str;
    }

    return str1==str2;
}
int main() { return 0; }