/*
TOP DOWN APPROACH:-
TIME COMPLEXITY:-O(N)
SPACE COMPLEXITY:- O(N)[can be optimized ....]
int solve(vector<int> &nums,vector<int> &dp,int n){
    //base cases
    if(n==0){
        return nums[0];
    }
    if(n<0){
        return 0;
    }
    //dp
    if(dp[n]!=-1){
        return dp[n];
    }


    int include=solve(nums,dp,n-2)+nums[n];
    int exclude=solve(nums,dp,n-1);

    dp[n]=max(include,exclude);

    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    int ans=solve(nums,dp,n-1);
    return ans;
}

****************************************************************************

BOTTOM UP APPROACH:-
int solveTab(vector<int> &nums,int n){
    vector<int> dp(n,0);
    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int include=dp[i-2]+nums[i];
        int exclude=dp[i-1];

        dp[i]=max(include,exclude);
    }
     return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return solveTab(nums,  n);
}
*************************************************************************

SPACE OPTIMIZATION :-O(1)......(ONLY VARIABLES ARE USED)

    int solveOpt(vector<int> &nums,int n){
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n;i++){
        int include=prev2+nums[i];
        int exclude=prev1;

        int curr=max(include,exclude);
        prev2=prev1;
        prev1=curr;
    }
     return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return solveOpt(nums,  n);
}
*/