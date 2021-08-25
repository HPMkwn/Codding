#include <bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    
    unordered_set<string> fromcity;

    for(auto x : paths){
        fromcity.insert(x[0]);
    }

    for(auto x : paths){
        
        if(fromcity.find(x[1])== fromcity.end())return x[1];
    }

    return "";
}
int main() { return 0; }