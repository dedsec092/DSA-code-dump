/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int maxProfit(vector<int>& prices) {
        int buy=prices[0];// assigning in day one initially
        int profit=0; 

        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-buy; // sell-buy
            
            // loss is avoided as profit is assigned with 0 initially
            profit=max(profit,diff); 
            buy=min(buy,prices[i]); // minimising buying price
        }
        return profit;
    }
*/