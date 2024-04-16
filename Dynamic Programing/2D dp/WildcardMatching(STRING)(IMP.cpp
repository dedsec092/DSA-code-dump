/*
QUESTION:Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).


 HAVE TO START FROM THE LAST INDEX(S.LENGTH()-1,P.LENGTH()-1) TO PASS ALL THE TEST CASE..
 TIME COMPLEXITY:O(N*M)..
 SPACE COMPLEXITY :O(N*M)..

bool solve(string &s, string &p,int i,int j,  vector<vector<int>> &dp){
        if(i<0&&j<0){// WHEN BOTH STRING GETS MATHCED
            return true;
        }
        if(i>=0 && j<0){// WHEN PATTERN STRING(P) FINSHES BEFORE STRING (S)..
            return false;
        } 
        if(i<0 && j>=0){// WHEN STRING(S) FINSHES BEFORE PATTERN STRING (P)..
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){// IF * IS NOT PRESENT IN PATTERN STRING
                    return false;
                }     
            }
            return true;// WHEN * IS PRESENT THEN PATTERN MATHCING IS POSSIBLE
        }

        int ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==p[j] || p[j]=='?'){
           return dp[i][j]= solve(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
           return dp[i][j]=  solve(s,p,i-1,j,dp) || solve(s,p, i, j-1,dp);
        }
        else{
            return false;
        }
       
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }

    BOTTOM UP AND SPACE OPTIMIZATION AVAILABLE IN PLAYLIST!!!
*/