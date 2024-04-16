/*
#include <bits/stdc++.h> 
void solve(string str,vector<string>& ans,int i,string st){
	if(i>=str.length()){
		if(st.length()>0){
			ans.push_back(st);
		}
		
		return;
	}
	(HAVE TO EXCLUDE FIRST OR ELSE IF WE INCLUDE FIRST THEN RECURSION WILL KEEP ON INCUDING AND THE CODE WILL NOT WORK)
    EXCLUDE
	solve(str,ans,i+1,st);
    
    INCLUDE
	char element=str[i];
	st.push_back(element);
	solve(str,ans,i+1,st);
}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string st="";
	int i=0;
	solve(str,ans,i,st);
	return ans;
	
}

*/