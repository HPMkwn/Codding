#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey,string ruleValue) {

    int key = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    int total=0;
    for(int i=0;i<items.size();i++){
        if(items[i][key]==ruleValue)total++;
    }

    return total;
}

int main() { return 0; }