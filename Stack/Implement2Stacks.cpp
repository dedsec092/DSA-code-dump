/*
class TwoStack {

public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    TwoStack(int s) {
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    
    
    void push1(int num) {
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    
    void push2(int num) {
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        return -1;
    }
};


*/