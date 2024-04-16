/*
QUESTION:Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

TIME COMPLEXITY: O(N *M)
SPACE COMPLEXITY:O(N *M)
TOP DOWN APPROACH:
int solve(string word1, string word2,int i,int j ,vector<vector<int>> &dp){
        //BASE CASE
        if(i==word1.length()){
            return word2.length()-j;// IF WORD1 IS SHORTER THEN WORD2..WILL OPERATE ON REST OF THE WORD2
            // IF WORD2 LENGTH ==J TEHN 0 WILL BE RETURNED ...BASE CASE FOR STOPPING..
        }
        if(j==word2.length()){
            return word1.length()-i;// IF WORD2 IS SHORTER THEN WORD1..WILL OPERATE ON REST OF THE WORD1
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        // IF WORD MATHES JUST MOVE AHEAD
        if(word1[i]==word2[j]){
            ans=solve(word1,word2,i+1,j+1,dp);
        }
        else{
            // **WE ARE ONLY COUNTING THESE OPERATIONS NOT PERFORMING IT 
            int insertAns=1+solve(word1,word2,i,j+1,dp);
            int deleteAns=1+solve(word1,word2,i+1,j,dp);
            int replaceAns=1+solve(word1,word2,i+1,j+1,dp);
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
    *************************************************************************************************************
    BOTTOM UP APPROACH:
    int solveTab(string word1, string word2){
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
      
        for(int j=0;j<word2.length();j++){
            dp[word1.length()][j]=word2.length()-j;
        }
        for(int i=0;i<word1.length();i++){
            dp[i][word2.length()]=word1.length()-i;
        }
        for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                 int ans=0;
                 if(word1[i]==word2[j]){
                     ans=dp[i+1][j+1];
                 }
                 else{
                     int insertA=1+dp[i][j+1];
                     int delA=1+dp[i+1][j];
                     int replaceA=1+dp[i+1][j+1];

                 ans=min(insertA,min(delA,replaceA));

        }
        dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        
        return solveTab(word1,word2);
    }
    ******************************************************************************************************
    SPACE OPTIMIZATION:
    SPACE COMPLEXITY:O(M)

    int solveTab(string word1, string word2){

        vector<int> next(word2.length()+1,0);
        vector<int> curr(word2.length()+1,0);
        for(int j=0;j<word2.length();j++){
           next[j]=word2.length()-j;
        }

        for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                //CATCH HERE -> BASE CASE ANALYSIS(SEE BOTTOM UP)
                curr[word2.length()]=word1.length()-i;
                 int ans=0;
                 if(word1[i]==word2[j]){
                     ans=next[j+1];
                 }
                 else{
                     int insertA=1+curr[j+1];
                     int delA=1+next[j];
                     int replaceA=1+next[j+1];

                 ans=min(insertA,min(delA,replaceA));

        }
        curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
         if(word2.length()==0){
            return word1.length();
        }
        
        return solveTab(word1,word2);
    }
*/