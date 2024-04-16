/*
QUESTION:You are given an array prices where prices[i] is the price of a given stock on the ith day,
 and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like,
 but you need to pay the transaction fee for each transaction.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY:O(N)

 TOP DOWN :
  int solve(int index,int buy,vector<int>& prices,int fee,vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            int buyIt=solve(index+1,0,prices,fee,dp)-prices[index];
            int skipBuy=solve(index+1,1,prices,fee,dp);
            profit=max(buyIt,skipBuy);
        }
        else{
            int sellIt=solve(index+1,1,prices,fee,dp)+prices[index]-fee;
            int skipSell=solve(index+1,0,prices,fee,dp);
            profit=max(sellIt,skipSell);
        }
        dp[index][buy]=profit;
        return dp[index][buy];

    }
    int maxProfit(vector<int>& prices, int fee) {
       vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
    ****************************************************************
    BOTTOM UP:
     int solveTab(vector<int>& prices, int fee){
        int n=prices.size();
          vector<vector<int>> dp(n+1,vector<int>(2,0));
          for(int index=n-1;index>=0;index--){
              for(int buy=0;buy<=1;buy++){
                  int profit=0;
                  if(buy){
                 int buyIt=dp[index+1][0]-prices[index];
                int skipBuy=dp[index+1][1];
                 profit=max(buyIt,skipBuy);
             }
                 else{
                    int sellIt=dp[index+1][1]+prices[index]-fee;
                    int skipSell=dp[index+1][0];
                     profit=max(sellIt,skipSell);
        }
                dp[index][buy]=profit;
              }
          }
          return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
     
        return solveTab(prices,fee);
    }
    *********************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY: O(1) AS PARAMETER(buy) HAS CONSTANT SPACE WHICH IS 2..
     int solveTab(vector<int>& prices, int fee){
        int n=prices.size();
          
          vector<int> curr(2,0);
          vector<int> next(2,0);
          for(int index=n-1;index>=0;index--){
              for(int buy=0;buy<=1;buy++){
                  int profit=0;
                  if(buy){
                 int buyIt=next[0]-prices[index];
                int skipBuy=next[1];
                 profit=max(buyIt,skipBuy);
             }
                 else{
                    int sellIt=next[1]+prices[index]-fee;
                    int skipSell=next[0];
                     profit=max(sellIt,skipSell);
        }
                curr[buy]=profit;
              }
              next=curr;
          }
          return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
     
        return solveTab(prices,fee);
    }


*/