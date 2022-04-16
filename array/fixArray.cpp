#include<bits/stdc++.h>
using namespace std;

void fixArray(vector<int> arr){

    for(int i=0;i<arr.size();){
        if(arr[i]!= -1 && i!=arr[i]){
            swap(arr[i],arr[arr[i]]);
        }else{
            i++;
        }
    }
}

int main(){
    
    return 0;
}