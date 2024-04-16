/*
QUESTION:Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n

TOP DOWN APPROACH:
TIME COMPLEXITY: O(N square)
SPACE COMPLEXITY: O(N )
int solve(int n,vector<int> &dp ){
    if(n<=1){// if there is 1 or less nodes then only one tree or null can be formed
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){// assuming every i as root node 
         ans += solve(i-1,dp)*solve(n-i,dp);// (left subtree)*(right subtree) /// CATALAN NUMBERS LOGIC
    }
   
    dp[n]=ans;
    return dp[n];

}
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    ***********************************************************************************
BOTTOM UP APPROACH:
int solveTab(int n){
     vector<int> dp(n+1,0);
     dp[0]=1;// by analysing base case in top down
     dp[1]=1;

    // i-> number of nodes
     for(int i=2;i<=n;i++){
         //j -> root node
         for(int j=1;j<=i;j++){
             dp[i]+=dp[j-1]*dp[i-j];
         }
     }
     return dp[n];

}
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveTab(n);
    }
    ****************************************************************************
    FOR MORE OPTIMIZATION JUST PRINT "CATALAN NUMBER" 

       int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=numTrees(i)*numTrees(n-1-i); CATALAN NUMBERS
        }
        return ans;
    }

*/