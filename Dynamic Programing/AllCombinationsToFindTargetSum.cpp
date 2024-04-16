/*
TOP DOWN APPROACH:

TIME COMPLEXITY :O(N*tar)..
SPACE COMPLEXITY: O(N)

int solve(vector<int> &num, int tar, vector<int> &dp){
    //base case
    if(tar==0){
        return 1;// 1 will be returned when target becomes 0
    }
    if(tar<0){
        return 0;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }

    int ans=0;
    TRAVERSING THROUGH num ARRAY TO FIND ALL COMBINATIONS
    //DUE TO RECURSION THIS LOOP WILL RUN MANY TIMES FROM 0 BUT DP WILL REDUCE THE TIME COMPLEXITY...
    for(int i=0;i<num.size();i++){
        ans+=solve(num,  tar-num[i],  dp);// adding up all the 1s from base case
                                            // and adding it and storing it in "ans"
    }
    dp[tar]=ans;
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar+1,-1);
    return solve(num,tar,dp);
}
**************************************************************************************************
BOTTOM UP APPROACH:

int solveTab(vector<int> &num, int tar){
     vector<int> dp(tar+1,0);
     dp[0]=1;
    
     //traversing 1 to tar
     for(int i=1;i<=tar;i++){
         //traversing num
         for(int j=0;j<num.size();j++){
             if(i-num[j]>=0){
                 dp[i]+=dp[i-num[j]];
             }
             
         }
     }
     return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
   
    return solveTab(num,tar);
}
*/