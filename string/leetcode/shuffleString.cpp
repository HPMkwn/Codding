#include <bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {

    map<int,int> mp;

    for(int i=0;i<indices.size();i++){
        mp[indices[i]] = i;
    }

    string str="";

    map<int,int> ::iterator itr=mp.begin();
    for(itr;itr != mp.end() ;itr++){
        str += s[itr->second];
    }
    return str;
}

string restoreStringII(string s, vector<int>& indices) {

    string str1 = s;

    for(int i=0;i<indices.size();i++){
        str1[i] = s[indices[i]];
    }

    return s;

}


int main() { return 0; }