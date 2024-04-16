/*
LOTS OF NEW SYNTAX....
Time Complexity:-O(n*klog(k))..
Space Complexity:-O(n*k)..

MAKING USE OF MINHEAP TOP AS IT WILL BE SMALLEST IN THE HEAP..
#include <bits/stdc++.h> 
#include<queue>

class node{//...custom data structure which contains data,row and col...
    public:          //(node)
    int data;
    int r;
    int c;
    node(int data,int r,int c){
        this->data=data;
        this->r=r;
        this->c=c;
    }
};

class compare{//need to do this BS to minHeap to work on custom node
    public:
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)//multiple arrays given in 
{                                                                   //form of 2d array(kArrays)..
    STEP 1-:
    priority_queue<node*, vector<node*>, compare >minHeap;
    for(int i=0;i<k;i++){
        node*temp=new node(kArrays[i][0],i,0);// all frist elements of kArrays..
        minHeap.push(temp);
    }

    vector<int> ans;

    STEP 2-:

    while(!minHeap.empty()){
        node*temp= minHeap.top();//we know that minHeap top will have the smallest value..
                                    //so push it n ans to get sorted final array..
        ans.push_back(temp->data);
        minHeap.pop();
        //...push next element 
        int r=temp->r;
        int c=temp->c;

        if(c+1<kArrays[r].size()){
            node* next=new node(kArrays[r][c+1],r,c+1);
            minHeap.push(next);
        }
    }
    return ans;
}
*/