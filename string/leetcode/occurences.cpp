#include <bits/stdc++.h>
using namespace std;

bool areOccurrencesEqual(string s) {
    int arr[26] = {0};

    for(auto x : s){
        arr[x - 'a']++;
    }

    int isequal;
    for(int i=0;i<26;i++){

        if(isequal!=0 && isequal != arr[i]){
            return false;
        }else isequal = arr[i];
    }
    return true;
}

int main() { return 0; }