#include<iostream>
using namespace std;

bool linear(int arr[],int key,int n){
    if(n==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
   bool ans= linear(arr+1,key,n-1);
   return ans;
}
int main(){
    int arr[5]={1,2,3,4,5};
    int key=2;
    cout<<linear(arr,key,5);

}