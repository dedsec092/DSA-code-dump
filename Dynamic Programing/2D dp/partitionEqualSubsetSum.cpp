/*
QUASTION:Given an array arr[] of size N,
 check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

 TOP DOWN APPROACH:
  bool solve(int index,int N, int arr[],int target, vector<vector<int>> &dp){
        //base cases
        if(index>=N){
            return 0;
        }
        if(target==0){// ans case
            return 1;
        }
        if(target<0){// when target becomes negative
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include=solve(index+1,N,arr,target-arr[index],dp);
        bool exclude=solve(index+1,N,arr,target,dp);
        
        dp[index][target]=include or exclude;// applying or to find ans
        return dp[index][target];
    }
    int equalPartition(int N, int arr[])
    {
        int total=0;// calculating total sum of array
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total%2!=0){// if toatal is odd then equal partitioning is impossible so ans is NO
            return 0;
        }
        int target =total/2;// because first half array elements sum upto the target then other half array 
                                //will add upto target as well because total is even in this case( odd case handled) 
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solve(0,N,arr,target,dp);
    }
    ********************************************************************************************
    BOTTOM UP APPROACH:
     bool solveTab(int N, int arr[],int target){
         vector<vector<int>> dp(N+1,vector<int>(target+1,0));// N+1 done to handle indexing in loops 
         for(int i=0;i<=N;i++ ){
             dp[i][0]=1;
         }
         
         for(int index=N-1;index>=0;index--){
             for(int tar =1;tar<=target;tar++){
                  bool include=0;
                 if(tar-arr[index]>=0){
                       include=dp[index+1][tar-arr[index]];
                 }
                
                 bool exclude=dp[index+1][tar];
        
                dp[index][tar]=include or exclude;
             }
         }
         return dp[0][target];
    }
    int equalPartition(int N, int arr[])
    {
        int total=0;// calculating total sum of array
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total%2!=0){// if toatal is odd then equal partitioning is impossible so ans is NO
            return 0;
        }
        int target =total/2;
        return solveTab(N,arr,target);
    }
    *******************************************************************************************
    SPACE OPTIMIZATION :
     bool solveTab(int N, int arr[],int target){
        
         vector<int> curr(target+1,0);
         vector<int> next(target+1,0);
         curr[0]=1;
         next[0]=1;
        
         for(int index=N-1;index>=0;index--){
             for(int tar =1;tar<=target;tar++){
                  bool include=0;
                 if(tar-arr[index]>=0){
                       include=next[tar-arr[index]];
                 }
                
                 bool exclude=next[tar];
        
                curr[tar]=include or exclude;
             }
             next=curr;// going up in loop and curr will go boom next will have the ans
         }
         return next[target];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total=0;// calculating total sum of array
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total%2!=0){// if toatal is odd then equal partitioning is impossible so ans is NO
            return 0;
        }
        int target =total/2;
        return solveTab(N,arr,target);
    }
*/