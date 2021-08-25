#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][i] = 1;
    }

    int maxlenpal = 0,si=0,sj=0;
    
    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                // dp[i][j] = dp[i + 1][j - 1];
            }
            if(maxlenpal < dp[i][j]){maxlenpal = dp[i][j];si=i-1;sj=j-1;}
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return s.substr(si,sj-si+1);
}

int main() { 
    
    cout<<longestPalindrome("abbca")<<"\n";
    return 0; 

}