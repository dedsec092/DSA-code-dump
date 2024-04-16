/*
APPROACH using BFS...
#include<unordered_map>
#include <list>
#include <queue>
// BFS is used to detect cycle.
bool isCycle(int node, unordered_map<int ,list<int> > &adj,unordered_map<int ,bool> &visited){
    queue<int> q;
    unordered_map<int ,int> parent;
    parent[node]=-1;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour :adj[front]){
            if(visited[neighbour]==true&&neighbour!=parent[front]){// if front is not the parent of next node(neighbour)
                                                                   // That means cycle exists     
                return true;
            }
            else if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int ,list<int> > adj;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int ,bool> visited;
   
    for(int i=0;i<n;i++){
         
        if(!visited[i]){
            bool ans=isCycle(i,adj,visited);
            if(ans==true){
            return "Yes";
        }
        }
      
    }
    return "No";
}

****************************************************************************************************

APPROACH using DFS

#include<unordered_map>
#include <list>

bool isCycle(int node,int parent ,unordered_map<int ,list<int> > &adj, unordered_map<int ,bool> &visited){
    visited[node]=true;

    for(auto neighbour:adj[node]){
       if(!visited[neighbour]){
           bool cycleDetected=isCycle(neighbour,  node,adj,visited);
           if(cycleDetected)
            return true;
       }
       else if(visited[neighbour]==true && neighbour!=parent){
           return true;
       }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int ,list<int> > adj;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int ,bool> visited;
   
    for(int i=0;i<n;i++){
         
        if(!visited[i]){
            bool ans=isCycle(i,-1,adj,visited);
            if(ans==true)
                 return "Yes";
        
        }
      
    }
    return "No";
}

*/