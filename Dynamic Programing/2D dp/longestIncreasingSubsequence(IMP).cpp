/*
QUESTION:Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
Input:
N = 16
A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 
6
Explanation:
There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.

TIME COMPLEXITY :O(N square)
SPACE COMPLEXITY: O(N square)
TOP DOWN APPROACH:
 int solve(int n, int a[],int curr,int prev,vector<vector<int>> &dp){
        //base case
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){ //we did +1 in prev as we pased -1 as initial parameter and -1 is a invalid index
            return dp[curr][prev+1];
        }
        
        
        int include=0;
        if(prev==-1||a[prev]<a[curr]){
            include=1+solve(n,a,curr+1,curr,dp);
        }
        
        int exclude=solve(n,a,curr+1,prev,dp);
        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    int longestSubsequence(int n, int a[])
    {
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return solve(n,a,0,-1,dp);
    }
    *********************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(int n, int a[]){
         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
         
         for(int curr=n-1;curr>=0;curr--){
             for(int prev=curr-1;prev>=-1;prev--){
                 int include=0;
                if(prev==-1 || a[prev]<a[curr]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
             }
         }
         
         return dp[0][0];
    }
    int longestSubsequence(int n, int a[])
    {
        return solveTab(n,a);
        
    }
    ***************************************************************************
    SPACE OPTIMIZATION: O(N)
    int solveTab(int n, int a[]){
        
         vector<int> currRow(n+1,0);
         vector<int> nextRow(n+1,0);
         
         for(int curr=n-1;curr>=0;curr--){
             for(int prev=curr-1;prev>=-1;prev--){
                 int include=0;
                if(prev==-1 || a[prev]<a[curr]){
                    include=1+nextRow[curr+1];
                }
                int exclude=nextRow[prev+1];
                currRow[prev+1]=max(include,exclude);
             }
             nextRow=currRow; //curr will go boom and next will have ans
         }
         
         return nextRow[0];
    }
    int longestSubsequence(int n, int a[])
    {
        return solveTab(n,a);
        
    }
    **************************************************************************
    TIME OPTIMIZATION :O(NlogN)
    SPACE OPTIMIZATION: O(N)

    USING BINARY SEARCH IN DP
        int solveOptimal(int n, int a[]){
            //base case
        if(n==0){
            return 0;
        }
        vector<int> ans;// size of this array will be the ans
        ans.push_back(a[0]);// first element will definitly be pushed as there is nothing to compare
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){..// increasing will be pushed
                ans.push_back(a[i]);
            }
            else{
                APPLYING BINARY SEARCH IN DP
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i]; REPLACING ELEMENT TO SAVE SPACE
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
        return solveOptimal(n,a);
        
    }
*/