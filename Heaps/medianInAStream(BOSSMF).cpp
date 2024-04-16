/*
#include<queue>
int signum(int a,int b){
	if(a==b)//case even numbers in array..
	return 0;
	else if (a>b){// ODD NUMBER n at left part and n-1 in right part of array
		return 1;
	}
	else{// ODD NUMBER n-1 at left part and n in right part of array
		return -1;// returning 1 or or -1 is a signum thing...
	}
}

void callMedian(int element,priority_queue<int> &maxHeap,
priority_queue<int ,vector<int>, greater<int> >&minHeap,int &median){
	switch(signum(maxHeap.size(),minHeap.size())){
		case 0: if(element>median){
			minHeap.push(element);// minheap is the right part of array ..adding onr more element from stream
			median=minHeap.top();
		}
		else{
			maxHeap.push(element);// maxheap is the left part of array 
			median=maxHeap.top();
		}
		break;

		case 1: if(element>median){
			minHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
		else{
			  minHeap.push(maxHeap.top());// this step is to maintain balance
			  maxHeap.pop();				
			  maxHeap.push(element);
			  median=(minHeap.top()+maxHeap.top())/2;
		}
		break;

		case -1: if(element>median){
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
		else{
			maxHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
		break;

	}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int ,vector<int>, greater<int> >minHeap;
	int median=0;

	for(int i=0;i<n;i++){
		callMedian(arr[i],maxHeap,minHeap,median);//for every arr[i] we have to save a median..
		ans.push_back(median);
	}
	return ans;
}

*********************************************************************************************************

SOLUTION WITHOUT USING SWITCH IN CALLMEDIAN()....

#include<queue>
int signum(int a,int b){
	if(a==b)//case even numbers in array..
	return 0;
	else if (a>b){// ODD NUMBER n at left part and n-1 in right part of array
		return 1;
	}
	else {// ODD NUMBER n-1 at left part and n in right part of array
		return -1;// returning 1 or or -1 is a signum thing...
	}
}

void callMedian(int element,priority_queue<int> &maxHeap,
priority_queue<int ,vector<int>, greater<int> >&minHeap,int &median){
	int signumOutput=signum(maxHeap.size(),minHeap.size());
	if(signumOutput==0){
		if(element>median){
			minHeap.push(element);// minheap is the right part of array ..adding onr more element from stream
			median=minHeap.top();
		}
		else{
			maxHeap.push(element);// maxheap is the left part of array 
			median=maxHeap.top();
		}
	}
	
	   if(signumOutput==1){
		   if(element>median){
			minHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
		else{
			  minHeap.push(maxHeap.top());// this step is to maintain balance
			  maxHeap.pop();				
			  maxHeap.push(element);
			  median=(minHeap.top()+maxHeap.top())/2;
		}
	   }

	   if(signumOutput==-1){
		   if(element>median){
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
		else{
			maxHeap.push(element);
			median=(minHeap.top()+maxHeap.top())/2;
		}
	   }
		


	}


vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int ,vector<int>, greater<int> >minHeap;
	int median=0;

	for(int i=0;i<n;i++){
		callMedian(arr[i],maxHeap,minHeap,median);//for every arr[i] we have to save a median..
		ans.push_back(median);
	}
	return ans;
}
*/

