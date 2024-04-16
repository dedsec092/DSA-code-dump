/*
TIME COMPLEXITY OF DFS :- O(N+E) or O(V+E)
void dfs(int node,unordered_map<int ,bool> &visited,
             unordered_map<int,list<int>> &adj, vector<int> &component){

    component.push_back(node);
    visited[node]=true;

    //traversing all connected nodes of "node"..
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i,  visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int ,bool>visited;
    vector<vector<int>> ans;


    for(int i=0;i<V;i++){..this loop is to make sure all disconnected components of the graph gets included.
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
*/