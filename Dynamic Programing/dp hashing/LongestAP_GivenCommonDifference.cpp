/*
 int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        unordered_map<int,int> dp;

        for(int i=0;i<arr.size();i++){

            int prevAP =arr[i]-difference;// prevAP is before current index "i"
            int prevAns=0;// this refers to longest subsequence till temp 

            // we used map only for this searching purpose
            if(dp.count(prevAP)){// if temp found in map update prevAns 
                prevAns=dp[prevAP];// storing in dp
            }

            // current ans update
            dp[arr[i]]=1+prevAns; 
        `   
            // ans update
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
*/