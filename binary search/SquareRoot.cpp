/*
class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int mid=s+(e-s)/2;
       int ans=0;
        while(s<=e){
            int sq=mid*mid;
            if(sq==x){
                return mid;
            }
            else if(sq<x){
                ans=mid;
                s=mid+1;
            }
            else{
               e=mid-1;
            }
             mid=s+(e-s)/2;
        }
        return ans;
    }
};
*/