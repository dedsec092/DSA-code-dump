/*
#include <bits/stdc++.h> 
bool isSafe(int x,int y,vector < vector < int >> & arr,int n,vector<vector<bool> >&visited){
    if((x>=0&&x<n)&&(y>=0&&y<n)&&(arr[x][y]==1)&&visited[x][y]==0){
        return true;
    }
    return false;
}
void solve(int x,int y,vector < vector < int >> & arr,int n,vector<vector<bool> >&visited,
            vector < string > &ans,  string path){
    if(x==n-1&&y==n-1){
        ans.push_back(path);
        return;
    }
   
    //dlru
      visited[x][y]=1;
    //down
    if(isSafe(x+1,y,arr,n,visited)){
        
        solve(x+1,  y,  arr,  n, visited ,  ans,  path+'D');
        
    }
    
    //left
     if(isSafe(x,y-1,arr,n,visited)){
       
        solve(x,  y-1,  arr,  n, visited ,  ans,  path+'L');
       
    }

    //right
     if(isSafe(x,y+1,arr,n,visited)){
       
        solve(x,  y+1,  arr,  n, visited ,  ans,  path+'R');
        
    }

    //up
     if(isSafe(x-1,y,arr,n,visited)){
       
        solve(x-1,  y,  arr,  n, visited ,  ans,  path+'U');
       
    }
     visited[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector < string > ans;
    string path="";
    vector<vector< bool> >visited (n, vector<bool> (n,0));
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,visited,ans,path);
    return ans;
}
*/