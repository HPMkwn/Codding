#include <bits/stdc++.h>
using namespace std;

int InsertIndexOfAnElementInSortedArray(vector<int> &arr, int target) {
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i <= j) {
        int mid = (i+j)>>1;

        if(target > arr[mid])i = mid+1;
        else if (target < arr[mid]) j = mid-1;
        else return mid;
    }
    return i;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

    sort(arr2.begin(),arr2.end());
    int count=0;
    for(int i=0;i<arr1.size();i++){

        int ind = InsertIndexOfAnElementInSortedArray(arr2,arr1[i]);

        if(i<(arr1.size()) && abs(arr2[ind]-arr1[i])<=d){count++;continue;}

        if(i>0 && abs(arr2[ind]-arr1[i-1])<=d)count++;
    }

    cout<<count<<"\n";

    return count;
}

int main() { 
    
    vector<int> arr1 = {4,5,8};
    vector<int> arr2 = {10,9,1,8};
    int d = 2;
    cout<<findTheDistanceValue(arr1,arr2,d)<<"\n";
    return 0; }