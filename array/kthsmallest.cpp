#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[high];
    int i=low,j=low;
    while(j<high){
        if(arr[j]<pivot){
            swap(arr[j],arr[i]);
            i++;
        }
        j++;
    }
    swap(arr[high],arr[i]);

    return i;
}

int quicksort(vector<int> &arr,int low,int high,int k){
    
    if(low < high){
        int p = partition(arr,low,high);
        if(p==k)return arr[p];
        else if((p-low)>k) {int ret = quicksort(arr,low,p-1,k); if(ret!=-1)return ret;}
        return quicksort(arr,p+1,high,k);
    }
    else if(low==high)return arr[low];
    else return -1;
}

int main(){
    vector<int> arr={12,5,787,1,23};
    for (auto &i : arr)
    {
        cout<<i<<" ";
    }
    
    cout<<"\n"<<quicksort(arr,0,arr.size()-1,2-1)<<"\n";
    for (auto &i : arr)
    {
        cout<<i<<" ";
    }
    
    return 0;
}