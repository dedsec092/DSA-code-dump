/*
//QUESTION: A FROG NEEDS TO REACH AT END POSITION IN A THREE LANE ROAD WITH OBSTACLES
              //  FROG HAVE TO USE MINIMUM SIDEJUMPS AND REACH AT THE END
TIME COMPLEXITY:O(3*3*N)...O(N)
SPACE COMPLEXITY: O(4*N)...O(N)
TOP DOWN APPROACH:
    int solve(vector<int>& obstacles,int currlane,int currpos, vector<vector<int>> &dp){
        int n=obstacles.size()-1;// adjusted according to question

        //base case
        if(currpos==n){
            return 0;
        }
        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }

        //CONDITION FOR NO OBSTACLES
        if(obstacles[currpos+1]!=currlane){
            return solve(obstacles,currlane,currpos+1,dp);
        }
        else{
                //FOR SIDE JUMPS
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){ //THIS LOOP IS CONTROLLING THE SIDE JUMPS
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans,1+solve(obstacles,i,currpos,dp));
                }
            }
             dp[currlane][currpos]=ans;
        }
       
        return dp[currlane][currpos];
    }
    int minSideJumps(vector<int>& obstacles) {
        
       vector<vector<int>>dp(4,vector<int> (obstacles.size(),-1)) ; 
       return solve(obstacles,2,0,dp);
    }
    ******************************************************************************************
    BOTTOM UP APPROACH:

     int solveTab(vector<int>& obstacles){
       vector<vector<int>> dp(4,vector<int>(obstacles.size(),1e9));
       int n=obstacles.size()-1;
       dp[0][n]=0;
       dp[1][n]=0;
       dp[2][n]=0;
       dp[3][n]=0;

       for(int currpos=n-1;currpos>=0;currpos--){
           for (int currlane=1;currlane<=3;currlane++){
                    if(obstacles[currpos+1]!=currlane){
            dp[currlane][currpos]=dp[currlane][currpos+1];
        }
        else{
            int ans=1e9;
            for(int i=1;i<=3;i++){
                if(currlane!=i && obstacles[currpos]!=i){
                     ans=min(ans,1+dp[i][currpos+1/** (+1)necessary as everything heppans in reverse order]);
                }
               
            }
            dp[currlane][currpos]=ans;
        }
           }
       
       }
       return min(dp[2][0],min(dp[1][0]+1,dp[3][0]+1));
  }
    int minSideJumps(vector<int>& obstacles) {
       
        return solveTab(obstacles);
    }
    ******************************************************************************************************
    SPACE OPTIMIZATION: O(1)

    int solve(vector<int>& obstacles){
        int n=obstacles.size()-1;
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);

        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(obstacles[currpos+1]!=currlane){
                    curr[currlane]=next[currlane];
                }
                else{
                    int ans=1e9;
                    for(int i=1;i<=3;i++){
                        if(currlane!=i && obstacles[currpos]!=i){
                            ans=min(ans,1+next[i]);
                        }
                    }
                    curr[currlane]=ans;
                }
            }
            next=curr;
        }
        return min(next[2],min(next[1]+1,next[3]+1));// curr will go BOOM bcoz of iterations 
        //and next(vector) will have the ans
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);

    }

*/