#include<iostream>
using namespace std;

int binarySearch(int *arr,int s,int e,int key){
   
   if(s>e){
    return -1;
   }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}
int main(){
     int arr[5]={1,2,3,4,5};
    int key=6;
    cout<<binarySearch(arr,0,4,6);
}