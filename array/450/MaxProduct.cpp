/*
int maxProduct(vector<int>& nums) {
        int prefix=1;  // FIRST HALF OF THE ARRAY
        int suffix=1; // SECOND HALF OF THE ARRAY
        int ans=INT_MIN;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++){
            if(prefix==0){
                prefix=1; // RESTARTING IF MULTIPLIED WITH 0 TO EXCLUDE 0
            }
            if(suffix==0){
                suffix=1;
            }
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1]; // TRAVERSING FROM LAST
            ans =max(ans,max(prefix,suffix));
        }
        return ans;
    }
*/