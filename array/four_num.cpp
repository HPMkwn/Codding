#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {

    int n= array.size();
    unordered_map<int,vector<vector<int>>> allSumUpPairs;

    vector<vector<int>> ret;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int currentSum = array[i] + array[j];
            int difference = targetSum - currentSum;
            if(allSumUpPairs.find(difference)!= allSumUpPairs.end()){
                for(vector<int> pair : allSumUpPairs[difference]){
                    pair.push_back(array[i]);
                    pair.push_back(array[j]);
                    ret.push_back(pair);
                }
            }
        }
        for(int k=0;k<i;k++){
            int currentSum = array[i] + array[k];
            allSumUpPairs[currentSum].push_back({array[i],array[k]});
        }
    }

  return ret;
}



int main(){
    
    return 0;
}