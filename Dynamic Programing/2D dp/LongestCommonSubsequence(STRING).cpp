/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

TIME COMPLEXITY:O(N*M) WHERE N IS LENGTH OF STRING1 AND M IS LENGTH OF STRING2
SPACE COMPLEXITY: O(N*M)..

TOP DOWN APPROACH:
 int solve(string& text1, string& text2,int i,int j, vector<vector<int>> &dp){
        if(i==text1.length()){
            return 0;
        }
        if(j==text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+solve(text1,text2,i+1,j+1,dp);// we got a match so ans will increase by 1 here
        }
        else{
            // maximising the ans by taking max of this recursion calls..
            ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp)); 
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.length()+1,vector<int>(text2.length()+1,-1));
        return solve(text1,text2,0,0,dp);
    }
    *****************************************************************************
    BOTTOM UP:
     int solveTab(string &text1, string &text2){
         vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
         for(int i=text1.length()-1;i>=0;i--){
             for(int j=text2.length()-1;j>=0;j--){
                  int ans=0;
                 if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                 }
                 else{
                     ans=max(dp[i+1][j],dp[i][j+1]);
                 }
             dp[i][j]=ans;
             }
         }
         return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
       
        return solveTab(text1,text2);

    }
    ****************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY: O(M)
    int solveTab(string &text1, string &text2){

         vector<int> next(text2.length()+1,0);
         vector<int> curr(text2.length()+1,0);
         for(int i=text1.length()-1;i>=0;i--){
             for(int j=text2.length()-1;j>=0;j--){
                  int ans=0;
                 if(text1[i]==text2[j]){
                    ans=1+next[j+1];
                 }
                 else{
                     ans=max(next[j],curr[j+1]);
                 }
            curr[j]=ans;
             }
             next=curr;// next will save the ans and curr will go boom ,according to rhe flow of loop  
         }
         return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
       
        return solveTab(text1,text2);

    }
*/