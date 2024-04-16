/*


#include <bits/stdc++.h> 
#define MOD 1000000007

//MOD UTILS
int add(int a,int b){
    return (a%MOD+b%MOD)%MOD;
}

int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;//.. range issue solved
}
**********************************************************
TOP DOWN APPROACH:
int solve(int n,int k, vector<int> &dp){
    if(n==1){
        return k;// one fence can be coloured in k ways
    }
    if(n==2){
        return add(k,mul(k,k-1));// [both fence one colour(k)+[one with let red (k) *another with blue(k-1)]]
    }
    if(dp[n]!=-1){
        return dp[n];
    }
                //same colour at end       //diff colour at end
    dp[n]=add(mul(solve(n-2,  k, dp),k-1),mul(solve(n-1,  k, dp),k-1));
    return dp[n];
    

}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

******************************************************************************************************************************
BOTTOM UP APPROACH:

int solveTab(int n,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
   return solveTab( n,  k);
}
********************************************************************************************************************************
SPACE OPTIMIZATION :
USING ONLY VARIABLE
SPACE COMPLEXITY:O(1)

int solveTab(int n,int k){
    
   int prev2=k;
    int prev1=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        int curr=add(mul(prev2,k-1),mul(prev1,k-1));

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
   return solveTab( n,  k);
}
*/