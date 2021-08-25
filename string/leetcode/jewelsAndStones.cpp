#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    set<char> s;

    for(int i=0;i<jewels.length();i++){
        s.insert(jewels[i]);
    }

    int total;
    for(int i=0;i<stones.length();i++){
        if(s.find(stones[i]) != s.end() )total++;
    }

    return total;
}
int main() { return 0; }