#include<iostream>
using namespace std;
class heap {
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){

        size=size+1;
        arr[size]=val;
        int i=size;
//...find the correct position of new value as parent node will be the highest value...
        while(i>1){
            int parent=i/2;

            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        //make the last node as root node 
        arr[1]=arr[size];
        size--;//...deletion complete...

        //rearranging remaining node...
        int i=1;

        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex<size&& arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size&& arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
        }
    }
  
};