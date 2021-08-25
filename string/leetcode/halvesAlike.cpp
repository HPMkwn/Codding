#include <bits/stdc++.h>
using namespace std;

bool halvesAreAlike(string s) {
    
        int count=0;
        unordered_set<char> set{'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<s.size()>>1;i++){
            if(set.find(s[i])!=set.end())count++;
        }

        for(int i=s.size()>>1;i<s.size();i++){
            if(set.find(s[i])!=set.end()))count--;
        }

        return count==0;
}

int main() { return 0; }