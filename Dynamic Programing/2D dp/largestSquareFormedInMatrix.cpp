/*
TOP DOWN APPROACH:
TIME COMPLEXITY: O(m*n)...
SPACE COMPLEXITY: O(m*n)...
int solve(int &maxi,int i,int j,vector<vector<int>> &mat, vector<vector<int>> &dp){
    //BASE CASE
    if(i>=mat.size()||j>=mat[0].size()){// INDECES SHOULD BE INSIDE THE MATRIX
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //CONDITIONS FOR FORMING AND MAXIMIZING A SQUARE
    int right=solve(maxi,i,j+1,mat,dp);//EXPANDING RIGHT
    int diagonal=solve(maxi,i+1,j+1,mat,dp);//EXPANDING DIAGONALLY
    int down= solve(maxi,i+1,j,mat,dp);// EXPANDING DOWN
    
    
    if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(diagonal,down));// ADDING 1 IF SQUARE FORMED..taking min() to make sure its perfectly square
        maxi=max(maxi,dp[i][j]);// STORING MAX ANS...
        return dp[i][j];//RETURNING ANS
    }
    else{
        return dp[i][j]=0;
    }
    
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=0;//WILL BE THE FINAL ANS..
        solve(maxi,0,0,mat,dp);
        return maxi;
    }
    *********************************************************************************************************
    BOTTOM UP APPROACH:(USING TOP DOWN APPROACH):

     int solveTab( vector<vector<int>> &mat,int &maxi){
        
        int row=mat.size();
        int col=mat[0].size();
        
         vector<vector<int>> dp(row+1,vector<int>(col+1,0));
         
         for(int i=row-1;i>=0;i--){// FORMED THIS NESTED LOOP BY ANALYSING THE BASE CASE..
             for(int j=col-1;j>=0;j--){
                    int right=dp[i][j+1];
                    int diagonal=dp[i+1][j+1];
                    int down=dp[i+1][j];
                    
                    if(mat[i][j]==1){
                        dp[i][j]=1+min(right,min(diagonal,down));
                        maxi=max(maxi,dp[i][j]);
                       
                    }
                    else{
                         dp[i][j]=0;
                    }
             }
         }
         return dp[0][0];
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        solveTab(mat,maxi);
        return maxi;
    }
    ********************************************************************************
    SPACE OPTIMIZATION:O(m)..
    int solveTab( vector<vector<int>> &mat,int &maxi){
        
        int row=mat.size();
        int col=mat[0].size();
        
       // using only two m size arrays to traverse through..
         vector<int> curr(col+1,0);
          vector<int> next(col+1,0);
         
         
         for(int i=row-1;i>=0;i--){
             for(int j=col-1;j>=0;j--){
                    int right=curr[j+1];
                    int diagonal=next[j+1];
                    int down=next[j];
                    
                    if(mat[i][j]==1){
                        curr[j]=1+min(right,min(diagonal,down));
                        maxi=max(maxi,curr[j]);
                       
                    }
                    else{
                         curr[j]=0;
                    }
             }
             next =curr;// in the end next will be the ans
         }
         return next[0]; // in the end the "next" becomes the final ans
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        solveTab(mat,maxi);
        return maxi;
    }
*/