/*
void addAns(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(vector<vector<int>> &board,int row,int col,int n){
	int x=row;
	int y=col;

	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}
	x=row;
	y=col;
	while(x>=0&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	x=row;
	y=col;
	while(x<n&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}
	return true;
}
void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
	// base case
	if(col==n){
		addAns(board,ans,n);
		return;
	}
	//solving one case ,rest reccursion will do...
	for(int row=0;row<n;row++){
		if(isSafe(board,row,col,n)){
			board[row][col]=1;
			solve(col+1,ans,board,n);
			//backtracking
			board[row][col]=0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));..GONNA TEST ON BOARD
	vector<vector<int>> ans;                        AND SAVE THE FINAL ANSWER IN ans.

	solve(0,ans,board,n);

	return ans;
	
}
*/