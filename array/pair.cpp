#include<bits/stdc++.h>
using namespace std;


bool isPairSum(vector<int> arr,int val){

    int i=0,j=arr.size()-1;

    while (i<j)
    {
        if(arr[i]+ arr[j]==val)return true;

        else if(arr[i] + arr[j] > val)j--;

        else i++;
    }

    return false;    
}


int main(){

}