/*
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
****************************************************************
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,sum=0,mini=INT_MAX,n=nums.size();
        
        while(j<n){
            sum+=nums[j];

            while(sum>=target){// SLIDING i ...
                mini=min(mini,j-i+1);// POTENTIAL SOLUTION..(j-i+1..SLIDING WINDOW SIZE[ANS])
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(mini==INT_MAX){
            return 0;
        }
        else{
            return mini;
        }
*/