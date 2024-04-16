/*
QUESTION:Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence
 by deleting some or no elements without changing the order of the remaining elements.

TIME COMPLEXITY:O(N square)
SPACE COMPLEXITY:O(N square)
 TOP DOWN:

 // VERY SIMILAR TO THE QUESTION:  "LongestCommonSubsequence(string)"
// APPROACH: REVERSE THE GIVEN STRING AND FIND ITS LongestCommonSubsequence AND THAT WILL BE PALINDROMIC
    int solve(int i,int j,string &s,string &revStr,vector<vector<int>> &dp){
        if(i==s.length()){
            return 0;
        }
        if(j==revStr.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==revStr[j]){
            ans=1+solve(i+1,j+1,s,revStr,dp);
        }
        else{
            ans=max(solve(i+1,j,s,revStr,dp),solve(i,j+1,s,revStr,dp));
        }
    dp[i][j]=ans;
    return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length(),-1));
        return solve(0,0,s,revStr,dp);
    }
    **************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(string &s,string &revStr){
        int n=s.length();
         vector<vector<int>> dp(s.length()+1,vector<int>(s.length(),0));
         for(int i=n-1;i>=0;i--){
             for(int j=n-1;j>=0;j--){
                  int ans=0;
              if(s[i]==revStr[j]){
                ans=1+solve(i+1,j+1,s,revStr,dp);
            }
            else{
                ans=max(solve(i+1,j,s,revStr,dp),solve(i,j+1,s,revStr,dp));
            }
    dp[i][j]=ans;
             }
         }
         return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
       
        return solveTab(s,revStr);
    }
    ************************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY: O(N)
    int solveTab(string &s,string &revStr){
        int n=s.length();
        
         vector<int> curr(s.length()+1,0);
         vector<int> next(s.length()+1,0);
         for(int i=n-1;i>=0;i--){
             for(int j=n-1;j>=0;j--){
                  int ans=0;
              if(s[i]==revStr[j]){
                ans=1+next[j+1];
            }
            else{
                ans=max(next[j],curr[j+1]);
            }
    curr[j]=ans;
             }
             next=curr;
         }
         return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
       
        return solveTab(s,revStr);
    }
*/