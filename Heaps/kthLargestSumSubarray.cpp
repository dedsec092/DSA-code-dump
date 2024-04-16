/*
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int> > mini;// used min heap...
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){//..no choice (we have to use two loops to save subarrays)
			sum+=arr[j];//.....storing subarray sums..
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){//...comparing the smallest element of heap to sum
					mini.pop();		//..so that in the end all the large elements
					mini.push(sum); // will add up..
				}
			}
		}
	}
	return mini.top();
}
*/