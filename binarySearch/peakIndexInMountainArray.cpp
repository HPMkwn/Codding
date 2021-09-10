#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

    int n = arr.size();
    int i=0,j=n-1;

    while(i<=j){
        int mid = (i+j)>>1;

        if((mid == 0 || arr[mid-1] > arr[mid]) && (mid == n-1 || arr[mid] > arr[mid+1]))j = mid -1;
        else if((mid == 0 || arr[mid-1] < arr[mid]) && (mid == n-1 || arr[mid] < arr[mid+1]))i=mid+1;
        else return mid;
    }
    return -1;
}

int main(){

    vector<int> arr = {3,5,7,2,0};

    cout<<peakIndexInMountainArray(arr)<<"\n";

    return 0;
}