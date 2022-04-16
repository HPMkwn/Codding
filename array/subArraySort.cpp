#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySort(vector<int> array) { 

    int n= array.size();
    vector<int> suffix(n,0);
    int tempmin = INT_MAX;
    for(int i=n-1;i>=0;i--){
        if(array[i] < tempmin){
            tempmin = array[i];
        }
        suffix[i]= tempmin;
    }
    vector<int> suffix(n,0);
    int tempmax = INT_MIN;
    
    for(int i=0;i<n;i++){
        ;
    }
    return {}; 
}

int main() { return 0; }