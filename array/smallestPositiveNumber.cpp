#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n) {
    int l = 0, r = n - 1;
    while (l <= r) {
        if (arr[l] > 0) {
            swap(arr[l], arr[r]);
            r--;
        } else {
            l++;
        }
    }
    // cout << "l is " << l << "\n";
    // for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    // cout<<"\n";
    for (int i = l; i < n; i++) {

        int temp = arr[i]>0 ? arr[i] : (-1)*arr[i]; 
        if ((temp + l - 1) < n) {

            arr[temp + l - 1] *=(-1);
        }

        // cout<<i<<" "<<arr[i]<<"\n";
    }


    for (int i = l; i < n; i++) {

        if (arr[i] > 0) return i - l + 1;
    }

    return n - l + 1;
}

int main() { 
    
    vector<int> arr;

    int n;
    cin>>n;
    int temp=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<missingNumber(arr,arr.size())<<"\n";
    
    return 0; 
}