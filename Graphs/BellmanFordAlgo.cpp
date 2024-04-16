/*
// BELLMANFORD ALGO IS SIMILAR TO DIJSKTRA ALGO 
// ONLY DIFFERENCE IS THAT DIJSKTRA CANNOT DEAL WITH NEGETIVE DISTANCE(WEIGHTS)
//TIME COMPLEXITY:- O(N*M)...WORSE COMPARE TO DIJKSTRA
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src]=0;

    for(int i=1;i<=n;i++){
        //TRAVERSING N-1 TIMES
        //TRAVERSING EVERY EDGE
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){//RELAXATION STEP
                dist[v]=dist[u]+wt;
            }
        }
    }
    return dist;

/*
    //CHECKING IF THERE IS ANY NEGATIVE LOOP PRESENT IN THE GRAPH
    bool flag=false;

    TRAVERSING THE EDGES ONE LAST TIME TO CHECK FOR NEGETIVE LOOP 
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9&&((dist[u]+wt)<dist[v])){
                flag=true;
            }
        }
    if(flag==false){
        return dist[dest]
    }
    return -1;
    
}
*/