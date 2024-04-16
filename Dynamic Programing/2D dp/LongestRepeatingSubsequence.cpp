/*
	int solve(string &str,int i,int j, vector<vector<int>> &dp){
	    if(i==str.length()|| j==str.length()){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    int ans;
	    if(i!=j && str[i]==str[j] ){
	        
	            ans=1+solve(str,i+1,j+1,dp);
	        
	    }
	    else{
	        ans=max(solve(str,i+1,j,dp),solve(str,i,j+1,dp));
	    }
	    
	    dp[i][j]=ans;
	    return dp[i][j];
	}
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    string str2=str;
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    return solve(str,0,0,dp);
		}
*/