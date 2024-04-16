/*
#include <bits/stdc++.h>
int merge(long long *arr,int start, int end,int mid){
   int count=0;
    int i=start;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            count+=(mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j<=end){
         temp.push_back(arr[j]);
            j++;
    }
        for(int k=start;k<=end;k++){
            arr[k]=temp[k-start]; // WHY (- START) ??????
        }
    return count;
}
int mergeSort(long long *arr,int start,int end) {
    int count=0;
    if(start>=end){
        return count;
    }
    int mid=(start+end)/2;
    count+= mergeSort(arr,  start,  mid); // AS ARRAY DIVIDES DOWN TO SINGLE ELEMENTS THERE CAN BE INVERSIONS
    count+=mergeSort(arr,  mid+1,  end);
    count+=merge(arr,start,end,mid); // INVERSION BETWEEN TWO SORTED ARRAYS ...
    return count;

}
long long getInversions(long long *arr, int n){
        return mergeSort(arr, 0,  n-1);
}

*/