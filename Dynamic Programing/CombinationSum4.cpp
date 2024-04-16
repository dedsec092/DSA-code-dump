/*
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
***************************************************************
int solve(vector<int>& nums, int target,  vector<int> &dp,int n){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+solve(nums,target-nums[i],dp,n);
    }
    dp[target]=ans;
    return dp[target];
}
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp,n);
    }
*/