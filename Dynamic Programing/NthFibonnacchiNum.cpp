/*
TOP DOWN APPROACH:-
TIME COMPLEXITY:-O(N)
SPACE COMPLEXITY:-O(N)

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int fib(int n,vector<int> &dp){
        //base case
        if(n<=1){
                return n;
        }
        //retriving already solved values
        if (dp[n]!=-1){
                return dp[n];
        }
        //storing answers in dp array
        dp[n]= fib(n-1,dp)+fib(n-2,dp);
        
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int> dp(n+1);// will store subproblem values to save time
        for(int i=0 ;i<=n;i++){
                dp[i]=-1;
        }

        cout<<fib(n,dp)<<endl;

        return 0;
}

*****************************************************************************************

BOTTOM UP APPROACH 

#include<bits/stdc++.h>
using namespace std;

int main()
{
       int n;
       cin>>n;

       vector<int> dp(n+1);

       dp[1]=1;
       dp[0]=0;

       for(int i=2;i<=n;i++){
               dp[i]=dp[i-1]+dp[i-2];
       }

       cout<<dp[n]<<endl;
}
*********************************************************************************************
SPACE OPTIMIZATION ON BUTTOM UP (USING ONLY VARIABLES)
space complexity :-O(1)
int main()
{
       int n;
       cin>>n;

       int prev1=1;
       int prev2=0;

       for(int i=2;i<=n;i++){
               int curr=prev1+prev2;
               //shift logic
               prev2=prev1;
               prev1=curr;
       }

       cout<<prev1<<endl;
}
*/