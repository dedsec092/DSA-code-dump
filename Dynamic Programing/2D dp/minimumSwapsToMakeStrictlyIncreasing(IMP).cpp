/*
QUESTION: You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. 

TIME COMPLEXITY : O(N) (LOOK AT SOLVETAB FOR DETAIL)
SPACE COMPLEXITY:O(N)

TOP DOWN APPROACH:
int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swaped, vector<vector<int> > &dp){
    //base case
    if(index==nums1.size()){
        return 0;
    }
    //tracking prevs 
    int prev1=nums1[index-1];
    int prev2=nums2[index-1];

    if(swaped){// swapping will be done here in swap recursion call
        swap(prev1,prev2);
    }

    if(dp[index][swaped]!=-1){
        return dp[index][swaped];
    }

    int ans=INT_MAX;// will take minimum ans
    // no swapping
    if(prev1<nums1[index] && prev2<nums2[index]){// stricty increasing condition
        ans=solve(nums1,nums2,index+1,0,dp);
    }
    
    //swapping.. if no swapping condition(above condition) got skipped then swapping will occur
    if(prev1<nums2[index] && prev2<nums1[index]){
        ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));
    }
    dp[index][swaped]=ans;
    return dp[index][swaped];

}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);// gotta make sure that the first element is smaller then every other elements  
        nums2.insert(nums2.begin(),-1);// so that comparision can be done ...
        vector<vector<int> > dp(nums1.size(),vector<int>(2,-1));// swapped is a bool so it will take only space of 2(T or F)
        bool swaped=0;
        return solve(nums1,nums2,1,swaped,dp);
    }
    *********************************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
     vector<vector<int>> dp(n+1,vector<int> (2,0));
     for(int index=n-1;index>=1;index--){
         for (int swaped=1;swaped>=0;swaped--){
             int prev1=nums1[index-1];
            int prev2=nums2[index-1];

            if(swaped){
                swap(prev1,prev2);
            }
               int ans=INT_MAX;
            if(prev1<nums1[index]&&prev2<nums2[index]){
                 ans=dp[index+1][0];
                 }
            if(prev2<nums1[index]&&prev1<nums2[index]){
                ans=min(ans,1+dp[index+1][1]);
                 }
                dp[index][swaped]=ans;
         }
     }
     return dp[1][0];
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        return solveTab(nums1,nums2);
    }
    ***************************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY :O(1) CONSTANT SPACE

    int solveTab(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
     
     vector<int> curr(2,0);
     vector<int> next(2,0);
     for(int index=n-1;index>=1;index--){
         for (int swaped=1;swaped>=0;swaped--){
             int prev1=nums1[index-1];
            int prev2=nums2[index-1];

            if(swaped){
                swap(prev1,prev2);
            }
               int ans=INT_MAX;
            if(prev1<nums1[index]&&prev2<nums2[index]){
                 ans=next[0];
                 }
            if(prev2<nums1[index]&&prev1<nums2[index]){
                ans=min(ans,1+next[1]);
                 }
                curr[swaped]=ans;
         }
         next=curr;
     }
     return next[0];
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        return solveTab(nums1,nums2);
    }
*/