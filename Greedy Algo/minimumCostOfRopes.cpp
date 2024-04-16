/*
QUESTION:There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29

APPROACH:
long long minCost(long long arr[], long long n) {
        priority_queue<long long ,vector<long long >, greater<long long> > minHeap;
        for(int i=0;i<n;i++){
            minHeap.push(arr[i]);
        }
        long long ans=0; // total cost..
        while(minHeap.size()>1){
            long long first=minHeap.top();
            minHeap.pop();
            long long second=minHeap.top();
            minHeap.pop();
            long long mergeCost=first+second;
            ans=ans+mergeCost;
            minHeap.push(mergeCost);
        }
        return ans;
    }
*/