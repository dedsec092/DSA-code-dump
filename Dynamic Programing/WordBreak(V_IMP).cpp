/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
 sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

*******************************************************************************************
int solve(string &s,unordered_set<string> &set,vector<int> dp,int index){
    if(index==s.length()){
        return true;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    for(int i=index;i<s.length();i++){
        if(set.count(s.substr(index,i+1-index)) && solve(s,set,dp,i+1)){
            dp[index]=true;
            return dp[index];
        }
    }
     dp[index]=false;
     return dp[index];
}
    bool wordBreak(string s, vector<string>& wordDict) {

        // USING SET TO ACCESS PARTICULAR STRING USING {set.count()}

        unordered_set<string> set(wordDict.begin(),wordDict.end()); // PUSHED ALL THE GIVEN DICTIONARY WORDS
        vector<int> dp(s.length(),-1);
        return solve(s,set,dp,0); 
    }
*/