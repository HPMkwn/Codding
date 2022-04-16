#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b, i) for (int i = a; i < b; i++)
#define rrep(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int subSeqSum(vector<int> &arr){
    int n = arr.size();
    if(arr.size()<2)return arr[0];
    int including = arr[0];
    int excluding = INT_MIN;

    for(int i=1;i<n;i++){

        int tempIncluding = max((excluding==INT_MIN && arr[i]<0)? 0 + arr[i] : (excluding + arr[i]),arr[i]);
        int tempExcluding = max(including,excluding);

        including = tempIncluding;
        excluding = tempExcluding;
    }

    return max(including,excluding);
}

int main(){

    vector<int> arr = {-1,-2,-1,-4,-5};

    cout<<subSeqSum(arr)<<"\n";
    return 0;
}