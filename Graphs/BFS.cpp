/*
#include<queue>
#include<set>
#include <unordered_map>
TIME COMPLEXITY OF BFS :- O(N+E) or O(V+E)
void prepareAdj(unordered_map<int ,set<int>> &adjList,vector<vector<int>> &adj ){
    for(int i=0;i<adj.size();i++){
        int u=adj[i][0];
        int v=adj[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs( unordered_map<int ,set<int>> &adjList, vector<int> &ans,
         unordered_map<int ,bool> &visited,int node){
    
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int ,bool> visited;
    unordered_map<int ,set<int>> adjList;
    vector<int> ans;
    prepareAdj(adjList,adj);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(adjList,ans,visited,i);
        }
    }
    return ans;
}
*/