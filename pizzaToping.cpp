#include <bits/stdc++.h>
using namespace std;

pair<int,int> ReturnPrizeOfPizza(int priceOfTopping, int PriceOfAlooTikki,
                       int priceOfPizza) {
    vector<vector<pair<int,int>>> dp(3, vector<pair<int,int>>(priceOfPizza + min(priceOfTopping,PriceOfAlooTikki) + 1, {0,0}));
    int endPriceOfPizza = priceOfPizza + min(priceOfTopping,PriceOfAlooTikki);
    for(int i=0;i<3;i++){
        dp[i][0] = {1,1};
    }
    int arr[] = {priceOfTopping,PriceOfAlooTikki};
    for(int i=1;i<=2;i++){
        for(int j=1;j<=endPriceOfPizza;j++){
            if(j>=arr[i-1]){
                if((dp[i-1][j-arr[i-1]].first != 0 && dp[i-1][j-arr[i-1]].second!= 0) && (dp[i][j-arr[i-1]].first != 0 && dp[i][j-arr[i-1]].second!= 0)){
                    if(dp[i-1][j-arr[i-1]].first + dp[i-1][j-arr[i-1]].second < dp[i][j-arr[i-1]].first + dp[i][j-arr[i-1]].second){
                        dp[i][j] = dp[i-1][j-arr[i-1]];
                        dp[i][j].first++;
                        dp[i][j].second++;
                    }else{
                        dp[i][j] = dp[i][j-arr[i-1]];
                        dp[i][j].first++;
                        dp[i][j].second++;
                    }
                }else if(dp[i-1][j-arr[i-1]].first != 0 && dp[i-1][j-arr[i-1]].second!= 0){
                    dp[i][j] = dp[i-1][j-arr[i-1]];
                    dp[i][j].first++;
                    dp[i][j].second++;
                }else if(dp[i][j-arr[i-1]].first != 0 && dp[i][j-arr[i-1]].second!= 0){
                    dp[i][j] = dp[i][j-arr[i-1]];
                    dp[i][j].first++;
                    dp[i][j].second++;
                }
            }
        }
    }

    for(int i=priceOfPizza;i<endPriceOfPizza;i++){
        if(dp[0][i].first != 0 && dp[0][i].second!= 0)return dp[0][i];
        if(dp[1][i].first != 0 && dp[1][i].second!= 0)return dp[1][i];
    }
}

int main() { return 0; }