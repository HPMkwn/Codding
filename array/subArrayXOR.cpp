#include<bits/stdc++.h>
using namespace std;


int subArraysXOR(vector<int> arr,int XOR){

    int n= arr.size();
    map<int,int> mp;
    int total=0;
    int XORtillHere=0;
    for(int i=0;i<n;i++){
        XORtillHere ^= arr[i];

        if(mp.find(XORtillHere^XOR)!= mp.end()){
            total += mp[XORtillHere^XOR];
        }

        if(XORtillHere==XOR)total++;

        mp[XORtillHere]++;
    }

    return total;
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    int XOR;
    cin>>XOR;
    cout<<subArraysXOR(arr,XOR);
    return 0;
}