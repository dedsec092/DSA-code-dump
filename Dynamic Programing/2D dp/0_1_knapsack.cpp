/*
TOP DOWN APPROACH(HONORED ONE):

TIME COMPLEXITY:O(N*Capacity)
 int solve(int index,int W, int wt[], int val[], int n, vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][W]!=-1){
            return dp[index][W];
        }

        int ans=0;
        int include=0;
        if(wt[index]<=W){
             include=solve(index+1,W-wt[index],wt,val,n,dp)+val[index];
        }
        int exclude=solve(index+1,W,wt,val,n,dp);
        ans=max(include,exclude);
        dp[index][W]=ans;
        return dp[index][W];
    }
	
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return solve(0,W,wt,val,n,dp);
    }
*************************************************************************************************************
BOTTOM UP APPROACH:
REPLICATING THE STEPS FROM TOP DOWN APPROACH:


int solveTab(vector<int> &values, vector<int> &weights, int n, int capacity){
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));

	for(int w=weights[0];w<=capacity;w++){
		if(weights[0]<=capacity){
			dp[0][w]=values[0];
		}
		else{
			dp[0][w]=0;
		}
	}
	for(int i=1;i<n;i++){
		for(int w=0;w<=capacity;w++){

			int include=0;

			if(weights[i]<=w){
				include=values[i]+dp[i-1][w-weights[i]];
			}
			int exclude=dp[i-1][w];

			dp[i][w]=max(include,exclude);
		}
	}
	return dp[n-1][capacity];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	
	return solveTab(values,weights,n-1,w);
}
****************************************************************************************************************
*/