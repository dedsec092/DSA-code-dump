/*
QUESTION:A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

TIME COMPLEXITY:O(N square)
SPACE COMPLEXITY:O(N square)
TOP DOWN APPROACH:
    int solve(vector<int>& satisfaction,int index,int time, vector<vector<int>> &dp){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }

        int include= satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1,dp);
        int exclude=solve(satisfaction,index+1,time,dp);

        dp[index][time]=max(include,exclude);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());//here sorting is necessary
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

        return solve(satisfaction,0,0,dp);
    }
    ************************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0) );// base case handled as we initialised with 0
        //in top down the flow of index and time was from 0 to n that means in bottom up flow will be from n to 0..
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+dp[index+1][time+1];
                int exclude=dp[index+1][time];

                dp[index][time]=max(include,exclude);                
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        return solveTab(satisfaction);
    }
    ********************************************************************************************
    SPACE OPTIMIZATION: O(N)
     int solveTab(vector<int>& satisfaction){
        int n=satisfaction.size();

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+next[time+1];
                int exclude=next[time];

                curr[time]=max(include,exclude);                
            }
            next=curr; //curr will go boom next will store the ans at the end
        }
        return next[0];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        return solveTab(satisfaction);
    }
*/