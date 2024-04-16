/*
Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.

*****************************************************************************************
void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        //TRAVERSING TO FIND A BREAKING POINT 
        for(int i=n-2;i>=0;i--){// COMPARING WITH LAST ELEMENT
            if(nums[i]<nums[i+1]){ // i=n-2 REASON(i+1)...
                
                index=i;
                break;
            }
        }
        if(index==-1){// IT MEANS THE nums IS THE LAST PERMUTATION SO JUST SORT IT
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);// SWAP THE BREAKING POINT WITH SLIGHTLY BIGGER NUMBER
            }
        }
        reverse(nums.begin()+index+1,nums.end()); // REVERSE THE ARRAY FROM BREAKING POINT TO GET NEXT PERMUTATION
    }


*/