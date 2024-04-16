/*
QUESTION:You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

TOP DOWN:
TIME COMPLEXITY: O(N)...BUY AND LIMIT ARE CONSTANT PARAMETERS
SPACE COMPLEXITY: O(N)..BUY AND LIMIT ARE CONSTANT PARAMETERS

//  HERE INLY EXTRA CONDITION ADDED IS THAT ONLY TWO TRANSACTIONS ARE ALWOED
// ONE TRANSACTION COMPLETES ON SELLING..
    int solve(int index,int buy,int limit,vector<int>& prices,vector<vector<vector<int>>> &dp){
        //BASE CASE
        if(index==prices.size()){
            return 0;
        }
        if(limit==0){// TRANSACTION LIMIT 
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit=0;
        if(buy){// IF BUYING IS ALLOWED
            int buyIt=solve(index+1,0,limit,prices,dp)-prices[index];// SUBSTRACTING AS WE HAVE TO PAY IN CASE OF BUYING
            int skipBuy=solve(index+1,1,limit,prices,dp);
            profit=max(buyIt,skipBuy);// MAXIMISING PROFIT
        }
        else{
            int sellIt=solve(index+1,1,limit-1,prices,dp)+prices[index];// LIMIT -1 ON SELLING
            int skipSell=solve(index+1,0,limit,prices,dp);
            profit=max(sellIt,skipSell);// MAXIMISING PROFIT
        }
        dp[index][buy][limit]=profit;
        return dp[index][buy][limit];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
    ***********************************************************************************************************
    BOTTOM UP:
 int solveTab(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(2,vector<int>(3,0)));
    
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
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
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveTab(prices);
    }

    *******************************************************************************************************
    SPACE OPTIMIZATION: 
    SPACE COMPLEXITY: O(1)..
    
    int solveTab(vector<int>& prices){
        int n=prices.size();
     
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
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
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveTab(prices);
    }
*/