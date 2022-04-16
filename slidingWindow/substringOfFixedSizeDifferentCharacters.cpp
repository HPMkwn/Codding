#include <bits/stdc++.h>
using namespace std;



void printmap(map<char,int> &mp){

    for(pair<char,int> x: mp){
        cout<<x.first<<" : "<<x.second<<"\n";
    }

    cout<<"\n";
}

int countGoodSubstrings(string s) {

    map<char,int> m;
    int i=0;
    int count=0;
    while (i<s.length())
    {
        if(i<3){
            m[s[i]] ++;
            if(m[s[i]]==0)
                m.erase(s[i]);
        }        

        if(i>=3){
            m[s[i]]++;
            m[s[i-3]]--;
            if(m[s[i-3]]==0)
                m.erase(s[i-3]);
        }
        if(m.size()==3)
            count++;
        i++;
    }
    
    return count;
}


int main() { 
    
    string str = "aababcabc";
    // cout<<"Enter String : ";
    // cin>>str;
    cout<<"\nTotal number of uniques : " <<countGoodSubstrings(str);
    
    return 0; }