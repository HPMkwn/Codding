#include<bits/stdc++.h>
using namespace std;


int inversionUsingMergeSort(vector<int> &arr, int l,int r,map<int,vector<int>> &pairs){
    long long inversions=0;
    if(l<r){
        int mid = (l+r)>>1;
        inversions += inversionUsingMergeSort(arr,l,mid,pairs);
        inversions += inversionUsingMergeSort(arr,mid+1,r,pairs);

        int i = l;
        int j = mid+1;
        vector<int> temp(arr.size(),0);
        int k=l;
        while(i<=mid && j<=r){

            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++]; 
            }else{
                
                inversions += (mid-i+1);

                pairs[arr[j]].insert(pairs[arr[j]].end(), arr.begin()+(i), arr.begin()+(mid +1));

                temp[k++] = arr[j++];
            }
        }

        while (i<=mid)
        {
            temp[k++] = arr[i++];
        }
        while (j<=r)
        {
            temp[k++] = arr[j++];
        }

        for(int o=l;o<=r;o++){
            arr[o] = temp[o];
        }
    }
    return inversions;
}

int inversionsUsingSTL(vector<int> &arr){

    int n = arr.size();
    set<int> s;
    int inversions=0;
    for(int i=0;i<n;i++){
        inversions += distance(s.upper_bound(arr[i]),s.end());
        s.insert(arr[i]);
    }

    return inversions;
}

int main(){
    
    vector<int> arr{7,4,5,2,3,15,10,30,1};

    map<int,vector<int>> pairs;

    cout<<"inversions : "<<inversionUsingMergeSort(arr,0,arr.size()-1,pairs)<<"\n";

    for (auto x : pairs){
        cout<< "possible values of x : " << x.first<<" and count : "<<x.second.size()<<"\n";
        for(auto y : x.second){
            cout<<y<<", ";
        }
        cout<<"\n";
    }
    
    return 0;
}