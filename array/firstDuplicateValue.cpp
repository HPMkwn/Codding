#include<bits/stdc++.h>
using namespace std;

int firstDuplicateValue(vector<int> array) { 
	
	int largestvalue=0;
    for(int i=0;i<array.size();i++){
        if(largestvalue > array[i])largestvalue  = array[i];
    }
    vector<bool> vec(largestvalue+1,0); 
	for(int i=0;i<array.size();i++){
		if(!vec[array[i]])vec[array[i]]=1;
        else if(vec[array[i]]) return array[i];
	}
	return -1; 
}


int main(){
    
    return 0;
}