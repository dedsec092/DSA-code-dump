/*
// USING KAHNS ALGO (BFS)...using indegree 
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;// adjList
    for(int i=0;i<edges.size();i++){
      int u=edges[i].first-1;
      int v=edges[i].second-1;

      adj[u].push_back(v);
    }
    // indegree array
    vector<int> indegree(n);
    int count=0;

    for(auto i:adj){
      for(auto j: i.second){
        indegree[j]++;
      }
    }

    queue<int> q;
    //pushing nodes of indegree 0.
    for(int i=0;i<n;i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }

  //BFS
    while(!q.empty()){
      int front=q.front();
      q.pop();
      count++;// imp step
      for(auto neighbour:adj[front]){
        indegree[neighbour]--;
        if(indegree[neighbour]==0){
          q.push(neighbour);
        }
      }
    }
    
    if(count==n){ // CYCLE IS NOT PRESENT CONDITION
      return false;
    }
    else{
      return true;
    }
}
*/