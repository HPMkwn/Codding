#include <bits/stdc++.h>
using namespace std;


vector<int> largestRange2(vector<int> array){

}

vector<int> largestRange(vector<int> array)
{
    
    set<int> s;
    for(int i=0;i<array.size();i++)s.insert(array[i]);

    vector<int> finalPair{-1,-1};

    for(auto itr=s.begin();itr!= s.end();){
        auto st = *itr;
        auto temp = st;
        while((itr!=s.end() && (*itr == temp+1 || *itr == st))){
            if((finalPair[1] -finalPair[0]) <= ((*itr)-st)){
                finalPair[0] = st;
                finalPair[1] = *itr;
            }
            temp = *itr;
            itr++;
        }			
    }

    return finalPair;
}

int main(){
    vector<int> ret = largestRange({1,11,3,0,15,5,2,4,10,7,12,6});
    for(int i=0;i<ret.size();i++)cout<<ret[i]<<" ";
    return 0;
}