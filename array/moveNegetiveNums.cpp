/*
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int temp=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            swap(nums[temp],nums[i]);
            temp++;
        }
    }
    return nums;
}
*/