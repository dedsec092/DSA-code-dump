/*
//CONDITION TO FIND CYCLE IN DIRECTED GRAPH:-
 // WE WILL NEED AN EXTRA DATA STRUCTURE (dfsVisited)

#include <unordered_map>
#include <list>
bool isCycle(int node,unordered_map<int ,bool> &visited, 
            unordered_map<int,bool> &dfsVisited,unordered_map<int ,list<int> > &adj){
  visited[node]=true;
  dfsVisited[node]=true;
  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
       bool cycleDetected=isCycle(neighbour,visited,dfsVisited,adj);
       if(cycleDetected){
         return true;
       }
    }
    else if (visited[neighbour]==true && dfsVisited[neighbour]==true){ <---CONDION TO FIND CYCLE 
      return true;
    }
  }
        dfsVisited[node]=false;
        return false;
            }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int ,list<int> > adj;
    for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;

      adj[u].push_back(v);
    }
    unordered_map<int ,bool>visited;
    unordered_map<int,bool> dfsVisited;

     for(int i=0;i<n;i++){
       if(!visited[i]){
         bool ans=isCycle(i,visited,dfsVisited,adj);
         if(ans==true){
           return true;
         }
       }
     }
     return false;
}
*/