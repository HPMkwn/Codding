#include<bits/stdc++.h>
using namespace std;


int findSeparationLine(vector<int> nums){
    int i=0,j=nums.size()-1;
    int label1 = nums[0],label2 = nums.back();
    while (i<j)
    {
        int mid = (i+j)>>1;
        if(nums[mid]==label1){
            i = mid+1;
        }else{
            j = mid - 1;
        }
    }
    if(nums[i]==label1)return i+1;
    return i;
    
}


int main(){
    
    return 0;
}