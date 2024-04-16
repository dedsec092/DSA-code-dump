/*
TOP DOWN APPROACH:-

int solve(vector<int> &houses, int n,vector<int> &dp){
	if(n==0){// SAY THERE IS ONLY ONE HOUSE THEN BETTER TO ROB IT 
		return houses[0];
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int include=solve(houses,  n-2, dp)+houses[n];
	int exclude=solve(houses, n-1, dp);

	dp[n]=max(include,exclude);
	return dp[n];
}

int maxMoneyLooted(vector<int> &houses, int n)
{
	vector<int>dp(n,-1);
	return solve(houses,n-1,dp);
}

************************************************
BOTTOM UP APPROACH WITH SPACE OPTIMIZATION
int solve(vector<int> &houses, int n){
	int prev1=houses[0];
	int prev2=0;

	for(int i=1;i<n;i++){
		int include=prev2+houses[i];
		int exclude=prev1;

		int curr=max(include,exclude);

		prev2=prev1;
		prev1=curr;
	}
	return prev1;
}
int maxMoneyLooted(vector<int> &houses, int n)
{
	return solve(houses,n);
}
*/