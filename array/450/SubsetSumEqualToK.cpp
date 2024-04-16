/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a 
subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
********************************************************************************************
#include <bits/stdc++.h> 
bool solve(int n, int k, vector<int> &arr,  vector< vector<int>> dp,int index){
    if(k==0){
        return 1;
    }
    if(k<0){
        return 0;
    }
    if(index==arr.size()){
        return 0;
    }
    if(dp[index][k]!=-1){
        return dp[index][k];
    }
    bool include=solve( n,  k-arr[index],  arr,  dp,  index+1);
    bool exclude=solve(n,  k,  arr,  dp,  index+1);
    dp[index][k]=include || exclude;
    return dp[index][k];

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector< vector<int>> dp(n+1,vector<int>(k+1,-1));
    return solve( n,  k,  arr,  dp, 0);
}
*/