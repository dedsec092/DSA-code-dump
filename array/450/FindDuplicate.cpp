/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.
***********************************************************************
    int findDuplicate(vector<int>& nums) {
         unordered_map<int,int> mapping;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
        mapping[nums[i]]++;
        }
        for(auto i: mapping){
        if(i.second>1){
           ans=i.first;
            }
        }
    return ans;
    }
*/