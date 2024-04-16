/*
QUESTION:We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

MAIN PART:Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
NOTE: HAVE TO GUERENTEE A WIN REGARDLESS OF NUMBER WITH MINIMUM MONEY SPEND.

TOP DOWN APPROACH:
int solve(int start,int end, vector<vector<int>> &dp){
    //base case
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }

    int ans=INT_MAX;
    for(int i=start;i<=end;i++){// for every number
    // max(solve(),solve()) IS TO TEST EVREY NUMBER
    
        ans=min(ans, i + max(solve(start,i-1,dp),solve(i+1,end,dp))); // FINDING MINIMUM ANS
         // GOING FOR WORST CASE FOR GUERENTEED WIN: MAX 
    // OVERALL ANS :MIN..
    }
    dp[start][end]=ans;
    return dp[start][end];

}
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp); 
    }
    **************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(int n){
      vector<vector<int>> dp(n+2,vector<int>(n+2,0)); // in loops we used i+1 ,thats why n+2(size) to avoid runtime error

      // by analysing flow of recursion
      for(int start =n;start>=1;start--){
          for(int end=start;end<=n;end++){
              if(start==end){
                  continue;
              }
              else{
                      int ans=INT_MAX;
                for(int i=start;i<=end;i++){
                     ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
              }
              dp[start][end]=ans;
              }
          
          }
      }
      return dp[1][n];
}
    int getMoneyAmount(int n) {
        return solveTab(n);
    }
    ********************************************
    NO FURTHER OPTIMIZATION
*/