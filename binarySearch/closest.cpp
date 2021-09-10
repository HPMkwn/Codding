#include <bits/stdc++.h>
using namespace std;

int closestElement(vector<int> &arr, int target) {
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

int main() { 
    
    vector<int> arr = {1,2,4,8,10};

    cout<<closestElement(arr,8)<<"\n";

    return 0; }