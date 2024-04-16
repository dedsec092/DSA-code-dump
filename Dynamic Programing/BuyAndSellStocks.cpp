/*
QUESTION:You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
TOP DOWN APPROACH:
TIME COMPLEXITY:O(N)
SPACE COMPLEXITY: O(N)

int solve(int index,int buy,vector<int>& prices, vector<vector<int>> &dp){// buy is a boolian parameter to check allowence of buying
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        // CAN'T BUY TWICE OR SELL TWICE 

        if(buy){ // checking if buying is allowed..
            int buyIt= solve( index+1,0,prices,dp)-prices[index]; //substracting cause we have to pay to buy 
            int skipBuy=solve(index+1,1,prices,dp);
            profit=max(buyIt,skipBuy);// maximising profit
        }
        else{// if we can't buy that means we can sell..
            int sellIt=solve(index+1,1,prices,dp)+prices[index];//adding cause we will get money on selling 
            int skipSell=solve(index+1,0,prices,dp);
            profit=max(sellIt,skipSell);// maximising profit
        }
        dp[index][buy]= profit;
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
            return solve(0,1,prices,dp);
    }
    ***********************************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(vector<int>& prices){
         vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
            int n=prices.size();
         for(int index=n-1;index>=0;index--){
             for(int buy=0; buy<=1;buy++){
                  int profit=0;
        if(buy){
            int buyIt=dp[index+1][0]-prices[index]; 
            int skipBuy=dp[index+1][1];
            profit=max(buyIt,skipBuy);
        }
        else{
            int sellIt=dp[index+1][1]+prices[index];
            int skipSell=dp[index+1][0];
            profit=max(sellIt,skipSell);
        }
        dp[index][buy]=profit;
             }
         }
        return  dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
    
        return solveTab(prices);
    }
    ***********************************************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY: O(1).. BECAUSE CONSTANT SPACE USED
    int solveTab(vector<int>& prices){
         vector<int> curr(2,0);
         vector<int> next(2,0); 
            int n=prices.size();
         for(int index=n-1;index>=0;index--){
             for(int buy=0; buy<=1;buy++){
                  int profit=0;
                    if(buy){
                        int buyIt=next[0]-prices[index]; 
                        int skipBuy=next[1];
                        profit=max(buyIt,skipBuy);
                     }
                     else{
                    int sellIt=next[1]+prices[index];
                    int skipSell=next[0];
                    profit=max(sellIt,skipSell);
                 }
                 curr[buy]=profit;
             }
             next=curr;// next will store the ans and curr will go boom as index is moving from n-1 to 0..
         }
        return  next[1];
    }
    int maxProfit(vector<int>& prices) {
    
        return solveTab(prices);
    }

*/