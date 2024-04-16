/*
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

**************************************************************
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0,ans=1;
    while(i<n){
        if(at[i]<dt[j]){
            ans++;
            i++;
        }
        else{
            i++;j++;
        }
    }
    return ans;
}
*/