/*
QUESTION: A POLYGON WILL BE GIVEN AND WE HAVE TO CREATE ALL POSSIBLE TRIANGLES SUCH THAT THE SUM OF THE  PRODUCT OF 
    VECTICES OF TRIANGLE SHOULD BE MINIMUM ...(WILL GET MANY ANSWERS GOTTA RETURN THE MINIMUM ONE)

    TOP DOWN APPROACH:
    TIME COMPLEXITY : O(N cube)
    SPACE COMPLEXITY: O(N square)
    int solve(vector<int>& values,int i,int j, vector<vector<int> >&dp){
        if(i+1==j){ // THIS BASE CASE MEANS ONLY TWO VERTICES ARE REMAINING(TRAIANGLE CANNOT BE FORMED)
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){//MAKING i AND j AS BASE OF THE TRIANGLE AND CHANGING k(last vertex) TO FIND ALL THE TRIANGLES
        // picking minimum sum of triangles from all possible triangles...
            ans=min(ans,values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp));//MAIN RECURRENCE RELATION
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int> >dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
        
    } 

****************************************************************************************************************
    BOTTOM UP APPROACH:
        int solveTab(vector<int>& values){
        int n=values.size();
        vector<vector<int> >dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){// OPPOSITE OF TOP DOWN
            for(int j=i+2;j<n;j++){
                    int ans=INT_MAX;
                 for(int k=i+1;k<j;k++){
                         ans=min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
        }
            dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        
        return solveTab(values);
        
    }
    ********************************************************
    NO SCOPE FOR SPACE OPTIMIZATION YET....
*/