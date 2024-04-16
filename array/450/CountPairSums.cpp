/*
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
*****************************************
Input:
N = 4, K = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
**********************************************************
 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>map;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=k-arr[i]; // SAY x IS REMAINING AFTER WE SUBSTRACT arr[i] TO IT
            if(map[x]){ // IF THERES A MAPPING EXISTS FOR x
                ans=ans+map[x];// FREQUNCY OF x WILL BE ADDED TO ans...
            }
            map[arr[i]]++;// MAPPING EVERY ELEMENT 
        }
        return ans;
    }
*/