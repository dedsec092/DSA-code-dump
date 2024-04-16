/*
TOP DOWN APPROACH:-
TIME COMPLEXITY :-O(x*n)..
SPACE COMPLEXITY :- O(x)


#include <bits/stdc++.h> 
int solve(vector<int> &num, vector<int> &dp,int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini=INT_MAX;
    //traversing coin values
    for(int i=0;i<num.size();i++){
        int ans=solve(num,  dp,  x-num[i]);
        if(ans!=INT_MAX){//if ans is valid
            mini=min(mini,ans);
        }
    }
    dp[x]=mini;

    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans=solve(num,dp,x);

    if(ans==INT_MAX){
        return -1;
    }
    else{
         return ans;
    }
   
}
*************************************************************************************

BOTTOM UP APPROACH:-

int solve(vector<int> &num, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;//when x=0 then ans=0 (base case)

    //going to update values of dp array
    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
         if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
            dp[i] = min(dp[i],1+ dp[i - num[j]]);// here "1+" is to count number of coins
    }
     }
    }
    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    int ans=solve(num,  x);
    return ans;
}
*/