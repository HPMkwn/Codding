#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

void dfs(vector<vector<int>>& graph,int sv,vector<bool>& visited){
    visited[sv] = true;
    cout<<sv<<" ";
    for(int cv : graph[sv]){
        if(!visited[cv])
            dfs(graph,cv,visited);
    }
}

void bfs(vector<vector<int>> &graph, int sv, vector<bool>visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty()){
        sv = q.front();
        cout << sv << " ";
        q.pop();
        for (int cv : graph[sv]){
            if (!visited[cv]){
                visited[cv] = true;
                q.push(cv);
            }
        }
    }
}
int main(){
    int n,e,x,y;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    F(0,e,i){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    vector<bool> visited(n,false);

    dfs(graph,0,visited);
    cout<<"\n";
    bfs(graph,0,visited);

  return 0;
}