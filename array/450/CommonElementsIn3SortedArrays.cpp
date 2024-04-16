/*
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
****************************************************************
#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
   vector<int> ans;
   int i=0;
   int j=0;
   int k=0;
   set<int> s;
   while(i<a.size()&& j<b.size()&& k<c.size()){
       if(a[i]<b[j]){
           i++;
       }
       else if(b[j]<c[k]){
           j++;
       }
       else if(c[k]<a[i]){
           k++;
       }
       else if(a[i]==b[j]&& b[j]==c[k]){
          s.insert(a[i]);
           i++;
           j++;
           k++;
       }
   }
    for(auto it: s){
        ans.push_back(it);
    }
    return ans;
}
*/