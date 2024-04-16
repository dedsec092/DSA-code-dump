/*
TOP DOWN APPROACH:
TIME COMPLEXITY WITHOUT DP: EXPONENTIAL..

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY : O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007
long long int solve(int n,vector< long long int>& dp){
  if(n==1){
    return 0;
  }
  if(n==2){
    return 1;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
// recursion relation explanation:
//..when we pick an element for derangement we will have n-1 positions to place it
// case1: if we *swapped* an element to an i element that means two element deranged at the same time..(n-2)
// case 2: if element placed in a random position to get deranged ...(n-1)
// combining both cases: n-1*(f(n-2)+f(n-1))   
  dp[n]=((n-1)%MOD)*(((solve(n-1, dp)%MOD)+(solve(n-2,  dp))%MOD)%MOD);

  return dp[n];
}
long long int countDerangement(int n) {
  vector< long long int > dp(n+1,-1);
    long long int ans=solve(n,dp);
    return ans;
}
***********************************************************************************
BOTTOM UP OR TABULATION METHOD:
#include <bits/stdc++.h> 
#define MOD 1000000007
long long int solveTab(int n){
  vector<int> dp(n+1,0);
  dp[1]=0;
  dp[2]=1;

  for(int i=3;i<=n;i++){
    long long int first=dp[i-1]%MOD;
    long long int second=dp[i-2]% MOD;
    long long int sum=(first+second) %MOD;

    long long int ans= ((i-1)*sum)%MOD;

    dp[i]=ans;
  }
  return dp[n];
}
long long int countDerangement(int n) {
  return solveTab( n);
} 
***********************************************************************************
SPACE OPTIMIZATION (USING ONLY VARIABLES):
SPACE COMPLEXITY :O(1)..

#include <bits/stdc++.h> 
#define MOD 1000000007
long long int solveTab(int n){
    int prev2=0;
  int prev1=1;

  for(int i=3;i<=n;i++){
    long long int first=prev1%MOD;
    long long int second=prev2% MOD;

    long long int sum=(first+second)%MOD;
    long long int ans=((i-1)*sum)%MOD;

    prev2=prev1;
    prev1=ans;
  }
  return prev1;
}
long long int countDerangement(int n) {
  return solveTab( n);
}
*/