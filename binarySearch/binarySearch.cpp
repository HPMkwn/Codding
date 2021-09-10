#include<bits/stdc++.h>
using namespace std;

int binaryserch(vector<int> nums,int target)
{
    int i=0,j=nums.size()-1;

    while(i<=j){
        int mid = (i + j)>>1;

        if(target > nums[mid])i = mid+1;
        else if(target < nums[mid])j = mid -1;
        else return mid;
    }

    return -1;
}
int main()
{
    int t,n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    
    cin>>t;
    int x;
    while(t--){
        cin>>x;
        cout<<binaryserch(arr,x)+1<<"\n";
    }
    return 0;   
}
