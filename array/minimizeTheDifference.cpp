/*
#include <bits/stdc++.h> 
int minimizeIt(vector<int> A, int K)
{// MINIMIZING THE MAXIMUM DIFFERENCE BETWEEN TWO ELEMENTS...
// CAN SUBSTRACT OR ADD K IN ANY ELEMENT TO GET THE MINIMUM DIFFIRENCE..
	int n=A.size();
	sort(begin(A),end(A));//..sorting
	
	int ans=A[n-1]-A[0];// initial ans..
	int smallest=A[0]+K;
	int largest=A[n-1]-K;
	int mini,maxi;

	for(int i=0;i<n;i++){
		maxi=max(largest,A[i]+K);// finding potential answers..
		mini=min(smallest,A[i+1]-K);
		
		if(mini<0) continue;// breaks the iteration and moves to next iteration..
		ans=min(ans,maxi-mini);
	}
	return ans;
}
*/