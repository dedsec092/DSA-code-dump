/*
#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

  

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rear==size){
            return;
        }
        arr[rear]=data;
        rear++;
    }

    int dequeue() {
        if(qfront==rear){
            return -1;
        }
        int element=arr[qfront];
       arr[qfront]=-1;
        qfront++;
         if(qfront==rear){
            qfront=0;
            rear=0;
        }
        
        return element;
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
        return arr[qfront];
    }
};
*/