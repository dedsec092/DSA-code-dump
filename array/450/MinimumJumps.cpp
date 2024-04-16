/*
QUESTION:Given an array of N integers arr[] where each element represents the maximum length of the jump 
that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, 
then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.
************************************************************************************
int solve(int index,vector<int> &arr, int n,vector<int> &dp){
    if(index==n-1){
        return 0;
    }
    if(index>n){
        return 1e9;// USING 1e9 AS -1 IS ALREADY ON USE (DP)
    }
    if(arr[index]==0){
        return 1e9;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int ans=1e9;
    int val=arr[index];
    for(int i=index;i<=(index+val)&& i<n;i++){
        if(i!=index){// WHEN val =0 (i==index WILL RESULT RUN TIME ERROR)
            ans=min(ans,solve(i, arr,n,dp)+1);
        }
         
    }
    dp[index]=ans;
    return dp[index];
}
int minimumJumps(vector<int> &arr, int n)
{
    vector<int> dp(n+1,-1);
    int ans=solve(0, arr, n,  dp);
    if(ans==1e9){
        return -1;
    }
    return ans;
}
*/