/*
QUASYION :
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.

//SIMILAR TO HOUSE ROBBERY PROBLEM
TIME COMPLEXITY :O(N square)
SPACE COMPLEXITY: O(N square)
TOP DOWN APPROACH:
int solve(int index,int endIndex,vector<int>& slices,int n, vector<vector<int>> &dp){
    //base case
    if(index>endIndex ||n==0 ){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }

    int take=slices[index]+solve(index+2,endIndex,slices,n-1,dp);//"index+2" because bob and alice are taking slices too
    int notTake=solve(index+1,endIndex,slices,n,dp);

    dp[index][n]=max(take,notTake);
    return dp[index][n];
}
    int maxSizeSlices(vector<int>& slices) {
       
        int k=slices.size();
        // if including 1st element then gonna exclude last 
         vector<vector<int>> dp1(k,vector<int>(k,-1));
          vector<vector<int>> dp2(k,vector<int>(k,-1));
        int case1=solve(0,k-2,slices,k/3,dp1);// including 1st element and excluding last one
        int case2=solve(1,k-1,slices,k/3,dp2);// including last element and excluding 1st one
        return max(case1,case2);
    }
    *******************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(vector<int>& slices){
    int k=slices.size();
    vector<vector<int>> dp1(k+2,vector<int>(k+2,0));//did k+2 because index is going out of bound in loops
     vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

     for(int index=k-2;index>=0;index--){
         for(int n=1;n<=k/3;n++){
             int take=slices[index]+dp1[index+2][n-1];
             int notTake=dp1[index+1][n];

            dp1[index][n]=max(take,notTake);
         }

     }
     int case1=dp1[0][k/3];

     for(int index=k-1;index>=1;index--){
         for(int n=1;n<=k/3;n++){
            int take=slices[index]+dp2[index+2][n-1];
            int notTake=dp2[index+1][n];

            dp2[index][n]=max(take,notTake);
         }
     }
     int case2=dp2[1][k/3];
     return max(case1,case2);
}
    int maxSizeSlices(vector<int>& slices) {
        return solveTab(slices);
    }
    ***********************************************************************************************
    SPACE OPTIMIZATION: 
    SPACE COMPLEXITY :O(N)
    int solveTab(vector<int>& slices){
    int k=slices.size();
    
     vector<int> curr1(k+2,0);
      vector<int> prev1(k+2,0);
       vector<int> next1(k+2,0);
        vector<int> curr2(k+2,0);
         vector<int> prev2(k+2,0);
          vector<int> next2(k+2,0);
     

     for(int index=k-2;index>=0;index--){
         for(int n=1;n<=k/3;n++){
             int take=slices[index]+next1[n-1];
             int notTake=curr1[n];

            prev1[n]=max(take,notTake);
         }
         next1=curr1;
         curr1=prev1;// prev will go boom as iteration is inversed(--)

     }
     int case1=curr1[k/3];

     for(int index=k-1;index>=1;index--){
         for(int n=1;n<=k/3;n++){
            int take=slices[index]+next2[n-1];
            int notTake=curr2[n];

            prev2[n]=max(take,notTake);
         }
          next2=curr2;
         curr2=prev2;
     }
     int case2=curr2[k/3];
     return max(case1,case2);
}
    int maxSizeSlices(vector<int>& slices) {
        return solveTab(slices);
    }
*/