/*
#include <bits/stdc++.h>
#include<stack> 
int findMinimumCost(string str) {
  stack<char> s;
  int a=0;
  int b=0;
  if(str.length()%2!=0){
    return -1;
  }

  for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(ch=='{'){
      s.push(ch);
    }
    else{
      if(!s.empty()&&s.top()=='{'){
        s.pop();
      }
      else{
        s.push(ch);
      }
    }
  }

  while(!s.empty()){
    if(s.top()=='{'){
      a++;
    }
    else{
      b++;
    }
    s.pop();
  }
  int ans=((a+1)/2 )+((b+1)/2);

  return ans;
}
*/