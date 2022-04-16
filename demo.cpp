#include<bits/stdc++.h>
using namespace std;

int main(){

  map<int,int> mp;
  for(int i=0;i<10;i++)mp[i]=i;
  mp[1]--;
  cout<<mp.size()<<"\n";
  return 0;
}