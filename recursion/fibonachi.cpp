#include<iostream>
using namespace std;
int fibonacci(int n){
    int ans=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    ans=fibonacci(n-1)+fibonacci(n-2);
    return ans;
}
int main(){
    int n=4;
    cout<<fibonacci(n);
}