/*

int findMaxValue(vector<vector<int>>& mat, int n) {
	vector<vector<int>> M(n,vector<int> (n,INT_MIN));
	int ans=INT_MIN;
	for(int i=n-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			// MAXIMISING MATRIX M IN EVERY POSSIBLE WAY 
			M[i][j]=max(mat[i+1][j+1],max(M[i+1][j+1],max(M[i+1][j],M[i][j+1])));
			ans=max(ans,M[i][j]-mat[i][j]);
		}
	}
	return ans;
}
*/