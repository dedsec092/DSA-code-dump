/*
QUESTION:You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

TIME COMLEXITY:O(N*K)
SPACE COMPLEXITY:O(N*K)


TOP DOWN APPROACH:
int solve(int index,int buy,int limit,vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit=0;
        if(buy){
            int buyIt=solve(index+1,0,limit,prices,dp)-prices[index];
            int skipBuy=solve(index+1,1,limit,prices,dp);
            profit=max(buyIt,skipBuy);
        }
        else{
            int sellIt=solve(index+1,1,limit-1,prices,dp)+prices[index];
            int skipSell=solve(index+1,0,limit,prices,dp);
            profit=max(sellIt,skipSell);
        }
        dp[index][buy][limit]=profit;
        return dp[index][buy][limit];

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
    ****************************************************************************************
    BOTTOM UP APPRACH:
    int solveTab(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;
                      if(buy){
                         int buyIt=dp[index+1][0][limit]-prices[index];
                        int skipBuy=dp[index+1][1][limit];
                         profit=max(buyIt,skipBuy);
        }
        else{
                        int sellIt=dp[index+1][1][limit-1]+prices[index];
                        int skipSell=dp[index+1][0][limit];
                        profit=max(sellIt,skipSell);
             }
             dp[index][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        return solveTab(k,prices);
    }
    ******************************************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY: O(K)
    
     int solveTab(int k, vector<int>& prices){
        int n=prices.size();
       
        vector<vector<int>> curr(2,vector<int>(k+1,0));
         vector<vector<int>> next(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;
                      if(buy){
                         int buyIt=next[0][limit]-prices[index];
                        int skipBuy=next[1][limit];
                         profit=max(buyIt,skipBuy);
        }
        else{
                        int sellIt=next[1][limit-1]+prices[index];
                        int skipSell=next[0][limit];
                        profit=max(sellIt,skipSell);
             }
             curr[buy][limit]=profit;
                }
            }
            next=curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        return solveTab(k,prices);
    }
*/