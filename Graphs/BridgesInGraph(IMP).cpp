/*
TIME COMPLEXITY:- O(N+E)
SPACE COMPLEXITY:-O(N)

#include<unordered_map>
#include<list>
void dfs(int node,int parent, unordered_map<int,list<int>> &adj, vector<int> &disc,  vector<int> &low
,int timer, unordered_map<int,bool> &visited, vector<vector<int>> &ans){

    visited[node]=true;
    disc[node]=low[node]=timer++;

    for(auto neighbour:adj[node]){
        if(neighbour==parent){
            continue;// skipping an iteration when neighbour is parent
        }

        if(!visited[neighbour]){
           
            dfs( neighbour,node,  adj, disc, low, timer, visited, ans);
            low[node]=min(low[node],low[neighbour]);// low[neighbour] will usally be higher then low[node] but not in case of back edge

            // checking for bridge edge...
            if(low[neighbour]>disc[node]){
                vector<int> a;
                a.push_back(neighbour);
                a.push_back(node);
                ans.push_back(a);// updating ans...
            }
        }
        else{
            // already visited and not parent
            // this is a back edge
            low[node]=min(low[node],disc[neighbour]);
        }
    }
}

            
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //adjList
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //required data structures
    vector<int> disc(v);
    vector<int> low(v);
    int timer=0;
    int parent=-1;
    unordered_map<int,bool> visited;

    //initialising disc[] and low[]...("disc" means discover)
    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }

    vector<vector<int>> ans;

    //dfs
    for(int i=0;i<v;i++) {
        if(!visited[i]){
            dfs(i,parent,adj,disc,low,timer,visited,ans);
        }
    }
    
    return ans;
}
*/