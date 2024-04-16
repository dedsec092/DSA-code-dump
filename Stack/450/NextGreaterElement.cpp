/*
Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
***********************************************************************************
 vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
       
        
        vector<long long > ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            else{
                ans[i]=-1;
            }
            
            s.push(arr[i]);
        }
        return ans;
    }

    ***********************************************************************************
    2ND VARIATION (CIRCULAR ARRAY):

    Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

 vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> ans(n);
        
        for(int i=(2*n)-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n){ //WITHOUT THIS CONDITION THE INDEX WILL GO OUT OF BOUND 
                  if(!s.empty()){
                ans[i]=s.top();
                        }
                 else{
                    ans[i]=-1;
                     }
            }
          
            s.push(nums[i%n]);
        }
        return ans;
    }
*/