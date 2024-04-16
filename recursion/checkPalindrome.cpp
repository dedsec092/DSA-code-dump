#include<iostream>
using namespace std;

bool isPalindrome(string &str,int i,int j){
    if(i>j){
        return true;
    }
   if(str[i]!=str[j]){
        return false;
   }
    i++;j--;
   bool ans= isPalindrome(str,i,j);
   return ans;
    
}
int main(){

    string str="abaa";
    cout<<isPalindrome(str,0,str.length()-1);
}