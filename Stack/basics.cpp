#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;

    stack(int size){
        this->size=size;
        top=-1;
        arr= new int[size];
    }


void push(int element){
    if(size-top>1){
        top++;
        arr[top]=element;
    }
    else{
        cout<<" stack overflow";
    }
}

void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<" stack underflow";
    }
}
void peek(){
    if(top>=0)
    cout<<arr[top];

    else{
        cout<<" nothing in stack";
    }

}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

};
int main(){

    stack s(5);

    s.push(1);

    s.peek();

}