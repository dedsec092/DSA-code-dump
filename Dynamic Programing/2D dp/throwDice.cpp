/*
Given N dice each with M faces,
 numbered from 1 to M, find the number of ways to get sum X.
  X is the summation of values on each face when all the dice are thrown.

  TOP DOWN APPROACH:
  long long solve(int faces,int dice,int target, vector<vector<int>> &dp){
      //base cases
      // ONLY WHEN DICE AND TARGET BECOMES 0 WE WILL GET AN OUTPUT
      if(dice==0&&target==0){
          return 1;
      }
       if(dice!=0&&target==0){
          return 0;
      }
       if(dice==0&&target!=0){
          return 0;
      }
      if(target<0){// TARGET BECOMES NEGETIVE
          return 0;
      }
      if(dp[dice][target]!=-1){
          return dp[dice][target];
      }
      long long ans=0;
      
      for(int i=1;i<=faces;i++){
          ans=ans+solve(faces,dice-1,target-i,dp);
      }
      dp[dice][target]=ans;
      return dp[dice][target];
  }
    long long noOfWays(int M , int N , int X) {
        vector<vector<int>> dp(N+1,vector<int>(X+1,-1)); // "+1 "  because of accessing 0 as well
        return solve(M,N,X,dp);
    }
    ************************************************************************************
    BOTTOM UP APPROACH:

    long long solveTab(int faces,int d,int t){
       vector<vector<long long>> dp(d+1,vector<long long>(t+1,0));
       dp[0][0]=1; BY ANALISING BASE CASE 
       
       for(int dice=1;dice<=d;dice++){ BOTTOM UP ITERATIONS...
           for(int target=1;target<=t;target++){
               long long ans=0;
      
                 for(int i=1;i<=faces;i++){
                     if(target-i>=0){
                         ans=ans+dp[dice-1][target-i];
                     }
                     
                    }
                     dp[dice][target]=ans;
           }
       }
       return dp[d][t];
  }
    long long noOfWays(int M , int N , int X) {
      
        return solveTab(M,N,X);
    }
    ********************************************************************************************
    SPACE OPTIMIZATION:
    long long solveTab(int faces,int d,int t){
     
       vector<long long > curr(t+1,0);
       vector<long long > prev(t+1,0);
       
       prev[0]=1; // ofcoarse prev would be assigned first..
       
       for(int dice=1;dice<=d;dice++){
           for(int target=1;target<=t;target++){
               long long ans=0;
      
                 for(int i=1;i<=faces;i++){
                     if(target-i>=0){
                         ans=ans+prev[target-i];
                     }
                     
                    }
                     curr[target]=ans;
           }
           prev=curr;
       }
       return prev[t];
  }
    long long noOfWays(int M , int N , int X) {
        // "+1 "  because of accessing 0 as well
        return solveTab(M,N,X);
    }
*/