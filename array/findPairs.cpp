#include<bits/stdc++.h>
using namespace std;

int N;
map<int,set<int>> mp;

int lsb(int x){
    return x & (~x + 1);
}

void insert(int val,int indOfVal){

    int i = val;
    while(i <= N){
        if(mp.find(i) != mp.end()){
            mp[i].insert(indOfVal);
        }else{
            set<int> s({indOfVal});
            mp[i] = s;
        }
        i += lsb(i);
    }
}

set<int>  findVals(int val){
    set<int> ret;
    // cout<< "findVals for i : "<< val<<"\n";
    int i = val;
    while(i>0){
        if(mp.find(i)!= mp.end() && mp[i].size()>0){
            set<int> temp = mp[i];
            for(auto x: ret)
                temp.insert(x);
            ret = temp;
        }
        i -= lsb(i);
    }

    return ret;
}

void printmap(){

    cout<<"=================>\n";
    for(pair<int,set<int>> x : mp){
        cout<<"for : "<<x.first<<"\n";
        for(auto y : x.second){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    

    vector<int> arr({5,1,4,7,3,6,2});
    N = 5;
    for(int i=arr.size()-1;i>=0;i--){
        
        // cout<<"Iteration for arr[i] = "<<arr[i]<<"\n";
        set<int> temp = findVals(arr[i]-1);
        // cout<<"Size of set"<<temp.size()<<endl;
        for(auto x : temp){
            cout<<arr[i]<<" : "<< arr[x]<<"\n";
        }
        insert(arr[i],i);
    }
    return 0;
}