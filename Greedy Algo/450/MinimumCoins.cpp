/*
Ninja has an unlimited supply of coins of 
1, 2, 5, 10, 20, 50, 100, 500, and 1000

Example:
Input: 'V' = 60
Output: 2

Ninja need to pay two coins only 50 + 10 = 60
******************************************************************
int minimumCoins(int v) {
    int ans=0;
    vector<int> arr={1,2,5,10,20,50,100,500,1000};
    for(int i=8;i>=0;i--){
        if(v>=arr[i]){
            int curr=v/arr[i];
            ans+=curr;
            v-=arr[i]*curr;
        }
    }
    return ans;
}

*/