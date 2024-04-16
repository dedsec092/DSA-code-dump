/*
TIME : O(N)
SPACE : O(1)

  void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {// 0 FOUND BOTH LOW AND MID MOVES AHEAD
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {// IF 1 FOUND ONLY MID MOVES AHEAD
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
*************************************************************************************************
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int countZero=0;
   int countOne=0;
   int countTwo=0;
  
   for(int i=0;i<n;i++){
      if(arr[i]==0){
         countZero++;
      }
      if(arr[i]==1){
         countOne++;
      }
      if(arr[i]==2){
         countTwo++;
      }
   }
    int i=0;
   while(countZero>0){
      arr[i]=0;
      i++;
      countZero--;
   }

    while(countOne>0){
      arr[i]=1;
      i++;
      countOne--;
   }

    while(countTwo>0){
      arr[i]=2;
      i++;
      countTwo--;
   }



}
*/