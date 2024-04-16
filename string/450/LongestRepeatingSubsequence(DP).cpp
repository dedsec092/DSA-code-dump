/*
Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.


TIME COMPLEXITY: O(N square)
SPACE COMPLEXITY: O(N square)
*****************************************************************************
TOP DOWN:
//DP SOLUTION
	int solve(string &str,string &str2,int i,int j, vector<vector<int>> &dp,int n){
    //BASE CASE
	    if(i==n||j==n){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    int ans;
	    if(i!=j && str[i]==str2[j]){
	        ans=1+solve(str,str2,i+1,j+1,dp,n);
	        
	    }
	    else{
        // COMPARING IF WE SHOULD TAKE i+1 OR j+1 TO GET LONGEST ANS
	        ans=max(solve(str,str2,i+1,j,dp,n),solve(str,str2,i,j+1,dp,n));
	    }
	    dp[i][j]=ans;
	    return dp[i][j];
	}

int LRS(string & str) {
   string str2=str;
		    int n=str.length();
		    vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,-1));
		    return solve(str,str2,0,0,dp,n);
}
**************************************************************
BOTTOM UP:
	int solveTab(string &str,string & str2,int n){
	     vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,0));
	     int ans;
	     for(int i=n-1;i>=0;i--){
	         for(int j=n-1;j>=0;j--){
	             if(i!=j && str[i]==str[j]){
	                 ans=1+dp[i+1][j+1];
	             }
	             else{
	                 ans=max(dp[i+1][j],dp[i][j+1]);
	             }
	             dp[i][j]=ans;
	         }
	     }
	     return dp[0][0];
	}
	
		int LongestRepeatingSubsequence(string str){
		    string str2=str;
		    int n=str.length();
		   
		    return solveTab(str,str2,n);
		}
*************************************************************
    SPACE OPTIMIZATION:
    SPACE: O(N)

    	int solveTab(string &str,string & str2,int n){
	    
            vector<int> curr(str.length()+1,0);
            vector<int> next(str.length()+1,0);
	     int ans;
	     for(int i=n-1;i>=0;i--){
	         for(int j=n-1;j>=0;j--){
	             if(i!=j && str[i]==str[j]){
	                 ans=1+next[j+1];
	             }
	             else{
	                 ans=max(next[j],curr[j+1]);
	             }
	             curr[j]=ans;
	         }
	         next=curr;
	     }
	     return next[0];
	}
	
		int LongestRepeatingSubsequence(string str){
		    string str2=str;
		    int n=str.length();
		   
		    return solveTab(str,str2,n);
		}
*/