#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &array,int exp){
	
	int n = array.size();
	vector<int> count(256,0),output(n,0);
	
	for(int i=0;i<n;i++){
		count[(array[i]/exp)%10]++;
	}
	
	for(int i=1;i<256;i++)count[i] += count[i-1];
	
	for(int i=n-1;i>=0;i--)output[--count[(array[i]/exp)%10]] = array[i];
	
	for(int i=0;i<n;i++)array[i] = output[i];
}


int getMax(vector<int> array){
    int val = 0;

    for(int i=0;i<array.size();i++){
        if(val<array[i])val = array[i];
    }

    return val;
}

vector<int> radixSort(vector<int> array) {
    
    int maxValue = getMax(array);

    cout<<maxValue<<"\n";
	for(int exp=1; maxValue/exp > 0;exp *=10){
		countingSort(array,exp);
	}

    return array;
}


int main(){
    
    vector<int> arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2};

    arr = radixSort(arr);

    for(auto x : arr)cout<<x<<" ";
    cout<<"\n";
    return 0;
}