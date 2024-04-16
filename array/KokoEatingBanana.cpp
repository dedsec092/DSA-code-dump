/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
**********************************************************************************************
long long  findMax(vector<int>& piles){
    long long  maxi=0;
    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,(long long)piles[i]);
    }
    return maxi;
}
long long  calculateTotalHours(vector<int>& piles,long long  currMid){
    long long  totalHours=0;
    for(int i=0;i<piles.size();i++){
        totalHours+= ceil((double)piles[i]/(double)currMid); // ceil(0.5)=1..
    }
    return totalHours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start=1;
        long long  end=findMax(piles);
        long long ans=0;
        while(start<=end){
            long long  mid=(start+end)/2;
            long long  totalHours=calculateTotalHours(piles,mid);
            if(totalHours<=h){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
*/