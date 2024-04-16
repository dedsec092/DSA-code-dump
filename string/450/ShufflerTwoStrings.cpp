/*
QUESTION:You are given three strings “A”, “B” and “C”. Your task is to check whether “C” is formed by an interleaving of A and B. 
C is said to be interleaving “A” and “B”, if the length of “C” is equal to the sum of the length of A and length of B,
 all the characters of “A” and “B” are present in “C”, and the order of all these characters remains the same in all three strings.

For Example:
If A = “aab”, B = “abc”, C = “aaabbc”
Here C is an interleaving string of A and B. 
Because C contains all the characters of A and B 
and the order of all these characters is also the same in all three strings.
*******************************************************************
//USING 2D DP...
TIME COMPLEXITY O(N*M)
SPACE COMPLEXITY: O(N*M)
bool solve(string a, string b, string c,int l1,int l2,int l3,vector<vector<int>> &dp){
	if(l3==0){
		return true;
	}
	if(dp[l1][l2]!=-1){
		return dp[l1][l2];
	}

	int x=0;
	int y=0;

	if(l1-1>=0 && a[l1-1]==c[l3-1]){
		x=solve(a,  b,  c,  l1-1,  l2,  l3-1,  dp);
	}
	if(l2-1>=0 && b[l2-1]== c[l3-1]){
		y=solve(a,  b,  c,  l1,  l2-1,  l3-1, dp);
	}
	dp[l1][l2]=(x||y);// X OR Y
	return dp[l1][l2];
}
bool isInterleave(string a, string b, string c){
	int l1=a.length();
	int l2=b.length();
	int l3=c.length();

	if(l1+l2!=l3){
		return false;
	}
	vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
	return solve(a,b,c,l1,l2,l3,dp);
}
*/