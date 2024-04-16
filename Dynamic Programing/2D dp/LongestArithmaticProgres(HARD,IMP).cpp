/*
QUESTION:Given an array called A[] of sorted integers having no duplicates, find the length of the Longest Arithmetic Progression in it.
set[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.

TIME COMPLEXITY: O(N square)
SPACE COMPLEXITY:  O(N square)
TOP DOWN APPROACH:
int solve(int index,int diff,int A[], unordered_map<int,int> dp[]){
    if(index<0){
        return 0;
    }
    if(dp[index].count(diff)){
        return dp[index][diff];
    }
    int ans=0;// this ans will be added to the main function's ans to make final ans
    
    for(int j=index-1;j>=0;j--){
        if(A[index]-A[j]==diff){
            ans=max(ans,1+solve(j,diff,A,dp));// diff is changing in fn call (not in recursion calls)
        }
    }
    dp[index][diff]=ans;
    return dp[index][diff];
    
}
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2){
            return n;
        }
        int ans=0; //this will be updated using "solve" fn..
        unordered_map<int,int> dp[n+1];// map is used beacause every index has multiple diffs which
                                    // results to multiple lengths(answers) so map is required
        
        for(int i=0;i<n;i++){// checking evry possible AP
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,A[j]-A[i],A,dp));// here two elements are selected
                // AND BY DEFUALT THEY ARE INCLUDED IN AP(thats why "2+")..solve fn called for traversing 
                //backward to find AP elements..
            }
        }
        
        return ans;
    }
    ***************************************************************************************
*/