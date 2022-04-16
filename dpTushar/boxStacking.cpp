#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b, i) for (int i = a; i < b; i++)
#define rrep(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int maxHeight(vector<vector<int>> &boxes){
    int n = boxes.size();
    vector<vector<int>> arr(3*n); 

    int k=0;
    rep(0,n,i){
        sort(boxes[i].begin(),boxes[i].end());

        arr[k++] = {boxes[i][1],boxes[i][0],boxes[i][2]};
        arr[k++] = {boxes[i][2],boxes[i][1],boxes[i][0]};
        arr[k++] = {boxes[i][2],boxes[i][0],boxes[i][1]};
    }   

    sort(arr.begin(),arr.end(),[&](const vector<int> &a,const vector<int> &b){return a[0]*a[1] < b[0]*b[1];});

    vector<int> dp(3*n +1);
    int maxh = 0;
    rep(0,3*n,i){
        dp[i] = arr[i][2];
        rep(0,i,j){
            if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1])
                dp[i] = max(dp[i],dp[j]+arr[j][3]);
        }

        maxh = max(maxh,dp[i]);
    }

    return maxh;
}

int main(){



    return 0;
}