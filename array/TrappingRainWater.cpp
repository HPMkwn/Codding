#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int> arr){

    int n =arr.size();
    vector<int> prefix(n,INT_MIN),suffix(n,0);

    int sum=0;
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = max(prefix[i-1],arr[i]);
    }

    suffix[n-1] = arr[n-1];
    for(int i=n-2;i>0;i--){
        suffix[i] = max(suffix[i+1],arr[i]);
    }

    for(int i=0;i<n;i++){
        sum += min(prefix[i],suffix[i]) - arr[i];
    }
    return sum;
}

int main(){
    
    vector<int> arr({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});

    queue<int> q;


    cout<<rainWater(arr)<<"\n";
    return 0;
}