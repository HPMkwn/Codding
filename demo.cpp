#include<bits/stdc++.h>
using namespace std;

bool check(int i,int j,int n,vector<vector<bool>> &isVisted){
  return i>-1 && j>-1 && i<n && j<n && !isVisted[i][j];
}

bool inBound(int i,int j,int n){
  return i>-1 && j>-1 && i<n && j<n;
}

vector<vector<bool>> licquer_level(vector<vector<int>> grid){
  int n = grid.size();
  int i=n>>1,j=n>>1;
  int level= grid[i][j];
  vector<vector<bool>> isVisited(n,vector<bool>(n,false));

  queue<pair<int,int>> flow;
  set<pair<int,int>> pick;
  flow.push({i,j});
  isVisited[i][j] = true;

  vector<pair<int,int>> traverse = {{-1,0},{0,1},{1,0},{0,-1}};
  while(!flow.empty()){

    int size = flow.size();
    if(size){
      for(int k=0;k<size;k++){
        pair<int,int> temp = flow.front();
        flow.pop();
        for(int t=0;t<4;t++){
          int tempi = temp.first + traverse[t].first;
          int tempj = temp.second + traverse[t].second;
          
          if(check(tempi,tempj,n,isVisited) && grid[tempi][tempj] <= level){
            flow.push({tempi,tempj});
            isVisited[tempi][tempj]= true;
          }else if(!inBound(tempi,tempj,n)){
            return isVisited;
          }else if(check(tempi,tempj,n,isVisited) && grid[tempi][tempj] > level){
            pick.insert({tempi,tempj});
          }
        }
      }
    }else{
      int size = pick.size();
      int i=0;
      int m = INT_MAX;
      vector<int> ind;
      for(auto itr = pick.begin(); itr!= pick.end();itr++,i++){
        int temp = grid[itr->first][itr->second];
        if(m > temp){
          ind.clear();
          while (flow.empty()){
            flow.pop();
          }
          flow.push({itr->first,itr->second});
          ind.push_back(i);
        }else if(m==temp){
          flow.push({itr->first,itr->second});
          ind.push_back(i);
        }
      }
      
      size = flow.size();
      for(int i=0;i<size;i++){
        auto x = flow.front();
        flow.pop();
        pick.erase(x);
        flow.push(x);
      }
      level = grid[flow.front().first][flow.front().second];
    }
  }

  return {{}};
}

int main(){

  vector<vector<int>> grid = {
    {494,88 ,89 ,770,984,726,507},
    {340,959,220,301,639,280,290},
    {666,906,632,824,127,505,787},
    {673,499,843,172,193,613,154},
    {544,211,124,60 ,575,572,389},
    {635,170,174,946,593,314,300},
    {620,167,931,780,416,954,275}
  };

  vector<vector<bool>> ret = licquer_level(grid);
  int n = ret.size();

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(ret[i][j])cout<<".";
      else cout<<"|";
    }
    cout<<"\n";
  }

  return 0;
}