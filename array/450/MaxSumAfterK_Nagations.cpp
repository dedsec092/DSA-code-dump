/*
Example 1:

Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
******************************************************************************************
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mini;
        for(int i=0;i<nums.size();i++){
            mini.push(nums[i]);
        }
        for(int i=k;i>0;i--){
            int top=mini.top();
            mini.pop();
            top=top * -1;
            mini.push(top);
        }
        int ans=0;
        while(!mini.empty()){
            int top=mini.top();
            mini.pop();
            ans+=top;
        }
        return ans;
    }
*/