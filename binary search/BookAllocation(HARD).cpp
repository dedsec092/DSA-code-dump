/*

APPROACH -> make a search  space of 0 to sum of all pages then assign pages to students...all student must read ..all books must be asssigned...


#include <bits/stdc++.h> 
bool isPossibleSol(vector<int> &pages, int n, int b,int mid){
	int ninjaCount=1;
	int pageSum=0;
	for(int i=0;i<n;i++){
		if(pageSum+pages[i]<=mid){
			pageSum+=pages[i];
		}
		else{
			ninjaCount++;
			if(ninjaCount>b||pages[i]>mid){
				return false;
			}
			pageSum=0;
			pageSum=pages[i];
		}
		if(ninjaCount>b){
			return false;
		}
		
	}
	return true;
}
int allocateBooks(vector<int> &pages, int n, int b) ...b is number of students or ninjas..
{
	int s=0;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=pages[i];
	}
	int e=sum;
	int ans=-1;...store answer here...
	int mid=s+(e-s)/2;
	while(s<=e){
		if(isPossibleSol(pages,n,b,mid)){
			ans=mid;
			e=mid-1;......Need smallest possible answer....
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
*/