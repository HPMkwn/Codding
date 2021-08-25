#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr){

    for(auto x : arr){
        if(x>1)return true;
    }

    return false;
}

int lengthOfLongestSubstring(string s) {

    vector<int> arr(128,0);

    int start=0,end=0;
    int maxlength = 0,temp=0;
    for(end;end<s.size();end++){
        arr[s[end]]++;

        while(check(arr)){
            start++;
            temp = (end - start + 1);
        }
        maxlength = max(temp,maxlength);
    }
}

int main() { 
    string str = "";
    cout<<lengthOfLongestSubstring(str)<<"\n";
    return 0; }